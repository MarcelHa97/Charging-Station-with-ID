/*****************************************************************************
1. * Copyright 2020, All rights reserved, For internal use only
*
* FILE:		CTR_INIT.h
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
* Created: 20.02.2020 13:38:52
* Author: Marc Wechselberger
*****************************************************************************/

/*   *** INCLUDES ***   */
#include "lcd.h"
#include "i2c.h"

#ifndef CTR_INIT_H_
#define CTR_INIT_H_

/**************************************************************************
* NAME: CtrInitComponents
* Description: The functions initialization of the components ...
* of the atmel controller and hardware
*
* Subroutines Called:
* void i2c_init(void)
* void lcd_init(void)
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
* Created: 20.02.2020 14:26
* Author: Marc Wechselberger
*
**************************************************************************/
extern void vCtrInitComponents(void);





#endif /* CTR_INIT_H_ */