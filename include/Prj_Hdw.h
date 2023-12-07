//#############################################################################
// Prj_Hdw.H
//
//
//
// Created: 04.03.2022
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __Prj_Hdw_H_LOADED_DC294A168008__
#define __Prj_Hdw_H_LOADED_DC294A168008__
//#############################################################################

//------------------------------------------------------------------------------------------------------------------------
// @AMID@Prj_Hdw@_2023-08-18-1028
//------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------
//
// DO NOT INLUDE THIS FILE IN OTHER FILES!
// THIS HEADER WILL BE EXCLUSIVE INLUDED BY Hdw.h!
//
//------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------
//



//-------------------------------------------------------------------
// Built in LED

#ifdef _DEB_FLAG_DEBUG_
#define HDW_LED_BUILTIN_MODE_OUTPUT() {}
#define HDW_LED_BUILTIN_ON() {}
#define HDW_LED_BUILTIN_OFF() {}
#define HDW_LED_BUILTIN_TOGGLE() {}

#define HDW_DEB_LED_BUILTIN_MODE_OUTPUT() {HDW_DIO_PB5_MODE_OUTPUT();}
#define HDW_DEB_LED_BUILTIN_ON() {HDW_DIO_PB5_ON();}
#define HDW_DEB_LED_BUILTIN_OFF() {HDW_DIO_PB5_OFF();}
#define HDW_DEB_LED_BUILTIN_TOGGLE() {HDW_DIO_PB5_TOGGLE();}


#else

#define HDW_LED_BUILTIN_MODE_OUTPUT() {HDW_DIO_PC1_MODE_OUTPUT();}
#define HDW_LED_BUILTIN_ON() {HDW_DIO_PC1_ON();}
#define HDW_LED_BUILTIN_OFF() {HDW_DIO_PC1_OFF();}
#define HDW_LED_BUILTIN_TOGGLE() {HDW_DIO_PC1_TOGGLE();}

#endif


//-------------------------------------------------------------------
// LED for blinking / morsing information.


#define HDW_LED_BLINK_MODE_OUTPUT() {HDW_DIO_PC1_MODE_OUTPUT();}
#define HDW_LED_BLINK_ON() {HDW_DIO_PC1_ON();}
#define HDW_LED_BLINK_OFF() {HDW_DIO_PC1_OFF();}
#define HDW_LED_BLINK_TOGGLE() {HDW_DIO_PC1_TOGGLE();}



//-------------------------------------------------------------------
//
#define HDW_SPIBUS_GO_MODE_OUTPUT() {HDW_DIO_PD7_MODE_OUTPUT()}
#define HDW_SPIBUS_GO_ON() {HDW_DIO_PD7_ON();}
#define HDW_SPIBUS_GO_OFF() {HDW_DIO_PD7_OFF();}
#define HDW_SPIBUS_GO_ACTIVE() {HDW_SPIBUS_GO_OFF();}
#define HDW_SPIBUS_GO_INACTIVE() {HDW_SPIBUS_GO_ON();}

#define HDW_SPIBUS_A0_MODE_OUTPUT() {HDW_DIO_PD4_MODE_OUTPUT()}
#define HDW_SPIBUS_A0_ON() {HDW_DIO_PD4_ON();}
#define HDW_SPIBUS_A0_OFF() {HDW_DIO_PD4_OFF();}

#define HDW_SPIBUS_A1_MODE_OUTPUT() {HDW_DIO_PD5_MODE_OUTPUT()}
#define HDW_SPIBUS_A1_ON() {HDW_DIO_PD5_ON();}
#define HDW_SPIBUS_A1_OFF() {HDW_DIO_PD5_OFF();}

#define HDW_SPIBUS_A2_MODE_OUTPUT() {HDW_DIO_PD6_MODE_OUTPUT()}
#define HDW_SPIBUS_A2_ON() {HDW_DIO_PD6_ON();}
#define HDW_SPIBUS_A2_OFF() {HDW_DIO_PD6_OFF();}


//-------------------------------------------------------------------
// TX485 enable
//
#define HDW_TX485_ENA_MODE_OUTPUT() {HDW_DIO_PB0_MODE_OUTPUT()}
#define HDW_TX485_ENA_ON() {HDW_DIO_PB0_ON();}
#define HDW_TX485_ENA_OFF() {HDW_DIO_PB0_OFF();}

//-------------------------------------------------------------------
// RX485 enable
//
#define HDW_RX485_ENA_MODE_OUTPUT() {HDW_DIO_PD7_MODE_OUTPUT()}
#define HDW_RX485_ENA_ON() {HDW_DIO_PD7_OFF();}
#define HDW_RX485_ENA_OFF() {HDW_DIO_PD7_ON();}

//-------------------------------------------------------------------
// Fan 1
//
//#define HDW_REL_MODE_OUTPUT() {HDW_DIO_PE4_MODE_OUTPUT()}
//#define HDW_REL_ON() {HDW_DIO_PE4_ON();}
//#define HDW_REL_OFF() {HDW_DIO_PE4_OFF();}




//-------------------------------------------------------------------
// Key START
// 
//#define HDW_KEY_START_MODE_INPUT() {HDW_DIO_PF3_MODE_INPUT();}
//#define HDW_KEY_START_READ (HDW_DIO_PF3_READ)


//#############################################################################
//#############################################################################
//#############################################################################
#endif
