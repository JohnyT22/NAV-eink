/**
 * @file edisplay.h
 * @author Jan Tomček (xtomec09@stud.fit.vutbr.cz)
 * @brief Header file for SPI comunication
 * @version 0.1
 * @date 01.05.2023
 *
 *
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef __E_INK_DISPLAY_H__
#define __E_INK_DISPLAY_H__

#include <stdint.h>

/*
GND	    GND	Ground
SCLK    P13	SPI CLK pin, clock signal input
DIN	    P14	SPI MOSI pin, data input
CS	    P15	Chip selection, low active
BUSY	P25	Busy status output pin (means busy)
RST	    P26	Reset, low active
DC	    P27	Data/command, low for commands, high for data
*/

#define EINK_SCLK_PIN (18)
#define EINK_MOSI_PIN (23)
#define EINK_CS_PIN (5)    // low active
#define EINK_BUSY_PIN (13) // output pin (means busy)
#define EINK_RST_PIN (12)  // low active
#define EINK_DC_PIN (14)   // low for commands, high for data

#define EINK_HEIGHT 200
#define EINK_WIDTH 200

/**
 * @brief Enum for update type for the display - Full/Partial
 * 
 */
typedef enum
{
    EINK_FULL_UPDATE,
    EINK_PARTIAL_UPDATE
} eink_update_t;

/**
 * @brief Data structure for image buffer
 * 
 */
typedef struct _image
{
    int size;
    uint8_t *data;
} eink_image_t;

void einkD_Init(eink_update_t updateType);
void einkD_Refresh();
void einkD_Clear();
void einkD_Sleep();
eink_image_t *einkD_GetImgPointer();

#endif //__E_INK_DISPLAY_H__