#include "Artnet.h"

// General pointer to facilitate calling back to non-static function Artnet::on_DMX_frame()
void* pt2Object;

//bool connect_wifi(void)
//{
//	START;
//
//	char* ssid = "Trap_House";
//	char* password = "ThIsHoUsEisatrap72";
//
//
//	boolean state = true;
//	int i = 0;
//
//	WiFi.begin(ssid, password);
//	Serial.println("");
//	Serial.println("Connecting to WiFi");
//
//	// Wait for connection
//	Serial.print("Connecting");
//	while (WiFi.status() != WL_CONNECTED)
//	{
//		delay(500);
//		Serial.print(".");
//		if (i > 40) {
//			state = false;
//			break;
//		}
//		i++;
//	}
//	if (state) {
//		Serial.println("");
//		Serial.print("Connected to ");
//		Serial.println(ssid);
//		Serial.print("IP address: ");
//		Serial.println(WiFi.localIP());
//	}
//	else {
//		Serial.println("");
//		Serial.println("Connection failed.");
//	}
//
//	MEM;
//	END;
//
//	return state;
//}

Artnet::Artnet(LED_Fixture* new_fixture, LED_Group* new_group)
	:Animation(new_fixture, new_group),
	send_frame(1),
	previous_data_length(0)
{
	START;

	num_universes = (num_leds * 3) / 512 + (((num_leds * 3) % 512) ? 1 : 0);
	universes_received = new bool[num_universes];
	
	//connect_wifi();

	artnet.begin();

	THING;

	artnet.setArtDmxCallback(Artnet::on_DMX_frame_wrapper);

	THING;

	pt2Object = (void*) this;

	END;
}

void Artnet::run()
{
	START;

	artnet.read();

	END;
}

void Artnet::on_DMX_frame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
	START;

	//for (int i = 0; i < length / 3; i++)
	//{
	//	//int led = i + (universe - startUniverse) * (previousDataLength / 3);
	//	if (i < 144)
	//	{
	//		leds[i + universe * 144] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
	//	}
	//}

	send_frame = 1;
	// set brightness of the whole strip
	if (universe == 15)
	{
		FastLED.setBrightness(data[0]);
		//FastLED.show();
		//FastLED_Show_ESP32();
	}

	// Store which universe has got in
	if ((universe - start_universe) < num_universes) {
		universes_received[universe - start_universe] = 1;
	}

	for (int i = 0; i < num_universes; i++)
	{
		if (universes_received[i] == 0)
		{
			//Serial.println("Broke");
			send_frame = 0;
			break;
		}
	}

	// read universe and put into the right part of the display buffer
	for (int i = 0; i < length / 3; i++)
	{
		int led = i + (universe - start_universe) * (previous_data_length / 3);
		if (led < num_leds)
			leds[led] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
	}
	previous_data_length = length;

	if (send_frame)
	{
		//FastLED.show();
		//FastLED_Show_ESP32();
		// Reset universeReceived to 0
		memset(universes_received, 0, num_universes);
	}

	END;
}


void Artnet::on_DMX_frame_wrapper(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
	START;

	// explicitly cast to a pointer to Classname
	Artnet* mySelf = (Artnet*)pt2Object;

	// call member
	mySelf->on_DMX_frame(universe, length, sequence, data);

	END;
}