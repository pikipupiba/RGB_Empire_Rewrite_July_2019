#include "Display.h"



void Display::build_screen()
{
	START;

	END;
}

Display::Display()
	:mode(_ddm_Default),
	tft(SSD_13XX(_cs, _dc)),
	errorCode(0),
	time_to_display_avg(6),
	time_to_display_max(0),
	time_to_display_avg_old(0),
	time_to_display_max_old(0),
	total_frames(0)
{
	SPI.begin(_sclk, _miso, _mosi, 35);

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
		tft.setRotation(1);
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

	unsigned long int start = micros();

	switch (mode)
	{
	case _ddm_Default:
		draw_screen_1();
		break;
	case _ddm_Test:
		display_test(tft);
		show_button_presses();
		break;
	default:
		build_screen();
	}

	total_frames++;

	float time_to_display = (micros() - start) / 1000;

	time_to_display_avg = (time_to_display_avg * (total_frames - 1) + time_to_display) / (float)total_frames;

	if(time_to_display > time_to_display_max && millis() > 5000)
	{
		time_to_display_max = time_to_display;
	}

	END;
}

void Display::draw_screen_1()
{
	if (fps != FastLED.getFPS())
	{
		fps = FastLED.getFPS();
		draw_fps(90, 108);
	}
	if (memory != ESP.getFreeHeap() / 1000)
	{
		memory = ESP.getFreeHeap() / 1000;
		draw_memory(0, 108);
	}
	if (!(time_to_display_avg < time_to_display_avg_old * 1.05 && time_to_display_avg > time_to_display_avg_old * 0.95))
	{
		time_to_display_avg_old = time_to_display_avg;
		draw_TTD_avg(0,0);
	}
	if (time_to_display_max != time_to_display_max_old)
	{
		time_to_display_max_old = time_to_display_max;
		draw_TTD_max(0, 20);
	}

}

void Display::show_button_presses()
{
}

void Display::draw_fps(int x, int y, int size)
{
	tft.fillRect(x, y, 38, 20, CRGB::Black);

	tft.setCursor(x + 4, y + 4);
	tft.setTextColor(WHITE);
	tft.setTextScale(size);
	tft.print(fps);
}

void Display::draw_memory(int x, int y, int size)
{
	tft.fillRect(x, y, 70, 20, CRGB::Black);

	tft.setCursor(x + 4, y + 4);
	tft.setTextColor(WHITE);
	tft.setTextScale(size);
	tft.print(memory);
	tft.print(" KB");
}

void Display::draw_TTD_avg(int x, int y, int size)
{
	tft.fillRect(x, y, 80, 20, CRGB::Black);

	tft.setCursor(x + 4, y + 4);
	tft.setTextColor(WHITE);
	tft.setTextScale(size);
	tft.print(time_to_display_avg);
	tft.print(" ms");
}

void Display::draw_TTD_max(int x, int y, int size)
{
	tft.fillRect(x, y, 70, 20, CRGB::Black);

	tft.setCursor(x + 4, y + 4);
	tft.setTextColor(WHITE);
	tft.setTextScale(size);
	tft.print(time_to_display_max);
	tft.print(" ms");
}
