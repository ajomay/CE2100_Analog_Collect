//#############################################################################
// Config.C
//
//
//
// Created: 30.07.2023
// History:
//
// (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################

#include "Debug.h"


#include "EepromAccess.h"


//-------------------------------------------------------------------
//
#include "Config.h"


CNF_CONFIG_STRUCT CnfConfig;

//-------------------------------------------------------------------
//

#define COUNT_REDUNDANT_SETS 3

// Start address in EEPROM should not be 0,
// because adresss 0 is damaged more often than others
#define EEPROM_START_ADR 1


//--------------------------------------------------------------------------------
// Init Config Module
//
void CnfInit(void)
  {
    CnfMakeDefaults();
  }

//--------------------------------------------------------------------------------
// Save config data to internal EEPROM.
// Eep-writing uses the "update" feature, so only cells with changed contents will
// be physically written due to livetime of EEPROM cells.
//
void CnfSaveConfig(void)
{
  // Access tool.
  EepromAccess Eep;

  TSINT16 k;

  Eep.SetCurrentAddress(EEPROM_START_ADR);

  // Write all redudant data sets.
  //
  for (k = 0; k < COUNT_REDUNDANT_SETS; k++)
  {
    //TCrc16::CRC16 Crc;
    // Loading calibration is currently skipped.
    // A fixed calibration is loaded in CurInit();
    // Crc = Eep.WriteBlockToCurrentAddress((TUCHAR*)&MxHallOberve, sizeof(MxHallOberve));

    //Crc = Eep.WriteBlockToCurrentAddress((TUCHAR*)&CnfConfig, sizeof(CnfConfig));
    //sprintf(DebStr, "CnfSaveConfig(): %d %.4X", k, (unsigned int)Crc); Serial.println(DebStr);
    Eep.WriteBlockToCurrentAddress((TUCHAR*)&CnfConfig, sizeof(CnfConfig));
  }
}


//--------------------------------------------------------------------------------
// Load config data from internal EEPROM.
// The first found valid data set will be treated as good and rewritten to all
// redudant config data sets.
// Eep-writing uses the "update" feature, so only cells with changed contents will
// be physically written due to livetime of EEPROM cells.
//
void CnfLoadConfig(void)
{

  // Access tool.
  EepromAccess Eep;

  TSINT16 k;

  Eep.SetCurrentAddress(EEPROM_START_ADR);

  // Search at least one valid config data set.
  //
  for (k = 0; k < COUNT_REDUNDANT_SETS; k++)
  {
    TCrc16::CRC16 Crc;
    // Loading calibration is currently skipped.
    // A fixed calibration is loaded in CurInit();
    // Crc = Eep.ReadBlockFromCurrentAddress((TUCHAR*)&MxHallOberve, sizeof(MxHallOberve));

    Crc = Eep.ReadBlockFromCurrentAddress((TUCHAR*)&CnfConfig, sizeof(CnfConfig));


    //sprintf(DebStr, "CnfLoadConfig(): %d %.4X", k, (unsigned int)Crc); Serial.println(DebStr);
    if (Crc == 0)
    {
      CnfSaveConfig();
      return;
    }
  }

  //sprintf(DebStr, "CnfLoadConfig(): no valid config found!"); Serial.println(DebStr);
  CnfMakeDefaults();
  CnfSaveConfig();
}


//--------------------------------------------------------------------------------
//
void CnfMakeDefaults(void)
{
  //sprintf(DebStr, "CnfMakeDefaults(): generating defaults."); Serial.println(DebStr);
  
  CnfConfig.UnitAdr= '1';
}


//#############################################################################
//#############################################################################
//#############################################################################
