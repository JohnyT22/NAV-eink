/**
 * @file egraphics.h
 * @author Jan Tomček (xtomec09@stud.fit.vutbr.cz)
 * @brief Header file for graphical functions
 * @version 0.1
 * @date 01.05.2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef __E_INK_GRAPHICS_H__
#define __E_INK_GRAPHICS_H__

#include <stdint.h>

/**
 * @brief definition of the color white
 *
 */
#define EINK_WHITE (1)

/**
 * @brief definition of the color black
 *
 */
#define EINK_BLACK (0)

void einkD_Set_Pixel(int x, int y, uint8_t color);
void einkD_Draw_Line(int x1, int y1, int x2, int y2, uint8_t color);

void einkD_Draw_Circle(int xc, int yc, unsigned r, uint8_t color);
void einkD_Draw_Filled_Circle(int xc, int yc, unsigned r, uint8_t color);

void einkD_Draw_Rectangle(int x1, int y1, int x2, int y2, uint8_t color);
void einkD_Draw_Filled_Rectangle(int x1, int y1, int x2, int y2, uint8_t color);

void einkD_Draw_Triangle(int ax, int ay, int bx, int by, int cx, int cy, uint8_t color);
void einkD_Draw_Filled_Triangle(int ax, int ay, int bx, int by, int cx, int cy, uint8_t color);

void einkD_Draw_Bitmap(uint8_t *bitmap, unsigned mapWidth, unsigned mapHeight, int posX, int posY, unsigned finalWidth, unsigned finalHeight);

void einkD_Set_Text_Cursor(unsigned x, unsigned y);
void einkD_Print(char *str, unsigned font_size, uint8_t color);
void einkD_PrintLn(char *str, unsigned font_size, uint8_t color);

void _egraphics_init();

#endif //__E_INK_GRAPHICS_H__