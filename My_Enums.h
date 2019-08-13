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
	Plant = 10,
	Tree = 11
};

enum Display_Mode
{
	Parallel = 0,
	Sequential = 1,
	Every_Other_Sequential = 2
};

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

struct Animation_Parameters
{
	float brightness = 255;

	float position = 0;
	float speed = 0.5;
	float acceleration = 0;

	float hue = 0;
	float hue_speed = 0.5;
	float hue_acceleration = 0;

	float offset = 0;
	float size = 5;
	float size_offset = 0;
};

#endif

