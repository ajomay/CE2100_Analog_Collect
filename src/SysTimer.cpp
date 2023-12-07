/*
###################################################################
 SysTimer.C



 Created: 14.11.2003
 History:

 (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
 Roentgenstrasse 104
 D-64291 Darmstadt
###################################################################
*/


#include "SysTimer.h"



void SysStartLocalTimer(TTIMERVAL *pTimer)
    {
    (*pTimer)= SysGetTime();
    }


void SysStartTimer(TTIMERVAL *pTimer, TTIMERVAL Time)
    {
    (*pTimer)= SysGetTime() + Time;
    }


TBOOL SysIsLocalTimeout(TTIMERVAL *pTimer, TTIMERVAL Time)
		{
	
		if ((SysGetTime() - (*pTimer)) < Time) return FALSE;
		
		return TRUE;
		}
	

TBOOL SysIsTimeout(TTIMERVAL *pTimer)
		{
	
		if ( SysGetTime()<(*pTimer) ) return FALSE;
		
		return TRUE;
		}



TTIMERVAL SysGetTime(void)
	{
	return millis();
	}
