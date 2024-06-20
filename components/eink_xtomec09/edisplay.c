/**
 * @file edisplay.c
 * @author Jan Tomček (xtomec09@stud.fit.vutbr.cz)
 * @brief Module with functions for eink display functionality
 * @version 0.1
 * @date 01.05.2023
 *
 *
 * code based on Raspbery pi jetson driver from waveshare repozitory
 * repozitory: https://github.com/waveshare/e-Paper/blob/master/RaspberryPi_JetsonNano/c/lib/e-Paper/EPD_1in54.c
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "esp_log.h"

#include "eink.h"

/**
 * @brief array for image data
 *
 */
static uint8_t _image_data[5000];

/**
 * @brief Image buffer
 *
 * This buffer is transfered to einkDisplay after calling einkD_Refresh()
 *
 */
static eink_image_t image;

static const char *TAG = "edisplay.c";

/**
 * @brief LUT for full update, used in einkD_Init(eink_update_t updateType)
 *
 */
static const uint8_t lut_full_update[] = {
    0x02, 0x02, 0x01, 0x11, 0x12, 0x12, 0x22, 0x22,
    0x66, 0x69, 0x69, 0x59, 0x58, 0x99, 0x99, 0x88,
    0x00, 0x00, 0x00, 0x00, 0xF8, 0xB4, 0x13, 0x51,
    0x35, 0x51, 0x51, 0x19, 0x01, 0x00};

/**
 * @brief LUT for partial update, used in einkD_Init(eink_update_t updateType)
 *
 */
static const uint8_t lut_partial_update[] = {
    0x10, 0x18, 0x18, 0x08, 0x18, 0x18, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x13, 0x14, 0x44, 0x12,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/**
 * @brief Returs the pointer to the image buffer
 *
 * @return eink_image_t* - pointer to image buffer
 */
eink_image_t *einkD_GetImgPointer()
{
    return &image;
}

/**
 * @brief Resets the eink Display
 *
 */
void einkD_Reset()
{
    if(DEBUG)ESP_LOGI(TAG, "Resetting display...");
    gpio_set_level(EINK_RST_PIN, 1);
    vTaskDelay(100);
    gpio_set_level(EINK_RST_PIN, 0);
    vTaskDelay(10);
    gpio_set_level(EINK_RST_PIN, 1);
    vTaskDelay(100);
    if(DEBUG)ESP_LOGI(TAG, "Reset DONE");
}

/**
 * @brief Sends command via SPI
 *
 * @param cmd byte number of the command
 */
void einkD_SendCommand(uint8_t cmd)
{
    gpio_set_level(EINK_DC_PIN, 0);
    SPI_Send_Byte(cmd);
}

/**
 * @brief Sends data byte via SPI
 *
 * @param data byte of data
 */
void einkD_SendData(uint8_t data)
{
    gpio_set_level(EINK_DC_PIN, 1);
    SPI_Send_Byte(data);
}

/**
 * @brief Sends data via SPI
 *
 * Iterates through data and sends individual bytes via einkD_SendData(uint8_t data)
 *
 * @param data pointer to data array
 * @param size array size
 */
void einkD_SendDataBatch(uint8_t *data, size_t size)
{
    gpio_set_level(EINK_DC_PIN, 1);

    for (size_t i = 0; i < size; i++)
    {
        SPI_Send_Byte(data[i]);
    }
}

/**
 * @brief Waits until the Busy pin goes to low
 *
 */
void einkD_WaitForBusy()
{
    if(DEBUG)ESP_LOGI(TAG, "Waiting for busy pin...");
    while (gpio_get_level(EINK_BUSY_PIN) == 1)
    {
        vTaskDelay(100);
    }
    if(DEBUG)ESP_LOGI(TAG, "Waiting DONE");
}

/**
 * @brief Sets the area where there will be drawn
 *
 * @param Xstart X position of start
 * @param Ystart Y position of start
 * @param Xend X position of end
 * @param Yend Y position of end
 */
void einkD_SetWindow(uint8_t Xstart, uint8_t Ystart, uint8_t Xend, uint8_t Yend)
{
    einkD_SendCommand(0x44); // SET_RAM_X_ADDRESS_START_END_POSITION
    einkD_SendData((Xstart >> 3) & 0xFF);
    einkD_SendData((Xend >> 3) & 0xFF);

    einkD_SendCommand(0x45); // SET_RAM_Y_ADDRESS_START_END_POSITION
    einkD_SendData(Ystart & 0xFF);
    einkD_SendData((Ystart >> 8) & 0xFF);
    einkD_SendData(Yend & 0xFF);
    einkD_SendData((Yend >> 8) & 0xFF);
}

/**
 * @brief Sets cursor to given position
 *
 * @param X X position
 * @param Y Y position
 */
void einkD_SetCursor(uint8_t X, uint8_t Y)
{
    einkD_SendCommand(0x4E); // SET_RAM_X_ADDRESS_COUNTER
    einkD_SendData((X >> 3) & 0xFF);

    einkD_SendCommand(0x4F); // SET_RAM_Y_ADDRESS_COUNTER
    einkD_SendData(Y & 0xFF);
    einkD_SendData((Y >> 8) & 0xFF);
}

/**
 * @brief Refreshes the eink Display content
 *
 * Send the Image buffer to the eink Display and sends the command to refresh
 *
 */
void einkD_Refresh()
{
    if(DEBUG)ESP_LOGI(TAG, "Refreshing Display");

    uint8_t Width, Height;
    Width = (EINK_WIDTH % 8 == 0) ? (EINK_WIDTH / 8) : (EINK_WIDTH / 8 + 1);
    Height = EINK_HEIGHT;

    int Addr = 0;

    einkD_SetWindow(0, 0, EINK_WIDTH, EINK_HEIGHT);
    for (uint8_t j = 0; j < Height; j++)
    {
        einkD_SetCursor(0, j);
        einkD_SendCommand(0x24);
        for (uint8_t i = 0; i < Width; i++)
        {
            Addr = i + j * Width;
            einkD_SendData(image.data[Addr]);
        }
    }

    einkD_SendCommand(0x22); // DISPLAY_UPDATE_CONTROL_2
    einkD_SendData(0xC4);
    einkD_SendCommand(0x20); // MASTER_ACTIVATION
    einkD_SendCommand(0xFF); // TERMINATE_FRAME_READ_WRITE

    einkD_WaitForBusy();
    if(DEBUG)ESP_LOGI(TAG, "Refresh DONE");
}

int gpio_inicialized = 0;	

/**
 * @brief Inicializes the gpio pins for eink Display excluding the SPI pins
 *
 * Pins are definded in edisplay.h
 * Busy pin - EINK_BUSY_PIN
 * RST pin - EINK_RST_PIN
 * DC pin - EINK_DC_PIN
 *
 */
void gpioInit()
{
    if(gpio_inicialized == 1) return;
    if(DEBUG)ESP_LOGI(TAG, "GPIO inicialization...");
    gpio_config_t busy_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .pin_bit_mask = (1 << EINK_BUSY_PIN)};

    gpio_config_t rst_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .pin_bit_mask = (1 << EINK_RST_PIN)};

    gpio_config_t dc_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .pin_bit_mask = (1 << EINK_DC_PIN)};

    gpio_config(&busy_conf);
    gpio_config(&rst_conf);
    gpio_config(&dc_conf);

    gpio_set_level(EINK_RST_PIN, 1);
    gpio_set_level(EINK_DC_PIN, 0);

    gpio_inicialized = 1;
    if(DEBUG)ESP_LOGI(TAG, "GPIO DONE");
}

/**
 * @brief Inicialization of the eink Display
 *
 * Inicialize sequence for the display
 *
 * sets the type of update - Full/Partial
 *
 * @param updateType type of update
 */
void einkD_Init(eink_update_t updateType)
{
    if(DEBUG)ESP_LOGI(TAG, "Starting inicialization...");
    image.size = 5000;
    image.data = _image_data;

    _egraphics_init();

    gpioInit(); // set BUSY, RST, DC pins
    SPI_Init();

    einkD_Reset();
    memset(image.data, 0, image.size);

    einkD_SendCommand(0x01); // DRIVER_OUTPUT_CONTROL
    einkD_SendData((EINK_HEIGHT - 1) & 0xFF);
    einkD_SendData(((EINK_HEIGHT - 1) >> 8) & 0xFF);
    einkD_SendData(0x00); // GD = 0; SM = 0; TB = 0;

    einkD_SendCommand(0x0C); // BOOSTER_SOFT_START_CONTROL
    einkD_SendData(0xD7);
    einkD_SendData(0xD6);
    einkD_SendData(0x9D);

    einkD_SendCommand(0x2C); // WRITE_VCOM_REGISTER
    einkD_SendData(0xA8);    // VCOM 7C

    einkD_SendCommand(0x3A); // SET_DUMMY_LINE_PERIOD
    einkD_SendData(0x1A);    // 4 dummy lines per gate

    einkD_SendCommand(0x3B); // SET_GATE_TIME
    einkD_SendData(0x08);    // 2us per line

    einkD_SendCommand(0x11);
    einkD_SendData(0x03);

    // set the look-up table register
    einkD_SendCommand(0x32);
    if (updateType == EINK_FULL_UPDATE)
    {
        einkD_SendDataBatch((uint8_t *)lut_full_update, sizeof(lut_full_update));
    }
    else
    {
        einkD_SendDataBatch((uint8_t *)lut_partial_update, sizeof(lut_partial_update));
    }

    if(DEBUG)ESP_LOGI(TAG, "Init DONE");
}

/**
 * @brief Cleares the display content
 *
 */
void einkD_Clear()
{
    if(DEBUG)ESP_LOGI(TAG, "Clearing Display");
    memset(image.data, 0xFF, image.size);
    einkD_Refresh();
}

/**
 * @brief Puts the display into deepsleep mode
 *
 */
void einkD_Sleep()
{
    if(DEBUG)ESP_LOGI(TAG, "Putting Display to sleep");
    gpio_set_level(EINK_DC_PIN, 0);
    einkD_SendCommand(0x10);
    einkD_SendData(0x01);
    vTaskDelay(100);
}