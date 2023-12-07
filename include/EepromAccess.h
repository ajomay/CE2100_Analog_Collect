//#############################################################################
// EepromAccess.H
//
// 
//
// Created: 27.04.2022
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __EepromAccess_H_LOADED_B017921662CD__
#define __EepromAccess_H_LOADED_B017921662CD__
//#############################################################################

//-------------------------------------------------------------------
// @AMID@EepromAccess_H@_2023-08-20-1207
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//
#include "Formats.h"

#include "Crc16.h"

//-------------------------------------------------------------------
//

class EepromAccess
{

  public:

    EepromAccess();

    void WriteTest(void);

    void SetCurrentAddress(TSINT16 CurrentAddress);

    TCrc16::CRC16 WriteBlockToCurrentAddress(TUCHAR *pSrc, TSINT16 CountToWrite);

    TCrc16::CRC16 ReadBlockFromCurrentAddress(TUCHAR *pSrc, TSINT16 CountToRead);

  private:

  TSINT16 m_CurrentAdr;

};




//#############################################################################
//#############################################################################
//#############################################################################
#endif
