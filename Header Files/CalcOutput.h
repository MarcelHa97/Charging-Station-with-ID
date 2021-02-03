/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			CalcOutput.h
* PROJECT:		Ladesaeule mit ID
* MODULE:		Calculation Unit
*
* Description:	This file queries the total costs and the total power after 
*				completion of the loading process and displays them on the 
*				LCD display. 
*
* Notes: none
*
* Compiler dependencies or special instructions: none
*
* REVISION HISTORY
* REVISION I
*	Date:	25.02.2020
*	By:		Marcel Hammerl
*
* REVISIOIN II
*	Date:	17.03.2020
*	By:		Marcel Hammerl
*
*****************************************************************************/

/** includes **/
#pragma once
#include "CalcCalculation.h"


#ifndef CALCOUTPUT_H_
#define CALCOUTPUT_H_

/** functions **/

/**************************************************************************
* NAME:			void vCalcPrintChargingInfo(void)
* Description:	This function calls the two functions iCalcGetCost(void) and 
*				fCalcGetLoadingCapacity(void) to get the cost and loading 
*				capacity and passes it to function CtrPrintChargingInfo(float,float) 
*				for output on the LCD display. 
*
* Subroutines Called:	iCalcGetCost(void)
*						fCalcGetLoadingCapacity(void)
*						CtrPrintChargingInfo(float,float)
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
* Date: 17.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
* REVISION I
* Date: 17.03.2020
* By: Marcel Hammerl
*
**************************************************************************/
void vCalcPrintChargingInfo(void);


#endif /* CALCOUTPUT_H_ */