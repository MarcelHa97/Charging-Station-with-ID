/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			chargingControl.c
* PROJECT:		Charging station with ID
* MODULE:		Control of the charging unit
*
* Description:  This file include all functions to initialize, set and reset the output to start/stop the
*				charging process of the car. It also includes control unit to check the plug connection,
*				if a car is connected to the charging station or not.
*
*
* Notes:		After initialization of the charging control unit, it is possible to set the output for
*				charging a car with setOutput-function. If the output is staid to output can reseted by
*				the resetOutput-function. To check if a car is connected to the charging station, it can
*				used the checkPlug-function, the function return a bool value.
*
* Compiler dependencies or special instructions: none
*
* REVISION HISTORY
*
*****************************************************************************/

#include "chargingConrol.h"

/***********************************************************************************/

void vCtrInitChargingControl(){
	DDRD |= (1<<OUTPUT_PLUG_DDRD);
	DDRD &= ~(1<<CHECK_PLUG_DDRD);
	PORTD &= ~(1<<OUTPUT_PLUG_DDRD);
}

/***********************************************************************************/

void vCtrSetOutput(){
	PORTD |= (1<<OUTPUT_PLUG_DDRD);
}

/***********************************************************************************/

void vCtrResetOutput(){
	PORTD &= ~(1<<OUTPUT_PLUG_DDRD);
}

/***********************************************************************************/

bool bCtrCheckPlug(){
	if(!(PIND & (1<<CHECK_PLUG_DDRD))){
		return true;
	} else {
		return false;
	}
}

/***********************************************************************************/