// My_Enums.h

// I'll use this file to store any enumerated values and structs
// until I decide where to put them for realsies.

#ifndef _MY_ENUMS_h
#define _MY_ENUMS_h

#include "arduino.h"
#include <vector>
#include <FastLED.h>
#include "Bug.h"

// Shapes from 0-9 are strips.
// Shapes from 10-99 are fixtures.
enum Shape
{
	Linear,
	Folded,
	Panel,
	Circle,
	Polygon,
	Spiral,
	Plant = 10,
	Tree = 11,
	Vertical_Lamp = 12
};

enum Fixture_Display_Mode
{
	Default_Fixture,
	Parallel,
	Sequential,
	Every_Other_Sequential,
};

enum Display_Display_Mode
{
	_Default_Display,
	_SD_Card,
	_Test
};

enum Strip_Display_Mode
{
	Default_Strip,
	Left_To_Right,
	Around,
	Middle_Out
};

enum Animation_Name
{
	_Default,
	_Rainbow_Wave,
	_Glitter,
	_Rainbow_Wave_With_Glitter,
	_Random_Rainbow_Wave,
	_Artnet,
	_Sinelon,
	_Mr_Poopy_Worm,
	_Base,
	_Template_Animation
};

enum Transition_Type
{
	_Fade,
	_Wipe,
	_Dissolve
};

enum Input_Type
{
	_Button,
	_Encoder,
	_Potentiometer,
	_Switch
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

struct led_set
{
	CRGBSet* leds;
};

struct LED_Group
{
	std::vector<CRGBSet> leds;
	int group_number;

	int get_size();
};

struct LED_Arrangement
{
	Strip_Display_Mode strip_display_mode;
	std::vector<LED_Group> led_groups;

	int num_groups;
	int size;

	int get_num_groups();
	int get_size();
};

struct LED_Arrangements
{
	std::vector<LED_Arrangement> arrangements;

	int num_groups;

	int get_size();
};

struct Animation_Variables
{
	float brightness = 255.0;
	float brightness_speed = 0;
	float brightness_acceleration = 0;
	float brightness_offset = 0;

	float position = 1.0;
	float speed = 0.2;
	float acceleration = 0;
	float position_offset = 0;

	float hue = 0;
	float hue_speed = 1.0;
	float hue_acceleration = 0;
	float hue_offset = 5;

	float size = 10.0;
	float size_speed = 0;
	float size_acceleration = 0;
	float size_offset = 0;

	float density = 5.0;
	float fade = 80.0;


	float start = 0;
	float end = 0;
	float range_start = 0;
	float range_end = 0;

	int current_palette = 0;
	int target_palete = 0;
	float cycle_palettes = 0;	// =0 means palette does not cycle, >0 signifies the amount of time it takes the palette to change

	int stage = 0;				// =0 means it has not started and must be initialized, >0 can be used to keep track of various stages

	Strip_Display_Mode strip_display_mode;
};


//class CRGBArray2 : public CPixelView<CRGB> {
//	CRGB rawleds[];
//public:
//	CRGBArray2(int size) : CPixelView<CRGB>(rawleds, size), rawleds(new CRGB[size]) {}
//	using CPixelView::operator=;
//};

#endif

