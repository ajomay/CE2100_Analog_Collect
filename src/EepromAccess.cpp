// #############################################################################
//  EepromAccess.C
//
//
//
//  Created: 27.04.2022
//  History:
//
//  (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################

//#include "Debug.h"

#include <EEPROM.h>

//-------------------------------------------------------------------
//
#include "EepromAccess.h"

//-------------------------------------------------------------------
//
EepromAccess::EepromAccess()
{
  m_CurrentAdr = 0;
}

//-------------------------------------------------------------------
//

void EepromAccess::WriteTest(void)
{
  int TestSize = 300;

  int k;

  for (k = 0; k < TestSize; k++)
  {
    int Out = (k % 251);
    EEPROM.update(k, Out);

#ifdef _DEB_FLAG_DEBUG_
    sprintf(DebStr, "WriteTest: WR %d %d ", k, Out);
    Serial.println(DebStr);
#endif
  }

#ifdef _DEB_FLAG_DEBUG_
  for (k = 0; k < TestSize; k++)
  {
    int Z = EEPROM.read(k);
    sprintf(DebStr, "WriteTest: RD %d %d ", k, Z);
    Serial.println(DebStr);
  }
#endif
}

//-------------------------------------------------------------------
//
void EepromAccess::SetCurrentAddress(int CurrentAddress)
{
  m_CurrentAdr = CurrentAddress;
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::SetCurrentAddress(): %d", m_CurrentAdr);
  Serial.println(DebStr);
#endif
}

//-------------------------------------------------------------------
//
TCrc16::CRC16 EepromAccess::WriteBlockToCurrentAddress(TUCHAR *pSrc, TSINT16 CountToWrite)
{
  // sprintf(DebStr, "EepromAccess::WriteBlockToCurrentAddress(): %d", CountToWrite); Serial.println(DebStr);

  TSINT16 k;

  TCrc16 Crc;

  TUCHAR C;

  TSINT16 SaveStartAdr = m_CurrentAdr;

  // Write m_CurrentAdr as 'salt'.
  //
  C = (TUCHAR)(m_CurrentAdr & 0xFF);
  EEPROM.update(m_CurrentAdr, C);
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::WriteBlockToCurrentAddress(): %d %.2x", m_CurrentAdr, (int)C);
  Serial.println(DebStr);
#endif
  m_CurrentAdr++;
  Crc.DoStreamingCrc(C);

  for (k = 0; k < CountToWrite; k++)
  {
    C = pSrc[k];
    EEPROM.update(m_CurrentAdr, C);
#ifdef _DEB_FLAG_DEBUG_
    sprintf(DebStr, "EepromAccess::WriteBlockToCurrentAddress(): %d %.2x", m_CurrentAdr, (int)C);
    Serial.println(DebStr);
#endif
    m_CurrentAdr++;
    Crc.DoStreamingCrc(C);
  }

  C = Crc.GetCrcL();
  EEPROM.update(m_CurrentAdr, C);
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::WriteBlockToCurrentAddress(): %d %.2x", m_CurrentAdr, (int)C);
  Serial.println(DebStr);
#endif
  m_CurrentAdr++;

  C = Crc.GetCrcH();
  EEPROM.update(m_CurrentAdr, C);
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::WriteBlockToCurrentAddress(): %d %.2x", m_CurrentAdr, (int)C);
  Serial.println(DebStr);
#endif
  m_CurrentAdr++;
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::WriteBlockToCurrentAddress(): Next: %d", m_CurrentAdr);
  Serial.println(DebStr);
#endif

  SetCurrentAddress(SaveStartAdr);

  TCrc16::CRC16 CrcVerifikation = ReadBlockFromCurrentAddress(NULL, CountToWrite);

#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::WriteBlockToCurrentAddress(): %d %.4x", m_CurrentAdr, (int)CrcVerifikation);
  Serial.println(DebStr);
#endif

  return CrcVerifikation;
}

//-------------------------------------------------------------------
//
TCrc16::CRC16 EepromAccess::ReadBlockFromCurrentAddress(TUCHAR *pSrc, TSINT16 CountToRead)
{
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::ReadBlockFromCurrentAddress(): %d", CountToRead);
  Serial.println(DebStr);
#endif

  TSINT16 k;

  TCrc16 Crc;

  TUCHAR C;

  TSINT16 TargetAdr = 0;

  // Read 'salt'.
  //
  C = EEPROM.read(m_CurrentAdr);
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::ReadBlockFromCurrentAddress(): %d %.2x", m_CurrentAdr, (int)C);
  Serial.println(DebStr);
#endif
  m_CurrentAdr++;
  Crc.DoStreamingCrc(C);

  // Read data and store.
  for (k = 0; k < CountToRead; k++)
  {
    C = EEPROM.read(m_CurrentAdr);
#ifdef _DEB_FLAG_DEBUG_
    sprintf(DebStr, "EepromAccess::ReadBlockFromCurrentAddress(): %d %.2x", m_CurrentAdr, (int)C);
    Serial.println(DebStr);
#endif
    m_CurrentAdr++;
    Crc.DoStreamingCrc(C);

    if (pSrc != NULL)
    {
      pSrc[TargetAdr++] = C;
    }
  }

  // Read CRC-L.
  //
  C = EEPROM.read(m_CurrentAdr);
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::ReadBlockFromCurrentAddress(): %d %.2x", m_CurrentAdr, (int)C);
  Serial.println(DebStr);
#endif
  m_CurrentAdr++;
  Crc.DoStreamingCrc(C);

  // Read CRC-H.
  //
  C = EEPROM.read(m_CurrentAdr);
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::ReadBlockFromCurrentAddress(): %d %.2x", m_CurrentAdr, (int)C);
  Serial.println(DebStr);
#endif
  m_CurrentAdr++;
  Crc.DoStreamingCrc(C);
#ifdef _DEB_FLAG_DEBUG_
  sprintf(DebStr, "EepromAccess::ReadBlockFromCurrentAddress(): CRC= %.4x", Crc.GetCrc());
  Serial.println(DebStr);
  sprintf(DebStr, "EepromAccess::ReadBlockFromCurrentAddress(): Next: %d", m_CurrentAdr);
  Serial.println(DebStr);
#endif

  return Crc.GetCrc();
}

// #############################################################################
// #############################################################################
// #############################################################################
