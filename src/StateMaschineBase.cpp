// #############################################################################
//  StateMaschineBase.C
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

//#include "Debug.h"

//-------------------------------------------------------------------
//
#include "StateMaschineBase.h"

//-------------------------------------------------------------------
//
TUINT16 StateMaschineBase::m_CountOfInstances = 0;


//-------------------------------------------------------------------
//
StateMaschineBase::StateMaschineBase()
{
    m_ErrorNumber = 0;

    m_InstanceId = m_CountOfInstances;

    m_CountOfInstances++;

    m_EventVector = 0;

    m_Cmd = 0xFF;
    m_State = 0xFF;
}

//-------------------------------------------------------------------
//
void StateMaschineBase::SetEvent(TUINT16 EventBitNo)
{
    m_EventVector |= (1 << EventBitNo);
}

TBOOL StateMaschineBase::IsEvent(TUINT16 EventBitNo)
{
    TUINT16 Mask = (1 << EventBitNo);
    TBOOL Result = (m_EventVector & Mask);
    m_EventVector &= (~Mask);
    return Result;
}

//-------------------------------------------------------------------
//
void StateMaschineBase::ClearEvents(void)
{
}

//-------------------------------------------------------------------
//
TUINT16 StateMaschineBase::GetInstanceId(void)
{
    return m_InstanceId;
}

//-------------------------------------------------------------------
//
TUCHAR StateMaschineBase::GetCommand(void)
{
    return m_Cmd;
}

//-------------------------------------------------------------------
//
void StateMaschineBase::SetCommand(TUCHAR Cmd)
{
    m_IsReady = FALSE;
    m_Cmd = Cmd;
}

//-------------------------------------------------------------------
//
TBOOL StateMaschineBase::GetIsReady(void)
{
    return m_IsReady;
}

//-------------------------------------------------------------------
//
TSINT16 StateMaschineBase::GetErrorNum(void)
{
    return m_ErrorNumber;
}

// #############################################################################
// #############################################################################
// #############################################################################
