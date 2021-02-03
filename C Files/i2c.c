/*****************************************************************************
* 1. Copyright 2020, Author: Ulrich
*
* Source: https://www.ulrichradig.de/home/index.php/avr/lcd-am-pcf8574 
*
* FILE:			i2c.c
* PROJECT:		Charging station with ID
* MODULE:		Two wire interface (TWI)
*
* Description:  This file include all function to assemble a connection over the
*				two wire interface of the microcontroller. It also include functions
*				to start and stop a conversation between the master and the slaves.
*				It also include functions to send data (one byte) and read data with nak.
*
* Notes:		After initialization of the TWI by calling the i2cInit-function the has to be
*				send by the i2cStart-function with the address of the slave. If the start condition
*				has been sent, now it can be read a data byte from the salve by the the i2cReadNack-function
*				or it can be sent a data byte from the master to the slave by i2cByte-function.
*				After reading or writing of a data byte, it has to be sent a stop instruction.
*
*
* Compiler dependencies or special instructions: none
*
* REVISION HISTORY
*
*****************************************************************************/

#include "i2c.h"

//***************************************************************************************
void i2c_init(void){
	I2C_PORT |= (1 << SDA_PIN | 1 << SCL_PIN);			
	TWCR0 = 0;
	TWSR0 = 0;
	TWBR0 = ((F_CPU/SCL_CLOCK)-16)/2;
	_delay_ms(50);
}



//***************************************************************************************
uint8_t i2c_start (uint8_t addr){
	uint16_t timeout = 0;

    TWCR0 = (1 << TWINT | 1 << TWSTA | 1 << TWEN);
    while(!(TWCR0 & (1<<TWINT))){
	    if((timeout++) > 1000) return 1;
	}
    TWDR0 = addr;
    TWCR0 = (1 << TWINT | 1 << TWEN);
	timeout = 0;
    while(!(TWCR0 & (1<<TWINT))){
	    if((timeout++) > 1000) return 1;
    }
	return 0;
}

//***************************************************************************************
uint8_t i2c_byte (uint8_t byte){  
	uint16_t timeout = 0;
    TWDR0 = byte;
    TWCR0 = (1 << TWINT | 1 << TWEN);
    while(!(TWCR0 & (1<<TWINT))){
		if((timeout++) > 1000) return 1;
	}
	return 0;
}

//***************************************************************************************
uint8_t i2c_readNak(void)
{
	uint16_t timeout = 0;
	TWCR0 = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR0 & (1<<TWINT))){
		if((timeout++) > 1000) return 0;
	}
    return TWDR0;
}

//***************************************************************************************
void i2c_stop (void){
    TWCR0 = (1 << TWINT | 1 << TWSTO | 1 << TWEN);
	TWCR0 = 0;
}
