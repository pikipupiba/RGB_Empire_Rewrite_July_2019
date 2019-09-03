// Bug.h

// All functions and variables related to BUGging will go here.

// Use the macro D(1-5)(*your code here*) when putting in BUG code.

// Uncomment the following lines to enable BUGging code.
#define BUG_1	// Free memory after constructors and FPS.
//#define BUG_2	// 
//#define BUG_3	// 
//#define BUG_4	// 
#define BUG_5	// Beginning, middle, and end of every function.

#ifndef _BUG_h
#define _BUG_h

#include "Arduino.h"
#include <vector>

#define START BUG5(Bug::start(__PRETTY_FUNCTION__))
#define THING BUG5(Bug::thing_counter())
#define END BUG5(Bug::end())
#define MEM Bug::display_memory(" after " + String(__PRETTY_FUNCTION__))

#if defined BUG_1
#	define BUG1(x) x
#else
#	define BUG1(x)
#endif

#if defined BUG_2
#	define BUG2(x) x
#else
#	define BUG2(x)
#endif

#if defined BUG_3
#	define BUG3(x) x
#else
#	define BUG3(x)
#endif

#if defined BUG_4
#	define BUG4(x) x
#else
#	define BUG4(x)
#endif

#if defined BUG_5
#	define BUG5(x) x
#else
#	define BUG5(x)
#endif

// This line is used to selectively enable BUGging code without enabling BUG_(1-5)
#define BUG(x) x

struct name_and_time
{
	String function_name;
	unsigned long start_time;
};

class Bug
{
protected:

	static std::vector<name_and_time> function_stack;
	static std::vector<int> thing_stack;

public:
	Bug();

	static void fps(const int seconds);

	static void display_memory(String new_string);

	static void start(String new_string);

	static void end();

	static void thing_counter();
};

#endif

