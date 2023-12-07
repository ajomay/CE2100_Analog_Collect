
#include "Formats.h"

#include "Debug.h"

#include "Hdw.h"

#include "Led.h"

#include "Config.h"

#include "Prj_User.h"

#include "SpiControl.h"

#include "Ser485Slave.h"
#include "SerialSlaveCommands.h"

//-------------------------------------------------------------------
//
extern TBOOL DebIsDebugMode;


//--------------------------------------------------------------------------------
// Serial Communication
//
TSerial SerIf;



//------------------------------------------------------------------------------------------------------------------------
// Setup
//------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//
//
void setup()
{

  LedFlashes();

#ifndef _DEB_FLAG_DEBUG_
  LedMorseVersion(REV_MAIN, REV_SUB);
  delay(500);
#endif

  // Open serial communications and wait for port to open:
  Serial.begin(REV_SERIAL_PORT_SPEED);

  // wait for serial port to connect. Needed for native USB port only
  while (!Serial)
  {
  };

  {
    Serial.println("");
    char OutStr[80];
#ifdef _DEB_FLAG_DEBUG_
    sprintf(OutStr, "### CE2100_Analog_Collect DEBUG V%d.%d ID=%.8lX ###", REV_MAIN, REV_SUB, REV_SW_ID_DEC);
#else
    sprintf(OutStr, "### CE2100_Analog_Collect V%d.%d ID=%.8lX ###", REV_MAIN, REV_SUB, REV_SW_ID_DEC);
#endif

    Serial.println(OutStr);
    Serial.print("Loading...");
  }

  //----------------------------------------
// Load configuration.
//
  CnfLoadConfig();

  //----------------------------------------
  // Set unit address
  //
  SerIf.SetAdr(CnfConfig.UnitAdr);

#ifndef _DEB_FLAG_DEBUG_
  delay(1500);

  LedMorseValue(SerIf.GetAdr());
#endif

  {
    char OutStr[40];
    sprintf(OutStr, " Adr: '%c' (0x%.2x). Ok!", SerIf.GetAdr(), (int)SerIf.GetAdr());

    Serial.println(OutStr);
  }

  //----------------------------------------
  //
  PrjUsrInit();

  SpiCtrlInit();
}

//------------------------------------------------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------------------------------------------------
// Loop
//------------------------------------------------------------------------------------------------------------------------

//
//
void loop()
{
  //--------------------------------------------------------------------------------
  // Handle Serial Port
  //
  {

    static TSTATEVALUE SerRequest = 0;

    SerRequest = SerIf.Handle();

    if (SerRequest == TSerial::REQ_CMD_SET_RESONSE)
    {
      switch (SerIf.m_ReceivedCmd)
      {
      //----------------------------------------
      case SerialSlaveCommands::CMD_GET_ALIVE:
      {
        TSLONG32 AliveResponse = 42;

        if (DebIsDebugMode)
        {
          AliveResponse += 100;
        }

#ifdef _ALLOW_QUICK_ALLWAYS_TRUE
        AliveResponse += 10000;
#endif

        SerIf.SetResponse(AliveResponse, TSerial::ERR_OK);
      }
      break;

      //----------------------------------------
      case SerialSlaveCommands::CMD_GET_ID:
      {
        SerIf.SetResponse(REV_SW_ID_DEC, TSerial::ERR_OK);
      }
      break;

      //----------------------------------------
      case SerialSlaveCommands::CMD_GET_LASTERR_NUM:
        // SerIf.SetResponse((TSLONG32)DevStepper.GetErrorNum(), TSerial::ERR_OK);
        SerIf.SetResponse((TSLONG32)424242, TSerial::ERR_OK);
        break;

      //----------------------------------------
      case SerialSlaveCommands::CMD_SET_DEV_ADDR:
        // Too keep Cmd N compatible with older versions, single digit params are ok....
        if ((SerIf.m_ReceivedPar1 > 0) && (SerIf.m_ReceivedPar1 < 10))
        {
          CnfConfig.UnitAdr = '0' + ((int)SerIf.m_ReceivedPar1);
          SerIf.SetAdr(CnfConfig.UnitAdr);
          SerIf.SetResponse(SerIf.m_ReceivedPar1, TSerial::ERR_OK);
        }
        else
        {
          // This is the modern way to go....
          if (
              ((SerIf.m_ReceivedPar1 >= 65) && (SerIf.m_ReceivedPar1 <= 90)) ||
              ((SerIf.m_ReceivedPar1 >= 97) && (SerIf.m_ReceivedPar1 <= 122)) ||
              ((SerIf.m_ReceivedPar1 > 48) && (SerIf.m_ReceivedPar1 <= 57)))
          {
            CnfConfig.UnitAdr = ((int)SerIf.m_ReceivedPar1);
            SerIf.SetAdr(CnfConfig.UnitAdr);
            SerIf.SetResponse(SerIf.m_ReceivedPar1, TSerial::ERR_OK);
          }
          else
          {
            SerIf.SetResponse(0, TSerial::ERR_VALUE_INVALID);
          }
        }
#ifdef _DEB_FLAG_DEBUG_
        sprintf(DebStr, "loop: %d '%c'", (int)(CnfConfig.UnitAdr), (char)CnfConfig.UnitAdr);
        Serial.println(DebStr);
#endif
        break;

      //----------------------------------------
      case SerialSlaveCommands::CMD_SAVE_EEPROM:
        SerIf.SetResponse(0, TSerial::ERR_OK);
        CnfSaveConfig();
        break;

      //----------------------------------------
      case SerialSlaveCommands::CMD_FACTORY_RESET:
        if (SerIf.m_ReceivedPar1 == 12345678)
        {
          CnfMakeDefaults();
          SerIf.SetResponse(SerIf.m_ReceivedPar1, TSerial::ERR_OK);
        }
        else
        {
          SerIf.SetResponse(0, TSerial::ERR_VALUE_INVALID);
        }
        break;

      //----------------------------------------
      case SerialSlaveCommands::CMD_GET_COMMAND:
        // SerIf.SetResponse((TSLONG32)DevStepper.GetCommand(), TSerial::ERR_OK);
        SerIf.SetResponse((TSLONG32)424243, TSerial::ERR_OK);
        break;

      //----------------------------------------
      case SerialSlaveCommands::CMD_SET_COMMAND:
        if ((SerIf.m_ReceivedPar1 >= 0) && (SerIf.m_ReceivedPar1 < 10))
        {
          // DevStepper.SetCommand((TUCHAR)SerIf.m_ReceivedPar1);
          SerIf.SetResponse(SerIf.m_ReceivedPar1, TSerial::ERR_OK);
        }
        else
        {
          SerIf.SetResponse(0, TSerial::ERR_VALUE_INVALID);
        }
        break;

        // *** End of switch(SerIf.m_ReceivedCmd) ***
      }; // switch (SerIf.m_ReceivedCmd)
    }

    if (SerRequest == TSerial::REQ_CMD_POST_PROCESSING)
    {
      // sprintf(DebStr, "REQ_CMD_POST_PROCESSING %c", SerIf.m_ReceivedCmd); Serial.println(DebStr);
      switch (SerIf.m_ReceivedCmd)
      {
      case CMD_SAVE_EEPROM:
        CnfSaveConfig();
        break;
      }
    }
  }


  SpiCtrlHandle();
}
