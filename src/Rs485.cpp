//#############################################################################
// Rs485.C
//
//
//
// Created: 25.07.2023
// History:
//
// (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################

//-------------------------------------------------------------------
//
#include "Rs485.h"



#ifdef RS485_CPU_CONTROLLINO
#include <Controllino.h>
#include <SPI.h>
#endif

#include "Hdw.h"


//-------------------------------------------------------------------
//
#ifdef RS485_CPU_CONTROLLINO
void Rs485Init(long baud)
{
  Controllino_RS485Init(baud);
  Controllino_RS485RxEnable();
}
#endif

//-------------------------------------------------------------------
//
#ifdef RS485_CPU_ARDUINO
void Rs485Init(void)
{
  Rs485SwitchToRecMode();
}
#endif

//-------------------------------------------------------------------
//
bool Rs485IsCharAvail()
{
#ifdef RS485_CPU_CONTROLLINO
  return Serial3.available();
#endif

#ifdef RS485_CPU_ARDUINO
  return Serial.available();
#endif
  
}
//-------------------------------------------------------------------
//
int Rs485ReadChar()
{
#ifdef RS485_CPU_CONTROLLINO
  return Serial3.read();
#endif

#ifdef RS485_CPU_ARDUINO
  return Serial.read();
#endif
}

//-------------------------------------------------------------------
//
void Rs485Transmit(const char *data)
{
  Rs485SwitchToTransmitMode();

#ifdef RS485_CPU_CONTROLLINO
  //Controllino_RS485TxEnable();
  Serial3.write(data);
#endif

#ifdef RS485_CPU_ARDUINO
  //HDW_TX485_ENA_MODE_OUTPUT();
  //HDW_TX485_ENA_ON();
  Serial.write(data);
#endif

}

//-------------------------------------------------------------------
//
void Rs485Transmit(byte *data, int len)
{
  Rs485SwitchToTransmitMode();

#ifdef RS485_CPU_CONTROLLINO
  //Controllino_RS485TxEnable();
  Serial3.write(data, len);
#endif

#ifdef RS485_CPU_ARDUINO
  //HDW_TX485_ENA_MODE_OUTPUT();
  //HDW_TX485_ENA_ON();
  Serial.write(data, len);
#endif


}

//-------------------------------------------------------------------
//
bool Rs485IsTramsmitReady(void)
{
#ifdef RS485_CPU_CONTROLLINO
  if (!( UCSR3A & (1 << TXC3))) return false;

  Controllino_RS485RxEnable();
#endif

#ifdef RS485_CPU_ARDUINO
  if (!( UCSR0A & (1 << TXC0))) return false;

  HDW_TX485_ENA_MODE_OUTPUT();
  HDW_TX485_ENA_OFF();

  HDW_NOP_2;

  HDW_RX485_ENA_MODE_OUTPUT();
  HDW_RX485_ENA_ON();

#endif

  return true;
}


//-------------------------------------------------------------------
//
void Rs485SwitchToRecMode(void)
{
#ifdef RS485_CPU_CONTROLLINO
  Controllino_RS485RxEnable();
#endif

#ifdef RS485_CPU_ARDUINO
  HDW_TX485_ENA_MODE_OUTPUT();
  HDW_TX485_ENA_OFF();

  HDW_RX485_ENA_MODE_OUTPUT();
  HDW_RX485_ENA_ON();

  HDW_NOP_2;

#endif

}

//-------------------------------------------------------------------
//
void Rs485SwitchToTransmitMode(void)
{
#ifdef RS485_CPU_CONTROLLINO
  Controllino_RS485TxEnable();
#endif

#ifdef RS485_CPU_ARDUINO
  HDW_RX485_ENA_MODE_OUTPUT();
  HDW_RX485_ENA_OFF();

  HDW_TX485_ENA_MODE_OUTPUT();
  HDW_TX485_ENA_ON();

  HDW_NOP_2;

#endif
}

//#############################################################################
//#############################################################################
//#############################################################################
