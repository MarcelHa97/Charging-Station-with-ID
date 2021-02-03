/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			CalcADC.c
* PROJECT:		Ladesaeule mit ID
* MODULE:		Calculation Unit
*
* Description:	This file initializes the analog to digital converter. The function
*				"vCalcADCInit()" starts a conversion and returns the result.
*
*
* Notes: none
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
#include "CalcADC.h"

/** functions **/
void vCalcADCInit(){
	// ADMUX:
	ADC_internal_AREF();
	ADC_select_channel_ADC3(); 
	ADC_right_adjust();
	
	// ADCSRA:
	ADC_enable();
	ADC_stop_conversion();
	ADC_enable_auto_trigger();
	ADC_disable_interrupt();
	ADC_prescaler_128();
	
	// ADCSRB:
	ADC_disable_analog_comparator();
	ADC_source_free_running();
	
	// set Pin PC3 (=ADC3) as Input
	DDRC &= ~0x08;
}


uint16_t iCalcReadADC(){
	// start conversion
	ADC_start_conversion();
	// wait until ADC is completed	
	while( (ADCSRA & 0x10) == 0 );
	// clear ADC-Interrupt-Flag
	ADCSRA |= 0x10;
	
	// return the result (16 bit register)
	return ADC;
}

