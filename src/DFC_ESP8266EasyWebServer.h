//
#ifndef DFC_ESP8266_EASY_WEB_SERVER_H
#define DFC_ESP8266_EASY_WEB_SERVER_H

//Config defines
#define WEB_TCP_PORT        80

//Includes
#include "DFC_ESP8266EasyWebServerData.h"
#include <ESP8266WebServer.h>

class DFC_ESP8266EasyWebServer
{
public: //Constructor
  DFC_ESP8266EasyWebServer();
  
public: //Interface
  void      Init();
  void      Loop();

public: //Static callbacks
  static void OnPageNotFound();
  
  static bool DoPageFromFile();
  
protected: //Help functions
  static String Help_getContentType(String filename);

public: //Config

protected: //Variables
  static ESP8266WebServer mWebServer;

};

#endif //DFC_ESP8266_EASY_WEB_SERVER_H