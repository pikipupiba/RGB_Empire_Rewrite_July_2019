#include "Display.h"

Display_Mode Display::mode = Test;
SSD_13XX Display::tft = SSD_13XX(_cs, _dc);
uint8_t Display::errorCode = 0;

void Display::build_screen()
{
	START;

	END;
}

Display::Display()
{
	
}

Display* Display::create()
{
	START;

	long unsigned debug_start = millis();
	while (!Serial && ((millis() - debug_start) <= 5000));
	tft.begin(false);
	delay(30);
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
		Serial.println(F("Benchmark Sketch V1.1"));
		tft.setTextColor(YELLOW);
		tft.setTextScale(2);
	}

	return new Display;

	END;
}

void Display::update()
{
	START;

	switch (mode)
	{
	case Test:
		display_test(&tft);
		break;
	default:
		build_screen();
	}

	END;
}
