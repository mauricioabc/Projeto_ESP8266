#include "JsonBuilder.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include <cstddef>

JsonBuilder::JsonBuilder() {

}

void JsonBuilder::JsonMessageBuilder(const char* tag, float value, char* jsonBuffer, size_t bufferSize) {
   StaticJsonDocument<100> jsonDoc;
   jsonDoc[tag] = value;

   serializeJson(jsonDoc, jsonBuffer, bufferSize);
   // serializeJsonPretty(jsonDoc, Serial);
}
