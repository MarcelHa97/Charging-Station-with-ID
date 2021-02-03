/*****************************************************************************
* Copyright 2020, All rights reserved, For internal use only
*
* FILE:			main.c
* PROJECT:		Charging station with ID
* MODULE:		Main process of the charging process 
*
* Description:  This file include all functions execute the charging process. It also
*				include the main-function to start the software of the charging station. 
*
*
* Notes:		The main function call all the needed function of the different files to 
*				execute and control the charging process of the charging station
*
* Compiler dependencies or special instructions: none
*
* REVISION HISTORY
*
*****************************************************************************/

//Load all files for the charging process
#define F_CPU 16000000
#include <avr/io.h>
#include "mfrc522.h"
#include "spi.h"
#include "authentication.h"
#include "chargingConrol.h"
#include "CalcCalculation.h"
#include "CalcOutput.h"
#include "CalcADC.h"
#include "CalcTimer.h"
#include "USER_INTERFACE.h"
#include "CTR_INIT.h"
#include <avr/interrupt.h>
#include <avr/delay.h>

//Global variables to save different charging status  
bool b_status_error;
bool b_Charging_status_1;
bool b_Charging_status_2;
bool b_status;

/** functions **/

/**************************************************************************
* NAME:			void intInterrupt()
* Description:	Initialize the interrupt
*
* Subroutines Called:	sei()
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
void intInterrupt(){
	EICRA |= ((1<<ISC11)|(1<<ISC10)|(1<<ISC01)|(1<<ISC00));
	EIMSK |= ((1<<INT0)|(1<<INT1));
	sei();
}

/**************************************************************************
* NAME:			int main(void)
* Description:	This function is the main-function, which controls the whole 
*				charging process of the charging station. In the first step it
*				initialize the different units of the software. After this it 
*				initialize the database and a prize for simulation. 
*
* Subroutines Called:	vAuthInitAuthentication();
*						vCtrInitChargingControl();
*						vCalcCalculationInit();
*						vCalcADCInit();
*						vCalcTimerInit();
*						CtrInitComponents();
*						intInterrupt();
*						vCalcSetPrice(float)
*						bCtrCheckPlug()
*						vCtrPrintChargingInfo1()
*						vCtrPrintChargingInfo2(float)
*						bAuthCompromiseCardDatabase(uint8_t, bool*)
*						vAuthsetLED(bool, bool*)
*						vCtrSetOutput()
*						vCalcSetLoadingCapacity(bool*)
*						vCtrResetOutput()
*						CtrPrintChargingInfo(float, float)
*						fCalcGetLoadingCapacity()
*						fCalcGetCost()
*						_delay_ms(uint8_t)
*
* Returns: int
*
* Globals:	b_status_error()
*			b_Charging_status_1()
*			b_Charging_status_2()
*			b_status()	
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
int main(void) {
	vAuthinitAuthentication();
	vCtrInitChargingControl();
	vCalcCalculationInit();
	vCalcADCInit();
	vCalcTimerInit();
	vCtrInitComponents();
	intInterrupt();
	
	uint8_t database[] = {24, 45, 89, 56, 12, 2, 56, 34, 20, 5}; // Numbers of valued numbers of cards, what will accepted at the charging station. 
	float prize = 0.23;		//Set the current prize of the power per kWh
	
	b_status_error = true;
	b_Charging_status_1 = true;
	b_Charging_status_2 = false;
	
	vCalcSetPrice(prize);
	
	while(1){
		if(!bCtrCheckPlug() && b_Charging_status_1){
			vCtrPrintChargingInfo1();
			b_Charging_status_1 = false;
		} else if(bCtrCheckPlug()){
			vCtrPrintChargingInfo2(prize);
			
			b_status = bAuthCompromiseCardDatabase(database, &b_status_error); //Wait until a card is found
			vAuthsetLED(b_status, &b_status_error);
			
			if(b_status && b_status_error){
				vCtrSetOutput();
				b_Charging_status_2 = true;
				vCalcSetLoadingCapacity(&b_status_error);
				vCtrResetOutput();
				
				if(fCalcGetLoadingCapacity() > 0.7){
					vCtrPrintChargingInfo(fCalcGetLoadingCapacity(), fCalcGetCost()); //Prints the costs and the quantity power
					_delay_ms(3000);
				}
			}
			b_status_error = true;
			b_Charging_status_2 = false;
		} 
	}
}

/**************************************************************************
* NAME:			ISR(INT0_vect)
* Description:	Interrupt routine 1, it will execute if the plug of the charging wire
*				was unplugged of the socket. It shows an error message and reset the output
*				of the charging process
*
* Subroutines Called:	vCtrResetOutput()
*						vCtrPrintChargingInfo3()
*
* Returns: none
*
* Globals:  b_status_error
*			b_Charging_status_1
*			b_Charging_status_2
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
ISR(INT0_vect){
	b_status_error = false;
	b_Charging_status_1 = true;	//If the plug is unplugged of the socket the status will set true
	vCtrResetOutput();
	
	if(b_Charging_status_2){
		vCtrPrintChargingInfo3();
	}
}

/**************************************************************************
* NAME:			ISR(INT1_vect)
* Description:	Interrupt routine, it will execute if the interrupt button	
*				of the charging station was pressed. It shows an error message and
*				reset the output of the charging proccess
*
* Subroutines Called:	vCtrResetOutput()
*						vCtrPrintChargingInfo3()
*
* Returns: none
*
* Globals:  b_status_error
*			b_Charging_status_2
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
ISR(INT1_vect){
	b_status_error = false;
	vCtrResetOutput();
	
	if(b_Charging_status_2){
		vCtrPrintChargingInfo3();
	}
}



