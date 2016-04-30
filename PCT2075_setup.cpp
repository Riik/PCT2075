#include "PCT2075_setup.h"
#include "PCT2075.h"
#include "external_board.h"
#include "TestSignal.h"
#include "TestMode.h"
//#include "exit_testmode.h"

int byteswritten, result, state;
float temperature;
int16_t x2_temperature;
byte register_select;

const char sens_addrs_flt[] = {0x37, 0x35, 0x36, 0x74, 0x2D, 0x2F, 0x71, 0x2C, 0x2E};
const char sens_addrs_gnd[] = {0x76, 0x28, 0x2A, 0x73, 0x4A, 0x4E, 0x70, 0x48, 0x4C};

#define ledpin 13
/**
 * This function intializes the Arduino and the library functions
 */
void setup()
{
	Wire.begin();                // join i2c bus (address optional for master)
	Serial.begin(115200);        // start serial communication at 115200 baud

	//set pinmodes
	pinMode(MULTIPLEXER_A, OUTPUT);
	pinMode(MULTIPLEXER_B, OUTPUT);
	pinMode(IAMP_IN, INPUT);
	digitalWrite(MULTIPLEXER_A, LOW);
	digitalWrite(MULTIPLEXER_B, LOW);
	pinMode(led, OUTPUT);
	pinMode(POWER_PIN, OUTPUT);

	//use external voltage reference
	analogReference(EXTERNAL);

	//  init_io_expander();
	init_DAC();
	digitalWrite(POWER_PIN, LOW);
	delay(50);
	digitalWrite(POWER_PIN, HIGH);
}

/**
 * This is the main loop of the program.
 */
void loop()
{
	delay(500);
	digitalWrite(ledpin, HIGH);
	delay(500);
	digitalWrite(ledpin, LOW);
//	read_temperatures();
	testmode(TESTMODE_2);
}
