/*
 * Serial.h
 *
 *  Created on: 20 apr. 2016
 *      Author: Rik van der Vlist
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include  "Arduino.h"

extern void print_error_msg(int result);
extern void printBits_8(uint8_t myInt);
extern void printBits_16(uint16_t myInt);
extern void check_returncode(int result, String name);

#endif /* SERIAL_H_ */
