/*****************************************************************************
* 1. Copyright 2020, Author: Ulrich
*
* Source: https://www.ulrichradig.de/home/index.php/avr/lcd-am-pcf8574
*
* FILE:			i2c.h
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


#ifndef I2C_H_
	
#define I2C_H_

//Define clock speed of the CPU
#define F_CPU 16000000		

//Include the necessary libraries
#include <avr/io.h>
#include <util/delay.h>
#include <compat/twi.h>
	
//Definition of the output pins for the TWI
#define SDA_PIN			PC4
#define SCL_PIN			PC5 
#define I2C_PORT		PORTC 
#define SCL_CLOCK		100000UL
	
/** functions **/

/**************************************************************************
* NAME:			void i2c_init(void)
* Description:	Initialize the TWI
*
* Subroutines Called:	none
*
* Returns: none
*
* Globals: none
*
* Designer(s):
* Design Document:
*
* Tested By: Marcel Hammerl
* Date: 25.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
*
**************************************************************************/
void i2c_init(void);
	
/**************************************************************************
* NAME:			uint8_t i2c_start (uint8_t);
* Description:	Function to send a start instruction with the address of the 
*				slave.
*
* Subroutines Called:	none
*
* Returns: uint8_t
*
* Globals: none
*
* Designer(s):
* Design Document:
*
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 25.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
*
**************************************************************************/	
uint8_t i2c_start (uint8_t);

/**************************************************************************
* NAME:			uint8_t i2c_byte (uint8_t)
* Description:	Sends a data byte to the slave
*
* Subroutines Called:	none
*
* Returns: uint8_t
*
* Globals: none
*
* Designer(s):
* Design Document:
*
* Tested By: Marcel Hammerl
* Date: 25.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
*
**************************************************************************/
uint8_t i2c_byte (uint8_t);  

/**************************************************************************
* NAME:			uint8_t i2c_readNak(void)
* Description:	Reads a data byte with nak
*
* Subroutines Called:	none
*
* Returns: uint8_t
*
* Globals: none
*
* Designer(s):
* Design Document:
*
* Tested By: Marcel Hammerl
* Date: 25.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
*
**************************************************************************/
uint8_t i2c_readNak(void);

/**************************************************************************
* NAME:			void i2c_stop (void)
* Description:	Sends a stop instruction to finish the transvering process 
*
* Subroutines Called:	none
*
* Returns: none
*
* Globals: none
*
* Designer(s):
* Design Document:
*
* Tested By: Marcel Hammerl
* Date: 25.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
*
**************************************************************************/
void i2c_stop (void);

#endif /* I2C_H_ */