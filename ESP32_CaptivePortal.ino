#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <DNSServer.h>

#include "page1.h"
#include "page2.h"
#include "page3.h"
#include "page4.h"

AsyncWebServer  server(80);
DNSServer dnsServer;

IPAddress apIP(192, 168, 1, 1);

void handleRoot() {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", PAGE1);
  });
}

void webServerSetup(){
  
  //This is a super simple page that will be served up any time the root location is requested.  Get here intentionally by typing in the IP address.
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", PAGE1);
  });
  server.on("/page1", [](AsyncWebServerRequest *request){
    request->send(200, "text/html", PAGE1);
  });
  server.on("/page2", [](AsyncWebServerRequest *request){
    request->send(200, "text/html", PAGE2);
  });
  server.on("/page3", [](AsyncWebServerRequest *request){
    request->send(200, "text/html", PAGE3);
  });
  server.on("/page4",[](AsyncWebServerRequest *request){
    request->send(200, "text/html", PAGE4);
  });
  //This is an example of a redirect type response.  onNotFound acts as a catch-all for any request not defined above
  server.onNotFound([](AsyncWebServerRequest *request){
    request->redirect("/");
  });

  server.begin();                         //Starts the server process
}


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("ESP32-Portal");
  dnsServer.start(53, "*",  WiFi.softAPIP());

  webServerSetup();
  
  server.begin();
}

void loop() {
  dnsServer.processNextRequest();
}
