#include <SPI.h>
#include <TFT_ILI93XX.h>

/*
Teensy 3.5 alternative SPI1 test.
You can force SPI1 by using mosi = 0 and sclk = 32 (on T5)
In this way the CS pin is limited to pin 6 (cannot be changed), but it's still possible
manage the dc pin in the old way so as DC pin you can use any.
It will not be as fast as SPI0 since it uses FIFO with 4 bytes buffer and low level pin manipulation
and this method is forced to 1 buffer lenght and almost standard pin manipulation.
This sketch it's here just for test
 */
#define __CS1 	6
#define __DC 	9


uint8_t errorCode = 0;

TFT_ILI93XX tft = TFT_ILI93XX(6, 10, 255, 0, 32);

void setup() {
	Serial.begin(38400);
	long unsigned debug_start = millis();
	while (!Serial && ((millis() - debug_start) <= 5000));
	Serial.println("serial ok, testing lib...");
  tft.begin();

  //the following it's mainly for Teensy
  //it will help you to understand if you have choosed the
  //wrong combination of pins!
  errorCode = tft.getErrorCode();
  if (errorCode != 0) {
	  Serial.print("Init error! ");
	  if (bitRead(errorCode, 0)) Serial.print("MOSI or SCLK pin mismach!\n");
	  if (bitRead(errorCode, 1)) Serial.print("CS or DC pin mismach!\n");
  }
  else {
	  tft.println("You got it");
  }
}

void loop(void) {
}