// Bug.h

// elf file location
// C:\Users\pikipupiba\AppData\Local\Temp\VMBuilds\RGB_Empire_Rewrite_July_2019\esp32_esp32wrover\Release/RGB_Empire_Rewrite_July_2019.ino.elf

// All functions and variables related to BUGging will go here.

// Use the macro D(1-5)(*your code here*) when putting in BUG code.

// Uncomment the following lines to enable BUGging code.
#define BUG_1	// Free memory after constructors and FPS.
#define BUG_2	// 
//#define BUG_3	// 
//#define BUG_4	// 
#define BUG_5	// Beginning, middle, and end of every function.

#ifndef _BUG_h
#define _BUG_h

#include "Arduino.h"
#include <vector>
#include "FastLED.h"

#define START BUG5(Bug::start(__PRETTY_FUNCTION__))
#define START2 BUG2(Bug::start(__PRETTY_FUNCTION__))
#define THING BUG5(Bug::thing_counter())
#define THING2 BUG2(Bug::thing_counter())
#define END BUG5(Bug::end(__PRETTY_FUNCTION__))
#define END2 BUG2(Bug::end(__PRETTY_FUNCTION__))
#define MEM Bug::display_memory(" after " + String(__PRETTY_FUNCTION__))

#define P(x) Bug::print(#x, x);

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
	//static int framesPerSecond;

	Bug();

	//static void fps(const int mseconds, const int display_interval);

	static void display_memory(String new_string);

	static inline void start(String new_string);

	static inline int end(String new_string);

	static inline void thing_counter();

	static inline void print(String new_string, float value);

	static inline void print(String new_string, int value);
};

inline void Bug::start(String new_string)
{
	name_and_time n_and_t;

	n_and_t.function_name = new_string;
	n_and_t.start_time = millis();

	function_stack.push_back(n_and_t);
	thing_stack.push_back(0);

	for (int i = 0; i < function_stack.size() - 1; i++)
	{
		Serial.print("      ");
	}

	Serial.println("Starting " + new_string);

}

inline int Bug::end(String new_string)
{
	name_and_time n_and_t = function_stack.back();

	int function_time = millis() - n_and_t.start_time;

	if (n_and_t.function_name.equals(new_string))
	{

		for (int i = 0; i < function_stack.size() - 1; i++)
		{
			Serial.print("      ");
		}

		function_stack.pop_back();
		thing_stack.pop_back();

		Serial.println("Ending " + n_and_t.function_name + " after " + (function_time)+" millis");
	}
	else
	{
		Serial.println("START/END MISMATCH IN " + new_string);
	}

	return function_time;
}

inline void Bug::thing_counter()
{
	thing_stack.back()++;

	BUG5
	(
		for (int i = 0; i < thing_stack.size() - 1; i++)
		{
			Serial.print("      ");
		}
	)

		Serial.println("Thing #" + (String)thing_stack.back());
}

inline void Bug::print(String new_string, float value)
{
	Serial.println(new_string + String(value));
}

inline void Bug::print(String new_string, int value)
{
	Serial.println(new_string + String(value));
}


#endif

