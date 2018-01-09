/*
*/

//library includes
#include "DFC_ESP8266EasyWebServer.h"
#include <DString.h>
#include <FS.h>

//Config defines
#define WEB_DEBUG

//debug
#undef DBG
#undef DBGLN
#undef DBGF

#ifdef WEB_DEBUG
  #define DBG(...) Serial.print( __VA_ARGS__ )
  #define DBGLN(...) Serial.println( __VA_ARGS__ )
  #define DBGF(...) Serial.printf( __VA_ARGS__ )
#else
  #define DBG(...)
  #define DBGLN(...)
  #define DBGF(...)
#endif

ESP8266WebServer DFC_ESP8266EasyWebServer::mWebServer(80);

  
DFC_ESP8266EasyWebServer::DFC_ESP8266EasyWebServer()
{
}

void DFC_ESP8266EasyWebServer::Init()
{
  mWebServer.onNotFound(OnPageNotFound);
  mWebServer.begin();

  DString Blub = "--ab--cd--ef--gh--";
  Blub.replace("--", "++");  
  DBGLN(Blub);
}

void DFC_ESP8266EasyWebServer::Loop()
{
  mWebServer.handleClient();
}

void DFC_ESP8266EasyWebServer::OnPageNotFound()
{
  if (DoPageFromFile()) return;
}

bool DFC_ESP8266EasyWebServer::DoPageFromFile()
{
  DString PageFile;
  PageFile = mWebServer.uri();
  PageFile.AppendFront("/wwwroot");
  DString HtmlFile;

  if (PageFile.endsWith("/"))
  {
    if (SPIFFS.exists(PageFile + "index.htm")) HtmlFile = PageFile + "index.htm";
    else if (SPIFFS.exists(PageFile + "index.html")) HtmlFile = PageFile + "index.html";
  }
  else
  {
    if (SPIFFS.exists(PageFile)) HtmlFile = PageFile;
    else if (SPIFFS.exists(PageFile + ".htm")) HtmlFile = PageFile + ".htm";
    else if (SPIFFS.exists(PageFile + ".html")) HtmlFile = PageFile + ".html";
  }
  
  if (HtmlFile.length() <= 0)
  {
    DString Answer;
    Answer.Format("Page %s not found.", mWebServer.uri().c_str());
    DBGLN(Answer);
    mWebServer.send(404, "text/plain", Answer);
    return false;
  }

  DBGLN(HtmlFile);
  
  String contentType = Help_getContentType(HtmlFile);
  File file = SPIFFS.open(HtmlFile, "r");
  size_t sent = mWebServer.streamFile(file, contentType);
  file.close();
  return true;
}

String DFC_ESP8266EasyWebServer::Help_getContentType(String filename)
{
  if(mWebServer.hasArg("download")) return "application/octet-stream";
  else if(filename.endsWith(".htm")) return "text/html";
  else if(filename.endsWith(".html")) return "text/html";
  else if(filename.endsWith(".css")) return "text/css";
  else if(filename.endsWith(".js")) return "application/javascript";
  else if(filename.endsWith(".png")) return "image/png";
  else if(filename.endsWith(".gif")) return "image/gif";
  else if(filename.endsWith(".jpg")) return "image/jpeg";
  else if(filename.endsWith(".ico")) return "image/x-icon";
  else if(filename.endsWith(".xml")) return "text/xml";
  else if(filename.endsWith(".pdf")) return "application/x-pdf";
  else if(filename.endsWith(".zip")) return "application/x-zip";
  else if(filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}
