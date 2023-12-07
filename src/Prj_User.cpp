// #############################################################################
//  Prj_User.C
//
//
//
//  Created: 14.03.2022
//  History:
//
//  (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################

#include "Debug.h"

//-------------------------------------------------------------------
//
#include "Prj_User.h"

#include "SysTimer.h"

#include "Hdw.h"

#include "ScalintToolsGenII.h"

//------------------------------------------------------------------------------------------------------------------------
// Start of declarations.
//------------------------------------------------------------------------------------------------------------------------

// Value to be used as marker
// saying "i am not valid"
//
#define PRJ_USR_INVALID_VALUE (-0x7FFFFFFFL)

SctScalingStruct PrjUsrCurrentDig2Phys;

TSTATEVALUE UserState;

/*
X1= 10
Y1= 10
X2=512
Y2=500

Y2-Y1= 490

Y = Mx + B

Mm= (Y2-Y1)/(X2-X1)
0,97609561752988047809

B= Y2 - M*X2
239,043824701195219124e-3

Mi= (X2-X1)(Y2-Y1)
1,02448979591836734694


*/

//-------------------------------------------------------------------
// Main init of this module.
//
void PrjUsrInit(void)
{
  UserState = 0;

  TUCHAR Result = 0;

  // Demo usage Scaling Tool.
  //

  // SctSetScalingStruct(SctScalingStruct *pS, TSLONG32 X1, TSLONG32 Y1, TSLONG32 X2, TSLONG32 Y2, TSLONG32 Ymin, TSLONG32 Ymax);
  // Result+= SctSetScalingStruct(&PrjUsrCurrentDig2Phys, 10, 10, 512, 500);
  Result += SctSetScalingStruct(&PrjUsrCurrentDig2Phys, 5, 100, 50, 400, -10000, 10000);
  // Result+= SctSetScalingStruct(&PrjUsrCurrentDig2Phys, 25, 1425, 2109, 45189, 0, 50000);
  // Result += SctSetScalingStruct(&PrjUsrCurrentDig2Phys, 0, 300, 500, 0, 0, 50000);

#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "PrjUsrInit: %ld", SctDoScaling(&PrjUsrCurrentDig2Phys, 50));
  Serial.println(DebStr);
  sprintf(DebStr, "PrjUsrInit: %ld", SctDoScaling(&PrjUsrCurrentDig2Phys, 0));
  Serial.println(DebStr);

  TSTATEVALUE Substate = 1;
  TSLONG32 Value;
  while (Substate != 0)
  {
    SctDoScaling(&Substate, &Value, &PrjUsrCurrentDig2Phys, 50);
  }

  sprintf(DebStr, "PrjUsrInit: via SM %ld", Value);
  Serial.println(DebStr);

  SctPrintSctScalingStruct(&PrjUsrCurrentDig2Phys, "PrjUsrCurrentDig2Phys");
#endif
}

//----------------------------------------
// Constants for UserState
// #CSA
//
enum
{
  STA_POWER_UP = 0,

};

//-------------------------------------------------------------------
// Main User handler
// #HMU
//
TSTATEVALUE PrjUsrHandle(void)
{
  // static TTIMERVAL Timer;
  // static TTIMERVAL CallStaWaitTimer;

  switch (UserState)
  {
  //----------------------------------------
  //
  case STA_POWER_UP:

    break;

  //----------------------------------------
  //
  default:
    UserState = STA_POWER_UP;
  }

  return UserState;
}

// #############################################################################
// #############################################################################
// #############################################################################
