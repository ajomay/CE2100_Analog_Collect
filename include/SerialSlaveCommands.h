// #############################################################################
//  SerialSlaveCommands.H
//
//
//
//  Created: 09.09.2023
//  History:
//
//  (C) ce.tron Gesellschaft fuer Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################
#ifndef __SerialSlaveCommands_H_LOADED_72C181075699__
#define __SerialSlaveCommands_H_LOADED_72C181075699__
// #############################################################################

enum SerialSlaveCommands
{
    CMD_GET_ALIVE = '0',
    CMD_GET_ID = '#',
    CMD_GET_LASTERR_NUM = '9',
    CMD_SET_DEV_ADDR = 'N',
    CMD_SAVE_EEPROM = 'X',
    CMD_FACTORY_RESET = 'Z',
    CMD_GET_COMMAND = 'c',
    CMD_SET_COMMAND = 'C',
};

//-------------------------------------------------------------------
//

// #############################################################################
// #############################################################################
// #############################################################################
#endif
