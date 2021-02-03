/*
 * spi_config.h
 *Copyright 2013 Shimon <shimon@monistit.com>
 *
 * Source: https://github.com/asif-mahmud/MIFARE-RFID-with-AVR/blob/master/lib/avr-rfid-library/include/spi_config.h
 */
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#include <avr/io.h>

/*
 * Set to 1, spi api will work in master mode
 * else in slave mode
 */
#define SPI_CONFIG_AS_MASTER 	1


/*
 * Config SPI pin diagram
 */
#define SPI_DDR		DDRB
#define SPI_PORT	PORTB
#define SPI_PIN		PINB
#define SPI_MOSI	PB3
#define SPI_MISO	PB4
#define SPI_SS		PB2
#define SPI_SCK		PB5

#endif
