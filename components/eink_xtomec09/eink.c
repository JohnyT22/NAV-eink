/**
 * @file eink.c
 * @author Jan Tomček (xtomec09@stud.fit.vutbr.cz)
 * @brief Module with function that demostrates basic library functions
 * @version 0.1
 * @date 01.05.2023
 *
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "eink.h"

/**
 * @brief Function demonstrating basic library functions
 *
 */
void einkD_Demo()
{
    einkD_Init(EINK_PARTIAL_UPDATE);
    einkD_Clear();

    vTaskDelay(100);

    einkD_Draw_Line(0, 0, EINK_WIDTH - 1, EINK_HEIGHT - 1, EINK_BLACK);
    einkD_Draw_Line(0, EINK_HEIGHT - 1, EINK_WIDTH - 1, 0, EINK_BLACK);
    einkD_Draw_Line(100, 0, EINK_WIDTH - 1, 100, EINK_BLACK);
    einkD_Draw_Line(EINK_WIDTH - 1, 100, 100, EINK_HEIGHT - 1, EINK_BLACK);
    einkD_Draw_Line(100, EINK_HEIGHT - 1, 0, 100, EINK_BLACK);
    einkD_Draw_Line(0, 100, 100, 0, EINK_BLACK);

    einkD_Draw_Circle(100, 100, 50, EINK_BLACK);
    einkD_Draw_Filled_Circle(100, 100, 15, EINK_BLACK);

    einkD_Draw_Rectangle(50, 50, 150, 150, EINK_BLACK);
    einkD_Draw_Filled_Rectangle(150, 150, 199, 199, EINK_BLACK);

    einkD_Draw_Filled_Triangle(0, 150, 50, 199, 50, 150, EINK_BLACK);
    einkD_Draw_Filled_Triangle(0, 50, 50, 50, 50, 0, EINK_BLACK);
    einkD_Draw_Triangle(150, 0, 150, 50, 199, 50, EINK_BLACK);

    einkD_Refresh();

    vTaskDelay(300);

    einkD_Clear();

    uint8_t bitmap[8] = {0b11101111, 0b11000111, 0b10000011, 0b00000001, 0b00000001, 0b10000011, 0b11000111, 0b11101111};
    einkD_Draw_Bitmap(bitmap, 8, 8, 0, 0, 100, 100);
    einkD_Draw_Bitmap(bitmap, 8, 8, 100, 100, 100, 100);

    einkD_Set_Text_Cursor(100, 0);
    einkD_PrintLn("Test", 8, EINK_BLACK);

    einkD_Set_Text_Cursor(100, 8);
    einkD_PrintLn("Test", 16, EINK_BLACK);

    einkD_Set_Text_Cursor(100, 24);
    einkD_PrintLn("Test", 25, EINK_BLACK);

    einkD_Set_Text_Cursor(0, 100);
    einkD_Print("Te", 20, EINK_WHITE);
    einkD_PrintLn("st", 20, EINK_WHITE);
    einkD_PrintLn(".,*:>< -", 12, EINK_WHITE);

    einkD_Refresh();

    einkD_Sleep();
}
