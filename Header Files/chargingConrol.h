/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			chargingControl.h
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

//Include the necessary libraries
#include <avr/io.h>
#include <stdbool.h>

#ifndef CHARGINGCONROL_H_
#define CHARGINGCONROL_H_

//Definition of the output and input pin for the charging control unit
#define OUTPUT_PLUG_DDRD	DDRD7
#define OUTPUT_PLUG_PORTD	PORTD7
#define CHECK_PLUG_DDRD		DDRD2
#define CHECK_PLUG_PORTD	PIND2

/** functions **/

/**************************************************************************
* NAME:			extern void vCtrinitChargingControl(void)
* Description:	Initialize the charging control
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
extern void vCtrinitChargingControl(void);

/**************************************************************************
* NAME:			extern void vCtrsetOutput(void)
* Description:	Sets the output of the charging station
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
extern void vCtrSetOutput(void);

/**************************************************************************
* NAME:			extern void vCtrResetOutput(void)
* Description:	Resets the output of the charging station
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
extern void vCtrResetOutput(void);

/**************************************************************************
* NAME:			extern bool bCtrcheckPlug(void)
* Description:	Checks the connection to a car, if a car is connected it returns
*				ture, if no car is connected it returns false
*
* Subroutines Called:	none
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
extern bool bCtrCheckPlug(void);

#endif /* CHARGINGCONROL_H_ */