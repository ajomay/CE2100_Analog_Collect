//#############################################################################
// Hdw.H
//
// 
//
// Created: 13.11.2019
// History:
//
// (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
// Roentgenstrasse 104
// D-64291 Darmstadt
//#############################################################################
#ifndef __Hdw_H_LOADED_38F62C56A48C__
#define __Hdw_H_LOADED_38F62C56A48C__
//#############################################################################

//-------------------------------------------------------------------
// @AMID@Hdw_H@_2023-08-18-1028
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//
#include "Formats.h"

//----------------------------------------------------------------------
// Definitions for all ports
#define HDW_DIO_PULLUPS_ON() {MCUCR &= ~(1<<4);}
#define HDW_DIO_PULLUPS_OFF() {MCUCR |= (1<<4);}

//----------------------------------------------------------------------
// Definitions for port-bit PA0

#define HDW_DIO_PA0_MODE_OUTPUT() {DDRA |= (1<<0);}
#define HDW_DIO_PA0_MODE_INPUT() {DDRA &= ~(1<<0);}
#define HDW_DIO_PA0_OFF() {PORTA &= ~(1<<0);}
#define HDW_DIO_PA0_ON() {PORTA |= (1<<0);}
#define HDW_DIO_PA0_TOGGLE() {PORTA ^= (1<<0);}
#define HDW_DIO_PA0_READ ((PINA &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PA1

#define HDW_DIO_PA1_MODE_OUTPUT() {DDRA |= (1<<1);}
#define HDW_DIO_PA1_MODE_INPUT() {DDRA &= ~(1<<1);}
#define HDW_DIO_PA1_OFF() {PORTA &= ~(1<<1);}
#define HDW_DIO_PA1_ON() {PORTA |= (1<<1);}
#define HDW_DIO_PA1_TOGGLE() {PORTA ^= (1<<1);}
#define HDW_DIO_PA1_READ ((PINA &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PA2

#define HDW_DIO_PA2_MODE_OUTPUT() {DDRA |= (1<<2);}
#define HDW_DIO_PA2_MODE_INPUT() {DDRA &= ~(1<<2);}
#define HDW_DIO_PA2_OFF() {PORTA &= ~(1<<2);}
#define HDW_DIO_PA2_ON() {PORTA |= (1<<2);}
#define HDW_DIO_PA2_TOGGLE() {PORTA ^= (1<<2);}
#define HDW_DIO_PA2_READ ((PINA &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PA3

#define HDW_DIO_PA3_MODE_OUTPUT() {DDRA |= (1<<3);}
#define HDW_DIO_PA3_MODE_INPUT() {DDRA &= ~(1<<3);}
#define HDW_DIO_PA3_OFF() {PORTA &= ~(1<<3);}
#define HDW_DIO_PA3_ON() {PORTA |= (1<<3);}
#define HDW_DIO_PA3_TOGGLE() {PORTA ^= (1<<3);}
#define HDW_DIO_PA3_READ ((PINA &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PA4

#define HDW_DIO_PA4_MODE_OUTPUT() {DDRA |= (1<<4);}
#define HDW_DIO_PA4_MODE_INPUT() {DDRA &= ~(1<<4);}
#define HDW_DIO_PA4_OFF() {PORTA &= ~(1<<4);}
#define HDW_DIO_PA4_ON() {PORTA |= (1<<4);}
#define HDW_DIO_PA4_TOGGLE() {PORTA ^= (1<<4);}
#define HDW_DIO_PA4_READ ((PINA &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PA5

#define HDW_DIO_PA5_MODE_OUTPUT() {DDRA |= (1<<5);}
#define HDW_DIO_PA5_MODE_INPUT() {DDRA &= ~(1<<5);}
#define HDW_DIO_PA5_OFF() {PORTA &= ~(1<<5);}
#define HDW_DIO_PA5_ON() {PORTA |= (1<<5);}
#define HDW_DIO_PA5_TOGGLE() {PORTA ^= (1<<5);}
#define HDW_DIO_PA5_READ ((PINA &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PA6

#define HDW_DIO_PA6_MODE_OUTPUT() {DDRA |= (1<<6);}
#define HDW_DIO_PA6_MODE_INPUT() {DDRA &= ~(1<<6);}
#define HDW_DIO_PA6_OFF() {PORTA &= ~(1<<6);}
#define HDW_DIO_PA6_ON() {PORTA |= (1<<6);}
#define HDW_DIO_PA6_TOGGLE() {PORTA ^= (1<<6);}
#define HDW_DIO_PA6_READ ((PINA &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PA7

#define HDW_DIO_PA7_MODE_OUTPUT() {DDRA |= (1<<7);}
#define HDW_DIO_PA7_MODE_INPUT() {DDRA &= ~(1<<7);}
#define HDW_DIO_PA7_OFF() {PORTA &= ~(1<<7);}
#define HDW_DIO_PA7_ON() {PORTA |= (1<<7);}
#define HDW_DIO_PA7_TOGGLE() {PORTA ^= (1<<7);}
#define HDW_DIO_PA7_READ ((PINA &(1<<7))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PB0

#define HDW_DIO_PB0_MODE_OUTPUT() {DDRB |= (1<<0);}
#define HDW_DIO_PB0_MODE_INPUT() {DDRB &= ~(1<<0);}
#define HDW_DIO_PB0_OFF() {PORTB &= ~(1<<0);}
#define HDW_DIO_PB0_ON() {PORTB |= (1<<0);}
#define HDW_DIO_PB0_TOGGLE() {PORTB ^= (1<<0);}
#define HDW_DIO_PB0_READ ((PINB &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PB1

#define HDW_DIO_PB1_MODE_OUTPUT() {DDRB |= (1<<1);}
#define HDW_DIO_PB1_MODE_INPUT() {DDRB &= ~(1<<1);}
#define HDW_DIO_PB1_OFF() {PORTB &= ~(1<<1);}
#define HDW_DIO_PB1_ON() {PORTB |= (1<<1);}
#define HDW_DIO_PB1_TOGGLE() {PORTB ^= (1<<1);}
#define HDW_DIO_PB1_READ ((PINB &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PB2

#define HDW_DIO_PB2_MODE_OUTPUT() {DDRB |= (1<<2);}
#define HDW_DIO_PB2_MODE_INPUT() {DDRB &= ~(1<<2);}
#define HDW_DIO_PB2_OFF() {PORTB &= ~(1<<2);}
#define HDW_DIO_PB2_ON() {PORTB |= (1<<2);}
#define HDW_DIO_PB2_TOGGLE() {PORTB ^= (1<<2);}
#define HDW_DIO_PB2_READ ((PINB &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PB3

#define HDW_DIO_PB3_MODE_OUTPUT() {DDRB |= (1<<3);}
#define HDW_DIO_PB3_MODE_INPUT() {DDRB &= ~(1<<3);}
#define HDW_DIO_PB3_OFF() {PORTB &= ~(1<<3);}
#define HDW_DIO_PB3_ON() {PORTB |= (1<<3);}
#define HDW_DIO_PB3_TOGGLE() {PORTB ^= (1<<3);}
#define HDW_DIO_PB3_READ ((PINB &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PB4

#define HDW_DIO_PB4_MODE_OUTPUT() {DDRB |= (1<<4);}
#define HDW_DIO_PB4_MODE_INPUT() {DDRB &= ~(1<<4);}
#define HDW_DIO_PB4_OFF() {PORTB &= ~(1<<4);}
#define HDW_DIO_PB4_ON() {PORTB |= (1<<4);}
#define HDW_DIO_PB4_TOGGLE() {PORTB ^= (1<<4);}
#define HDW_DIO_PB4_READ ((PINB &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PB5

#define HDW_DIO_PB5_MODE_OUTPUT() {DDRB |= (1<<5);}
#define HDW_DIO_PB5_MODE_INPUT() {DDRB &= ~(1<<5);}
#define HDW_DIO_PB5_OFF() {PORTB &= ~(1<<5);}
#define HDW_DIO_PB5_ON() {PORTB |= (1<<5);}
#define HDW_DIO_PB5_TOGGLE() {PORTB ^= (1<<5);}
#define HDW_DIO_PB5_READ ((PINB &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PB6

#define HDW_DIO_PB6_MODE_OUTPUT() {DDRB |= (1<<6);}
#define HDW_DIO_PB6_MODE_INPUT() {DDRB &= ~(1<<6);}
#define HDW_DIO_PB6_OFF() {PORTB &= ~(1<<6);}
#define HDW_DIO_PB6_ON() {PORTB |= (1<<6);}
#define HDW_DIO_PB6_TOGGLE() {PORTB ^= (1<<6);}
#define HDW_DIO_PB6_READ ((PINB &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PB7

#define HDW_DIO_PB7_MODE_OUTPUT() {DDRB |= (1<<7);}
#define HDW_DIO_PB7_MODE_INPUT() {DDRB &= ~(1<<7);}
#define HDW_DIO_PB7_OFF() {PORTB &= ~(1<<7);}
#define HDW_DIO_PB7_ON() {PORTB |= (1<<7);}
#define HDW_DIO_PB7_TOGGLE() {PORTB ^= (1<<7);}
#define HDW_DIO_PB7_READ ((PINB &(1<<7))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PC0

#define HDW_DIO_PC0_MODE_OUTPUT() {DDRC |= (1<<0);}
#define HDW_DIO_PC0_MODE_INPUT() {DDRC &= ~(1<<0);}
#define HDW_DIO_PC0_OFF() {PORTC &= ~(1<<0);}
#define HDW_DIO_PC0_ON() {PORTC |= (1<<0);}
#define HDW_DIO_PC0_TOGGLE() {PORTC ^= (1<<0);}
#define HDW_DIO_PC0_READ ((PINC &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PC1

#define HDW_DIO_PC1_MODE_OUTPUT() {DDRC |= (1<<1);}
#define HDW_DIO_PC1_MODE_INPUT() {DDRC &= ~(1<<1);}
#define HDW_DIO_PC1_OFF() {PORTC &= ~(1<<1);}
#define HDW_DIO_PC1_ON() {PORTC |= (1<<1);}
#define HDW_DIO_PC1_TOGGLE() {PORTC ^= (1<<1);}
#define HDW_DIO_PC1_READ ((PINC &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PC2

#define HDW_DIO_PC2_MODE_OUTPUT() {DDRC |= (1<<2);}
#define HDW_DIO_PC2_MODE_INPUT() {DDRC &= ~(1<<2);}
#define HDW_DIO_PC2_OFF() {PORTC &= ~(1<<2);}
#define HDW_DIO_PC2_ON() {PORTC |= (1<<2);}
#define HDW_DIO_PC2_TOGGLE() {PORTC ^= (1<<2);}
#define HDW_DIO_PC2_READ ((PINC &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PC3

#define HDW_DIO_PC3_MODE_OUTPUT() {DDRC |= (1<<3);}
#define HDW_DIO_PC3_MODE_INPUT() {DDRC &= ~(1<<3);}
#define HDW_DIO_PC3_OFF() {PORTC &= ~(1<<3);}
#define HDW_DIO_PC3_ON() {PORTC |= (1<<3);}
#define HDW_DIO_PC3_TOGGLE() {PORTC ^= (1<<3);}
#define HDW_DIO_PC3_READ ((PINC &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PC4

#define HDW_DIO_PC4_MODE_OUTPUT() {DDRC |= (1<<4);}
#define HDW_DIO_PC4_MODE_INPUT() {DDRC &= ~(1<<4);}
#define HDW_DIO_PC4_OFF() {PORTC &= ~(1<<4);}
#define HDW_DIO_PC4_ON() {PORTC |= (1<<4);}
#define HDW_DIO_PC4_TOGGLE() {PORTC ^= (1<<4);}
#define HDW_DIO_PC4_READ ((PINC &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PC5

#define HDW_DIO_PC5_MODE_OUTPUT() {DDRC |= (1<<5);}
#define HDW_DIO_PC5_MODE_INPUT() {DDRC &= ~(1<<5);}
#define HDW_DIO_PC5_OFF() {PORTC &= ~(1<<5);}
#define HDW_DIO_PC5_ON() {PORTC |= (1<<5);}
#define HDW_DIO_PC5_TOGGLE() {PORTC ^= (1<<5);}
#define HDW_DIO_PC5_READ ((PINC &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PC6

#define HDW_DIO_PC6_MODE_OUTPUT() {DDRC |= (1<<6);}
#define HDW_DIO_PC6_MODE_INPUT() {DDRC &= ~(1<<6);}
#define HDW_DIO_PC6_OFF() {PORTC &= ~(1<<6);}
#define HDW_DIO_PC6_ON() {PORTC |= (1<<6);}
#define HDW_DIO_PC6_TOGGLE() {PORTC ^= (1<<6);}
#define HDW_DIO_PC6_READ ((PINC &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PC7

#define HDW_DIO_PC7_MODE_OUTPUT() {DDRC |= (1<<7);}
#define HDW_DIO_PC7_MODE_INPUT() {DDRC &= ~(1<<7);}
#define HDW_DIO_PC7_OFF() {PORTC &= ~(1<<7);}
#define HDW_DIO_PC7_ON() {PORTC |= (1<<7);}
#define HDW_DIO_PC7_TOGGLE() {PORTC ^= (1<<7);}
#define HDW_DIO_PC7_READ ((PINC &(1<<7))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PD0

#define HDW_DIO_PD0_MODE_OUTPUT() {DDRD |= (1<<0);}
#define HDW_DIO_PD0_MODE_INPUT() {DDRD &= ~(1<<0);}
#define HDW_DIO_PD0_OFF() {PORTD &= ~(1<<0);}
#define HDW_DIO_PD0_ON() {PORTD |= (1<<0);}
#define HDW_DIO_PD0_TOGGLE() {PORTD ^= (1<<0);}
#define HDW_DIO_PD0_READ ((PIND &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PD1

#define HDW_DIO_PD1_MODE_OUTPUT() {DDRD |= (1<<1);}
#define HDW_DIO_PD1_MODE_INPUT() {DDRD &= ~(1<<1);}
#define HDW_DIO_PD1_OFF() {PORTD &= ~(1<<1);}
#define HDW_DIO_PD1_ON() {PORTD |= (1<<1);}
#define HDW_DIO_PD1_TOGGLE() {PORTD ^= (1<<1);}
#define HDW_DIO_PD1_READ ((PIND &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PD2

#define HDW_DIO_PD2_MODE_OUTPUT() {DDRD |= (1<<2);}
#define HDW_DIO_PD2_MODE_INPUT() {DDRD &= ~(1<<2);}
#define HDW_DIO_PD2_OFF() {PORTD &= ~(1<<2);}
#define HDW_DIO_PD2_ON() {PORTD |= (1<<2);}
#define HDW_DIO_PD2_TOGGLE() {PORTD ^= (1<<2);}
#define HDW_DIO_PD2_READ ((PIND &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PD3

#define HDW_DIO_PD3_MODE_OUTPUT() {DDRD |= (1<<3);}
#define HDW_DIO_PD3_MODE_INPUT() {DDRD &= ~(1<<3);}
#define HDW_DIO_PD3_OFF() {PORTD &= ~(1<<3);}
#define HDW_DIO_PD3_ON() {PORTD |= (1<<3);}
#define HDW_DIO_PD3_TOGGLE() {PORTD ^= (1<<3);}
#define HDW_DIO_PD3_READ ((PIND &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PD4

#define HDW_DIO_PD4_MODE_OUTPUT() {DDRD |= (1<<4);}
#define HDW_DIO_PD4_MODE_INPUT() {DDRD &= ~(1<<4);}
#define HDW_DIO_PD4_OFF() {PORTD &= ~(1<<4);}
#define HDW_DIO_PD4_ON() {PORTD |= (1<<4);}
#define HDW_DIO_PD4_TOGGLE() {PORTD ^= (1<<4);}
#define HDW_DIO_PD4_READ ((PIND &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PD5

#define HDW_DIO_PD5_MODE_OUTPUT() {DDRD |= (1<<5);}
#define HDW_DIO_PD5_MODE_INPUT() {DDRD &= ~(1<<5);}
#define HDW_DIO_PD5_OFF() {PORTD &= ~(1<<5);}
#define HDW_DIO_PD5_ON() {PORTD |= (1<<5);}
#define HDW_DIO_PD5_TOGGLE() {PORTD ^= (1<<5);}
#define HDW_DIO_PD5_READ ((PIND &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PD6

#define HDW_DIO_PD6_MODE_OUTPUT() {DDRD |= (1<<6);}
#define HDW_DIO_PD6_MODE_INPUT() {DDRD &= ~(1<<6);}
#define HDW_DIO_PD6_OFF() {PORTD &= ~(1<<6);}
#define HDW_DIO_PD6_ON() {PORTD |= (1<<6);}
#define HDW_DIO_PD6_TOGGLE() {PORTD ^= (1<<6);}
#define HDW_DIO_PD6_READ ((PIND &(1<<6))!=0)



//----------------------------------------------------------------------
// Definitions for port-bit PD7

#define HDW_DIO_PD7_MODE_OUTPUT() {DDRD |= (1<<7);}
#define HDW_DIO_PD7_MODE_INPUT() {DDRD &= ~(1<<7);}
#define HDW_DIO_PD7_OFF() {PORTD &= ~(1<<7);}
#define HDW_DIO_PD7_ON() {PORTD |= (1<<7);}
#define HDW_DIO_PD7_TOGGLE() {PORTD ^= (1<<7);}
#define HDW_DIO_PD7_READ ((PIND &(1<<7))!=0)

//----------------------------------------------------------------------
// Conditional
#if defined (CONTROLLINO_MAXI) || defined (CONTROLLINO_MAXI_AUTOMATION) || defined (CONTROLLINO_MEGA)

//----------------------------------------------------------------------
// Definitions for port-bit PE0

#define HDW_DIO_PE0_MODE_OUTPUT() {DDRE |= (1<<0);}
#define HDW_DIO_PE0_MODE_INPUT() {DDRE &= ~(1<<0);}
#define HDW_DIO_PE0_OFF() {PORTE &= ~(1<<0);}
#define HDW_DIO_PE0_ON() {PORTE |= (1<<0);}
#define HDW_DIO_PE0_TOGGLE() {PORTE ^= (1<<0);}
#define HDW_DIO_PE0_READ ((PINE &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PE1

#define HDW_DIO_PE1_MODE_OUTPUT() {DDRE |= (1<<1);}
#define HDW_DIO_PE1_MODE_INPUT() {DDRE &= ~(1<<1);}
#define HDW_DIO_PE1_OFF() {PORTE &= ~(1<<1);}
#define HDW_DIO_PE1_ON() {PORTE |= (1<<1);}
#define HDW_DIO_PE1_TOGGLE() {PORTE ^= (1<<1);}
#define HDW_DIO_PE1_READ ((PINE &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PE2

#define HDW_DIO_PE2_MODE_OUTPUT() {DDRE |= (1<<2);}
#define HDW_DIO_PE2_MODE_INPUT() {DDRE &= ~(1<<2);}
#define HDW_DIO_PE2_OFF() {PORTE &= ~(1<<2);}
#define HDW_DIO_PE2_ON() {PORTE |= (1<<2);}
#define HDW_DIO_PE2_TOGGLE() {PORTE ^= (1<<2);}
#define HDW_DIO_PE2_READ ((PINE &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PE3

#define HDW_DIO_PE3_MODE_OUTPUT() {DDRE |= (1<<3);}
#define HDW_DIO_PE3_MODE_INPUT() {DDRE &= ~(1<<3);}
#define HDW_DIO_PE3_OFF() {PORTE &= ~(1<<3);}
#define HDW_DIO_PE3_ON() {PORTE |= (1<<3);}
#define HDW_DIO_PE3_TOGGLE() {PORTE ^= (1<<3);}
#define HDW_DIO_PE3_READ ((PINE &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PE4

#define HDW_DIO_PE4_MODE_OUTPUT() {DDRE |= (1<<4);}
#define HDW_DIO_PE4_MODE_INPUT() {DDRE &= ~(1<<4);}
#define HDW_DIO_PE4_OFF() {PORTE &= ~(1<<4);}
#define HDW_DIO_PE4_ON() {PORTE |= (1<<4);}
#define HDW_DIO_PE4_TOGGLE() {PORTE ^= (1<<4);}
#define HDW_DIO_PE4_READ ((PINE &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PE5

#define HDW_DIO_PE5_MODE_OUTPUT() {DDRE |= (1<<5);}
#define HDW_DIO_PE5_MODE_INPUT() {DDRE &= ~(1<<5);}
#define HDW_DIO_PE5_OFF() {PORTE &= ~(1<<5);}
#define HDW_DIO_PE5_ON() {PORTE |= (1<<5);}
#define HDW_DIO_PE5_TOGGLE() {PORTE ^= (1<<5);}
#define HDW_DIO_PE5_READ ((PINE &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PE6

#define HDW_DIO_PE6_MODE_OUTPUT() {DDRE |= (1<<6);}
#define HDW_DIO_PE6_MODE_INPUT() {DDRE &= ~(1<<6);}
#define HDW_DIO_PE6_OFF() {PORTE &= ~(1<<6);}
#define HDW_DIO_PE6_ON() {PORTE |= (1<<6);}
#define HDW_DIO_PE6_TOGGLE() {PORTE ^= (1<<6);}
#define HDW_DIO_PE6_READ ((PINE &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PE7

#define HDW_DIO_PE7_MODE_OUTPUT() {DDRE |= (1<<7);}
#define HDW_DIO_PE7_MODE_INPUT() {DDRE &= ~(1<<7);}
#define HDW_DIO_PE7_OFF() {PORTE &= ~(1<<7);}
#define HDW_DIO_PE7_ON() {PORTE |= (1<<7);}
#define HDW_DIO_PE7_TOGGLE() {PORTE ^= (1<<7);}
#define HDW_DIO_PE7_READ ((PINE &(1<<7))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PF0

#define HDW_DIO_PF0_MODE_OUTPUT() {DDRF |= (1<<0);}
#define HDW_DIO_PF0_MODE_INPUT() {DDRF &= ~(1<<0);}
#define HDW_DIO_PF0_OFF() {PORTF &= ~(1<<0);}
#define HDW_DIO_PF0_ON() {PORTF |= (1<<0);}
#define HDW_DIO_PF0_TOGGLE() {PORTF ^= (1<<0);}
#define HDW_DIO_PF0_READ ((PINF &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PF1

#define HDW_DIO_PF1_MODE_OUTPUT() {DDRF |= (1<<1);}
#define HDW_DIO_PF1_MODE_INPUT() {DDRF &= ~(1<<1);}
#define HDW_DIO_PF1_OFF() {PORTF &= ~(1<<1);}
#define HDW_DIO_PF1_ON() {PORTF |= (1<<1);}
#define HDW_DIO_PF1_TOGGLE() {PORTF ^= (1<<1);}
#define HDW_DIO_PF1_READ ((PINF &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PF2

#define HDW_DIO_PF2_MODE_OUTPUT() {DDRF |= (1<<2);}
#define HDW_DIO_PF2_MODE_INPUT() {DDRF &= ~(1<<2);}
#define HDW_DIO_PF2_OFF() {PORTF &= ~(1<<2);}
#define HDW_DIO_PF2_ON() {PORTF |= (1<<2);}
#define HDW_DIO_PF2_TOGGLE() {PORTF ^= (1<<2);}
#define HDW_DIO_PF2_READ ((PINF &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PF3

#define HDW_DIO_PF3_MODE_OUTPUT() {DDRF |= (1<<3);}
#define HDW_DIO_PF3_MODE_INPUT() {DDRF &= ~(1<<3);}
#define HDW_DIO_PF3_OFF() {PORTF &= ~(1<<3);}
#define HDW_DIO_PF3_ON() {PORTF |= (1<<3);}
#define HDW_DIO_PF3_TOGGLE() {PORTF ^= (1<<3);}
#define HDW_DIO_PF3_READ ((PINF &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PF4

#define HDW_DIO_PF4_MODE_OUTPUT() {DDRF |= (1<<4);}
#define HDW_DIO_PF4_MODE_INPUT() {DDRF &= ~(1<<4);}
#define HDW_DIO_PF4_OFF() {PORTF &= ~(1<<4);}
#define HDW_DIO_PF4_ON() {PORTF |= (1<<4);}
#define HDW_DIO_PF4_TOGGLE() {PORTF ^= (1<<4);}
#define HDW_DIO_PF4_READ ((PINF &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PF5

#define HDW_DIO_PF5_MODE_OUTPUT() {DDRF |= (1<<5);}
#define HDW_DIO_PF5_MODE_INPUT() {DDRF &= ~(1<<5);}
#define HDW_DIO_PF5_OFF() {PORTF &= ~(1<<5);}
#define HDW_DIO_PF5_ON() {PORTF |= (1<<5);}
#define HDW_DIO_PF5_TOGGLE() {PORTF ^= (1<<5);}
#define HDW_DIO_PF5_READ ((PINF &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PF6

#define HDW_DIO_PF6_MODE_OUTPUT() {DDRF |= (1<<6);}
#define HDW_DIO_PF6_MODE_INPUT() {DDRF &= ~(1<<6);}
#define HDW_DIO_PF6_OFF() {PORTF &= ~(1<<6);}
#define HDW_DIO_PF6_ON() {PORTF |= (1<<6);}
#define HDW_DIO_PF6_TOGGLE() {PORTF ^= (1<<6);}
#define HDW_DIO_PF6_READ ((PINF &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PF7

#define HDW_DIO_PF7_MODE_OUTPUT() {DDRF |= (1<<7);}
#define HDW_DIO_PF7_MODE_INPUT() {DDRF &= ~(1<<7);}
#define HDW_DIO_PF7_OFF() {PORTF &= ~(1<<7);}
#define HDW_DIO_PF7_ON() {PORTF |= (1<<7);}
#define HDW_DIO_PF7_TOGGLE() {PORTF ^= (1<<7);}
#define HDW_DIO_PF7_READ ((PINF &(1<<7))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PG0

#define HDW_DIO_PG0_MODE_OUTPUT() {DDRG |= (1<<0);}
#define HDW_DIO_PG0_MODE_INPUT() {DDRG &= ~(1<<0);}
#define HDW_DIO_PG0_OFF() {PORTG &= ~(1<<0);}
#define HDW_DIO_PG0_ON() {PORTG |= (1<<0);}
#define HDW_DIO_PG0_TOGGLE() {PORTG ^= (1<<0);}
#define HDW_DIO_PG0_READ ((PING &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PG1

#define HDW_DIO_PG1_MODE_OUTPUT() {DDRG |= (1<<1);}
#define HDW_DIO_PG1_MODE_INPUT() {DDRG &= ~(1<<1);}
#define HDW_DIO_PG1_OFF() {PORTG &= ~(1<<1);}
#define HDW_DIO_PG1_ON() {PORTG |= (1<<1);}
#define HDW_DIO_PG1_TOGGLE() {PORTG ^= (1<<1);}
#define HDW_DIO_PG1_READ ((PING &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PG2

#define HDW_DIO_PG2_MODE_OUTPUT() {DDRG |= (1<<2);}
#define HDW_DIO_PG2_MODE_INPUT() {DDRG &= ~(1<<2);}
#define HDW_DIO_PG2_OFF() {PORTG &= ~(1<<2);}
#define HDW_DIO_PG2_ON() {PORTG |= (1<<2);}
#define HDW_DIO_PG2_TOGGLE() {PORTG ^= (1<<2);}
#define HDW_DIO_PG2_READ ((PING &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PG3

#define HDW_DIO_PG3_MODE_OUTPUT() {DDRG |= (1<<3);}
#define HDW_DIO_PG3_MODE_INPUT() {DDRG &= ~(1<<3);}
#define HDW_DIO_PG3_OFF() {PORTG &= ~(1<<3);}
#define HDW_DIO_PG3_ON() {PORTG |= (1<<3);}
#define HDW_DIO_PG3_TOGGLE() {PORTG ^= (1<<3);}
#define HDW_DIO_PG3_READ ((PING &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PG4

#define HDW_DIO_PG4_MODE_OUTPUT() {DDRG |= (1<<4);}
#define HDW_DIO_PG4_MODE_INPUT() {DDRG &= ~(1<<4);}
#define HDW_DIO_PG4_OFF() {PORTG &= ~(1<<4);}
#define HDW_DIO_PG4_ON() {PORTG |= (1<<4);}
#define HDW_DIO_PG4_TOGGLE() {PORTG ^= (1<<4);}
#define HDW_DIO_PG4_READ ((PING &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PG5

#define HDW_DIO_PG5_MODE_OUTPUT() {DDRG |= (1<<5);}
#define HDW_DIO_PG5_MODE_INPUT() {DDRG &= ~(1<<5);}
#define HDW_DIO_PG5_OFF() {PORTG &= ~(1<<5);}
#define HDW_DIO_PG5_ON() {PORTG |= (1<<5);}
#define HDW_DIO_PG5_TOGGLE() {PORTG ^= (1<<5);}
#define HDW_DIO_PG5_READ ((PING &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PH0

#define HDW_DIO_PH0_MODE_OUTPUT() {DDRH |= (1<<0);}
#define HDW_DIO_PH0_MODE_INPUT() {DDRH &= ~(1<<0);}
#define HDW_DIO_PH0_OFF() {PORTH &= ~(1<<0);}
#define HDW_DIO_PH0_ON() {PORTH |= (1<<0);}
#define HDW_DIO_PH0_TOGGLE() {PORTH ^= (1<<0);}
#define HDW_DIO_PH0_READ ((PINH &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PH1

#define HDW_DIO_PH1_MODE_OUTPUT() {DDRH |= (1<<1);}
#define HDW_DIO_PH1_MODE_INPUT() {DDRH &= ~(1<<1);}
#define HDW_DIO_PH1_OFF() {PORTH &= ~(1<<1);}
#define HDW_DIO_PH1_ON() {PORTH |= (1<<1);}
#define HDW_DIO_PH1_TOGGLE() {PORTH ^= (1<<1);}
#define HDW_DIO_PH1_READ ((PINH &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PH2

#define HDW_DIO_PH2_MODE_OUTPUT() {DDRH |= (1<<2);}
#define HDW_DIO_PH2_MODE_INPUT() {DDRH &= ~(1<<2);}
#define HDW_DIO_PH2_OFF() {PORTH &= ~(1<<2);}
#define HDW_DIO_PH2_ON() {PORTH |= (1<<2);}
#define HDW_DIO_PH2_TOGGLE() {PORTH ^= (1<<2);}
#define HDW_DIO_PH2_READ ((PINH &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PH3

#define HDW_DIO_PH3_MODE_OUTPUT() {DDRH |= (1<<3);}
#define HDW_DIO_PH3_MODE_INPUT() {DDRH &= ~(1<<3);}
#define HDW_DIO_PH3_OFF() {PORTH &= ~(1<<3);}
#define HDW_DIO_PH3_ON() {PORTH |= (1<<3);}
#define HDW_DIO_PH3_TOGGLE() {PORTH ^= (1<<3);}
#define HDW_DIO_PH3_READ ((PINH &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PH4

#define HDW_DIO_PH4_MODE_OUTPUT() {DDRH |= (1<<4);}
#define HDW_DIO_PH4_MODE_INPUT() {DDRH &= ~(1<<4);}
#define HDW_DIO_PH4_OFF() {PORTH &= ~(1<<4);}
#define HDW_DIO_PH4_ON() {PORTH |= (1<<4);}
#define HDW_DIO_PH4_TOGGLE() {PORTH ^= (1<<4);}
#define HDW_DIO_PH4_READ ((PINH &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PH5

#define HDW_DIO_PH5_MODE_OUTPUT() {DDRH |= (1<<5);}
#define HDW_DIO_PH5_MODE_INPUT() {DDRH &= ~(1<<5);}
#define HDW_DIO_PH5_OFF() {PORTH &= ~(1<<5);}
#define HDW_DIO_PH5_ON() {PORTH |= (1<<5);}
#define HDW_DIO_PH5_TOGGLE() {PORTH ^= (1<<5);}
#define HDW_DIO_PH5_READ ((PINH &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PH6

#define HDW_DIO_PH6_MODE_OUTPUT() {DDRH |= (1<<6);}
#define HDW_DIO_PH6_MODE_INPUT() {DDRH &= ~(1<<6);}
#define HDW_DIO_PH6_OFF() {PORTH &= ~(1<<6);}
#define HDW_DIO_PH6_ON() {PORTH |= (1<<6);}
#define HDW_DIO_PH6_TOGGLE() {PORTH ^= (1<<6);}
#define HDW_DIO_PH6_READ ((PINH &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PH7

#define HDW_DIO_PH7_MODE_OUTPUT() {DDRH |= (1<<7);}
#define HDW_DIO_PH7_MODE_INPUT() {DDRH &= ~(1<<7);}
#define HDW_DIO_PH7_OFF() {PORTH &= ~(1<<7);}
#define HDW_DIO_PH7_ON() {PORTH |= (1<<7);}
#define HDW_DIO_PH7_TOGGLE() {PORTH ^= (1<<7);}
#define HDW_DIO_PH7_READ ((PINH &(1<<7))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PJ0

#define HDW_DIO_PJ0_MODE_OUTPUT() {DDRJ |= (1<<0);}
#define HDW_DIO_PJ0_MODE_INPUT() {DDRJ &= ~(1<<0);}
#define HDW_DIO_PJ0_OFF() {PORTJ &= ~(1<<0);}
#define HDW_DIO_PJ0_ON() {PORTJ |= (1<<0);}
#define HDW_DIO_PJ0_TOGGLE() {PORTJ ^= (1<<0);}
#define HDW_DIO_PJ0_READ ((PINJ &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PJ1

#define HDW_DIO_PJ1_MODE_OUTPUT() {DDRJ |= (1<<1);}
#define HDW_DIO_PJ1_MODE_INPUT() {DDRJ &= ~(1<<1);}
#define HDW_DIO_PJ1_OFF() {PORTJ &= ~(1<<1);}
#define HDW_DIO_PJ1_ON() {PORTJ |= (1<<1);}
#define HDW_DIO_PJ1_TOGGLE() {PORTJ ^= (1<<1);}
#define HDW_DIO_PJ1_READ ((PINJ &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PJ2

#define HDW_DIO_PJ2_MODE_OUTPUT() {DDRJ |= (1<<2);}
#define HDW_DIO_PJ2_MODE_INPUT() {DDRJ &= ~(1<<2);}
#define HDW_DIO_PJ2_OFF() {PORTJ &= ~(1<<2);}
#define HDW_DIO_PJ2_ON() {PORTJ |= (1<<2);}
#define HDW_DIO_PJ2_TOGGLE() {PORTJ ^= (1<<2);}
#define HDW_DIO_PJ2_READ ((PINJ &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PJ3

#define HDW_DIO_PJ3_MODE_OUTPUT() {DDRJ |= (1<<3);}
#define HDW_DIO_PJ3_MODE_INPUT() {DDRJ &= ~(1<<3);}
#define HDW_DIO_PJ3_OFF() {PORTJ &= ~(1<<3);}
#define HDW_DIO_PJ3_ON() {PORTJ |= (1<<3);}
#define HDW_DIO_PJ3_TOGGLE() {PORTJ ^= (1<<3);}
#define HDW_DIO_PJ3_READ ((PINJ &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PJ4

#define HDW_DIO_PJ4_MODE_OUTPUT() {DDRJ |= (1<<4);}
#define HDW_DIO_PJ4_MODE_INPUT() {DDRJ &= ~(1<<4);}
#define HDW_DIO_PJ4_OFF() {PORTJ &= ~(1<<4);}
#define HDW_DIO_PJ4_ON() {PORTJ |= (1<<4);}
#define HDW_DIO_PJ4_TOGGLE() {PORTJ ^= (1<<4);}
#define HDW_DIO_PJ4_READ ((PINJ &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PJ5

#define HDW_DIO_PJ5_MODE_OUTPUT() {DDRJ |= (1<<5);}
#define HDW_DIO_PJ5_MODE_INPUT() {DDRJ &= ~(1<<5);}
#define HDW_DIO_PJ5_OFF() {PORTJ &= ~(1<<5);}
#define HDW_DIO_PJ5_ON() {PORTJ |= (1<<5);}
#define HDW_DIO_PJ5_TOGGLE() {PORTJ ^= (1<<5);}
#define HDW_DIO_PJ5_READ ((PINJ &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PJ6

#define HDW_DIO_PJ6_MODE_OUTPUT() {DDRJ |= (1<<6);}
#define HDW_DIO_PJ6_MODE_INPUT() {DDRJ &= ~(1<<6);}
#define HDW_DIO_PJ6_OFF() {PORTJ &= ~(1<<6);}
#define HDW_DIO_PJ6_ON() {PORTJ |= (1<<6);}
#define HDW_DIO_PJ6_TOGGLE() {PORTJ ^= (1<<6);}
#define HDW_DIO_PJ6_READ ((PINJ &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PJ7

#define HDW_DIO_PJ7_MODE_OUTPUT() {DDRJ |= (1<<7);}
#define HDW_DIO_PJ7_MODE_INPUT() {DDRJ &= ~(1<<7);}
#define HDW_DIO_PJ7_OFF() {PORTJ &= ~(1<<7);}
#define HDW_DIO_PJ7_ON() {PORTJ |= (1<<7);}
#define HDW_DIO_PJ7_TOGGLE() {PORTJ ^= (1<<7);}
#define HDW_DIO_PJ7_READ ((PINJ &(1<<7))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PK0

#define HDW_DIO_PK0_MODE_OUTPUT() {DDRK |= (1<<0);}
#define HDW_DIO_PK0_MODE_INPUT() {DDRK &= ~(1<<0);}
#define HDW_DIO_PK0_OFF() {PORTK &= ~(1<<0);}
#define HDW_DIO_PK0_ON() {PORTK |= (1<<0);}
#define HDW_DIO_PK0_TOGGLE() {PORTK ^= (1<<0);}
#define HDW_DIO_PK0_READ ((PINK &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PK1

#define HDW_DIO_PK1_MODE_OUTPUT() {DDRK |= (1<<1);}
#define HDW_DIO_PK1_MODE_INPUT() {DDRK &= ~(1<<1);}
#define HDW_DIO_PK1_OFF() {PORTK &= ~(1<<1);}
#define HDW_DIO_PK1_ON() {PORTK |= (1<<1);}
#define HDW_DIO_PK1_TOGGLE() {PORTK ^= (1<<1);}
#define HDW_DIO_PK1_READ ((PINK &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PK2

#define HDW_DIO_PK2_MODE_OUTPUT() {DDRK |= (1<<2);}
#define HDW_DIO_PK2_MODE_INPUT() {DDRK &= ~(1<<2);}
#define HDW_DIO_PK2_OFF() {PORTK &= ~(1<<2);}
#define HDW_DIO_PK2_ON() {PORTK |= (1<<2);}
#define HDW_DIO_PK2_TOGGLE() {PORTK ^= (1<<2);}
#define HDW_DIO_PK2_READ ((PINK &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PK3

#define HDW_DIO_PK3_MODE_OUTPUT() {DDRK |= (1<<3);}
#define HDW_DIO_PK3_MODE_INPUT() {DDRK &= ~(1<<3);}
#define HDW_DIO_PK3_OFF() {PORTK &= ~(1<<3);}
#define HDW_DIO_PK3_ON() {PORTK |= (1<<3);}
#define HDW_DIO_PK3_TOGGLE() {PORTK ^= (1<<3);}
#define HDW_DIO_PK3_READ ((PINK &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PK4

#define HDW_DIO_PK4_MODE_OUTPUT() {DDRK |= (1<<4);}
#define HDW_DIO_PK4_MODE_INPUT() {DDRK &= ~(1<<4);}
#define HDW_DIO_PK4_OFF() {PORTK &= ~(1<<4);}
#define HDW_DIO_PK4_ON() {PORTK |= (1<<4);}
#define HDW_DIO_PK4_TOGGLE() {PORTK ^= (1<<4);}
#define HDW_DIO_PK4_READ ((PINK &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PK5

#define HDW_DIO_PK5_MODE_OUTPUT() {DDRK |= (1<<5);}
#define HDW_DIO_PK5_MODE_INPUT() {DDRK &= ~(1<<5);}
#define HDW_DIO_PK5_OFF() {PORTK &= ~(1<<5);}
#define HDW_DIO_PK5_ON() {PORTK |= (1<<5);}
#define HDW_DIO_PK5_TOGGLE() {PORTK ^= (1<<5);}
#define HDW_DIO_PK5_READ ((PINK &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PK6

#define HDW_DIO_PK6_MODE_OUTPUT() {DDRK |= (1<<6);}
#define HDW_DIO_PK6_MODE_INPUT() {DDRK &= ~(1<<6);}
#define HDW_DIO_PK6_OFF() {PORTK &= ~(1<<6);}
#define HDW_DIO_PK6_ON() {PORTK |= (1<<6);}
#define HDW_DIO_PK6_TOGGLE() {PORTK ^= (1<<6);}
#define HDW_DIO_PK6_READ ((PINK &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PK7

#define HDW_DIO_PK7_MODE_OUTPUT() {DDRK |= (1<<7);}
#define HDW_DIO_PK7_MODE_INPUT() {DDRK &= ~(1<<7);}
#define HDW_DIO_PK7_OFF() {PORTK &= ~(1<<7);}
#define HDW_DIO_PK7_ON() {PORTK |= (1<<7);}
#define HDW_DIO_PK7_TOGGLE() {PORTK ^= (1<<7);}
#define HDW_DIO_PK7_READ ((PINK &(1<<7))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PL0

#define HDW_DIO_PL0_MODE_OUTPUT() {DDRL |= (1<<0);}
#define HDW_DIO_PL0_MODE_INPUT() {DDRL &= ~(1<<0);}
#define HDW_DIO_PL0_OFF() {PORTL &= ~(1<<0);}
#define HDW_DIO_PL0_ON() {PORTL |= (1<<0);}
#define HDW_DIO_PL0_TOGGLE() {PORTL ^= (1<<0);}
#define HDW_DIO_PL0_READ ((PINL &(1<<0))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PL1

#define HDW_DIO_PL1_MODE_OUTPUT() {DDRL |= (1<<1);}
#define HDW_DIO_PL1_MODE_INPUT() {DDRL &= ~(1<<1);}
#define HDW_DIO_PL1_OFF() {PORTL &= ~(1<<1);}
#define HDW_DIO_PL1_ON() {PORTL |= (1<<1);}
#define HDW_DIO_PL1_TOGGLE() {PORTL ^= (1<<1);}
#define HDW_DIO_PL1_READ ((PINL &(1<<1))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PL2

#define HDW_DIO_PL2_MODE_OUTPUT() {DDRL |= (1<<2);}
#define HDW_DIO_PL2_MODE_INPUT() {DDRL &= ~(1<<2);}
#define HDW_DIO_PL2_OFF() {PORTL &= ~(1<<2);}
#define HDW_DIO_PL2_ON() {PORTL |= (1<<2);}
#define HDW_DIO_PL2_TOGGLE() {PORTL ^= (1<<2);}
#define HDW_DIO_PL2_READ ((PINL &(1<<2))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PL3

#define HDW_DIO_PL3_MODE_OUTPUT() {DDRL |= (1<<3);}
#define HDW_DIO_PL3_MODE_INPUT() {DDRL &= ~(1<<3);}
#define HDW_DIO_PL3_OFF() {PORTL &= ~(1<<3);}
#define HDW_DIO_PL3_ON() {PORTL |= (1<<3);}
#define HDW_DIO_PL3_TOGGLE() {PORTL ^= (1<<3);}
#define HDW_DIO_PL3_READ ((PINL &(1<<3))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PL4

#define HDW_DIO_PL4_MODE_OUTPUT() {DDRL |= (1<<4);}
#define HDW_DIO_PL4_MODE_INPUT() {DDRL &= ~(1<<4);}
#define HDW_DIO_PL4_OFF() {PORTL &= ~(1<<4);}
#define HDW_DIO_PL4_ON() {PORTL |= (1<<4);}
#define HDW_DIO_PL4_TOGGLE() {PORTL ^= (1<<4);}
#define HDW_DIO_PL4_READ ((PINL &(1<<4))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PL5

#define HDW_DIO_PL5_MODE_OUTPUT() {DDRL |= (1<<5);}
#define HDW_DIO_PL5_MODE_INPUT() {DDRL &= ~(1<<5);}
#define HDW_DIO_PL5_OFF() {PORTL &= ~(1<<5);}
#define HDW_DIO_PL5_ON() {PORTL |= (1<<5);}
#define HDW_DIO_PL5_TOGGLE() {PORTL ^= (1<<5);}
#define HDW_DIO_PL5_READ ((PINL &(1<<5))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PL6

#define HDW_DIO_PL6_MODE_OUTPUT() {DDRL |= (1<<6);}
#define HDW_DIO_PL6_MODE_INPUT() {DDRL &= ~(1<<6);}
#define HDW_DIO_PL6_OFF() {PORTL &= ~(1<<6);}
#define HDW_DIO_PL6_ON() {PORTL |= (1<<6);}
#define HDW_DIO_PL6_TOGGLE() {PORTL ^= (1<<6);}
#define HDW_DIO_PL6_READ ((PINL &(1<<6))!=0)

//----------------------------------------------------------------------
// Definitions for port-bit PL7

#define HDW_DIO_PL7_MODE_OUTPUT() {DDRL |= (1<<7);}
#define HDW_DIO_PL7_MODE_INPUT() {DDRL &= ~(1<<7);}
#define HDW_DIO_PL7_OFF() {PORTL &= ~(1<<7);}
#define HDW_DIO_PL7_ON() {PORTL |= (1<<7);}
#define HDW_DIO_PL7_TOGGLE() {PORTL ^= (1<<7);}
#define HDW_DIO_PL7_READ ((PINL &(1<<7))!=0)



//----------------------------------------------------------------------
#endif // #if defined (CONTROLLINO_MAXI) || defined (CONTROLLINO_MAXI_AUTOMATION) || defined (CONTROLLINO_MEGA)
//----------------------------------------------------------------------



//----------------------------------------------------------------------
// Definitions for ADC
#define HDW_DIO_ADSC_ON() {ADCSRA |= (1<<6);}


//-------------------------------------------------------------------
//

// Pin that will be read by ADC in Interrupt
// Remark: CPU numbering system!
#define HDW_ADC_MUX_0TO4_12 (0x46)
#define HDW_ADC_MUX_0TO4_13 (0x47)
#define HDW_ADC_MUX_5 (0x08)


//-------------------------------------------------------------------
// NOP instruction
//
#define HDW_NOP __asm__ __volatile__ ("nop\n\t")
#define HDW_NOP_2 {HDW_NOP;}
#define HDW_NOP_4 {HDW_NOP_2;HDW_NOP_2;}

//-------------------------------------------------------------------
//
#define HDW_GLOBINT_ON __asm__ __volatile__ ("sei\n\t")  
#define HDW_GLOBINT_OFF __asm__ __volatile__ ("cli\n\t")  




//------------------------------------------------------------------------------------------------------------------------
// Project specific definitions
//------------------------------------------------------------------------------------------------------------------------

#include "Prj_Hdw.h"


//#############################################################################
//#############################################################################
//#############################################################################
#endif
