#pragma once

#include <SPI.h>
#include <SSD_13XX.h>
#include "My_Enums.h"
#include "Display_Test.h"
#include "Bug.h"

// For the ESP32
#define _cs   17  // goes to TFT CS
#define _dc   16  // goes to TFT DC
#define _mosi 23  // goes to TFT MOSI
#define _sclk 18  // goes to TFT SCK/CLK
#define _rst  5   // ESP RST to TFT RESET
#define _miso     // Not connected
//       3.3V     // Goes to TFT LED  
//       5v       // Goes to TFT Vcc
//       Gnd      // Goes to TFT Gnd      

class Display
{
protected:
	// Put all variables associated with the display itself here.
	static int height;
	static int width;

	static SSD_13XX tft;

	static uint8_t errorCode;

	static Display_Display_Mode mode;

	//void display_test();
	static void build_screen();

public:
	Display();

	static Display create();

	static void update();
	

};

