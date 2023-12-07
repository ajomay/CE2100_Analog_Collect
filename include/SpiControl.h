//#############################################################################
// SpiControl.H
//
// 
//
// Created: 27.11.2023
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __SpiControl_H_LOADED_33709C24A2D8__
#define __SpiControl_H_LOADED_33709C24A2D8__
//#############################################################################

//-------------------------------------------------------------------
//
#include "Formats.h"

#include "SysTimer.h"

//-------------------------------------------------------------------
//
extern void SpiCtrlInit(void);


#define SPICNTRL_COUNT_DTA 4

typedef struct
{
    TSTATEVALUE State;
    TTIMERVAL Timer;
    TUCHAR SpiValues[SPICNTRL_COUNT_DTA];
    TUCHAR Adr;
    TBOOL StartTransmissionNow;
} SPI_CNTRL_STRUCT;



//-------------------------------------------------------------------
//
extern void SpiCtrlInit(void);

//-------------------------------------------------------------------
//
extern void SpiCtrlHandle(void);


//#############################################################################
//#############################################################################
//#############################################################################
#endif

