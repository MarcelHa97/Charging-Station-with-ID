/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			CalcTimer.c
* PROJECT:		Ladesaeule mit ID
* MODULE:		Calculation Unit
*
* Description:	This file initializes the timer and clears every second during
*				a measurement b_Calc_1_sec_Flag to interrupt the measurement and
*				calculate an average current.
*
*
* Notes: none
*
*
* Compiler dependencies or special instructions: none
*
* REVISION HISTORY
* REVISION I
*	Date:	01.03.2020
*	By:		Marcel Hammerl
*
*****************************************************************************/

/** includes **/
#include "CalcTimer.h"


/** defines **/
ISR(TIMER1_OVF_vect){
	// The ISR is called when the timer has expired, i. e. when one second has passed. 
	// b_Calc_1_sec_Flag is cleared to interrupt the measurement and calculate an average 
	// current. b_Calc_1_sec_Flag is automatically set again so that the measurement can 
	// be continued. 
	
	vCalcClearSecFlag();
}

/** functions **/
void vCalcTimerInit(){
	// configure TCCR1A:
	Timer_No_Waveform_Generation();
	Timer_normal_port_operation_B();
	Timer_normal_port_operation_A();
	
	// configure TCCR1B:
	Timer_disable_Noise_Canceler();
	
	// When the timer is started, the prescaler is selected and the timer starts immediately.
	// Stop_Timer () is only called to make sure that the timer does not start yet.
	Stop_Timer();
	
	// configure TIMSK1:
	Timer_disable_Input_Interrupt();
	Timer_disable_Output_A_Interrupt();
	Timer_disable_Output_B_Interrupt();
	Timer_enable_Overflow_Interrupt();
	
	// enable global interrupt flag:
	sei();
}