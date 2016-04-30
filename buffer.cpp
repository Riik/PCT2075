#include "PCT2075_setup.h"
#include "PCT2075.h"
#include "external_board.h"
#include "buffer.h"
#include "Arduino.h"
///This array functions as the main buffer to store measured values.
float buffer[36];
/// This string holds the name/identifier of the buffer.
char buffername[15];
/**
 * Sets the identifier for the buffer to indicate what kind of storage the type of storage the buffer is used for.
 * This identifier/name is also used when the buffer prints its outptut.
 * @param name the identifier/name that is given to the buffer. Max length 15 characters.
 */
void namebuffer(const char name[]){
	uint8_t i;
	for(i = 0; i < 14 && name[i] != '\0'; i++){
		buffername[i] = name[i];
	}
}
/**
 * Inserts a value in a given position into the buffer
 * @param index the place to insert the value into the bufer
 * @param value that will be added to the buffer
 */
void bufferinsert(int index, float value){
	if(index >= 36) return;
	buffer[index] = value;
	Serial.print("Number: "); Serial.print(index);
	Serial.print("\tValue: "); Serial.println(value);
}

/**
 * Prints the name/identifier and all values in the buffer to the Serial output,
 * separated by comma's.
 */
void printbuffer(void){
	uint8_t i;
	Serial.print(buffername);
	for(i = 0; i < 36; i++){
		Serial.print(", ");
		Serial.print(buffer[i]);
	}
}

/**
 * Initializes the buffer by setting all the values in the buffer to zero.
 */
void clearbuffer(void){
	uint8_t i;
	for(i = 0; i < 36; i++){
		buffer[i] = 0;
	}
}
