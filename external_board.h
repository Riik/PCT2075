/*
 * external_board.h
 *
 *  Created on: 20 apr. 2016
 *      Author: Rik van der Vlist
 */

#ifndef EXTERNAL_BOARD_H_
#define EXTERNAL_BOARD_H_

extern void DAC_voltage(uint16_t voltage);
extern void init_DAC();
void set_multiplexer(unsigned int i);

#endif /* EXTERNAL_BOARD_H_ */
