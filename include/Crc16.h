//#############################################################################
// Crc16.H
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
#ifndef __Crc16_H_LOADED_6BCB374F5DB9__
#define __Crc16_H_LOADED_6BCB374F5DB9__
//#############################################################################


//-------------------------------------------------------------------
// @AMID@Crc16_H@_2023-08-18-0940 Class TCrc16
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//
#include "Formats.h"


//-------------------------------------------------------------------
//

class TCrc16
{

  public:

    TCrc16();

    typedef unsigned short int CRC16;

    CRC16 DoCrc(unsigned char *data, int len);
    // unsigned short int   AddCrc(unsigned char *data, int len);

    void   ResetCrc(void);
    CRC16   GetCrc(void);
    unsigned char GetCrcH(void);
    unsigned char GetCrcL(void);

    CRC16 DoStreamingCrc(unsigned char C);

    enum {StartValue = 0xFFFF};

  private:

    CRC16 m_Crc;

};


//#############################################################################
//#############################################################################
//#############################################################################
#endif
