// #############################################################################
//  Serial.C
//
//
//
//  Created: 19.05.2022
//  History:
//
//  (C) ce.tron Gesellschaft für Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################

#include "Debug.h"

//-------------------------------------------------------------------
//
#include "Hdw.h"

#include "Rs485.h"

//-------------------------------------------------------------------
//
#include "Ser485Slave.h"

#define SER_INTERCHR_TIMEOUT (1L * SYS_TIME_10_MSEC)
#define SER_INTERCHR_TIMEOUT_LONG (5L * SYS_TIME_1_SEC)

//-------------------------------------------------------------------
//
TSerial::TSerial(void)
{

  m_Adr = 0;

  m_State = STATE_INIT;

  m_TimLastContact = 0;

  Rs485Init();

  m_InterCharTimeout = SER_INTERCHR_TIMEOUT;
  m_SwitchToLongTimeoutCounter = 0;

#ifdef REV_FLAG_DEBUG
  SerDebStr[0] = 0;
#endif
}

//-------------------------------------------------------------------
//
bool TSerial::IsAdrValid(TUCHAR Adr)
{
  // Make sure that only characters are used that are directly consecutive in the ASCII table.
  // '@', CR and LF are not allowed as address.
  //
  if ((Adr >= '0') && (Adr <= ';'))
  {
#ifdef _DEB_FLAG_DEBUG_
    sprintf(DebStr, "TSerial::IsAdrValid: OK %d", (int)Adr);
    Serial.println(DebStr);
#endif

    return true;
  }
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "TSerial::IsAdrValid: ERR %d", (int)Adr);
  Serial.println(DebStr);
#endif
  return false;
}

//-------------------------------------------------------------------
//
void TSerial::SetAdr(TUCHAR Adr)
{
  m_Adr = Adr;

#ifdef _USE_LONG_TIMEOUT_
#pragma message "_USE_LONG_TIMEOUT_ is active"
  Serial.println("WARNING: TSerial::SetAdr(): Long Timeout is active!");
#endif

#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "TSerial::SetAdr(): Adr=0x%x", (int)m_Adr);
  Serial.println(DebStr);
  Serial.println(DebStr);
#endif

  // sprintf(DebStr, "TSerial::SetAdr(): Adr=0x%x", (int)m_Adr); Serial.println(DebStr);
}

TUCHAR TSerial::GetAdr(void)
{
  return m_Adr;
}

//-------------------------------------------------------------------
//
void TSerial::SetResponse(TSLONG32 RespValue, TUCHAR RespErr)
{
  m_Response = RespValue;
  m_RespErr = RespErr;
}

//-------------------------------------------------------------------
//

#define SENDBUF_SIZE (16L)

TSTATEVALUE TSerial::Handle(void)
{
  switch (m_State)
  {
  //----------------------------------------
  //
  case STATE_INIT:
    m_TimLastContact = SysGetTime();
    m_State = STATE_WAIT_START;
    break;

  //----------------------------------------
  //
  case STATE_WAIT_START:
    Rs485SwitchToRecMode();
    HDW_LED_BLINK_OFF();

    m_SwitchToLongTimeoutCounter = 0;

    // sprintf(DebStr, "TSerial::Handle(%d): Los!", (int)m_State); Serial.println(DebStr);
    m_State = STATE_WAIT_START_1;
    break;

  //----------------------------------------
  //
  case STATE_WAIT_START_1:
    if (Rs485IsCharAvail() > 0)
    {
      int Z = Rs485ReadChar();

      if (Z == CHAR_START)
      {
        SysStartLocalTimer(&m_Timer);
        // sprintf(DebStr, "TSerial::Handle(%d): ->STATE_WAIT_ADR", (int)m_State); Serial.println(DebStr);
        m_State = STATE_WAIT_ADR;
      }
      else
      {
        if ((Z == CHAR_SWITCH_TO_LONG_TIMEOUT))
        {
          if (m_SwitchToLongTimeoutCounter < (SW_TO_LONGTIO_COUNT - 1))
          {
            m_SwitchToLongTimeoutCounter++;
#ifdef QQQ_DEB_FLAG_DEBUG_
            sprintf(DebStr, "TSerial::Handle: $= %d", (int)(m_SwitchToLongTimeoutCounter));
            Serial.println(DebStr);
#endif
          }
          else
          {
            m_InterCharTimeout = SER_INTERCHR_TIMEOUT_LONG;
            char Msg[32];
            sprintf(Msg, "Timeout= %d ms", (int)(m_InterCharTimeout));
            Serial.println(Msg);
          }
        }
        else
        {
          m_SwitchToLongTimeoutCounter = 0;
#ifdef _DEB_FLAG_DEBUG_
          sprintf(DebStr, "TSerial::Handle: $= %d", (int)(m_SwitchToLongTimeoutCounter));
          Serial.println(DebStr);
#endif
        }
      }
      return m_State;
    }

#ifdef REV_FLAG_DEBUG
    if (SerDebStr[0] != 0)
    {
      Serial.println(SerDebStr);
      SerDebStr[0] = 0;
      m_State = STATE_SEND_DEBUG;
      return m_State;
    }
#endif

    break;

  //----------------------------------------
  //
  case STATE_WAIT_ADR:
    if (Rs485IsCharAvail() > 0)
    {
      int Z = Rs485ReadChar();
      SysStartLocalTimer(&m_Timer);

      if (Z == (int)CHAR_START)
      {
        // sprintf(DebStr, "TSerial::Handle(%d): Restart ->here", (int)m_State); Serial.println(DebStr);
        //  Stay here!
        return m_State;
      }

      // Introduced a universal address.
      if ((Z == ((int)m_Adr)) || (Z == '~'))
      {
        // sprintf(DebStr, "TSerial::Handle(%d): ->STATE_WAIT_CMD", (int)m_State); Serial.println(DebStr);
        HDW_LED_BLINK_MODE_OUTPUT();
        HDW_LED_BLINK_ON();

        m_State = STATE_WAIT_CMD;
        return m_State;
      }
      else
      {
        // sprintf(DebStr, "TSerial::Handle(%d): not me! %c", (int)m_State, (char)Z); Serial.println(DebStr);
        m_State = STATE_WAIT_START;
        return m_State;
      }
    }

    if (SysIsLocalTimeout(&m_Timer, m_InterCharTimeout))
    {
      // sprintf(DebStr, "TSerial::Handle(%d): Timeout ->STATE_WAIT_START", (int)m_State); Serial.println(DebStr);
      m_State = STATE_WAIT_START;
      return m_State;
    }
    break;

  //----------------------------------------
  //
  case STATE_WAIT_CMD:
    if (Rs485IsCharAvail() > 0)
    {
      int Z = Rs485ReadChar();
      SysStartLocalTimer(&m_Timer);

      if (Z == (int)CHAR_START)
      {
        // sprintf(DebStr, "TSerial::Handle(%d): Restart ->STATE_WAIT_ADR", (int)m_State); Serial.println(DebStr);
        m_State = STATE_WAIT_ADR;
        return m_State;
      }

      m_ReceivedCmd = (TUCHAR)(Z & 0xFF);
      m_DigitCount = 0;
      m_ReceivedPar1 = 0;
      m_ParSignum = 1;

      // Quick STOP command. No answer expected!
      //
      if (m_ReceivedCmd == '~')
      {
        m_State = STATE_WAIT_START;
        return REQ_EMERG_CMD_STOP_RECEIVED;
      }

      // sprintf(DebStr, "TSerial::Handle(%d): Cmd=%c ->STATE_WAIT_PAR", (int)m_State, m_ReceivedCmd); Serial.println(DebStr);
      m_State = STATE_WAIT_PAR;
      return m_State;
    }

    if (SysIsLocalTimeout(&m_Timer, m_InterCharTimeout))
    {
      // sprintf(DebStr, "TSerial::Handle(%d): Timeout ->STATE_WAIT_START", (int)m_State); Serial.println(DebStr);
      m_State = STATE_WAIT_START;
      return m_State;
    }
    break;

  //----------------------------------------
  //
  case STATE_WAIT_PAR:
    if (Rs485IsCharAvail() > 0)
    {
      int Z = Rs485ReadChar();
      SysStartLocalTimer(&m_Timer);

      if (Z == (int)CHAR_START)
      {
        // sprintf(DebStr, "TSerial::Handle(%d): Restart ->STATE_WAIT_ADR", (int)m_State); Serial.println(DebStr);
        m_State = STATE_WAIT_ADR;
        return m_State;
      }

      TUCHAR C = (TUCHAR)(Z & 0xFF);

      // We are ready!
      // Sign of Par1 is transfered to Par1.
      //
      if ((C == CHAR_END_1) || (C == CHAR_END_2))
      {
        m_ReceivedPar1 *= (TSLONG32)m_ParSignum;
        // sprintf(DebStr, "TSerial::Handle(%d): Cmd=%c Par=%ld ->STATE_EVAL", (int)m_State, m_ReceivedCmd, m_ReceivedPar1); Serial.println(DebStr);
        m_TimLastContact = SysGetTime();
        m_State = STATE_EVAL;
        return m_State;
      }

      // The sign can be defined at the first position of parameter.
      // Multiple sign chars in sequence are allowed.
      //
      if (m_DigitCount == 0)
      {
        if ((C == '+'))
        {
          return m_State;
        }
        else
        {
          if ((C == '-'))
          {
            m_ParSignum = -m_ParSignum;
            return m_State;
          }
        }
      }

      if ((C < '0') || (C > '9'))
      {
        // sprintf(DebStr, "TSerial::Handle(%d): ParChrErr %c", (int)m_State, C); Serial.println(DebStr);
        m_State = STATE_WAIT_START;
        return m_State;
      }

      m_DigitCount++;

      if (m_DigitCount > 9)
      {
        // sprintf(DebStr, "TSerial::Handle(%d): ParLen %d", (int)m_State, (int)m_DigitCount); Serial.println(DebStr);
        m_State = STATE_WAIT_START;
        return m_State;
      }

      m_ReceivedPar1 *= 10;
      m_ReceivedPar1 += ((TSLONG32)(C - '0'));
    }

    if (SysIsLocalTimeout(&m_Timer, m_InterCharTimeout))
    {
      // sprintf(DebStr, "TSerial::Handle(%d): Timeout ->STATE_WAIT_START", (int)m_State); Serial.println(DebStr);
      m_State = STATE_WAIT_START;
      return m_State;
    }
    break;

  //----------------------------------------
  //
  case STATE_EVAL:

    SetResponse(0, ERR_CMD_INVALID);

    m_State = STATE_SEND_RESP;
    return REQ_CMD_SET_RESONSE;

  //----------------------------------------
  //
  case STATE_SEND_RESP:
    SysStartLocalTimer(&m_Timer);
    m_State = STATE_SEND_RESP_1;
    break;

  //----------------------------------------
  //
  case STATE_SEND_RESP_1:
    if (!SysIsLocalTimeout(&m_Timer, 2L * SYS_TIME_1_MSEC))
      return (m_State);

    if (m_RespErr == 0)
    {
      char Msg[SENDBUF_SIZE];
      sprintf(Msg, "@!%ld\r\n", m_Response);
      Rs485Transmit(Msg);
    }
    else
    {
      char Msg[SENDBUF_SIZE];
      sprintf(Msg, "@?%d\r\n", (int)m_RespErr);
      Rs485Transmit(Msg);
    }
    m_State = STATE_SEND_RESP_2;
    break;

  //----------------------------------------
  //
  case STATE_SEND_RESP_2:
    /*
        if (!SysIsLocalTimeout(&m_Timer, TransmitEndurance)) return (m_State);
        Serial.flush();
        ActivateSendMode(FALSE);
    */
    if (!Rs485IsTramsmitReady())
      return m_State;

    m_State = STATE_WAIT_START;

    // !!!!
    //m_State = STATE_HURZ;

    if (m_RespErr == 0)
    {
      return REQ_CMD_POST_PROCESSING;
    }
    else
    {
      return m_State;
    }

    break;

  //----------------------------------------
  //
  case STATE_SEND_DEBUG:
    if (!Rs485IsTramsmitReady())
      return m_State;
    m_State = STATE_WAIT_START;
    break;

/*
  //----------------------------------------
  //
  case STATE_HURZ:
    SysStartLocalTimer(&m_Timer);

    m_State = STATE_HURZ_1;
    break;

  case STATE_HURZ_1:
    if (!SysIsLocalTimeout(&m_Timer, 5L * SYS_TIME_100_MSEC))
      return (m_State);

    m_State = STATE_SEND_RESP;
    break;
*/
  //----------------------------------------
  //----------------------------------------
  //
  default:
    m_State = STATE_INIT;
  }

  return m_State;
}

bool TSerial::IsPollTimeout(TTIMERVAL Time)
{
  bool Result = SysIsLocalTimeout(&m_TimLastContact, Time);

  if (Result)
  {
    m_TimLastContact = SysGetTime();
  }

  return Result;
}

// #############################################################################
// #############################################################################
// #############################################################################
