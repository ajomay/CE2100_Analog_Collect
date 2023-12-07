//#############################################################################
// ScalintToolsGenII.H
//
// 
//
// Created: 20.08.2023
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __ScalintToolsGenII_H_LOADED_9FECD48FAD0A__
#define __ScalintToolsGenII_H_LOADED_9FECD48FAD0A__
//#############################################################################

//-------------------------------------------------------------------
//
#include "Formats.h"


//-------------------------------------------------------------------
// Use smaller struct for saving scaling infos's
// to save memory.
//
// #define SCT_USE_SMALL_STRUCT 1

//-------------------------------------------------------------------
// Print C-Code of generated SctScalingStruct
// to save calibration reults.
//
//
//#define SCT_GENERATE_C_CODE 1


typedef struct
{
  // Calculate physical value from digital.
  //
  // Holds M.
  TSLONG32 Mz;
  TSLONG32 Mn;

  // Holds offset.
  TSLONG32 B;


#ifndef SCT_USE_SMALL_STRUCT
  TSLONG32 X1;
  TSLONG32 Y1;
  TSLONG32 X2;
  TSLONG32 Y2;

  // Min and Max values to limit the outputs of calculations to.
  TSLONG32 YMin;
  TSLONG32 YMax;
#endif

} SctScalingStruct;

//-------------------------------------------------------------------
//
extern TUCHAR SctSetScalingStruct(SctScalingStruct *pS, TSLONG32 X1, TSLONG32 Y1, TSLONG32 X2, TSLONG32 Y2, TSLONG32 Ymin, TSLONG32 Ymax);

//-------------------------------------------------------------------
// WARNING: 
// NO local storage of parameters in static variables.
// Allways call this function with all parameters full valid!
//
extern TSTATEVALUE SctDoScaling(TSTATEVALUE *pState, TSLONG32 *pResult, SctScalingStruct *pS, TSLONG32 X);


//-------------------------------------------------------------------
//
extern TSLONG32 SctDoScaling(SctScalingStruct *pS, TSLONG32 X);


//-------------------------------------------------------------------
//
extern void SctPrintSctScalingStruct(SctScalingStruct *pS, const char *pName);


#define SctAbsDiff_(a, b)(a>=b)?(a-b):(b-a);

//#############################################################################
//#############################################################################
//#############################################################################
#endif

