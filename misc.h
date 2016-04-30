/*
 * misc.h
 *
 *  Created on: 25 apr. 2016
 *      Author: Rik van der Vlist
 */

#ifndef MISC_H_
#define MISC_H_

void apply_to_all_PCT2075(void (*repeat_func) (byte, int));
void apply_to_row(void (*repeat_func) (byte, int), int i);



#endif /* MISC_H_ */
