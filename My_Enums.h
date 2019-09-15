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

enum End_Of_Range
{
	_Default_EOR,
	_Loop,
	_Bounce,
	_Stop
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
	_Rainbow_Wave,
	_Glitter,
	_Rainbow_Wave_With_Glitter,
	//_Random_Rainbow_Wave,
	_Sinelon,
	_Mr_Poopy_Worm,
	_Artnet,
	_Default,
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

// An LED_Group represents CRGBSets that will pull from the same pixel data.
struct LED_Group
{
	std::vector<CRGBSet> leds;	// Vector of CRGBSets that refer directly to parts of the LED_Fixture g_leds.
	int group_number;	// The group number. Even groups on different strips will copy each other if their group number is the same.

	int strip_number;	// The strip that this group is on.

	int size;			// The size of a group is equal to the largest CRGBSet it contains.

	int get_size();		// Calculates the size of the group.
	void add_to_group(LED_Group new_group);
};

// Every strip has 1 arrangement per display mode.
// TODO: Make a function to collapse an Arrangements struct into a single Arrangement struct for animations to use.
struct LED_Arrangement
{
	Strip_Display_Mode strip_display_mode;	// Display modes represent different ways to run animations on a given set of leds.

	std::vector<LED_Group> led_groups;		// Each arrangement contains 1 or more groups.

	int num_groups;	// The number of groups the arrangement contains.
	int size;		// The sum of the group sizes. Represents the total amount of pixels an animation must generate.

	int get_num_groups();
	int get_size();
};

// The selected arrangement for each strip is combined into this struct to be passed to animations and such.
struct LED_Arrangements
{
	std::vector<LED_Arrangement> arrangements;

	int num_groups;
	int size;

	int get_num_groups();
	int get_size();

	int get_artnet_size();

	LED_Arrangement compress();
};

enum Variable_Name
{
	_vBrightness,
	_vPosition,
	_vHue,
	_vSize,
	_vDensity,
	_vFade
};

// TODO: make value, speed, acceleration vector based to facilitate flexible movement profiles.
struct Bounded_Variable
{
	float value =		0.0;
	float min =			0.0;
	float max =			0.0;

	End_Of_Range eor =	_Loop;

	Bounded_Variable(float new_value, float new_min, float new_max, End_Of_Range new_eor);
	bool is_at_eor();
	void make_positive();
	void make_negative();
};

struct Animation_Variable
{
	Variable_Name name;

	Bounded_Variable value;
	Bounded_Variable speed;
	Bounded_Variable acceleration;
	Bounded_Variable offset;

	End_Of_Range eor;

	//Animation_Variable(Variable_Name new_name, Bounded_Variable new_value, Bounded_Variable new_speed, Bounded_Variable new_acceleration, Bounded_Variable new_offset, End_Of_Range new_eor);
	//Animation_Variable(Variable_Name new_name, float new_value, float new_speed, float new_offset, float new_min, float new_max, End_Of_Range new_eor);
	Animation_Variable(Variable_Name new_name, float new_value, float new_speed, float new_acceleration, float new_offset, float new_min, float new_max, End_Of_Range new_eor);

	void update();
};

// This struct should contain all variables required to calculate an animation an how it changes over time.
// Floats are used to ensure smooth transitions, slow movements, and antialiasing are possible.
constexpr int num_palettes = 10; // TODO: actually implement palettes

struct Animation_Variables
{
	float range_start = 0.0;
	float range_end = 0.0;

	Animation_Variable brightness;
	Animation_Variable position;
	Animation_Variable hue;
	Animation_Variable size;
	Animation_Variable density;
	Animation_Variable fade;

	// TODO: maybe make a struct to handle an animation's palettes
	CRGBPalette16 palette_current = CRGBPalette16(CRGB::Black);
	CRGBPalette16 palette_next = CRGBPalette16(RainbowColors_p);
	int palette_current_ID = 0;
	int palette_next_ID = 0;
	int palette_cycle = 0;	// =0 means palette does not cycle, >0 signifies the amount of time between palette changes in millis
	int palette_cycle_speed = 24;	// Speed at which to blend current palette to new palette. Usually beteen 1 and 48
	unsigned long palette_last_time = 0;// The time the palette last switched.

	// TODO: implement palettes
	// The palettes that are currently available for the animation to pick between.
	bool palette_mask[num_palettes] = { true, true, true, true, true, true, true, true, true, true };

	int stage = 0;				// =0 means it has not started and must be initialized, >0 can be used to keep track of various stages

	Strip_Display_Mode strip_display_mode;

	//Animation_Variables(float new_range_start, float new_range_end, float new_brightness, float new_position, float new_hue, float new_size, float density, float new_fade);
	Animation_Variables(float new_range_start, float new_range_end);

};

// TODO: maybe make struct to eliminate all the repeated code here and in Animation::update_vars()
struct Animation_Variables_Old
{
	// The current brightness of the animation.
	float brightness =				255.0;
	float brightness_speed =		0.0;
	float brightness_acceleration =	0.0;
	float brightness_offset =		0.0;
	float brightness_min =			0.0;
	float brightness_max =			255.0;
	End_Of_Range brightness_eor =	_Bounce;

	// Position is used to calculate the current state of the animation.
	// The logic of speed, acceleration, offset, min, and max extend to all the otehr variables.
	float position =		1.0;	// Value used by this frame of the animation.
	float speed =			0.2;	// How much the position changes each frame.
	float acceleration =	0.0;	// How much the speed changes each frame.
	float position_offset =	0.0;	// Difference in position between different features.
	float position_min =	0.0;	// Minimum value the position can reach regardless of speed, acceleration, etc.
	float position_max =	0.0;	// Maximum value the position can reach regardless of speed, acceleration, etc.

	// The current base hue of the animation.
	float hue =					0.0;
	float hue_speed =			1.0;
	float hue_acceleration =	0.0;
	float hue_offset =			5;
	float hue_min =				0.0;
	float hue_max =				255.0;

	// The size of an animation feature like a moving bar or something.
	float size =				10.0;
	float size_speed =			0.0;
	float size_acceleration =	0.0;
	float size_offset =			0.0;
	float size_min =			1.0;
	float size_max =			20.0;

	// The density of things like sparkles.
	float density = 5.0;
	float density_speed = 0.0;
	float density_acceleration = 0.0;
	float density_offset = 0.0;
	float density_min = 1.0;
	float density_max = 1000.0;

	// How much something fades every frame. Must be less than 255 to make sense;
	float fade =				80.0;
	float fade_speed =			0.0;
	float fade_acceleration =	0.0;
	float fade_offset =			0.0;
	float fade_min =			1.0;
	float fade_max =			255.0;

	float start =		0.0;
	float end =			0.0;
	float range_start =	0.0;
	float range_end =	0.0;

	// TODO: maybe make a struct to handle an animation's palettes
	CRGBPalette16 palette_current = CRGBPalette16(CRGB::Black);
	CRGBPalette16 palette_next = CRGBPalette16(RainbowColors_p);
	int palette_current_ID =	0;
	int palette_next_ID =		0;
	int palette_cycle =			0;	// =0 means palette does not cycle, >0 signifies the amount of time between palette changes in millis
	int palette_cycle_speed =	24;	// Speed at which to blend current palette to new palette. Usually beteen 1 and 48
	unsigned long palette_last_time = 0;// The time the palette last switched.

	// TODO: implement palettes
	// The palettes that are currently available for the animation to pick between.
	bool palette_mask[num_palettes] = { true, true, true, true, true, true, true, true, true, true };

	int stage = 0;				// =0 means it has not started and must be initialized, >0 can be used to keep track of various stages

	Strip_Display_Mode strip_display_mode;
};

#endif

