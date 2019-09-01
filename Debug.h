// Debug.h

// All functions and variables related to debugging will go here.

// Use the macro D(1-5)(*your code here*) when putting in debug code.


// Uncomment the following lines to enable debugging code.
//#define BUG_1	// Free memory after constructors.
//#define BUG_2	// 
//#define BUG_3	// 
//#define BUG_4	// 
//#define BUG_5	// Beginning, middle, and end of every function.

#ifndef _BUG_h
#define _BUG_h

#include "Arduino.h"
#include <vector>

#if defined BUG_1
#	define D1(x) x
#else
#	define D1(x)
#endif

#if defined BUG_2
#	define D2(x) x
#else
#	define D2(x)
#endif

#if defined BUG_3
#	define D3(x) x
#else
#	define D3(x)
#endif

#if defined BUG_4
#	define D4(x) x
#else
#	define D4(x)
#endif

#if defined BUG_5
#	define D5(x) x
#else
#	define D5(x)
#endif

// This line is used to selectively enable debugging code without enabling DEBUG_(1-5)
#define D(x) x

struct name_and_time
{
	String function_name;
	long start_time;
};

class Bug
{
protected:

	static std::vector<name_and_time> function_stack;

public:
	Bug();

	static void fps(const int seconds);

	static void display_memory(String new_string);

	static void start(String new_string);

	static void end();
};

#endif