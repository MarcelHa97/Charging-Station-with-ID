/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			CalcCalculation.c
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
#include "CalcCalculation.h"


/** globale Variablen **/
float f_Calc_Price;
float f_Calc_loading_capacity;
unsigned b_Calc_1_sec_Flag;


/** functions **/
/** Init **/
void vCalcCalculationInit(){
	f_Calc_Price = 0;
	f_Calc_loading_capacity = 0;
	b_Calc_1_sec_Flag = 0;
	
	vCalcTimerInit();
	vCalcADCInit();
}


/** set-fuctions **/
void vCalcSetPrice (float input1){
	f_Calc_Price = input1;
}

void vCalcSetLoadingCapacity(bool *status){
	
	// start timer when charging begins
	Start_Timer();
	
	// the last charge is reseted
	f_Calc_loading_capacity = 0;
	
	//intern variable
	float f_Calc_total_Power = 0;
	float f_Calc_total_Cost = 0.0;
	float f_Calc_Average_Current = First_Measurement_value;
			
	
	while ((f_Calc_Average_Current > Start_Measurement_Margin) && *status){
		
		// intern variable
		uint16_t i_Calc_Conversion_Counter = 0;
		float f_Calc_Current_in_one_Second = 0.0;
		float f_Calc_Power_in_one_Second = 0.0;
		
		// timer interrupt will clear this flag after one second
		b_Calc_1_sec_Flag = 1;
		
		// adds current over one second
		while(b_Calc_1_sec_Flag){
			i_Calc_Conversion_Counter ++;
			 f_Calc_Current_in_one_Second += fCalcElectricityMeasurement();
		}
		
		// average current is calculated [mA]
		f_Calc_Average_Current = (f_Calc_Current_in_one_Second / (float) i_Calc_Conversion_Counter) + Correction;
		
		// power in one second is calculated [           (mA / 1000.0) * V                 * s   = Ws]
		f_Calc_Power_in_one_Second = (f_Calc_Average_Current / 1000.0) * Charching_Voltage * 1.0;
		
		// gradually add power to a total power
		f_Calc_total_Power += f_Calc_Power_in_one_Second;
		
		// calculate current costs 
		f_Calc_total_Cost = f_Calc_Price * f_Calc_total_Power;
		
		// print current power and costs
		vCtrPrintChargingInfo(f_Calc_total_Power, f_Calc_total_Cost);
	}
	
	// update the global variable 
	f_Calc_loading_capacity = f_Calc_total_Power;
	
	// stop timer when the loading is finished
}


/** get-functions **/
float fCalcGetPrice (){
	return f_Calc_Price;
}

float fCalcGetLoadingCapacity(){
	return f_Calc_loading_capacity;
}

float fCalcGetCost(){
	return (f_Calc_Price * f_Calc_loading_capacity);						
}


/** measurement-function **/
float fCalcElectricityMeasurement(){
	int16_t i_Calc_ADC_value = 0;
	
	i_Calc_ADC_value = iCalcReadADC();

	 i_Calc_ADC_value = i_Calc_ADC_value - ADC_Value_0_Ampere;
	
	if (i_Calc_ADC_value < 0){
		i_Calc_ADC_value = (-1) * i_Calc_ADC_value;
	}
	
// returns electricity
// [mA    =         Count            * mV/Count              * mA/mV             ] 	
	return ((float) i_Calc_ADC_value * Voltage_per_ADC_Count * Ampere_per_Voltage);
}


/** interrput-function **/
void vCalcClearSecFlag(){
	b_Calc_1_sec_Flag = 0;
}
