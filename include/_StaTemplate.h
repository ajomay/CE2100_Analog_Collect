// #############################################################################
//  _StaTemplate.H
//
//
//
//  Created: 17.08.2023
//  History:
//
//  (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################
#ifndef ___StaTemplate_H_LOADED_A24ECF3A5D33__
#define ___StaTemplate_H_LOADED_A24ECF3A5D33__
// #############################################################################

//-------------------------------------------------------------------
// @AMID@StaTemplate_H@2023-08-18-0923
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//
#include "Formats.h"

#include "SysTimer.h"

#include "StateMaschineBase.h"

//-------------------------------------------------------------------
//

class _StaTemplate : public StateMaschineBase
{

    //--------------------------------------------------------------------------------

public:
    //-------------------------------------------------------------------
    //
    _StaTemplate();

    //-------------------------------------------------------------------
    //
    void Init(void);

    //-------------------------------------------------------------------
    //
    TSTATEVALUE Handle(void);

    enum Commands
    {
        CMD_READY,
        CMD_DO_SOMETHING,

        CMD_NOT_YET_DEFINED= 0xFF,
    };

    enum States
    {
        STA_POWER_UP = 0,

        STA_ENTER_WAIT_ACTION,
        STA_ENTER_WAIT_ACTION_1,

        STA_WAIT_ACTION,

        STA_DO_SOMETHING,

        REQ_BASE = 128,

        STA_GO_DEFAULT = 255,

    };

    enum Errors
    {
        ERR_OK = 0,

        ERR_INVALID_CMD,
    };

    //-------------------------------------------------------------------
    //

    // Use this approach to do parameters or results for commands.
    //
    // TSINT16 CmdPar1;
    // TSLONG32 CmdPar2;

    // TSINT16 CmdRes1;
    // TSINT16 CmdRes2;

    //--------------------------------------------------------------------------------

protected:
/*
    TUCHAR m_Cmd;

    TSTATEVALUE m_State;

    TTIMERVAL m_HandleTimer;

    bool m_IsReady;
    TSINT16 ErrorNumber;
    */
};

// #############################################################################
// #############################################################################
// #############################################################################
#endif
