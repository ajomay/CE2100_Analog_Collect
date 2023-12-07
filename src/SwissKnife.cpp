// #############################################################################
//  SwissKnife.C
//
//
//
//  Created: 18.08.2023
//  History:
//
//  (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################

#include "Debug.h"

//-------------------------------------------------------------------
//
#include "SwissKnife.h"

#include "SysTimer.h"

#include "Hdw.h"

//------------------------------------------------------------------------------------------------------------------------
// Start of functions.
//------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// Set next user state.
// Using a function for that allows debug outputs to be given out for
// every state change.
//
// WARNING: pState must not be NULL!
//
#ifdef _DEB_FLAG_DEBUG_
void SwKnSetUserState(TSTATEVALUE *pState, TSTATEVALUE NewState, const char *pComment)
{

  static TTIMERVAL TimerOld = 0;

  TTIMERVAL Timer = SysGetTime();

  if (pComment != NULL)
  {
    sprintf(DebStr, "StaChng: %d->%d dT=%ld %s", (int)(*pState), (int)NewState, Timer - TimerOld, pComment);
    Serial.println(DebStr);
  }
  else
  {
    sprintf(DebStr, "StaChng: %d->%d dT=%ld", (int)(*pState), (int)NewState, Timer - TimerOld);
    Serial.println(DebStr);
  }

  TimerOld = Timer;
  (*pState) = NewState;
}
#endif

void SwKnSetUserState(TSTATEVALUE *pState, TSTATEVALUE NewState)
{
  (*pState) = NewState;
}

/*
//--------------------------------------------------------------------------------
//
TSINT16 SwKGgt(TSINT16 a, TSINT16 b)
{
  while (b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
*/

// #############################################################################
// #############################################################################
// #############################################################################
