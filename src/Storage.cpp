#include "Storage.h"
#include <ArduinoJson.h>
#include <queue>

unsigned long max_temp_size = 6;
unsigned long max_humi_size = 3;
unsigned long max_wind_size = 2;

Storage::Storage(){

}

template<typename T>
void QueueToJsonArray(std::queue<T> q, JsonArray& array) {
    size_t size = q.size();
    for(size_t i = 0; i < size; ++i) {
        T value = q.front();
        q.pop();
        array.add(value);
    }
}

void Storage::SaveNewTemperature(float new_temperature) {
    temperature_queue.push(new_temperature);
}

void Storage::SaveNewHumidity(float new_humidity) {
    humidity_queue.push(new_humidity);
}

void Storage::SaveNewWind(float new_wind) {
    wind_queue.push(new_wind);
}

bool Storage::IsFull() {
  return temperature_queue.size() >= max_temp_size || 
          humidity_queue.size() >= max_humi_size || 
          wind_queue.size() >= max_wind_size;
}

void Storage::GenerateLastReadingsMessage(char* jsonBuffer, size_t bufferSize) {
    StaticJsonDocument<512> doc;
    JsonArray temperatureArray = doc.createNestedArray("temperature");
    JsonArray humidityArray = doc.createNestedArray("humidity");
    JsonArray windArray = doc.createNestedArray("wind");

    QueueToJsonArray(temperature_queue, temperatureArray);
    QueueToJsonArray(humidity_queue, humidityArray);
    QueueToJsonArray(wind_queue, windArray);

    serializeJson(doc, jsonBuffer, bufferSize);
    // serializeJsonPretty(doc, Serial);
}
