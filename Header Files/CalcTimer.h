/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:			CalcTimer.h
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
#pragma once
#include <avr/interrupt.h>
#include "CalcCalculation.h"


#ifndef CALCTIMER_H_
#define CALCTIMER_H_

/** defines **/
// configure TCCR1A:
#define Timer_normal_port_operation_A() TCCR1A &= ~0x40; TCCR1A &= ~0x80
#define Timer_normal_port_operation_B() TCCR1A &= ~0x10; TCCR1A &= ~0x20
#define Timer_No_Waveform_Generation() TCCR1A &= ~0x01; TCCR1A &= ~0x02; TCCR1B &= ~0x08; TCCR1B &= ~0x10


// configure TCCR1B:
#define Timer_disable_Noise_Canceler() TCCR1B &= ~0x80
#define Timer_prescaler_256() TCCR1B |= 0x04; TCCR1B &= ~0x02; TCCR1B &= ~0x01
#define Start_Timer() Timer_prescaler_256()
#define Stop_Timer() TCCR1B &= ~0x04; TCCR1B &= ~0x02; TCCR1B &= ~0x01


// configure TIMSK1:
#define Timer_disable_Input_Interrupt() TIMSK1 &= ~0x20
#define Timer_disable_Output_A_Interrupt() TIMSK1 &= ~0x02
#define Timer_disable_Output_B_Interrupt() TIMSK1 &= ~0x04
#define Timer_enable_Overflow_Interrupt() TIMSK1 |= 0x01


/** functions **/
/**************************************************************************
* NAME:			void vCalcTimerInit()
* Description:	Initializes the Timer
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
void vCalcTimerInit();

#endif /* CALCTIMER_H_ */