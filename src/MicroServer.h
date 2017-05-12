#ifndef MICROSERVER_H
#define MICROSERVER_H

#include <WiFiUdp.h>
#include <ESP8266mDNS.h>
#include "WiFiServer.h"
#include <WiFiClient.h>
#include <ESP8266WiFi.h>
//#include <ESP8266WebServer.h> 

#include <string>
#include <tuple>

#include "FileManager.h"

class Mechanical;

class MicroServer {

	public: 
		MicroServer(Mechanical *m);

		void setup(String hostname);
		void handleClients();

		void update(String msg);
		void update(String msg, WiFiClient * client);
	private: 
		const char* ap_default_psk = "microspot"; ///< Default PSK.

		WiFiClient currentClient;
		FileManager fileManager;
		Mechanical *mechanical;
};

#endif //MICROSERVER_H
