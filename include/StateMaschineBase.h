// #############################################################################
//  StateMaschineBase.H
//
//
//
//  Created: 18.08.2023
//  History:
//
//  (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################
#ifndef __StateMaschineBase_H_LOADED_9B5DCC68745A__
#define __StateMaschineBase_H_LOADED_9B5DCC68745A__
// #############################################################################

//-------------------------------------------------------------------
//
#include "Formats.h"

#include "SysTimer.h"

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
//

class StateMaschineBase
{

    //--------------------------------------------------------------------------------
public:
    //-------------------------------------------------------------------
    // THIS MUST BE OVERWRITTEN IN DERIVED CLASS!!
    //
    virtual void Init(void){Serial.println("Init() MUST BE OVERWRITTEN");};

    //-------------------------------------------------------------------
    // THIS MUST BE OVERWRITTEN IN DERIVED CLASS!!
    //
    virtual TSTATEVALUE Handle(void) { Serial.println("Handle() MUST BE OVERWRITTEN"); return 0;}; 

    //-------------------------------------------------------------------
    //
    StateMaschineBase();

    //-------------------------------------------------------------------
    //
    TUCHAR GetCommand(void);
    void SetCommand(TUCHAR Cmd);

    //-------------------------------------------------------------------
    //
    TBOOL GetIsReady(void);

    //-------------------------------------------------------------------
    //
    TSINT16 GetErrorNum(void);

    //-------------------------------------------------------------------
    //
    void SetEvent(TUINT16 EventBitNo);
    TBOOL IsEvent(TUINT16 EventBitNo);
    void ClearEvents(void);

    //-------------------------------------------------------------------
    //
    TUINT16 GetInstanceId(void);

    //--------------------------------------------------------------------------------
protected:
    TUCHAR m_Cmd;

    TSTATEVALUE m_State;

    bool m_IsReady;
    TSINT16 m_ErrorNumber;

    //--------------------------------------------------------------------------------
private:
    static TUINT16 m_CountOfInstances;

    TUINT16 m_EventVector;

    TUINT16 m_InstanceId;
};

// #############################################################################
// #############################################################################
// #############################################################################
#endif
