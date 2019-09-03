// 
// 
// 

#include "Bug.h"

std::vector<name_and_time> Bug::function_stack;

Bug::Bug()
{
}

void Bug::fps(const int seconds) {
	// Create static variables so that the code and variables can
	// all be declared inside a function
	static unsigned long lastMillis;
	static unsigned long frameCount;
	static unsigned int framesPerSecond;

	// It is best if we declare millis() only once
	unsigned long now = millis();

	frameCount++;

	if (now - lastMillis >= seconds * 1000) {
		framesPerSecond = frameCount / seconds;
		Serial.println(framesPerSecond);
		frameCount = 0;
		lastMillis = now;
	}
}

void Bug::display_memory(String new_string)
{

	Serial.println();

	for (int i = 0; i < function_stack.size() - 1; i++)
	{
		Serial.print("   ");
	}

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
		Serial.print("   ");
	}

	Serial.println("Starting " + new_string);

}

void Bug::end()
{
	for (int i = 0; i < function_stack.size() - 1; i++)
	{
		Serial.print("   ");
	}

	name_and_time n_and_t = function_stack.back();

	function_stack.pop_back();
	thing_stack.pop_back();

	Serial.println("Ending " + n_and_t.function_name + " after " + (millis() - n_and_t.start_time) + " millis");

}

void Bug::thing_counter()
{
	thing_stack[thing_stack.size() - 1] ++;

	for (int i = 0; i < thing_stack.size() - 1; i++)
	{
		Serial.print("   ");
	}

	Serial.println("Thing #" + thing_stack.back);
}
