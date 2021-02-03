/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:		CTR_INIT.c
* PROJECT:	
* MODULE:	CTR_INIT.h
*
* Description:
*
* Notes:
*
* Compiler dependencies or special instructions:
* needed include CTR_INIT.h
*
* REVISION HISTORY
* Date: By: Description:
* Created: 20.02.2020 13:38:52
* Author: Marcel Hammerl
*****************************************************************************/

void vCtrInitComponents(void){
	i2c_init();
	lcd_init();
	
}