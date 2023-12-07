/*
#####################################################################
 SysTimer.H



 Created: 14.11.2003
 History:

 (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
 Roentgenstrasse 104
 D-64291 Darmstadt
#####################################################################
*/
#ifndef __SysTimer_H_LOADED_
#define __SysTimer_H_LOADED_
/*#################################################################*/


//-------------------------------------------------------------------
// @AMID@SysTimer_H@_2023-08-18-0942
//-------------------------------------------------------------------


#include "Formats.h"



#define SYS_TIME_1_SEC (1000L)
#define SYS_TIME_0_1_SEC (100L)
#define SYS_TIME_0_0_1_SEC (10L)

#define SYS_TIME_100_MSEC (SYS_TIME_0_1_SEC)
#define SYS_TIME_10_MSEC (SYS_TIME_0_0_1_SEC)
#define SYS_TIME_1_MSEC (1L)

//-----------------------------------------------------------------------------
//

typedef  TULONG32 TTIMERVAL;




//---------------------------------------------------------

extern void SysStartLocalTimer(TTIMERVAL *pTimer);

extern TBOOL SysIsLocalTimeout(TTIMERVAL *pTimer, TTIMERVAL Time);





extern void SysStartTimer(TTIMERVAL *pTimer, TTIMERVAL Time);

extern TBOOL SysIsTimeout(TTIMERVAL *pTimer);



extern TTIMERVAL SysGetTime(void);




/*#################################################################*/
#endif
