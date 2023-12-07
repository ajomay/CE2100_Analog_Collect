//#############################################################################
// Debug.C
//
// 
//
// Created: 19.11.2019
// History:
//
// (C) ce.tron Gesellschaft f?r Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################


//-------------------------------------------------------------------
//
#include "Debug.h"

#include "SysTimer.h"

//-------------------------------------------------------------------
//

#ifdef _DEB_FLAG_DEBUG_

char DebStr[DEBUG_MSGBUF_SIZE];

volatile TTIMERVAL DebTimer;

volatile TUCHAR DebFlag=0;
volatile TUCHAR DebUCHAR=0;
volatile TSINT16 DebInt=0;


#endif



#ifdef _DEB_FLAG_DEBUG_
TBOOL DebIsDebugMode= TRUE;
#else
TBOOL DebIsDebugMode= FALSE; 
#endif

//#############################################################################
//#############################################################################
//#############################################################################
