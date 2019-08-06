// Debug.h

// All functions and variables related to debugging will go here.

// This file should be included in all other files with D(#include "Debug.h")

// Use the macro D(*your code here*) when putting in debug code.

// Uncomment the following line to enable debugging code.
//#define DEBUG_US

#ifndef _DEBUG_h
#define _DEBUG_h

#include "arduino.h"

#if defined DEBUG_US
#	define D(x) x
#else
#	define D(x)
#endif

// This line is used to selectively enable debugging code without enabling DEBUG_US
// Just throw a 2 in there!
#define D2(x) x

void fps(const int seconds);

#endif

