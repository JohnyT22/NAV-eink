/**
 * @file espi.c
 * @author Jan Tomček (xtomec09@stud.fit.vutbr.cz)
 * @brief Module for SPI comunication with the eINk display
 * @version 0.1
 * @date 01.05.2023
 *
 *
 * code is based on ESP-IDF example SPI sender
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "driver/spi_master.h"
#include "esp_log.h"

#include "eink.h"

static const char *TAG = "espi.c";

static spi_device_handle_t handle = NULL;
static spi_transaction_t t;
static esp_err_t ret;

/**
 * @brief SPI Inicialization function
 *
 * Inicialize SPI Comunication on pins that are
 * defined in edisplay.h:
 * MOSI - EINK_MOSI_PIN
 * SCLK - EINK_SCLK_PIN
 * SS   - EINK_CS_PIN
 *
 */
void SPI_Init()
{
    if(handle != NULL) return;
    if(DEBUG)ESP_LOGI(TAG, "SPI inicialization...");
    // Configuration for the SPI bus
    spi_bus_config_t buscfg = {
        .mosi_io_num = EINK_MOSI_PIN,
        .miso_io_num = -1,
        .sclk_io_num = EINK_SCLK_PIN,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1};

    // Configuration for the SPI device on the other side of the bus
    spi_device_interface_config_t devcfg = {
        .command_bits = 0,
        .address_bits = 0,
        .dummy_bits = 0,
        .clock_speed_hz = 1000000,
        .duty_cycle_pos = 128, // 50% duty cycle
        .mode = 0,
        .spics_io_num = EINK_CS_PIN,
        .cs_ena_posttrans = 3, // Keep the CS low 3 cycles after transaction, to stop slave from missing the last bit when CS has less propagation delay than CLK
        .queue_size = 3};

    // Initialize the SPI bus and add the device we want to send stuff to.
    ret = spi_bus_initialize(SENDER_HOST, &buscfg, DMA_CHAN);
    assert(ret == ESP_OK);
    ret = spi_bus_add_device(SENDER_HOST, &devcfg, &handle);
    assert(ret == ESP_OK);

    if(DEBUG)ESP_LOGI(TAG, "SPI DONE");
}

/**
 * @brief Sends byte via SPI
 *
 * @param byte byte that will be send over spi
 */
void SPI_Send_Byte(uint8_t byte)
{

    memset(&t, 0, sizeof(t));

    t.length = 8;
    t.tx_buffer = &byte;
    t.rx_buffer = NULL;

    ret = spi_device_transmit(handle, &t);
    assert(ret == ESP_OK);
}

/**
 * @brief Removes SPI comunication
 *
 * Removes device configured in SPI_Init()
 *
 */
void SPI_Finish()
{
    ret = spi_bus_remove_device(handle);
    assert(ret == ESP_OK);
}