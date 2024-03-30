#include "InstantMessage.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include <cstddef>

InstantMessage::InstantMessage() {

}

void InstantMessage::InstantMessageBuilder(const char* tag, float value, char* jsonBuffer, size_t bufferSize) {
   StaticJsonDocument<100> jsonDoc;
   jsonDoc[tag] = value;

   serializeJson(jsonDoc, jsonBuffer, bufferSize);
   // serializeJsonPretty(jsonDoc, Serial);
}
