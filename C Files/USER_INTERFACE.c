/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:		USER_INTERFACE.c
* PROJECT:	
* MODULE:	USER_INTERFACE.h
*
* Description:
*
* Notes:
*
* Compiler dependencies or special instructions:
* needed include USER_INTERFACE.h
*
* REVISION HISTORY
* Date: By: Description:
* Created: 20.02.2020 13:40:31
* Author: Marc Wechselberger
*****************************************************************************/

#include "USER_INTERFACE.h"

void vCtrPrintDisplayText(char *c_Text_display){
	lcd_clear(); // clear the lcd display
	lcd_home(); // reset the address of the lcd display to the first value
	lcd_print_str(c_Text_display); // printing the string given on the lcd display
}

void vCtrPrintChargingInfo(float i_Ctr_Power, float i_Ctr_FullPrize){
	// creates values for the conversion of the given float to a string with the dtostrf
	// values of the minimum width
	signed char c_Ctr_Width_Power = 1;
	signed char c_Ctr_Width_FullPrize = 1;
	// values of the number of decimal points 
	unsigned char c_Ctr_Dec = 2;
	unsigned int i_Ctr_str_length_power;
	
	char *s_Ctr_space;
	s_Ctr_space = (char*)malloc(5*sizeof(char));
	char s_Ctr_Power_Value[10];
	char s_Ctr_FullPrize_Value[10];
	char s_Ctr_Power[16] = "Power: ";
	char s_Ctr_FullPrize[16] = "Cost : ";
	
	dtostrf(i_Ctr_Power,c_Ctr_Width_Power,c_Ctr_Dec,s_Ctr_Power_Value); // conversion of the float into a string
	dtostrf(i_Ctr_FullPrize,c_Ctr_Width_FullPrize,c_Ctr_Dec,s_Ctr_FullPrize_Value); // conversion of the float into a string
	
	i_Ctr_str_length_power = strlen(s_Ctr_Power_Value);
	
	switch(i_Ctr_str_length_power){ // creating different white spaces in case of the variable length of the power value 
		case 4:
			s_Ctr_space = "     ";
			break;
		case 5:
			s_Ctr_space = "    ";
			break;
		case 6: 
			s_Ctr_space = "   "; 
			break;
	}
	
	strcat(s_Ctr_Power, s_Ctr_Power_Value); // combines the strings 
	strcat(s_Ctr_FullPrize, s_Ctr_FullPrize_Value); // comines the strings
	
	lcd_clear(); // clear the lcd display
	lcd_home(); // reset the address of the lcd display to the first value
	lcd_print_str(s_Ctr_Power); // printing the string given on the lcd display
	lcd_print_str(s_Ctr_space); // printing the string given on the lcd display
	lcd_print_str(s_Ctr_FullPrize);	// printing the string given on the lcd display
}

void vCtrPrintChargingInfo1(){
	char s_Ctr_ChargingInfo[32] = "Please connect  your Car!";
	
	vCtrPrintDisplayText(s_Ctr_ChargingInfo); // printing the given string on the lcd display
}

void vCtrPrintChargingInfo2(float i_Ctr_CurrentPrize){
	if(i_Ctr_CurrentPrize < 0.0){	// cancel the operation if a negative current prize is entered as parameter
		return;
	}
	char s_Ctr_ChargingInfo[32] = "Identify by Card"; // text message displayed on the lcd screen
	
	signed char c_Ctr_Width_CurrPrize = 1; // minimum width parameter for the conversion (needed for dtostrf)
	unsigned char c_Ctr_Dec_CurrPrize = 2; // amount of number which will be displayed after the decimal point (needed for dtostrf)
	
	char s_Ctr_CurrentPrize_Value[10]; // const char array as location for the saved string created by dtostrf
	char s_Ctr_CurrentPrize[32] = "Prize: "; // const string which will be combined to the integer value given as parameter 
	
	dtostrf(i_Ctr_CurrentPrize,c_Ctr_Width_CurrPrize,c_Ctr_Dec_CurrPrize,s_Ctr_CurrentPrize_Value);
	
	strcat(s_Ctr_CurrentPrize,s_Ctr_CurrentPrize_Value); // combines the strings created before to the information which ...
	strcat(s_Ctr_ChargingInfo,s_Ctr_CurrentPrize);		 // will be shown on the lcd display	
	
	vCtrPrintDisplayText(s_Ctr_ChargingInfo); // prints the string on the lcd display
}

void vCtrPrintChargingInfo3(){
	char s_Ctr_ChargingInfo[32] = "Loading process was interrupted";
	vCtrPrintDisplayText(s_Ctr_ChargingInfo); // printing the given string on the lcd display
	_delay_ms(2000); // delay for 2 sec
}
