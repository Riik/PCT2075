/**
 * This file contains all functions that are related to communication with the PCT2075 sensor
 */
#include "PCT2075_setup.h"


/**
* This function calls the read_temperature function for all sensors
*/
void read_temperatures(void){
	uint8_t i;
	uint16_t value;
	namebuffer("TEMPERATURE");
	for(i = 0; i < 4; i++){
		set_multiplexer(i);
		for(int j = 0; j < 9; j++){
			value = read_register(sens_addrs_gnd[j], 0x00);
			bufferinsert(j+i*9, (float) (value >> 5) * 0.125);
		}
	}
	printbuffer();
}

/**
 * This function reads a single register over I2C for one device.
 * @param SENS_ADDR The 7-bit device address of the DUT
 * @param REG_ADDR the 8-bit register address of the DUT that needs to be read
 * @return the value read from the register of the DUT
 */
uint16_t read_register(byte SENS_ADDR, byte REG_ADDR)
{
  uint16_t reading = 0;
  // instruct sensor to return a particular echo reading
  Wire.beginTransmission(SENS_ADDR); // transmit to PCT2075 temp sensor
  Wire.write(REG_ADDR);      // sets register pointer to echo #1 register (0x02)
  result = Wire.endTransmission();      // stop transmitting
  if(result)
  {
      Serial.println(F("PCT2075:"));
      print_error_msg(result);
  }
  // request reading from sensor
  Wire.requestFrom(SENS_ADDR, byte(0x02));    // request 2 bytes from slave device #112

  // receive reading from sensor
  if(2 <= Wire.available())    // if two bytes were received
  {
    reading = Wire.read();  // receive high byte (overwrites previous reading)
    reading = reading << 8;    // shift high byte to be high 8 bits
    reading |= Wire.read(); // receive low byte as lower 8 bits
  } else {
	  Serial.println("ERROR reading register");
  }
  return reading;
}

uint8_t read_register_byte(byte SENS_ADDR, byte REG_ADDR)
{
  uint8_t reading = 0;
  // instruct sensor to return a particular echo reading
  Wire.beginTransmission(SENS_ADDR); // transmit to PCT2075 temp sensor
  Wire.write(REG_ADDR);      // sets register pointer to echo #1 register (0x02)
  result = Wire.endTransmission();      // stop transmitting

  if(result)
  {
      Serial.println(F("PCT2075:"));
      print_error_msg(result);
  }
  // request reading from sensor
  Wire.requestFrom(SENS_ADDR, byte(0x01));    // request 2 bytes from slave device
  // receive reading from sensor
  if(Wire.available()){
	reading = Wire.read();  // receive byte
  } else {
	  Serial.println("ERROR reading register");
  }
  return reading;
}

/**
 * Write a word/uint16_t value to a two byte register on the DUT
 * @param SENS_ADDR the 7-bit slave address of the temperature sensor
 * @param REG_ADDR the pointer for the register that is to be written
 * @param value the contents of the register
 */
void write_register(byte SENS_ADDR, byte REG_ADDR, uint16_t value){
	  Wire.beginTransmission(SENS_ADDR); // transmit to PCT2075 temp sensor
	  Wire.write(byte(value >> 8));
	  Wire.write(byte(value & 0x00FF));
	  result = Wire.endTransmission();
}

/**
 * Write a single byte register on the DUT
 * @param SENS_ADDR the 7-bit slave address of the temperature sensor
 * @param REG_ADDR the pointer for the register that is to be written
 * @param value the contents of the register
 */
void write_register_byte(byte SENS_ADDR, byte REG_ADDR, uint8_t value){
	  Wire.beginTransmission(SENS_ADDR); // transmit to PCT2075 temp sensor
	  Wire.write(byte(value));
	  result = Wire.endTransmission();
}

/**
 * This function puts a selected I2C device in shutdown/sleep mode
 * @param SENS_ADDR The 7-bit device address
 * @param num The number of the device on the PCB
 */
void sleep_PCT2075(byte SENS_ADDR, int num)
{
  Wire.beginTransmission(SENS_ADDR); // transmit to PCT2075 temp sensor
  Wire.write(byte(0x01));      // sets register pointer to analog mux
  Wire.write(byte(0x01));      // do not use first part of 16-bit register
  result = Wire.endTransmission();      // stop transmitting
}
/**
 * This function wakes a selected I2C device from sleep/shutdown mode
 * @param SENS_ADDR The 7-bit device address
 * @param num The number of the device on the PCB
 */
void wake_PCT2075(byte SENS_ADDR, int num)
{
  Wire.beginTransmission(SENS_ADDR); // transmit to PCT2075 temp sensor
  Wire.write(byte(0x01));      // sets register pointer to analog mux
  Wire.write(byte(0x00));      // do not use first part of 16-bit register
  result = Wire.endTransmission();      // stop transmitting
}
