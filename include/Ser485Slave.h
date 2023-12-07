// #############################################################################
//  Serial.H
//
//
//
//  Created: 19.05.2022
//  History:
//
//  (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################
#ifndef __Ser485Slave_H_LOADED_10414BB8A0E5__
#define __Ser485Slave_H_LOADED_10414BB8A0E5__
// #############################################################################

//----------------------------------------
// @AMID@Ser485Slave_H@_2023-09-03-1201
//----------------------------------------

//--------------------------------------------------------------------------------
// <AM-2023-08-31-1857>:
// - Added REQ_EMERG_CMD_STOP_RECEIVED to run quick emergency off commands.
//
// <AM-2023-09-03-1201>
// - Added runtime switch to long ichr-timeout with 10 '$' signs.
//--------------------------------------------------------------------------------

#include <Arduino.h>

//-------------------------------------------------------------------
//
#include "Formats.h"

#include "SysTimer.h"

extern TUCHAR UnitAdr;

//-------------------------------------------------------------------
// NO LONGER VALID!
// Press 10 times '$' at runtime instead.
// #define _USE_LONG_TIMEOUT_ 1

//-------------------------------------------------------------------
//
class TSerial
{
  //-------------------------------------------------------------------
  //
public:
  //-------------------------------------------------------------------
  // Constructor
  //
  TSerial();

  //-------------------------------------------------------------------
  //
  bool IsAdrValid(TUCHAR Adr);

  //-------------------------------------------------------------------
  // States and requests
  //
  enum
  {
    STATE_INIT = 0,
    STATE_WAIT_START,
    STATE_WAIT_START_1,
    STATE_WAIT_ADR,
    STATE_WAIT_CMD,
    STATE_WAIT_PAR,
    STATE_EVAL,
    STATE_SEND_RESP,
    STATE_SEND_RESP_1,
    STATE_SEND_RESP_2,

    STATE_SEND_DEBUG,

    //STATE_HURZ,
    //STATE_HURZ_1,

    REQ_CMD_SET_RESONSE = 128,
    REQ_CMD_POST_PROCESSING,

    // This is fired directly when '~' follwows
    // the address or the universal address.
    // Dont respond to this!
    REQ_EMERG_CMD_STOP_RECEIVED,

  } States;

  //-------------------------------------------------------------------
  // Handler to call in loop()
  //
  TSTATEVALUE Handle(void);

  //-------------------------------------------------------------------
  // Set address to use
  //
  void SetAdr(TUCHAR Adr);
  TUCHAR GetAdr(void);

  //-------------------------------------------------------------------
  // Called from main dispatcher after creating a response.
  //
  void SetResponse(TSLONG32 RespValue, TUCHAR RespErr);

  //-------------------------------------------------------------------
  // Type of response.
  //
  enum
  {
    ERR_OK = 0,
    ERR_CMD_INVALID,
    ERR_VALUE_INVALID,
    ERR_NOT_ALLOWED,
  } Errors;

  //-------------------------------------------------------------------
  // Infos for dispatcher.
  //
  TUCHAR m_ReceivedCmd;
  TSLONG32 m_ReceivedPar1;
  TSCHAR m_ParSignum;

  //-------------------------------------------------------------------
  // Checks for Timeout of last contact to host.
  //
  bool IsPollTimeout(TTIMERVAL Time);

  //-------------------------------------------------------------------
  //
private:
  TUCHAR m_Adr;

  TSTATEVALUE m_State;

  TTIMERVAL m_TimLastContact;

  enum TimeOutManagement
  {
    SW_TO_LONGTIO_COUNT = 10
  };

  TTIMERVAL m_InterCharTimeout;
  TUCHAR m_SwitchToLongTimeoutCounter;

  // TSTATEVALUE m_DelayedRequest;

  // void ActivateSendMode(TBOOL On);

  // void ActivateReceiver(void);

  enum
  {
    CHAR_START = '@',
    CHAR_END_1 = 13,
    CHAR_END_2 = 10,
    CHAR_SWITCH_TO_LONG_TIMEOUT = '$',
  } Chars;

  TUCHAR m_DigitCount;

  TTIMERVAL m_Timer;

  TSLONG32 m_Response;
  TUCHAR m_RespErr;
};

// #############################################################################
// #############################################################################
// #############################################################################
#endif
