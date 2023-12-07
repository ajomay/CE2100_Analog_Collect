//#############################################################################
// Config.H
//
// 
//
// Created: 30.07.2023
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __Config_H_LOADED_74F8836BAE95__
#define __Config_H_LOADED_74F8836BAE95__
//#############################################################################

//-------------------------------------------------------------------
// @AMID@Config_H@_2023-08-20-1148
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//
#include "Formats.h"


//--------------------------------------------------------------------------------
// Init Config Module
//
extern void CnfInit(void);


//--------------------------------------------------------------------------------
// Save config data to internal EEPROM.
// Eep-writing uses the "update" feature, so only cells with changed contents will
// be physically written due to livetime of EEPROM cells.
//
extern void CnfSaveConfig(void);

//--------------------------------------------------------------------------------
// Load config data from internal EEPROM.
// The first found valid data set will be treated as good and rewritten to all
// redudant config data sets.
// Eep-writing uses the "update" feature, so only cells with changed contents will
// be physically written due to livetime of EEPROM cells.
//
extern void CnfLoadConfig(void);

//-------------------------------------------------------------------
//
typedef struct
{
    TUCHAR UnitAdr;
} CNF_CONFIG_STRUCT;

//--------------------------------------------------------------------------------
//
extern void CnfMakeDefaults(void);


//-------------------------------------------------------------------
//
extern CNF_CONFIG_STRUCT CnfConfig;


//#############################################################################
//#############################################################################
//#############################################################################
#endif
