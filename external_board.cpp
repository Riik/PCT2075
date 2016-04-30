/*
 * external_board.c

 *
 *  Created on: 20 apr. 2016
 *      Author: Rik van der Vlist
 */
#include "PCT2075_setup.h"

/**
 * Tests the I2C connection to the DAC and sets the output voltage to 0 V.
 */
void init_DAC()
{
  Wire.beginTransmission(byte(DAC_ADDR)); // select DAC
  Wire.write(byte(0x00));      // Write to output register, 600 mV
  Wire.write(byte(0x00));      //
  result = Wire.endTransmission();      // stop transmitting

  if(result)
  {
      Serial.println(F("DAC:"));
      print_error_msg(result);
  } else {
   Serial.println(F("Write to DAC succesful"));
  }
}

/**
 * Sends an I2C command to the DAC on the external board, setting a desired output voltage
 * @param voltage the desired output voltage in mV
 */
void DAC_voltage(uint16_t voltage)
{
  uint32_t temp = 0x00000000;
  uint16_t value;
  Serial.println(voltage);
  //calculate binary data. Vref = 2.5V, 2^10 steps
  temp = ((uint32_t) voltage *1024)/2500;
  Serial.println(temp);
  value = (uint16_t) temp;
  Serial.println(value);
  //compensate for opamp gain
  value >>= 1;
  //shift data to match 10-bit resolutio
  value <<= 2;
  //apply mask; first four command bits must be zero
  value &= 0x0FFF;

  Wire.beginTransmission(byte(DAC_ADDR)); // select DAC
  Wire.write(byte(value >> 8));      // Write to output register
  Wire.write(byte(value & 0x00FF));      //
  result = Wire.endTransmission();      // stop transmitting

  if(!result)
      Serial.println(F("Write to DAC succesfull"));
  else
  {
      Serial.println(F("DAC:"));
      print_error_msg(result);
  }
}
/**
 * This function sets the output pins of the Arduino that drive the
 * multiplexer on the external board
 * @param i the row of the multiplexer that is to be activated. Range: [0-4]
 */
void set_multiplexer(unsigned int i)
{
  if(i&0b0001)
    digitalWrite(MULTIPLEXER_A, HIGH); else
    digitalWrite(MULTIPLEXER_A, LOW);
  if(i&0b0010)
    digitalWrite(MULTIPLEXER_B, HIGH); else
    digitalWrite(MULTIPLEXER_B, LOW);
}
/**
 *\TODO: add buffer for first ten values and last values
 *\TODO: add option for Serial output
 * @param SENS_ADDR
 * @param num
 */
void measure_current(byte SENS_ADDR, int num)
{
	const uint8_t COUNTER_TRESHOLD = 10;
	/// the number of measurements that are done for calculating the average
	const int LOOPCOUNT = 256;
	/// sum of measurements, used for calculating the average
	long reading = 0;
	/// float that holds the calculated average value. This is used as a treshold
	float average;
	/// this is a debounce-style counter to check whether the treshold is passed.
	uint8_t counter = 0;
	uint8_t EDGE1, EDGE2, EDGE3;
	/// the float holding the average baseline current (return value)
	float current;
	Serial.print(F("Reading:  "));
	Serial.println(num);
	// wake the sensor that is to be measured. All other DUTs should be sleeping.
	wake_PCT2075(SENS_ADDR, num);
	delay(3000);
	// do measurements and calculate average
	for(int i = 0; i < LOOPCOUNT; i++)
	{
	reading += analogRead(A0);
	delay(1);
	}
	// put device back to sleep
	sleep_PCT2075(SENS_ADDR, num);
	average =  (float) reading/LOOPCOUNT;
	uint16_t i = 0;
	// search for the high edge of the waveform
	while(counter > COUNTER_TRESHOLD){
		if(analogRead(A0) < average)
			counter++;
		else
			counter = 0;
		i++;
	}
	EDGE1 = i;
	counter = 0;
	// search for the lower edge of of the waveform
	while(counter > COUNTER_TRESHOLD){
		if(analogRead(A0) < average)
			counter++;
		else
			counter = 0;
		i++;
	}
	// calculate sum until reading rise above average treshold
	EDGE2 = i;
	uint16_t value = 0;
	reading = 0;
	while(value < average){
		value = analogRead(A0);
		reading += value;
		i++;
	}
	EDGE3 = i;
	// now calculate the average over this lower period
	current = reading / (EDGE3- EDGE2);
}

