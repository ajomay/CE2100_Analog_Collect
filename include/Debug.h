//#############################################################################
// Debug.H
//
//
//
// Created: 19.11.2019
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __Debug_H_LOADED_7446B86D5859__
#define __Debug_H_LOADED_7446B86D5859__
//#############################################################################

//-------------------------------------------------------------------
// @AMID@Debug_H@_2023-08-18-0941
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//
#include "Formats.h"

#include "SysTimer.h"


//-------------------------------------------------------------------
//

// Uncomment for debug outputs
// 
//#define _DEB_FLAG_DEBUG_ 1

/*

#ifdef _DEB_FLAG_DEBUG_
sprintf(DebStr, "Mot: %d", (int)(State)); 
Serial.println(DebStr);
#endif


*/

//-------------------------------------------------------------------
//

#ifdef _DEB_FLAG_DEBUG_
#define DEBUG_MSGBUF_SIZE 128
extern char DebStr[DEBUG_MSGBUF_SIZE];
extern volatile TTIMERVAL DebTimer;
extern volatile TUCHAR DebFlag;
extern volatile TUCHAR DebUCHAR;
extern volatile TSINT16 DebSInt;
extern volatile TUINT16 DebUInt;
#endif


/*
sprintf(SerDebStr, "S: %ld ", xyz);
*/



#ifdef _DEB_FLAG_DEBUG_
#define DEB_SER_DEB_BUFSIZE 64
extern char SerDebStr[DEB_SER_DEB_BUFSIZE];
#endif 


#define DEB_ENDLESS_LOOP() {while(TRUE){};}

//#############################################################################
//#############################################################################
//#############################################################################
#endif
