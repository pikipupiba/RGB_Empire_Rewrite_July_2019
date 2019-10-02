#pragma once

#include <WiFi.h>
#include <WiFiUdp.h>
#include "Bug.h"

class Wifi_Class
{
protected:

	static WiFiUDP udp;
	static char incoming_packet[255];  // buffer for incoming packets
	static char  reply_packet[255];  // a reply string to send back

	static int udpPort;

	static bool connected;
	static bool timeout;
	static long try_again_time;

	static char* ssid;
	static char* password;

public:

	static void start_wifi();

	static void connectToWiFi();

	static void WiFiEvent(WiFiEvent_t event);

	static void get_udp_input();
};