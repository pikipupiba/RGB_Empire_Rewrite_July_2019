#pragma once

#include <SPI.h>
#include <SSD_13XX.h>
#include "My_Enums.h"
#include "Display_Test.h"
#include "Bug.h"


// For the ESP32
#define _cs   23  // goes to TFT CS
#define _dc   33  // goes to TFT DC
#define _mosi 13  // goes to TFT MOSI
#define _sclk 14  // goes to TFT SCK/CLK
#define _rst  9   // ESP RST to TFT RESET
#define _miso 12   // Not connected
//       3.3V     // Goes to TFT LED  
//       5v       // Goes to TFT Vcc
//       Gnd      // Goes to TFT Gnd      

class Display
{
protected:
	// Put all variables associated with the display itself here.
	int height;
	int width;

	Display_Display_Mode mode;

	SSD_13XX tft;

	uint8_t errorCode;

	int fps;
	int memory;
	float time_to_display_avg;
	int time_to_display_max;
	float time_to_display_avg_old;
	int time_to_display_max_old;
	unsigned long total_frames;

	//void display_test();
	static void build_screen();

public:
	Display();

	static Display create();

	void update();

	void draw_screen_1();

	void show_button_presses();
	
	void draw_fps(int x, int y, int size = 2);
	void draw_memory(int x, int y, int size = 2);
	void draw_TTD_avg(int x, int y, int size = 2);
	void draw_TTD_max(int x, int y, int size = 2);
};

