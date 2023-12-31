//#############################################################################
// Rs485.H
//
// RS485-Port for CONTROLLINO
//
// Created: 25.07.2023
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __Rs485_H_LOADED_5F9F3FE74F64__
#define __Rs485_H_LOADED_5F9F3FE74F64__
//#############################################################################

//-------------------------------------------------------------------
//
#include "Formats.h"


#define RS485_CPU_ARDUINO 1

//#define RS485_CPU_CONTROLLINO 1


//-------------------------------------------------------------------
//
#ifdef RS485_CPU_CONTROLLINO
extern void Rs485Init(long baud);
#endif

//-------------------------------------------------------------------
//
#ifdef RS485_CPU_ARDUINO
extern void Rs485Init(void);
#endif


//-------------------------------------------------------------------
//
extern bool Rs485IsCharAvail();


//-------------------------------------------------------------------
//
extern int Rs485ReadChar();


//-------------------------------------------------------------------
//

extern void Rs485Transmit(const char *data);

extern void Rs485Transmit(byte *data, int len);


//-------------------------------------------------------------------
//
extern bool Rs485IsTramsmitReady(void);


//-------------------------------------------------------------------
//
extern void Rs485SwitchToRecMode(void);

//-------------------------------------------------------------------
//
extern void Rs485SwitchToTransmitMode(void);



//#############################################################################
//#############################################################################
//#############################################################################
#endif
