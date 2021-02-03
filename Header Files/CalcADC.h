/*****************************************************************************
1. * Copyright 2012, All rights reserved, For internal use only
*
* FILE:			CalcADC.h
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
#pragma once
#include <avr/io.h>

#ifndef CALCADC_H_
#define CALCADC_H_

/** defines **/
// configure ADMUX:
#define ADC_internal_AREF() ADMUX |= (1<<REFS1); ADMUX |= (1<<REFS0)
#define ADC_right_adjust() ADMUX &= ~(1<<ADLAR)
#define ADC_select_channel_ADC3() ADMUX &= ~(1<<MUX3); ADMUX &= ~(1<<MUX2); ADMUX |= (1<<MUX1); ADMUX |= (1<<MUX0)

//configure ADCSRA
#define ADC_enable() ADCSRA |= (1<<ADEN)
#define ADC_disable() ADCSRA &= ~(1<<ADEN)

#define ADC_start_conversion() ADCSRA |= (1<<ADSC)
#define ADC_stop_conversion() ADCSRA &= ~(1<<ADSC)

#define ADC_enable_auto_trigger() ADCSRA |= (1<<ADATE)
#define ADC_disable_auto_trigger() ADCSRA &= ~(1<<ADATE)

#define ADC_enable_interrupt() ADCSRA |= (1<<ADIE)
#define ADC_disable_interrupt() ADCSRA &= ~(1<<ADIE)

#define ADC_prescaler_128() ADCSRA |= (1<<ADPS2); ADCSRA |= (1<<ADPS1); ADCSRA |= (1<<ADPS0)

// configure ADCSRB
#define ADC_enable_analog_comparator()	ADCSRB |= (1<<ACME)
#define ADC_disable_analog_comparator()	ADCSRB &= ~(1<<ACME)

#define ADC_source_free_running() ADCSRB &= ~(1<<ADTS2); ADCSRB &= ~(1<<ADTS1); ADCSRB &= ~(1<<ADTS0)


/** functions **/
/**************************************************************************
* NAME:			void vCalcADCInit(void)
* Description:	Initializes the Analog Digital Converter
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
void vCalcADCInit();

/**************************************************************************
* NAME:			uint16_t iCalcReadADC(void)
* Description:	This function starts an analog to digital conversion, waits
*				until it is finished and returns the 16 bit register "ADC"
*				containing the result of the conversion. 
*
* Subroutines Called: none
*
* Returns: ADC (16 bit register)
*
* Globals: none
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
uint16_t iCalcReadADC();

#endif /* CALCADC_H_ */