/**
 * @file efont.h
 * @author Jan Tomček (xtomec09@stud.fit.vutbr.cz)
 * @brief Header file containing font bitmaps, font is 8x8
 * @version 0.1
 * @date 01.05.2023
 *
 * Header file is taken and edited from:
 * https://github.com/dhepper/font8x8/blob/master/font8x8_basic.h
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Bitmap for black font
 *
 */
uint8_t fontblack[128][8] = {
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xE7, 0xC3, 0xC3, 0xE7, 0xE7, 0xFF, 0xE7, 0xFF},
    {0x93, 0x93, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0x93, 0x93, 0x01, 0x93, 0x01, 0x93, 0x93, 0xFF},
    {0xCF, 0x83, 0x3F, 0x87, 0xF3, 0x07, 0xCF, 0xFF},
    {0xFF, 0x39, 0x33, 0xE7, 0xCF, 0x99, 0x39, 0xFF},
    {0xC7, 0x93, 0xC7, 0x89, 0x23, 0x33, 0x89, 0xFF},
    {0x9F, 0x9F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xE7, 0xCF, 0x9F, 0x9F, 0x9F, 0xCF, 0xE7, 0xFF},
    {0x9F, 0xCF, 0xE7, 0xE7, 0xE7, 0xCF, 0x9F, 0xFF},
    {0xFF, 0x99, 0xC3, 0x00, 0xC3, 0x99, 0xFF, 0xFF},
    {0xFF, 0xCF, 0xCF, 0x03, 0xCF, 0xCF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xCF, 0x9F},
    {0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xCF, 0xFF},
    {0xF9, 0xF3, 0xE7, 0xCF, 0x9F, 0x3F, 0x7F, 0xFF},
    {0x83, 0x39, 0x31, 0x21, 0x09, 0x19, 0x83, 0xFF},
    {0xCF, 0x8F, 0xCF, 0xCF, 0xCF, 0xCF, 0x03, 0xFF},
    {0x87, 0x33, 0xF3, 0xC7, 0x9F, 0x33, 0x03, 0xFF},
    {0x87, 0x33, 0xF3, 0xC7, 0xF3, 0x33, 0x87, 0xFF},
    {0xE3, 0xC3, 0x93, 0x33, 0x01, 0xF3, 0xE1, 0xFF},
    {0x03, 0x3F, 0x07, 0xF3, 0xF3, 0x33, 0x87, 0xFF},
    {0xC7, 0x9F, 0x3F, 0x07, 0x33, 0x33, 0x87, 0xFF},
    {0x03, 0x33, 0xF3, 0xE7, 0xCF, 0xCF, 0xCF, 0xFF},
    {0x87, 0x33, 0x33, 0x87, 0x33, 0x33, 0x87, 0xFF},
    {0x87, 0x33, 0x33, 0x83, 0xF3, 0xE7, 0x8F, 0xFF},
    {0xFF, 0xCF, 0xCF, 0xFF, 0xFF, 0xCF, 0xCF, 0xFF},
    {0xFF, 0xCF, 0xCF, 0xFF, 0xFF, 0xCF, 0xCF, 0x9F},
    {0xE7, 0xCF, 0x9F, 0x3F, 0x9F, 0xCF, 0xE7, 0xFF},
    {0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0x03, 0xFF, 0xFF},
    {0x9F, 0xCF, 0xE7, 0xF3, 0xE7, 0xCF, 0x9F, 0xFF},
    {0x87, 0x33, 0xF3, 0xE7, 0xCF, 0xFF, 0xCF, 0xFF},
    {0x83, 0x39, 0x21, 0x21, 0x21, 0x3F, 0x87, 0xFF},
    {0xCF, 0x87, 0x33, 0x33, 0x03, 0x33, 0x33, 0xFF},
    {0x03, 0x99, 0x99, 0x83, 0x99, 0x99, 0x03, 0xFF},
    {0xC3, 0x99, 0x3F, 0x3F, 0x3F, 0x99, 0xC3, 0xFF},
    {0x07, 0x93, 0x99, 0x99, 0x99, 0x93, 0x07, 0xFF},
    {0x01, 0x9D, 0x97, 0x87, 0x97, 0x9D, 0x01, 0xFF},
    {0x01, 0x9D, 0x97, 0x87, 0x97, 0x9F, 0x0F, 0xFF},
    {0xC3, 0x99, 0x3F, 0x3F, 0x31, 0x99, 0xC1, 0xFF},
    {0x33, 0x33, 0x33, 0x03, 0x33, 0x33, 0x33, 0xFF},
    {0x87, 0xCF, 0xCF, 0xCF, 0xCF, 0xCF, 0x87, 0xFF},
    {0xE1, 0xF3, 0xF3, 0xF3, 0x33, 0x33, 0x87, 0xFF},
    {0x19, 0x99, 0x93, 0x87, 0x93, 0x99, 0x19, 0xFF},
    {0x0F, 0x9F, 0x9F, 0x9F, 0x9D, 0x99, 0x01, 0xFF},
    {0x39, 0x11, 0x01, 0x01, 0x29, 0x39, 0x39, 0xFF},
    {0x39, 0x19, 0x09, 0x21, 0x31, 0x39, 0x39, 0xFF},
    {0xC7, 0x93, 0x39, 0x39, 0x39, 0x93, 0xC7, 0xFF},
    {0x03, 0x99, 0x99, 0x83, 0x9F, 0x9F, 0x0F, 0xFF},
    {0x87, 0x33, 0x33, 0x33, 0x23, 0x87, 0xE3, 0xFF},
    {0x03, 0x99, 0x99, 0x83, 0x93, 0x99, 0x19, 0xFF},
    {0x87, 0x33, 0x1F, 0x8F, 0xE3, 0x33, 0x87, 0xFF},
    {0x03, 0x4B, 0xCF, 0xCF, 0xCF, 0xCF, 0x87, 0xFF},
    {0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x03, 0xFF},
    {0x33, 0x33, 0x33, 0x33, 0x33, 0x87, 0xCF, 0xFF},
    {0x39, 0x39, 0x39, 0x29, 0x01, 0x11, 0x39, 0xFF},
    {0x39, 0x39, 0x93, 0xC7, 0xC7, 0x93, 0x39, 0xFF},
    {0x33, 0x33, 0x33, 0x87, 0xCF, 0xCF, 0x87, 0xFF},
    {0x01, 0x39, 0x73, 0xE7, 0xCD, 0x99, 0x01, 0xFF},
    {0x87, 0x9F, 0x9F, 0x9F, 0x9F, 0x9F, 0x87, 0xFF},
    {0x3F, 0x9F, 0xCF, 0xE7, 0xF3, 0xF9, 0xFD, 0xFF},
    {0x87, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0x87, 0xFF},
    {0xEF, 0xC7, 0x93, 0x39, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00},
    {0xCF, 0xCF, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0x87, 0xF3, 0x83, 0x33, 0x89, 0xFF},
    {0x1F, 0x9F, 0x9F, 0x83, 0x99, 0x99, 0x23, 0xFF},
    {0xFF, 0xFF, 0x87, 0x33, 0x3F, 0x33, 0x87, 0xFF},
    {0xE3, 0xF3, 0xF3, 0x83, 0x33, 0x33, 0x89, 0xFF},
    {0xFF, 0xFF, 0x87, 0x33, 0x03, 0x3F, 0x87, 0xFF},
    {0xC7, 0x93, 0x9F, 0x0F, 0x9F, 0x9F, 0x0F, 0xFF},
    {0xFF, 0xFF, 0x89, 0x33, 0x33, 0x83, 0xF3, 0x07},
    {0x1F, 0x9F, 0x93, 0x89, 0x99, 0x99, 0x19, 0xFF},
    {0xCF, 0xFF, 0x8F, 0xCF, 0xCF, 0xCF, 0x87, 0xFF},
    {0xF3, 0xFF, 0xF3, 0xF3, 0xF3, 0x33, 0x33, 0x87},
    {0x1F, 0x9F, 0x99, 0x93, 0x87, 0x93, 0x19, 0xFF},
    {0x8F, 0xCF, 0xCF, 0xCF, 0xCF, 0xCF, 0x87, 0xFF},
    {0xFF, 0xFF, 0x33, 0x01, 0x01, 0x29, 0x39, 0xFF},
    {0xFF, 0xFF, 0x07, 0x33, 0x33, 0x33, 0x33, 0xFF},
    {0xFF, 0xFF, 0x87, 0x33, 0x33, 0x33, 0x87, 0xFF},
    {0xFF, 0xFF, 0x23, 0x99, 0x99, 0x83, 0x9F, 0x0F},
    {0xFF, 0xFF, 0x89, 0x33, 0x33, 0x83, 0xF3, 0xE1},
    {0xFF, 0xFF, 0x23, 0x89, 0x99, 0x9F, 0x0F, 0xFF},
    {0xFF, 0xFF, 0x83, 0x3F, 0x87, 0xF3, 0x07, 0xFF},
    {0xEF, 0xCF, 0x83, 0xCF, 0xCF, 0xCB, 0xE7, 0xFF},
    {0xFF, 0xFF, 0x33, 0x33, 0x33, 0x33, 0x89, 0xFF},
    {0xFF, 0xFF, 0x33, 0x33, 0x33, 0x87, 0xCF, 0xFF},
    {0xFF, 0xFF, 0x39, 0x29, 0x01, 0x01, 0x93, 0xFF},
    {0xFF, 0xFF, 0x39, 0x93, 0xC7, 0x93, 0x39, 0xFF},
    {0xFF, 0xFF, 0x33, 0x33, 0x33, 0x83, 0xF3, 0x07},
    {0xFF, 0xFF, 0x03, 0x67, 0xCF, 0x9B, 0x03, 0xFF},
    {0xE3, 0xCF, 0xCF, 0x1F, 0xCF, 0xCF, 0xE3, 0xFF},
    {0xE7, 0xE7, 0xE7, 0xFF, 0xE7, 0xE7, 0xE7, 0xFF},
    {0x1F, 0xCF, 0xCF, 0xE3, 0xCF, 0xCF, 0x1F, 0xFF},
    {0x89, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

/**
 * @brief Bitmap for white font
 *
 */
uint8_t fontwhite[128][8] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00},
    {0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x6C, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0x6C, 0x00},
    {0x30, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x30, 0x00},
    {0x00, 0xC6, 0xCC, 0x18, 0x30, 0x66, 0xC6, 0x00},
    {0x38, 0x6C, 0x38, 0x76, 0xDC, 0xCC, 0x76, 0x00},
    {0x60, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x18, 0x30, 0x60, 0x60, 0x60, 0x30, 0x18, 0x00},
    {0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00},
    {0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00},
    {0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60},
    {0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00},
    {0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x00},
    {0x7C, 0xC6, 0xCE, 0xDE, 0xF6, 0xE6, 0x7C, 0x00},
    {0x30, 0x70, 0x30, 0x30, 0x30, 0x30, 0xFC, 0x00},
    {0x78, 0xCC, 0x0C, 0x38, 0x60, 0xCC, 0xFC, 0x00},
    {0x78, 0xCC, 0x0C, 0x38, 0x0C, 0xCC, 0x78, 0x00},
    {0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0x0C, 0x1E, 0x00},
    {0xFC, 0xC0, 0xF8, 0x0C, 0x0C, 0xCC, 0x78, 0x00},
    {0x38, 0x60, 0xC0, 0xF8, 0xCC, 0xCC, 0x78, 0x00},
    {0xFC, 0xCC, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00},
    {0x78, 0xCC, 0xCC, 0x78, 0xCC, 0xCC, 0x78, 0x00},
    {0x78, 0xCC, 0xCC, 0x7C, 0x0C, 0x18, 0x70, 0x00},
    {0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00},
    {0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x60},
    {0x18, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x18, 0x00},
    {0x00, 0x00, 0xFC, 0x00, 0x00, 0xFC, 0x00, 0x00},
    {0x60, 0x30, 0x18, 0x0C, 0x18, 0x30, 0x60, 0x00},
    {0x78, 0xCC, 0x0C, 0x18, 0x30, 0x00, 0x30, 0x00},
    {0x7C, 0xC6, 0xDE, 0xDE, 0xDE, 0xC0, 0x78, 0x00},
    {0x30, 0x78, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0x00},
    {0xFC, 0x66, 0x66, 0x7C, 0x66, 0x66, 0xFC, 0x00},
    {0x3C, 0x66, 0xC0, 0xC0, 0xC0, 0x66, 0x3C, 0x00},
    {0xF8, 0x6C, 0x66, 0x66, 0x66, 0x6C, 0xF8, 0x00},
    {0xFE, 0x62, 0x68, 0x78, 0x68, 0x62, 0xFE, 0x00},
    {0xFE, 0x62, 0x68, 0x78, 0x68, 0x60, 0xF0, 0x00},
    {0x3C, 0x66, 0xC0, 0xC0, 0xCE, 0x66, 0x3E, 0x00},
    {0xCC, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0xCC, 0x00},
    {0x78, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00},
    {0x1E, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78, 0x00},
    {0xE6, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0xE6, 0x00},
    {0xF0, 0x60, 0x60, 0x60, 0x62, 0x66, 0xFE, 0x00},
    {0xC6, 0xEE, 0xFE, 0xFE, 0xD6, 0xC6, 0xC6, 0x00},
    {0xC6, 0xE6, 0xF6, 0xDE, 0xCE, 0xC6, 0xC6, 0x00},
    {0x38, 0x6C, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x00},
    {0xFC, 0x66, 0x66, 0x7C, 0x60, 0x60, 0xF0, 0x00},
    {0x78, 0xCC, 0xCC, 0xCC, 0xDC, 0x78, 0x1C, 0x00},
    {0xFC, 0x66, 0x66, 0x7C, 0x6C, 0x66, 0xE6, 0x00},
    {0x78, 0xCC, 0xE0, 0x70, 0x1C, 0xCC, 0x78, 0x00},
    {0xFC, 0xB4, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00},
    {0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFC, 0x00},
    {0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x00},
    {0xC6, 0xC6, 0xC6, 0xD6, 0xFE, 0xEE, 0xC6, 0x00},
    {0xC6, 0xC6, 0x6C, 0x38, 0x38, 0x6C, 0xC6, 0x00},
    {0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x30, 0x78, 0x00},
    {0xFE, 0xC6, 0x8C, 0x18, 0x32, 0x66, 0xFE, 0x00},
    {0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x78, 0x00},
    {0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02, 0x00},
    {0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00},
    {0x10, 0x38, 0x6C, 0xC6, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},
    {0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x78, 0x0C, 0x7C, 0xCC, 0x76, 0x00},
    {0xE0, 0x60, 0x60, 0x7C, 0x66, 0x66, 0xDC, 0x00},
    {0x00, 0x00, 0x78, 0xCC, 0xC0, 0xCC, 0x78, 0x00},
    {0x1C, 0x0C, 0x0C, 0x7C, 0xCC, 0xCC, 0x76, 0x00},
    {0x00, 0x00, 0x78, 0xCC, 0xFC, 0xC0, 0x78, 0x00},
    {0x38, 0x6C, 0x60, 0xF0, 0x60, 0x60, 0xF0, 0x00},
    {0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8},
    {0xE0, 0x60, 0x6C, 0x76, 0x66, 0x66, 0xE6, 0x00},
    {0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00},
    {0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78},
    {0xE0, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0xE6, 0x00},
    {0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00},
    {0x00, 0x00, 0xCC, 0xFE, 0xFE, 0xD6, 0xC6, 0x00},
    {0x00, 0x00, 0xF8, 0xCC, 0xCC, 0xCC, 0xCC, 0x00},
    {0x00, 0x00, 0x78, 0xCC, 0xCC, 0xCC, 0x78, 0x00},
    {0x00, 0x00, 0xDC, 0x66, 0x66, 0x7C, 0x60, 0xF0},
    {0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0x1E},
    {0x00, 0x00, 0xDC, 0x76, 0x66, 0x60, 0xF0, 0x00},
    {0x00, 0x00, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x00},
    {0x10, 0x30, 0x7C, 0x30, 0x30, 0x34, 0x18, 0x00},
    {0x00, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x00},
    {0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x00},
    {0x00, 0x00, 0xC6, 0xD6, 0xFE, 0xFE, 0x6C, 0x00},
    {0x00, 0x00, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x00},
    {0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8},
    {0x00, 0x00, 0xFC, 0x98, 0x30, 0x64, 0xFC, 0x00},
    {0x1C, 0x30, 0x30, 0xE0, 0x30, 0x30, 0x1C, 0x00},
    {0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00},
    {0xE0, 0x30, 0x30, 0x1C, 0x30, 0x30, 0xE0, 0x00},
    {0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
};