/*****************************************************************************
* Copyright 2020, All rights reserved, For internal use only
*
* FILE:			authentication.h
* PROJECT:		Charging station with ID
* MODULE:		Authentication unit
*
* Description:  This file include all functions to identify a charging station user by a RFID card.
*				The functions in this file load the valued card numbers from the database, read the
*				used card at the card reader from the user and compare the read card number with the
*				numbers from the database. If the controller find a the read card number in the 
*				database it returns a bool value in this case true. If it don't find the number in the
*				database the function return false.
*
*
* Notes:		After initialization of the authentication unit with the initAuthentication-function, 
*				it is possible to read and compare a card with the database, to do this it can used the 
*				function bCompareNumberDatabase. To show the result of the reading and comparing process, it
*				can uses the setLED-function. 
*
* Compiler dependencies or special instructions: none
*
* REVISION HISTORY
*
*****************************************************************************/


//Define clock speed of the CPU
#define F_CPU 16000000

//Include the necessary libraries
#include <stdbool.h>
#include "mfrc522.h"
#include "spi.h"
#include <avr/delay.h>


#ifndef AUTHENTICATION_H_
#define AUTHENTICATION_H_

//Definition of the different statues of the authentication unit
#define STATUS_AUTH_ACCEPTED	1					//Status information, if authentication was successful 
#define STATUS_AUTH_REJECT		0					//Status information, if authentication was not successful
#define ERROR_CARD_NOT_FOUND	101					//Error code "101", error if no card is found
#define ERROR_DATABASE			102					//Error code "102", error if the card numbers are not loaded form the database

//Definition of the output pins for the LEDs to show the status of the authentication
#define LED_RED					PORTD6
#define LED_GREEN				PORTD5

/** functions **/

/**************************************************************************
* NAME:			extern void aAuthinitAuthentication(void)
* Description:	Initialize the authentication unit
*
* Subroutines Called:	spi_init();
*						mfrc522_init()
*
* Returns: none
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
extern void vAuthinitAuthentication(void);

/**************************************************************************
* NAME:			extern uint8_t iAuthReadRFIDCard(bool *status);
* Description:	Starts a reading process and read the card number over the
*				RFID reader 
*
* Subroutines Called:	mfrc522_request()
*						mfrc522_get_card_serial()
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
extern uint8_t iAuthReadRFIDCard(bool *b_Status);

/**************************************************************************
* NAME:			extern bool bCompromiseCardDatabase(uint8_t *i_Card_Number_Database, bool *status)
* Description:	Read the card number over the RFID reader and compare the 
*				read card number with the stored card numbers in the database
*
* Subroutines Called:	iAuthReadRFIDCard();
*
* Returns: bool
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
extern bool bAuthCompromiseCardDatabase(uint8_t *i_Card_Number_Database, bool *b_Status);

/**************************************************************************
* NAME:			extern void vAuthsetLED(bool status, bool *status2)
* Description:	Show the result of the authentication process
*
* Subroutines Called: none
*
* Returns: none
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
extern void vAuthsetLED(bool status, bool *status2);

#endif /* AUTHENTICATION_H_ */