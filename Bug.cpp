// 
// 
// 

#include "Bug.h"

std::vector<name_and_time> Bug::function_stack;
std::vector<int> Bug::thing_stack;
//int Bug::framesPerSecond = 0;

Bug::Bug()
{
}

//void Bug::fps(int mseconds, int display_interval)
//{
//	START;
//
//	// Create static variables so that the code and variables can
//	// all be declared inside a function
//	static unsigned long lastMillis;
//	static unsigned long lastDisplayMillis;
//	static unsigned long frameCount;
//
//	// It is best if we declare millis() only once
//	unsigned long now = millis();
//
//	frameCount++;
//	//FastLED.countFPS();
//
//	// Update fps for anything that requires it.
//	if (now - lastMillis >= mseconds)
//	{
//		framesPerSecond = frameCount / ((float)mseconds / 1000.0);
//		frameCount = 0;
//		lastMillis = now;
//	}
//
//	// Show fps on the serial monitor.
//	if (now - lastDisplayMillis >= display_interval * 1000)
//	{
//		Serial.println(framesPerSecond);
//		Serial.println(FastLED.getFPS());
//
//		lastDisplayMillis = now;
//
//		MEM;
//	}
//
//	END;
//}

void Bug::display_memory(String new_string)
{

	//Serial.println();

	BUG5(
	for (int i = 0; i < function_stack.size() - 1; i++)
	{
		Serial.print("      ");
	})

	Serial.print("Memory remaining " + new_string + ": ");

	Serial.print((ESP.getFreeHeap() / 1024));

	Serial.println(" KB");
}

void Bug::start(String new_string)
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

int Bug::end(String new_string)
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

		Serial.println("Ending " + n_and_t.function_name + " after " + (function_time) + " millis");
	}
	else
	{
		Serial.println("START/END MISMATCH IN " + new_string);
	}

	return function_time;
}

void Bug::thing_counter()
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
