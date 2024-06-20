/**
 * @file espi.h
 * @author Jan Tomček (xtomec09@stud.fit.vutbr.cz)
 * @brief Header file for SPI comunication
 * @version 0.1
 * @date 01.05.2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#ifndef __SPI_H_EINK__
#define __SPI_H_EINK__

#include <stdint.h>
#include <stddef.h>


#define SENDER_HOST VSPI_HOST
#define DMA_CHAN 2

void SPI_Init();
void SPI_Send_Byte(uint8_t byte);
void SPI_Finish();

#endif //__SPI_H_EINK__