/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:		USER_INTERFACE.h
* PROJECT:
* MODULE:
*
* Description:
*
* Notes:
*
* Compiler dependencies or special instructions:
*
* REVISION HISTORY
* Date: By: Description:
* Created: 20.02.2020 13:40:31
* Author: Marc Wechselberger
*****************************************************************************/

/*   *** INCLUDES ***   */
#define F_CPU 16000000
#include <stdint.h>
#include "lcd.h"
#include <stdio.h>
#include <math.h>
#include <avr/delay.h>

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

/**************************************************************************
* NAME: vCtrPrintDisplayText(char *)
* Description: The functions prints the char* given as parameter on the LCD Display 
* 
*
* Subroutines Called:
* void lcd_clear(void)
* void lcd_home(void)
* void lcd_print_str(char *)
*
* Returns: void
*
* Globals: none
*
* Designer(s):/ Design Document:
* Programmer(s):
* Tested By: Date:
* Assumptions and Limitation:
*
* Exception Processing:
*
* NOTES:
*
* REVISION HISTORY
* Date: By: Description:
* Created: 10.04.2020 18:28
* Author: Marc Wechselberger
**************************************************************************/
void vCtrPrintDisplayText(char *c_Text_display);

/**************************************************************************
* NAME: vCtrPrintChargingInfo(float i_Ctr_Power, float i_Ctr_FullPrize)
* Description: The functions prints the information of the charging status on the LCD ...
* display including the current amount of energy taken form the station and the current ...
* amount of the cost
*
*
* Subroutines Called:
* void lcd_clear(void)
* void lcd_home(void)
* void lcd_print_str(char *)
* strcat(char *, const char *)
* dtostrf(double __val, signed char __width, unsigned char __prec, char *__s)
* strlen(const char *)
* malloc(size_t __size)
*
*
* Returns: void
*
* Globals: none
*
* Designer(s):/ Design Document:
* Programmer(s):
* Tested By: Date:
* Assumptions and Limitation:
*
* Exception Processing:
*
* NOTES:
*
* REVISION HISTORY
* Date: By: Description:
* Created: 10.04.2020 18:28
* Author: Marc Wechselberger
**************************************************************************/
void vCtrPrintChargingInfo(float i_Ctr_Power, float i_Ctr_FullPrize);

/**************************************************************************
* NAME: vCtrPrintChargingInfo1(void)
* Description: The functions creates an instruction for the user on the display to connect the car with the plug
*
*
* Subroutines Called:
* CtrPrintDisplayText(char *c_Text_display)
*
*
* Returns: void
*
* Globals: none
*
* Designer(s):/ Design Document:
* Programmer(s):
* Tested By: Date:
* Assumptions and Limitation:
*
* Exception Processing:
*
* NOTES:
*
* REVISION HISTORY
* Date: By: Description:
* Created: 10.04.2020 18:28
* Author: Marc Wechselberger
**************************************************************************/
void vCtrPrintChargingInfo1(void);

/**************************************************************************
* NAME: vCtrPrintChargingInfo2(float i_Ctr_CurrentPrize)
* Description: The functions creates an information for the user on the display that shows the current prize an the ...
* instruction to identify the user by holding the RFID card to the scanner
*
*
* Subroutines Called:
* CtrPrintDisplayText(char *c_Text_display)
* dtostrf(double __val, signed char __width, unsigned char __prec, char *__s)
* strcat(char *, const char *)
*
*
* Returns: void
*
* Globals: none
*
* Designer(s):/ Design Document:
* Programmer(s):
* Tested By: Date:
* Assumptions and Limitation:
*
* Exception Processing:
*
* NOTES:
*
* REVISION HISTORY
* Date: By: Description:
* Created: 10.04.2020 18:28
* Author: Marc Wechselberger
**************************************************************************/
void vCtrPrintChargingInfo2(float i_Ctr_CurrentPrize);

/**************************************************************************
* NAME: vCtrPrintChargingInfo3(void)
* Description: The functions creates an information for the user on the lcd display that the plug has been removed while the process was running
*
*
* Subroutines Called:
* CtrPrintDisplayText(char *c_Text_display)
* _delay_ms(double __ms)
*
*
* Returns: void
*
* Globals: none
*
* Designer(s):/ Design Document:
* Programmer(s):
* Tested By: Date:
* Assumptions and Limitation:
*
* Exception Processing:
*
* NOTES:
*
* REVISION HISTORY
* Date: By: Description:
* Created: 10.04.2020 18:28
* Author: Marc Wechselberger
**************************************************************************/
void vCtrPrintChargingInfo3(void);

#endif /* USER_INTERFACE_H_ */