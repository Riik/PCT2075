/*
 * PCT2075_setup.h
 *
 *  Created on: 19 apr. 2016
 *      Author: Rik van der Vlist
 */

#ifndef PCT2075_SETUP_H_
#define PCT2075_SETUP_H_

//#define VERBOSE

#include "Wire.h"
#include "Arduino.h"

extern int byteswritten, result, state;
extern float temperature;
extern int16_t x2_temperature;
extern byte register_select;

extern const char sens_addrs_flt[];
extern const char sens_addrs_gnd[];


#define SENS_ADDR_GND  0x4a
#define SENS_ADDR_FLOAT 0x2f
#define IO_ADDR      0x41
#define DAC_ADDR     0x60
#define IAMP_IN      A0
#define led          13
#define MULTIPLEXER_A 8
#define MULTIPLEXER_B 9
#define POWER_PIN    10
#define VERBOSE

#define TEMP_REG      0x00
#define REG_ALPHA     0x0A
#define REG_A         0x0B
#define REG_B         0x0C
#define REG_LDO       0x09

// USE WITH CARE: some testmodes may be harmful (analog test out) when connected to bus
// #define TESTMODE_0  0x14C8
// #define TESTMODE_1  0x14C7
#define TESTMODE_2  0x14C6
#define TESTMODE_3  0x14C5
#define TESTMODE_4  0x14C4
// #define TESTMODE_5  0x14C3
// #define TESTMODE_6  0x14C2
// #define TESTMODE_7  0x14C1
// #define TESTMODE_8  0x14C0

//output pins for SDA en SCL test signal.
//if these definitions changes, change the pins in the assmebler library as well!
#define p_SDA_ts A4
#define p_SCL_ts A5


#endif /* PCT2075_SETUP_H_ */
