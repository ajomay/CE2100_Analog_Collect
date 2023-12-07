//#############################################################################
// SwissKnife.H
//
// 
//
// Created: 18.08.2023
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __SwissKnife_H_LOADED_8D856DFF5F8A__
#define __SwissKnife_H_LOADED_8D856DFF5F8A__
//#############################################################################

//-------------------------------------------------------------------
//
#include "Formats.h"


//-------------------------------------------------------------------
//

//--------------------------------------------------------------------------------
// Set next user state.
// Using a function for that allows debug outputs to be given out for
// every state change.
//
// WARNING: pState must not be NULL!
//
extern void SwKnSetUserState(TSTATEVALUE *pState, TSTATEVALUE NewState, const char *pComment);
extern void SwKnSetUserState(TSTATEVALUE *pState, TSTATEVALUE NewState);

#ifdef _DEB_FLAG_DEBUG_
#define SwKnSetUserState_(pTgtSta, NewSta, Cmmt) SwKnSetUserState(pTgtSta, NewSta, Cmmt)
#else
#define SwKnSetUserState_(pTgtSta, NewSta, Cmmt) SwKnSetUserState(pTgtSta, NewSta)
#endif


//--------------------------------------------------------------------------------
//
//extern TSINT16 SwKGgt(TSINT16 a, TSINT16 b);


//#############################################################################
//#############################################################################
//#############################################################################
#endif

