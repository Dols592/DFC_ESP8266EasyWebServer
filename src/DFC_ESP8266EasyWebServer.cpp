/*
*/

//library includes
#include "DFC_ESP8266EasyWebServer.h"

//Config defines

//debug
#undef DBG
#undef DBGLN
#undef DBGF

#ifdef EASY_WEB_DEBUG
  #define DBG(...) Serial.print( __VA_ARGS__ )
  #define DBGLN(...) Serial.println( __VA_ARGS__ )
  #define DBGF(...) Serial.printf( __VA_ARGS__ )
#else
  #define DBG(...)
  #define DBGLN(...)
  #define DBGF(...)
#endif

DFC_ESP8266EasyWebServer::DFC_ESP8266EasyWebServer()
{
}

void DFC_ESP8266EasyWebServer::Init()
{
}

void DFC_ESP8266EasyWebServer::Loop()
{
}
