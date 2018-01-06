//
#ifndef DFC_ESP8266_EASY_WEB_SERVER_H
#define DFC_ESP8266_EASY_WEB_SERVER_H

//Config defines

//Includes
#include "DFC_ESP8266EasyWebServerData.h"

class DFC_ESP8266EasyWebServer  
{
public: //Constructor
  DFC_ESP8266EasyWebServer();
  
public: //Interface
  void      Init();
  void      Loop();

protected: //Help functions

public: //Config

protected: //Variables
};

#endif //DFC_ESP8266_EASY_WEB_SERVER_H