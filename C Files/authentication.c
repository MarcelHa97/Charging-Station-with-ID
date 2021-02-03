/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			authentication.c
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

#include "authentication.h"

void vAuthinitAuthentication(){
	//Initialization of the pins, the spi-bus and the RFID reader 
	spi_init();
	mfrc522_init();
	DDRD |= (1<<DDRD4);
	DDRD |= (1<<DDRD5);
	PORTD &= ~(1<<LED_GREEN);
	PORTD &= ~(1<<LED_RED);
}

uint8_t iAuthReadRFIDCard(bool *b_Status){ //Get the status as an address 
	uint8_t i_Card_Found = 0;
	uint8_t i_Card_Value = 0;
	char c_Str [20];
	
	while(*b_Status){					//Executed the loop as loop as the status is true
		i_Card_Found = mfrc522_request(PICC_REQALL,c_Str);
		
		if(i_Card_Found == CARD_FOUND){
			if(i_Card_Found == CARD_FOUND)
			{
				i_Card_Found = mfrc522_get_card_serial(&i_Card_Value);	//If the card was found the value of the card will store in the varible i_Card_Value
				return i_Card_Value;
				} else {
				return ERROR_CARD_NOT_FOUND;							//If no card was found it will return an error code
			}
		}
	}
}


bool bAuthCompromiseCardDatabase(uint8_t *i_Card_Number_Database, bool *b_Status){	//Get the Database and the address of the status
	uint8_t i_Card_Value;
	i_Card_Value = iAuthReadRFIDCard(b_Status);	//Call the function to search a card and store it in a variable 
	uint8_t i_loop = 0;
	
	if(i_Card_Value != ERROR_CARD_NOT_FOUND && i_Card_Value != 0){
		if(i_Card_Number_Database != 0){
			while((i_loop < 10) && *b_Status){						//It will need an array with 10 elements, any other array with more or less elements will not work
				if(i_Card_Number_Database[i_loop] == i_Card_Value){	//The value of the card will compare with the database values, if an correct value was found 
					return true;									//it returns true otherwise it returns false
				}
				i_loop++;
			}
			return false;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

void vAuthsetLED(bool b_Status, bool *b_Status2){ //Get the status of the comparing process and the address of the status
	if(b_Status && *b_Status2){
		PORTD |= (1<<LED_GREEN);
		_delay_ms(2000);
		PORTD &= ~(1<<LED_GREEN);
	} else if(*b_Status2) {
		PORTD |= (1<<LED_RED);
		_delay_ms(2000);
		PORTD &= ~(1<<LED_RED);
	}
}


