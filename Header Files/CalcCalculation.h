/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			CalcCalculation.h
* PROJECT:		Ladesaeule mit ID
* MODULE:		Calculation Unit
*
* Description:	This file measures an average current over one second and calculates
*				the corresponding average power [Ws]. As long as sufficient current
*				flows, the measurement continues. The average power is gradually
*				added to a total power. The current costs are calculated at any time
*				and at the end of the entire measurement the total costs are calculated.
*
*
* Notes:		After starting the loading process only the function
*				"vCalcSetLoadingCapacity()" has to be called. This is automatically
*				exited when the loading is finished. The total costs can be retrieved
*				using "fCalcGetCost()" and the entire line can be retrieved using
*				"fCalcGetLoadingCapacity()".
*
*
* Compiler dependencies or special instructions: none
*
* REVISION HISTORY
* REVISION I
*	Date:	25.02.2020
*	By:		Marcel Hammerl
*
* REVISION II
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
*****************************************************************************/

/** includes **/
#pragma once 
#include <avr/io.h>
#include <stdbool.h>
#include "CalcADC.h"
#include "CalcOutput.h"
#include "CalcTimer.h"
#include "USER_INTERFACE.h"


#ifndef CALCCALCULATION_H_
#define CALCCALCULATION_H_

/** defines **/

// ADC value by 0A (series resistor = 120 Ohm -> 754; series resistor= 240 Ohm -> 689)
#define ADC_Value_0_Ampere 780

// this value must be exceeded for a current measurement to start or continues
#define Start_Measurement_Margin 52.0

// initializes f_Calc_Average_Electricity with this value to start first meassurement
#define First_Measurement_value 53.0

// [mV/Count]; per + 3,483 mV at the ADC input, the ADC converter counts up one count value
#define Voltage_per_ADC_Count 3.483

// [mA/mV]; per + 3. 120 mA at the input of the current sensor the sensor outputs 1 mV more
#define Ampere_per_Voltage 3.120

// [V]; charging voltage = 4.31
#define Charching_Voltage 4.31

// [mA]; Correction summand to compensate an offset of the measured current
// (series resistor = 120 Ohm -> 20.0; series resistor= 240 Ohm -> 0.0)
#define Correction 0.0


/** functions **/

/**************************************************************************
* NAME:			void vCalcCalculationInit (void)
* Description:	Initializes the Calculation Unit
*
* Subroutines Called:	vCalcTimerInit(void)
						vCalcADCInit(void)
*
* Returns: none
*
* Globals:	f_Calc_Price
*			f_Calc_loading_capacity
*			b_Calc_1_sec_Flag
*
* Designer(s):
* Design Document:
*
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 15.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
* REVISION I
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
**************************************************************************/
void vCalcCalculationInit (void);


/**************************************************************************
* NAME:			void vCalcSetPrice (float)
* Description:	Set global variable "f_Calc_Price" to the input value
*
* Subroutines Called: none
*
* Returns: none
*
* Globals:	f_Calc_Price
*
* Designer(s):
* Design Document:
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 15.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
* REVISION I
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
**************************************************************************/
void vCalcSetPrice (float);


/**************************************************************************
* NAME:			void vCalcSetLoadingCapacity (void)
* Description:	This function measures an average current over one second and calculates
*				the corresponding average power [Ws]. As long as sufficient current
*				flows, the measurement continues. The average power is gradually
*				added to a total power. The current costs are calculated at any time
*				and at the end of the entire measurement the total costs are calculated.
*
* Subroutines Called:	fCalcElectricityMeasurement (void)
*						CtrPrintChargingInfo (float,float)
*
* Returns: none
*
* Globals:	f_Calc_loading_capacity
*
* Designer(s):
* Design Document:
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 15.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: This function is only called by the main routine after starting 
*		 the loading process. This is automatically exited when the loading
*		 is finished.
*
* REVISION HISTORY
* REVISION I
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
**************************************************************************/
void vCalcSetLoadingCapacity (bool *status);


/**************************************************************************
* NAME:			float fCalcGetPrice (void)
* Description:	returns the global variable f_Calc_Price
*
* Subroutines Called: none
*
* Returns: float f_Calc_Price
*
* Globals:	f_Calc_Price
*
* Designer(s):
* Design Document:
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 15.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
* REVISION I
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
**************************************************************************/
float fCalcGetPrice (void);


/**************************************************************************
* NAME:			float fCalcGetLoadingCapacity (void)
* Description:	returns the global variable 
*
* Subroutines Called: none
*
* Returns: float f_Calc_loading_capacity
*
* Globals:	f_Calc_loading_capacity
*
* Designer(s):
* Design Document:
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 15.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
* REVISION I
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
**************************************************************************/
float fCalcGetLoadingCapacity (void);


/**************************************************************************
* NAME:			float fCalcGetCost (void)
* Description:	multiplied f_Calc_loading_capacity by f_Calc_Price to obtain total costs
*
* Subroutines Called: none
*
* Returns: float
*
* Globals:  f_Calc_Price
*			f_Calc_loading_capacity
*
* Designer(s):
* Design Document:
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 15.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
* REVISION I
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
**************************************************************************/
float fCalcGetCost (void);


/**************************************************************************
* NAME:			float fCalcElectricityMeasurement (void)
* Description:	Reads the ADC register and subtracts an offset from this value. 
*				From this the absolute value is formed. The result is multiplied 
*				by the defines "Voltage_per_ADC_Count" and "Ampere_per_Voltage" 
*				to obtain milliamperes. The offset is caused by the current 
*				sensor, as it applies 2. 5V at the output when 0A at the input. 
*
* Subroutines Called: iCalcReadADC(void)
*
* Returns: float
*
* Globals: none
*
* Designer(s):
* Design Document:
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 15.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
* REVISION I
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
**************************************************************************/
float fCalcElectricityMeasurement (void);


/**************************************************************************
* NAME:			void vCalcClearSecFlag (void)
* Description:	This function is called by the ISR to clear the "b_Calc_1_sec_Flag"
*				after one second meassurement
*
* Subroutines Called: none
*
* Returns: none
*
* Globals: b_Calc_1_sec_Flag
*
* Designer(s):
* Design Document:
* Programmer(s): Marcel Hammerl
* Tested By: Marcel Hammerl
* Date: 15.03.2020
* Assumptions and Limitation: none
*
* Exception Processing: none
*
* NOTES: none
*
* REVISION HISTORY
* REVISION I
*	Date:	15.03.2020
*	By:		Marcel Hammerl
*
**************************************************************************/
void vCalcClearSecFlag (void);

#endif /* CALCCALCULATION_H_ */