/*
 * TestMode.h
 *
 *  Created on: 27 apr. 2016
 *      Author: Rik van der Vlist
 */

#ifndef TESTMODE_H_
#define TESTMODE_H_

extern void testmode(uint16_t testmode_code);
extern void disable_TWI(void);

extern void write_MTP(uint16_t value, byte REG_ADDR, byte ROW_ADDR);
extern void read_MTP();
extern uint16_t read_X4();
extern void activate_MTP();

extern void sweep_LDO();
extern void sweep_OSC();

extern void read_MTP_trim_values();

#endif /* TESTMODE_H_ */
