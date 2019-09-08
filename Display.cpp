#include "Display.h"

void Display::build_screen()
{
	START;

	END;
}

Display::Display()
	:mode(_Test),
	tft(SSD_13XX(_cs, _dc)),
	errorCode(0)
{
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
}

Display Display::create()
{
	START;

	END;
	return Display();

}

void Display::update()
{
	START;

	switch (mode)
	{
	case _Default_Display:
		break;
	case _Test:
		//display_test(&tft);
		show_button_presses();
		break;
	default:
		build_screen();
	}

	END;
}

void Display::show_button_presses()
{
}
