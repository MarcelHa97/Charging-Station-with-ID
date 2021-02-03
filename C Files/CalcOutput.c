/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			CalcOutput.c
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
#include "CalcOutput.h"

/** functions **/
void vCalcPrintChargingInfo(){
	// get loading capacity
	float f_Calc_Loading_Capacity = fCalcGetLoadingCapacity();
	
	// get costs
	float f_Calc_Cost = fCalcGetCost();
	
	// print loading capcity and costs
	CtrPrintChargingInfo(f_Calc_Loading_Capacity, f_Calc_Cost);
}

