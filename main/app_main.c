

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "esp_log.h"
#include "driver/gpio.h"

#include "eink.h"

#define GPIO_UP 27
#define GPIO_DOWN 16
#define GPIO_LEFT 17
#define GPIO_RIGHT 25
#define GPIO_MIDDLE 26

//static const char *TAG = "app_main.c";

void gpio_init();

void show_ReferenceScreen();
void drawHelp();
void play_Demo();
void sensor_Demo();
void anim_Demo();

void (*function)() = &drawHelp;



void main_loop_task(void *pvParameter)
{
    while (1)
    {
        (*function)();
        vTaskDelay(100);
    }
}

// Main application
void app_main(void)
{
    gpio_init();
    xTaskCreate(&main_loop_task, "eink_demo", 2048, NULL, 5, NULL);
}

static void IRAM_ATTR gpio_change_program_isr_handler(void *arg)
{
    function = arg;
}

void gpio_init()
{
    gpio_config_t up_conf = {
        .intr_type = GPIO_INTR_POSEDGE,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .pin_bit_mask = (1 << GPIO_UP)};

    gpio_config_t down_conf = {
        .intr_type = GPIO_INTR_POSEDGE,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .pin_bit_mask = (1 << GPIO_DOWN)};

    gpio_config_t left_conf = {
        .intr_type = GPIO_INTR_POSEDGE,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .pin_bit_mask = (1 << GPIO_LEFT)};

    gpio_config_t right_conf = {
        .intr_type = GPIO_INTR_POSEDGE,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .pin_bit_mask = (1 << GPIO_RIGHT)};

    gpio_config_t middle_conf = {
        .intr_type = GPIO_INTR_POSEDGE,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .pin_bit_mask = (1 << GPIO_MIDDLE)};

    gpio_config(&up_conf);
    gpio_config(&down_conf);
    gpio_config(&left_conf);
    gpio_config(&right_conf);
    gpio_config(&middle_conf);

    gpio_install_isr_service(0);

    gpio_set_intr_type(GPIO_UP, GPIO_INTR_POSEDGE);
    gpio_set_intr_type(GPIO_DOWN, GPIO_INTR_POSEDGE);
    gpio_set_intr_type(GPIO_LEFT, GPIO_INTR_POSEDGE);
    gpio_set_intr_type(GPIO_RIGHT, GPIO_INTR_POSEDGE);
    gpio_set_intr_type(GPIO_MIDDLE, GPIO_INTR_POSEDGE);

    gpio_isr_handler_add(GPIO_UP, gpio_change_program_isr_handler, (void*)(&show_ReferenceScreen));
    gpio_isr_handler_add(GPIO_DOWN, gpio_change_program_isr_handler, (void*)(&play_Demo));
    gpio_isr_handler_add(GPIO_LEFT, gpio_change_program_isr_handler, (void*)(&sensor_Demo));
    gpio_isr_handler_add(GPIO_RIGHT, gpio_change_program_isr_handler, (void*)(&anim_Demo));
    gpio_isr_handler_add(GPIO_MIDDLE, gpio_change_program_isr_handler, (void*)(&drawHelp));
}

void anim_Demo(){
    einkD_Init(EINK_PARTIAL_UPDATE);
    einkD_Clear();
    vTaskDelay(50);

    int posX = 39;
    int posY = 0;

    int dirX = 10;
    int dirY = 10;

    while(function == &anim_Demo){
        einkD_Draw_Filled_Rectangle(0,0,199,199,EINK_WHITE); //clean display

        einkD_Draw_Filled_Rectangle(posX, posY, posX+10, posY+10, EINK_BLACK);

        if((posX+11) >= EINK_WIDTH) dirX = -10;
        else if(posX <= 0) dirX = 10;

        if((posY+11) >= EINK_HEIGHT) dirY = -10;
        else if(posY <= 0) dirY = 10;

        posX += dirX;
        posY += dirY;        

        einkD_Refresh();
        vTaskDelay(100);
    }
}

float getRandomFloat(float from, float to){
    if(to <= from) return -1.0;
    uint32_t randomNum = esp_random();
    return from + (((float)randomNum/(float)UINT32_MAX)*(to - from));
}

void sensor_Demo(){
    einkD_Init(EINK_FULL_UPDATE);
    einkD_Clear();
    vTaskDelay(50);

    float outdTemp, indTemp;

    char tmp[10];

    while(function == &sensor_Demo){
        outdTemp = getRandomFloat(14, 33);
        indTemp = getRandomFloat(18, 26);

        einkD_Set_Text_Cursor(0,0);
        einkD_PrintLn("Venkovni", 18, EINK_BLACK);
        einkD_PrintLn("teplota:", 18, EINK_BLACK);

        sprintf(tmp, "%.2f", outdTemp);
        einkD_PrintLn(tmp, 18, EINK_BLACK);

        einkD_PrintLn("Vnitrni", 18, EINK_BLACK);
        einkD_PrintLn("teplota:", 18, EINK_BLACK);
        
        sprintf(tmp, "%.2f", indTemp);
        einkD_PrintLn(tmp, 18, EINK_BLACK);

        einkD_Refresh();

        einkD_Sleep();
        vTaskDelay(1000);
        einkD_Init(EINK_FULL_UPDATE);
        einkD_Clear();
    }
    einkD_Sleep();
}

void play_Demo(){
    einkD_Demo();
    vTaskDelay(100);
    function = &drawHelp;
}

void show_ReferenceScreen(){
    einkD_Init(EINK_FULL_UPDATE);
    einkD_Clear();
    vTaskDelay(100);
    einkD_Set_Text_Cursor(0,0);
    einkD_PrintLn("Dobry den", 18, EINK_BLACK);
    einkD_PrintLn("Petr Novak", 18, EINK_BLACK);
    einkD_PrintLn("Telefon", 14, EINK_BLACK);
    einkD_PrintLn("987 654 321", 14, EINK_BLACK);
    einkD_PrintLn("Uredni hodiny", 14, EINK_BLACK);
    einkD_PrintLn("Po-St 6:00-12:00", 10, EINK_BLACK);
    einkD_PrintLn("Ct-Pa 13:00-14:00", 10, EINK_BLACK);

    uint8_t qrCode[72] = {
        0b11111111, 0b11111111, 0b11111111,
        0b11111111, 0b11111111, 0b11111111,
        0b11000000, 0b01111101, 0b00000001,
        0b11011111, 0b01110101, 0b01111101,
        0b11010001, 0b01110001, 0b01000101,
        0b11010001, 0b01010101, 0b01000101,
        0b11010001, 0b01001101, 0b01000101,
        0b11011111, 0b01101011, 0b01111101,
        0b11000000, 0b01010101, 0b00000001,
        0b11111111, 0b11111111, 0b11111111,
        0b11001110, 0b00111011, 0b11001111,
        0b11101100, 0b11010001, 0b01100111,
        0b11001011, 0b01011101, 0b10110011,
        0b11100010, 0b10101000, 0b10100101,
        0b11110100, 0b01100001, 0b01111011,
        0b11111111, 0b11011100, 0b11010011,
        0b11000000, 0b01010011, 0b01111011,
        0b11011111, 0b01010110, 0b00000011,
        0b11010001, 0b01100011, 0b00011101,
        0b11010001, 0b01110101, 0b11010111,
        0b11010001, 0b01110001, 0b01010001,
        0b11011111, 0b01001010, 0b11000111,
        0b11000000, 0b01000100, 0b01101011,
        0b11111111, 0b11111111, 0b11111111
    };
    einkD_Draw_Bitmap(qrCode, 24, 24, 0, 120, 80, 80);

    einkD_Refresh();

    einkD_Sleep();

    while(function == &show_ReferenceScreen) vTaskDelay(50);
}

void drawHelp(){
    einkD_Init(EINK_FULL_UPDATE);
    einkD_Clear();
    einkD_Clear();
    vTaskDelay(100);

    einkD_Set_Text_Cursor(0,0);
    einkD_PrintLn("Referencni obrazovka", 10, EINK_BLACK);

    einkD_Set_Text_Cursor(80,94);
    einkD_PrintLn("Help", 10, EINK_BLACK);

    einkD_Set_Text_Cursor(0,110);
    einkD_PrintLn("Demo", 10, EINK_BLACK);
    einkD_PrintLn("Sensor", 10, EINK_BLACK);

    einkD_Set_Text_Cursor(159,110);
    einkD_PrintLn("Demo", 10, EINK_BLACK);
    einkD_Set_Text_Cursor(129,122);
    einkD_PrintLn("Animace", 10, EINK_BLACK);

    einkD_Set_Text_Cursor(60,187);
    einkD_PrintLn("Demo eInk", 10, EINK_BLACK);

    einkD_Draw_Circle(100, 100, 30, EINK_BLACK);

    //uparrow
    einkD_Draw_Filled_Triangle(100, 20, 95, 35, 105, 35, EINK_BLACK);
    einkD_Draw_Line(100, 20, 100, 70, EINK_BLACK);
    //down arrow
    einkD_Draw_Filled_Triangle(100, 179, 95, 164, 105, 164, EINK_BLACK);
    einkD_Draw_Line(100, 130, 100, 179, EINK_BLACK);
    //left arrow
    einkD_Draw_Filled_Triangle(20, 100, 35, 95, 35, 105, EINK_BLACK);
    einkD_Draw_Line(20, 100, 70, 100, EINK_BLACK);
    //right arrow
    einkD_Draw_Filled_Triangle(179, 100, 164, 95, 164, 105, EINK_BLACK);
    einkD_Draw_Line(130, 100, 179, 100,EINK_BLACK);


    einkD_Refresh();

    einkD_Sleep();

    while(function == &drawHelp) vTaskDelay(50);
}