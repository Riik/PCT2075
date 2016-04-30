/*
 * TestMode.cpp
 * \brief All functions related to entering, exiting and adjusting parameters in the Testmode
 *  Created on: 27 apr. 2016
 *      Author: Rik van der Vlist
 */
#include "PCT2075_setup.h"

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
/**
 * This function writes a two byte value temporary to the trim registers, which cannot be written directly over I2C.
 * First the word is written to the holding register, and then the contents of the holding register are transfered to the trim registers
 * using the MTP control. See the PCT2075 testmode summary for further reference.
 * @param SENS_ADDR the 7-bit address of the slave device
 * @param ROW_ADDR the row address of the MTP register.
 * @param value the values to be written to the MTP/trim registers.
 */
void write_MTP(byte SENS_ADDR, byte ROW_ADDR, uint16_t value)
{
	uint8_t temp;
	// prepare the command for MTP control register: set MTP active and address bits
	temp = (ROW_ADDR <<  4) | 0x80;
	// activate the MTP register
	write_register(SENS_ADDR, MTP_CONTROL_REG, (uint16_t) temp);
	#ifdef VERBOSE
	Serial.print(F("Activating MTP: ")); printBits_8(temp);
	#endif

	write_register(SENS_ADDR, HOLDING_REGISTER, value);
	// set MTP control to MTP active, MTP read holding and set MTP ROW address
	temp = (ROW_ADDR << 4) | 0x88;
	#ifdef VERBOSE
	Serial.print(F("Writing RDH bit: ")); printBits_8(temp);
	#endif
	// first byte of register are 0x00, second byte is MTP control
	write_register(SENS_ADDR, MTP_CONTROL_REG, (uint16_t) temp);
	// wait for device to write the MTP register
	delay(50);
}

void read_x4_registers(byte SENS_ADDR){
	uint16_t batchid;
	uint8_t adcreg;
	testmode(TESTMODE_3);
	adcreg = read_register_byte(SENS_ADDR, ADC_OSC_REG);
	batchid = read_register(SENS_ADDR, BATCHID_REG);
}


