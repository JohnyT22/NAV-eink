/**
 * @file egraphics.c
 * @author Jan Tomček (xtomec09@stud.fit.vutbr.cz)
 * @brief Module implementing standard grafical functions
 * @version 0.1
 * @date 01.05.2023
 *
 * All functions write to image buffer declared in edisplay module
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stddef.h>

#include "eink.h"
#include "efont.h"

/**
 * @brief Macro for absolute value of x
 *
 */
#define abs(x) ((x < 0) ? -x : x)

/**
 * @brief Pointer to image buffer
 *
 */
static eink_image_t *_eink_frame = NULL;

/**
 * @brief X position for text cursor
 *
 */
static int cursor_posX = 0;

/**
 * @brief Y position for text cursor
 *
 */
static int cursor_posY = 0;

/**
 * @brief Inicialization of module, gets the image buffer pointer
 *
 * Called from einkD_Init(eink_update_t updateType)
 */
void _egraphics_init()
{
    _eink_frame = einkD_GetImgPointer();
}

/**
 * @brief Sets the pixel in the image buffer to specific color
 *
 * @param x x coordinate of pixel
 * @param y y coordinate of pixel
 * @param color color of pixel
 */
void einkD_Set_Pixel(int x, int y, uint8_t color)
{
    if (x < 0 || x >= EINK_WIDTH || y < 0 || y >= EINK_HEIGHT || color > 1)
        return;
    int index = (y * EINK_WIDTH + x) / 8;
    int pos = 7 - ((y * EINK_WIDTH + x) % 8);

    uint8_t mask = (1 << pos);

    _eink_frame->data[index] = (_eink_frame->data[index] & ~mask) | (color << pos);
}

/**
 * @brief Helping function for drawing line to the image buffer
 *
 * source: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 *
 * @param x1 x position of start of line
 * @param y1 y position of start of line
 * @param x2 x position of end of line
 * @param y2 y position of end of line
 * @param color color of line
 */
void _Draw_Line(int x1, int y1, int x2, int y2, uint8_t color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int yi = 1;

    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }

    int D = (2 * dy) - dx;
    int y = y1;

    for (int x = x1; x <= x2; x++)
    {
        einkD_Set_Pixel(x, y, color);
        if (D > 0)
        {
            y = y + yi;
            D += 2 * (dy - dx);
        }
        else
            D += 2 * dy;
    }
}

/**
 * @brief Helping function for drawing line to the image buffer
 *
 * source: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 *
 * @param x1 x position of start of line
 * @param y1 y position of start of line
 * @param x2 x position of end of line
 * @param y2 y position of end of line
 * @param color color of line
 */
void _Draw_Line_Steep(int x1, int y1, int x2, int y2, uint8_t color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int xi = 1;

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }

    int D = (2 * dx) - dy;
    int x = x1;

    for (int y = y1; y <= y2; y++)
    {
        einkD_Set_Pixel(x, y, color);
        if (D > 0)
        {
            x = x + xi;
            D += 2 * (dx - dy);
        }
        else
            D += 2 * dx;
    }
}

/**
 * @brief Draws line to the image buffer
 *
 * source: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 *
 * @param x1 x position of start of line
 * @param y1 y position of start of line
 * @param x2 x position of end of line
 * @param y2 y position of end of line
 * @param color color of line
 */
void einkD_Draw_Line(int x1, int y1, int x2, int y2, uint8_t color)
{
    if (color > 1)
        return;
    if (abs(y2 - y1) < abs(x2 - x1))
    {
        if (x1 > x2)
            _Draw_Line(x2, y2, x1, y1, color);
        else
            _Draw_Line(x1, y1, x2, y2, color);
    }
    else
    {
        if (y1 > y2)
            _Draw_Line_Steep(x2, y2, x1, y1, color);
        else
            _Draw_Line_Steep(x1, y1, x2, y2, color);
    }
}

/**
 * @brief Helping function for circle rasterization
 *
 * source: https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
 *
 * @param xc x coordinate of center point
 * @param yc y coordinate of center point
 * @param x x offset
 * @param y y offset
 * @param color color of circle
 */
void _drawCircle(int xc, int yc, int x, int y, uint8_t color)
{
    if (color > 1)
        return;
    einkD_Set_Pixel(xc + x, yc + y, color);
    einkD_Set_Pixel(xc - x, yc + y, color);
    einkD_Set_Pixel(xc + x, yc - y, color);
    einkD_Set_Pixel(xc - x, yc - y, color);
    einkD_Set_Pixel(xc + y, yc + x, color);
    einkD_Set_Pixel(xc - y, yc + x, color);
    einkD_Set_Pixel(xc + y, yc - x, color);
    einkD_Set_Pixel(xc - y, yc - x, color);
}

/**
 * @brief Draws circle to the image buffer
 *
 * source: https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
 *
 * @param xc x coordinate of center point
 * @param yc y coordinate of center point
 * @param r circle radius
 * @param color color of circle
 */
void einkD_Draw_Circle(int xc, int yc, unsigned r, uint8_t color)
{
    if (color > 1)
        return;
    int x = 0, y = r;
    int d = 3 - 2 * r;
    _drawCircle(xc, yc, x, y, color);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        _drawCircle(xc, yc, x, y, color);
    }
}

/**
 * @brief Helping function for drawing filled circle
 *
 * @param xc x coordinate of center point
 * @param yc y coordinate of center point
 * @param x x offset
 * @param y y offset
 * @param color color of filled circle
 */
void _drawCircleFilled(int xc, int yc, int x, int y, uint8_t color)
{
    if (color > 1)
        return;
    einkD_Draw_Line(xc - x, yc + y, xc + x, yc + y, color);
    einkD_Draw_Line(xc - x, yc - y, xc + x, yc - y, color);
    einkD_Draw_Line(xc - y, yc + x, xc + y, yc + x, color);
    einkD_Draw_Line(xc - y, yc - x, xc + y, yc - x, color);
}

/**
 * @brief Draws filled circle to the image buffer
 *
 * source: https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
 *
 * @param xc x coordinate of center point
 * @param yc y coordinate of center point
 * @param r circle radius
 * @param color color of circle
 */
void einkD_Draw_Filled_Circle(int xc, int yc, unsigned r, uint8_t color)
{
    if (color > 1)
        return;
    int x = 0, y = r;
    int d = 3 - 2 * r;
    _drawCircle(xc, yc, x, y, color);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        _drawCircleFilled(xc, yc, x, y, color);
    }
    einkD_Draw_Line(xc - r, yc, xc + r, yc, color);
}

/**
 * @brief Draws rectangle to image buffer
 *
 * @param x1 x coordinate of starting point
 * @param y1 y coordinate of starting point
 * @param x2 x coordinate of end point
 * @param y2 y coordinate of end point
 * @param color color of rectangle
 */
void einkD_Draw_Rectangle(int x1, int y1, int x2, int y2, uint8_t color)
{
    if (color > 1)
        return;
    einkD_Draw_Line(x1, y1, x2, y1, color);
    einkD_Draw_Line(x1, y2, x2, y2, color);
    einkD_Draw_Line(x1, y1, x1, y2, color);
    einkD_Draw_Line(x2, y1, x2, y2, color);
}

/**
 * @brief Draws filled rectangle to the image buffer
 *
 * @param x1 x coordinate of starting point
 * @param y1 y coordinate of starting point
 * @param x2 x coordinate of end point
 * @param y2 y coordinate of end point
 * @param color color of rectangle
 */
void einkD_Draw_Filled_Rectangle(int x1, int y1, int x2, int y2, uint8_t color)
{
    if (color > 1)
        return;
    for (int y = y1; y < y2; y++)
    {
        for (int x = x1; x < x2; x++)
        {
            einkD_Set_Pixel(x, y, color);
        }
    }
}

/**
 * @brief Draws triangle to the image buffer
 *
 * @param ax x coordinate of first point
 * @param ay y coordinate of first point
 * @param bx x coordinate of second point
 * @param by y coordinate of second point
 * @param cx x coordinate of third point
 * @param cy y coordinate of third point
 * @param color color of triangle
 */
void einkD_Draw_Triangle(int ax, int ay, int bx, int by, int cx, int cy, uint8_t color)
{
    if (color > 1)
        return;
    einkD_Draw_Line(ax, ay, bx, by, color);
    einkD_Draw_Line(ax, ay, cx, cy, color);
    einkD_Draw_Line(bx, by, cx, cy, color);
}

/**
 * @brief Macro for geting minimum of x and y
 *
 */
#define min(x, y) ((x) < (y) ? (x) : (y))

/**
 * @brief Macro for geting maximum of x and y
 *
 */
#define max(x, y) ((x) > (y) ? (x) : (y))

/**
 * @brief Macro for calculating edge function
 *
 */
#define edgeFunction(ax, ay, bx, by, cx, cy) ((float)((cx - ax) * (by - ay) - (cy - ay) * (bx - ax)))

/**
 * @brief Draws filled triangle to the image buffer
 *
 * source: https://www.scratchapixel.com/lessons/3d-basic-rendering/rasterization-practical-implementation/rasterization-stage.html
 *
 * @param ax x coordinate of first point
 * @param ay y coordinate of first point
 * @param bx x coordinate of second point
 * @param by y coordinate of second point
 * @param cx x coordinate of third point
 * @param cy y coordinate of third point
 * @param color color of triangle
 */
void einkD_Draw_Filled_Triangle(int ax, int ay, int bx, int by, int cx, int cy, uint8_t color)
{
    if (color > 1)
        return;
    int bound_beg_x = min(ax, min(bx, cx));
    int bound_beg_y = min(ay, min(by, cy));
    int bound_end_x = max(ax, max(bx, cx));
    int bound_end_y = max(ay, max(by, cy));

    float area = edgeFunction(ax, ay, bx, by, cx, cy);

    if (area < 0)
    {
        int tmpx = bx;
        int tmpy = by;
        bx = cx;
        by = cy;
        cx = tmpx;
        cy = tmpy;
        area = edgeFunction(ax, ay, bx, by, cx, cy);
    }

    for (int j = bound_beg_y; j < bound_end_y; j++)
    {
        for (int i = bound_beg_x; i < bound_end_x; i++)
        {
            float px = i + 0.5f;
            float py = j + 0.5f;

            float w0 = edgeFunction(bx, by, cx, cy, px, py);
            float w1 = edgeFunction(cx, cy, ax, ay, px, py);
            float w2 = edgeFunction(ax, ay, bx, by, px, py);
            if (w0 >= 0 && w1 >= 0 && w2 >= 0)
            {
                w0 /= area;
                w1 /= area;
                w2 /= area;
                einkD_Set_Pixel(i, j, color);
            }
        }
    }
}

/**
 * @brief Draws the bitmap to the image buffer
 *
 * The bitmap in also being upscaled/downscaled based on the
 * finalresolution and the resolution of the bitmap
 *
 * @param bitmap pointer to the bitmap
 * @param mapWidth bitmap width
 * @param mapHeight bitmap height
 * @param posX x position of the bitmap in the image buffer
 * @param posY y position of the bitmap in the image buffer
 * @param finalWidth width of the bitmap in the image buffer
 * @param finalHeight height of the bitmap in the image buffer
 */
void einkD_Draw_Bitmap(uint8_t *bitmap, unsigned mapWidth, unsigned mapHeight, int posX, int posY, unsigned finalWidth, unsigned finalHeight)
{
    if (bitmap == NULL || posX >= EINK_WIDTH || posY >= EINK_HEIGHT || (posX + finalWidth) > EINK_WIDTH || (posY + finalHeight) > EINK_HEIGHT)
        return;

    float bitmapStepX = ((float)mapWidth) / ((float)finalWidth);
    float bitmapStepY = ((float)mapHeight) / ((float)finalHeight);

    float uoffset = 0.0, voffset = 0.0;
    int u, v;

    for (int j = 0; j < finalHeight; j++)
    {
        v = (int)voffset;
        for (int i = 0; i < finalWidth; i++)
        {
            u = (int)uoffset;

            // get bitmap bit value on u v pos
            int mapIndex = (v * mapWidth + u) / 8;
            int pos = 7 - ((v * mapWidth + u) % 8);

            uint8_t mask = (1 << pos);
            uint8_t color = ((bitmap[mapIndex] & mask) >> pos);

            einkD_Set_Pixel(posX + i, posY + j, color);

            uoffset += bitmapStepX;
        }
        uoffset = 0.0;
        voffset += bitmapStepY;
    }
}

/**
 * @brief Sets the text cursor to given coordinates
 *
 * @param x x coordinate
 * @param y y coordinate
 */
void einkD_Set_Text_Cursor(unsigned x, unsigned y)
{
    if (x >= EINK_WIDTH || y >= EINK_HEIGHT)
        return;
    cursor_posX = x;
    cursor_posY = y;
}

/**
 * @brief Prints text to the image buffer
 *
 * @warning test has to end with '\0'
 *
 * @param str pointer to the string
 * @param font_size size of the font <8, 36>
 * @param color color of the text
 */
void einkD_Print(char *str, unsigned font_size, uint8_t color)
{
    if (font_size < 8 || font_size > 36 || color > 1)
        return;

    int padding = max(font_size*0.2, 1);
    int posYwPadding = cursor_posY + padding;

    uint8_t(*font)[8] = (color == EINK_BLACK) ? fontblack : fontwhite;

    // 500 je max pocet znaku, co se vejde na display
    // pri nejmensi velikosti fontu 8
    for (int i = 0; i < 500; i++)
    {
        if (str[i] == '\0')
            break;
        uint8_t c = str[i];
        if (c > 0x007F)
            continue;

        if ((cursor_posX + font_size) > EINK_WIDTH)
        {
            cursor_posX = 0;
            cursor_posY += font_size + padding;
        }
        if ((cursor_posY + font_size) > EINK_HEIGHT)
            break;

        einkD_Draw_Bitmap(font[c], 8, 8, cursor_posX, posYwPadding, font_size, font_size);
        cursor_posX += font_size;
    }
}

/**
 * @brief Prints text on separate line to the image buffer
 *
 * uses einkD_Print(char *str, unsigned font_size, uint8_t color)
 *
 * @warning test has to end with '\0'
 *
 * @param str pointer to the string
 * @param font_size size of the font <8, 36>
 * @param color color of the text
 */
void einkD_PrintLn(char *str, unsigned font_size, uint8_t color)
{
    einkD_Print(str, font_size, color);

    cursor_posX = 0;
    int padding = max(font_size*0.2, 1); 
    cursor_posY += font_size + padding;
}
