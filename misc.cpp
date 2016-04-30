/*
 * misc.cpp
 * This files holds all functions that not belong to any of the other categories.
 *  Created on: 25 apr. 2016
 *      Author: Rik van der Vlist
 */
#include "PCT2075_setup.h"

/**
 * This function applies a given function to all the DUTs.
 * It sets the multiplexer and loops trough all the I2C adresses.
 * @param repeat_func the function that is to be executed. The function pointer must point to a function with a _byte_ and an _int_ as arguments.
 */
void apply_to_all_PCT2075(void (*repeat_func) (byte, int))
{
  for(unsigned int i=0; i < 4; i++)
  {
    // set multiplexer lines
    set_multiplexer(i);
    // read all sensors in row
    for(int j=0; j < 9; j++ )
    {
      repeat_func(sens_addrs_gnd[j], j+i*9);
    }
  }
}
/**
* Does the same as the apply_to_all_PCT2075() function, but only for a single row.
* @param repeat_func the function that is to be repeated
* @param i the number of the active row
*/
void apply_to_row(void (*repeat_func) (byte, int), int i)
{
  for(int j=0; j < 9; j++ )
  {
    repeat_func(sens_addrs_gnd[j], j+i*9);
    delay(1);
  }
}



