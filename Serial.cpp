#include "Serial.h"
#include "PCT2075_setup.h"

/**
 * Checks the I2C return code and prints an error message if necessary.
 * @param result the return value of the I2C Wire.EndTransmission() function
 */
void print_error_msg(int result)
{
    switch(result)
    {
       case 1:
           Serial.println(F("Too much data in buffer"));
           break;
       case 2:
           Serial.println(F("No ACK on address"));
           break;
       case 3:
           Serial.println(F("No ACK on data"));
           break;
       case 4:
           Serial.println(F("Unknown error occurred"));
           break;
       default:
    	   Serial.println(F("Something wierd happened"));
    }
}
/**
 * Prints a identifier + error message if a nonzero returncode is provided as an argument
 * @param result the return value of the I2C Wire.EndTransmission() function
 * @param name the identifier to be printed along with the error message
 */
void check_returncode(int result, String name)
{
  if(result)
  {
      Serial.print(name);
      Serial.print(F(" ERROR: "));
      print_error_msg(result);
  }
}

/**
 * Prints the binary value of a short/byte in ASCII
 * @param myInt the byte to be printed to Serial output
 */
void printBits_8(uint8_t myInt){
 for(uint8_t mask = 0x80; mask; mask >>= 1)
 {
   if(mask  & myInt)
       Serial.print('1');
   else
       Serial.print('0');
 }
 Serial.println();
}

/**
 * Prints the binary value of a int/word in ASCII
 * @param myInt the uint to be printed to Serial output
 */
void printBits_16(uint16_t myInt){
 for(uint16_t mask = 0x8000; mask; mask >>= 1)
 {
   if(mask  & myInt)
       Serial.print('1');
   else
       Serial.print('0');
 }
 Serial.println();
}
