#include "JsonBuilder.h"
#include <Arduino.h>
#include <ArduinoJson.h>

JsonBuilder::JsonBuilder() {

}

char* JsonBuilder::JsonMessageBuilder(const char* tag, float value) {
   StaticJsonDocument<100> jsonDoc;
   jsonDoc[tag] = value;

   char jsonBuffer[100];
   serializeJson(jsonDoc, jsonBuffer);
   serializeJsonPretty(jsonDoc, Serial);
   return jsonBuffer;
}
