// Physical_Input.h

// This is where all code pertaining to receiving input from physical
// buttons, knobs, encoders, and sensors is located.

#ifndef _PHYSICAL_INPUT_h
#define _PHYSICAL_INPUT_h


#include "arduino.h"
#include "EasyButton.h"


//#define ENCODER_USE_INTERRUPTS
#define ESP32
//#include <Encoder.h>

#define _Best_Button_Pin 32
#define _Rotary_Button_Pin 34
#define _Rotary_Pin_A 36
#define _Rotary_Pin_B 35

class Physical_Input
{
protected:
	bool enabled;

	EasyButton best_Button;
	EasyButton rotary_Button;
	//Encoder encoder;

	static void best_Button_on_pressed();

public:
	Physical_Input();

	void setup();

	void check();
};

#endif

