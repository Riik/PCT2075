/*
 * PCT2075.h
 *
 *  Created on: 20 apr. 2016
 *      Author: Rik van der Vlist
 */

#ifndef PCT2075_H_
#define PCT2075_H_

extern void read_temperature(byte SENS_ADDR, int num);
extern void sleep_PCT2075(byte SENS_ADDR, int num);
extern void wake_PCT2075(byte SENS_ADDR, int num);
extern uint16_t read_register(byte SENS_ADDR, byte REG_ADDR);
extern void read_temperatures(void);

#endif /* PCT2075_H_ */
