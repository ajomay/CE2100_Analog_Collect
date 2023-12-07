// #############################################################################
//  _StaTemplate.C
//
//
//
//  Created: 17.08.2023
//  History:
//
//  (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################

//#include "Debug.h"

//-------------------------------------------------------------------
//
#include "_StaTemplate.h"

#include "SwissKnife.h"

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
//
_StaTemplate::_StaTemplate()
{
    m_Cmd = CMD_NOT_YET_DEFINED;
};

//-------------------------------------------------------------------
//
void _StaTemplate::Init(void)
{
    m_Cmd = CMD_NOT_YET_DEFINED;
    m_IsReady = FALSE;
    m_ErrorNumber = ERR_OK;
    ClearEvents();

    SwKnSetUserState_(&m_State, STA_POWER_UP, "_StaTemplate::Init()");
};


//-------------------------------------------------------------------
//
TSTATEVALUE _StaTemplate::Handle(void)
{
    switch (m_State)
    {
        //----------------------------------------
    case STA_POWER_UP:
        m_Cmd = CMD_NOT_YET_DEFINED;
        m_IsReady = FALSE;
        SwKnSetUserState_(&m_State, STA_ENTER_WAIT_ACTION, "_StaTemplate::Handle()");
        break;

        //----------------------------------------
    case STA_ENTER_WAIT_ACTION:
        SwKnSetUserState_(&m_State, STA_ENTER_WAIT_ACTION_1, "_StaTemplate::Handle()");
        break;

        //----------------------------------------
    case STA_ENTER_WAIT_ACTION_1:
        m_Cmd = CMD_READY;
        SwKnSetUserState_(&m_State, STA_WAIT_ACTION, "_StaTemplate::Handle()");
        break;

        //----------------------------------------
    case STA_WAIT_ACTION:
        if (m_Cmd == CMD_READY)
        {
            m_IsReady = TRUE;
            break;
        }

        m_ErrorNumber = ERR_OK;
        m_IsReady = FALSE;

        switch (m_Cmd)
        {
        case CMD_DO_SOMETHING:
            SwKnSetUserState_(&m_State, STA_DO_SOMETHING, "_StaTemplate::Handle()");
            break;

        default:
            m_ErrorNumber = ERR_INVALID_CMD;
            SwKnSetUserState_(&m_State, STA_ENTER_WAIT_ACTION, "_StaTemplate::Handle()");
            break;
        }

        break;

        //----------------------------------------
    case STA_DO_SOMETHING:

        SwKnSetUserState_(&m_State, STA_ENTER_WAIT_ACTION, "_StaTemplate::Handle()");

        break;

        //----------------------------------------
        //----------------------------------------
    default:
        SwKnSetUserState_(&m_State, STA_POWER_UP, "_StaTemplate::Handle() DEFAULT");
        break;
    }

    return m_State;
}

// #############################################################################
// #############################################################################
// #############################################################################
