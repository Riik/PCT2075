/*
 * TestMode.cpp
 * \brief All functions related to entering, exiting and adjusting parameters in the Testmode
 *  Created on: 27 apr. 2016
 *      Author: Rik van der Vlist
 */
#include "Arduino.h"
#include "PCT2075_setup.h"
#include "TestMode.h"
#include "TestSignal.h"

/**
 * This function enters a certain testmode. First the board is power cycled, and then
 * the assembler function that generates the desired signal is called. The function also disable the Wire/TWI interface
 * and re-enables it afterwards. Assuming FCPU = 8 MHz, the signal is generated at 400 kHz.
 * @param testmode_code the 13-bits testmode signal (see PCT2075 Testmode description). Left 3 MSb's of signal are neglected.
 */
void testmode(uint16_t testmode_code)
{
  //disable I2C/TWI interface, so the Arduino doesn't mess up because of the testmode signal
  disable_TWI();
  #ifdef VERBOSE
  Serial.println(F("Power-cycling board..."));
  #endif
  digitalWrite(POWER_PIN, LOW);
  delay(5000);
  digitalWrite(POWER_PIN, HIGH);
  delay(500);
  #ifdef VERBOSE
  Serial.println(F("Board reset."));
  #endif
  // set A4 and A5 up as manual output pins
  pinMode(p_SDA_ts, OUTPUT);
  pinMode(p_SCL_ts, OUTPUT);
//  Serial.println(F("*****Entering test mode...");
  digitalWrite(led, HIGH);
  //enter test mode signal
  TestSignal(testmode_code);
}

/**
* Disables the hardware TWI interface of the ATMega 328P.
* This is necessary in order to use the pins as IO pins
*/
void disable_TWI(void)
{
  TWCR &= !(1<<TWEN);
}
/*
extern void write_MTP(uint16_t value, byte REG_ADDR, byte ROW_ADDR)
{
	for(int row =0; row < 4; row++){
		// for each row, set the multiplexer and then send the testmode signal
		set_multiplexer(row);
		testmode(TESTMODE_3);
		for(int i = 0; i < 9; i++){

		}
	}
}
*/
extern void write_MTP(uint16_t value, byte SENS_ADDR, byte REG_ADDR, byte ROW_ADDR)
{
	uint8_t register_value;

	#ifdef VERBOSE
	Serial.println(F("Current value of ADC/OSC trim REG:"));
	#endif




}


