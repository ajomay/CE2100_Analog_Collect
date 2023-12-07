// #############################################################################
//  SpiControl.C
//
//
//
//  Created: 27.11.2023
//  History:
//
//  (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################

#include "Debug.h"

//-------------------------------------------------------------------
//

#include <SPI.h>

#include "Hdw.h"

#include "SpiControl.h"

#define SPICTRL_SPI_SETTING SPISettings(400000, MSBFIRST, SPI_MODE3)

enum
{
    SPICNTRL_STA_INIT = 0,

    SPICNTRL_STA_WAIT_ACTION,

    SPICNTRL_STA_TRANSMIT,

};

//--------------------------------------------------------------------------------
//
SPI_CNTRL_STRUCT SpiControlStruct;

//-------------------------------------------------------------------
//
void SpiCtrlInit(void)
{
    SPI.begin();

    SpiControlStruct.State = SPICNTRL_STA_INIT;

// Generate an active access to address 0 to
// create an RESET-Signal for all SPI Bus devices. 
    HDW_SPIBUS_A0_OFF();   
    HDW_SPIBUS_A1_OFF();   
    HDW_SPIBUS_A2_OFF();   

    HDW_SPIBUS_A0_MODE_OUTPUT();
    HDW_SPIBUS_A1_MODE_OUTPUT();
    HDW_SPIBUS_A2_MODE_OUTPUT();

    HDW_SPIBUS_GO_ACTIVE();
    HDW_SPIBUS_GO_MODE_OUTPUT();

    delay(1);

}


//-------------------------------------------------------------------
//
void SpiCtrlSetAdrLines(TUCHAR Address)
    {
        if ((Address&0x01)!=0)
            {
             HDW_SPIBUS_A0_ON();   
            }
            else
            {
             HDW_SPIBUS_A0_OFF();   
            }
        HDW_SPIBUS_A0_MODE_OUTPUT();

        if ((Address&0x02)!=0)
            {
             HDW_SPIBUS_A1_ON();   
            }
            else
            {
             HDW_SPIBUS_A1_OFF();   
            }
        HDW_SPIBUS_A1_MODE_OUTPUT();

        if ((Address&0x04)!=0)
            {
             HDW_SPIBUS_A2_ON();   
            }
            else
            {
             HDW_SPIBUS_A2_OFF();   
            }
        HDW_SPIBUS_A2_MODE_OUTPUT();

    }


//-------------------------------------------------------------------
//
void SpiCtrlHandle(void)
{
    switch (SpiControlStruct.State)
    {

        //----------------------------------------
    case SPICNTRL_STA_INIT:
#ifdef _DEB_FLAG_DEBUG_
        sprintf(DebStr, "SpiCtrlHandle: %d", (int)(SpiControlStruct.State));
        Serial.println(DebStr);
#endif

        for (int i = 0; i < SPICNTRL_COUNT_DTA; i++)
        {
            SpiControlStruct.SpiValues[i] = 0;
        }
        SpiControlStruct.StartTransmissionNow = FALSE;
        SpiControlStruct.Adr= 3;
        SpiControlStruct.Timer = SysGetTime();
        SpiControlStruct.State = SPICNTRL_STA_WAIT_ACTION;

/*
// Just for debug...
        SpiControlStruct.SpiValues[0] = 1;
        SpiControlStruct.SpiValues[1] = 3;
        SpiControlStruct.SpiValues[2] = 7;
        SpiControlStruct.SpiValues[3] = 0xAA;
*/        
        break;

        //----------------------------------------
    case SPICNTRL_STA_WAIT_ACTION:
        if ((SysIsLocalTimeout(&SpiControlStruct.Timer, 5L * SYS_TIME_100_MSEC)) || (SpiControlStruct.StartTransmissionNow))
        {
            SpiControlStruct.State = SPICNTRL_STA_TRANSMIT;
            break;
        }
        break;

    //----------------------------------------
    case SPICNTRL_STA_TRANSMIT:
#ifdef QQQ_DEB_FLAG_DEBUG_
        sprintf(DebStr, "SpiCtrlHandle: Transmit start %d", (int)(DebInt++));
        Serial.println(DebStr);
#endif

        SPI.beginTransaction(SPICTRL_SPI_SETTING);
        SpiCtrlSetAdrLines(SpiControlStruct.Adr);
        HDW_SPIBUS_GO_ACTIVE();
        HDW_SPIBUS_GO_MODE_OUTPUT();

        for (int i = 0; i < SPICNTRL_COUNT_DTA; i++)
        {
#ifdef QQQ_DEB_FLAG_DEBUG_
            sprintf(DebStr, "SpiCtrlHandle: Transmit tx %d", (int)(i));
            Serial.println(DebStr);
#endif
            SPI.transfer(SpiControlStruct.SpiValues[i]);
        }
#ifdef QQQ_DEB_FLAG_DEBUG_
        sprintf(DebStr, "SpiCtrlHandle: Transmit end 1 %d", (int)(pRelCntrl->State));
        Serial.println(DebStr);
#endif
        HDW_SPIBUS_GO_INACTIVE();
        SPI.endTransaction();
        SpiCtrlSetAdrLines(0);


#ifdef QQQ_DEB_FLAG_DEBUG_
        sprintf(DebStr, "SpiCtrlHandle: Transmit end 2 %d", (int)(pRelCntrl->State));
        Serial.println(DebStr);
#endif

        SpiControlStruct.Timer = SysGetTime();
        SpiControlStruct.StartTransmissionNow = FALSE;
        SpiControlStruct.State = SPICNTRL_STA_WAIT_ACTION;
        break;

        //----------------------------------------
        //----------------------------------------
    default:
        SpiControlStruct.State = 0;
    };
}

// #############################################################################
// #############################################################################
// #############################################################################
