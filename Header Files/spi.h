/*
 * spi.h
 * Copyright 2013 Shimon <shimon@monistit.com>
 *
 * Source: https://github.com/asif-mahmud/MIFARE-RFID-with-AVR/blob/master/lib/avr-rfid-library/include/spi.h
 */
#ifndef SPI_H
#define SPI_H

#include "spi_config.h"
#include <stdint.h>

void spi_init();
uint8_t spi_transmit(uint8_t data);

#define ENABLE_CHIP() (SPI_PORT &= (~(1<<SPI_SS)))
#define DISABLE_CHIP() (SPI_PORT |= (1<<SPI_SS))


#endif
