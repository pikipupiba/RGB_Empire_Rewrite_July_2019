// My_Enums.h

// I'll use this file to store any enumerated values and structs
// until I decide where to put them for realsies.

#ifndef _MY_ENUMS_h
#define _MY_ENUMS_h

#include "arduino.h"

// Shapes from 0-9 are strips.
// Shapes from 10-99 are fixtures.
enum Shape
{
	Linear = 0,
	Folded = 1,
	Panel = 2,
	Circle = 3,
	Spiral = 4,
	Plant = 10,
	Tree = 11,
	Vertical_Lamp = 12
};

enum Display_Mode
{
	Default,
	Test,
	Parallel,
	Sequential,
	Every_Other_Sequential,
	Left_To_Right,
	Middle_Out,
	Around
};

enum Animation_Name
{
	_Base,
	_Rainbow_Wave,
	_Glitter,
	_Rainbow_Wave_With_Glitter,
	_Random_Rainbow_Wave
};

// Use structs to make passing parameters into methods fast and easy.

struct Strip_Parameters
{
	const int strip_pin;
	const int num_leds;
	const int leds_per_meter;
	const Shape shape;
	const int length_in_leds;
	const int width_in_leds;
};

struct Fixture_Parameters
{
	const int num_strips;
	const int total_num_leds;
	const int volts;
	const int milli_amps;
	const Strip_Parameters* strip_parameters[8];
};

struct Animation_Variables
{
	float brightness = 255;
	float brightness_speed = 0;
	float brightness_acceleration = 0;
	float brightness_offset = 0;

	float position = 0;
	float speed = 1;
	float acceleration = 0;
	float position_offset = 0;

	float hue = 0;
	float hue_speed = 1;
	float hue_acceleration = 0;
	float hue_offset = 0;

	float size = 5;
	float size_speed = 0;
	float size_acceleration = 0;
	float size_offset = 0;

	float density = 25.0;

	float range_start = 0;
	float range_end = 0;

	int current_palette = 0;
	int target_palete = 0;
	float cycle_palettes = 0;	// =0 means palette does not cycle, >0 signifies the amount of time it takes the palette to change

	int stage = 0;				// =0 means it has not started and must be initialized, >0 can be used to keep track of various stages

	Display_Mode display_mode;
};


#endif

