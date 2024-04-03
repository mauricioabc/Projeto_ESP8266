#include "Storage.h"
#include <ArduinoJson.h>
#include <queue>
#include <Configuration.h>

Configuration config_storage;

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
    Serial.println("Salvando temperatura na posição: " + String(temperature_queue.size() + 1) + "/" + String(max_temp_size));
    temperature_queue.push(new_temperature);
}

void Storage::SaveNewHumidity(float new_humidity) {
    Serial.println("Salvando umidade na posição: " + String(humidity_queue.size() + 1) + "/" + String(max_humi_size));
    humidity_queue.push(new_humidity);
}

void Storage::SaveNewWind(float new_wind) {
    Serial.println("Salvando vento na posição: " + String(wind_queue.size() + 1) + "/" + String(max_wind_size));
    wind_queue.push(new_wind);
}

bool Storage::IsFull() {
  return temperature_queue.size() >= max_temp_size &&
          humidity_queue.size() >= max_humi_size &&
          wind_queue.size() >= max_wind_size;
}

void Storage::GenerateLastReadingsMessage(char* jsonBuffer, size_t bufferSize) {
    StaticJsonDocument<512> doc;
    JsonArray temperatureArray = doc[config_storage.temperature_tag].to<JsonArray>();
    JsonArray humidityArray = doc[config_storage.humidity_tag].to<JsonArray>();
    JsonArray windArray = doc[config_storage.wind_tag].to<JsonArray>();

    QueueToJsonArray(temperature_queue, temperatureArray);
    QueueToJsonArray(humidity_queue, humidityArray);
    QueueToJsonArray(wind_queue, windArray);

    serializeJson(doc, jsonBuffer, bufferSize);
    // serializeJsonPretty(doc, Serial);
}

void Storage::ClearAll() {
    std::queue<float> empty;
    std::swap(temperature_queue, empty);

    std::queue<float> empty2;
    std::swap(humidity_queue, empty2);

    std::queue<float> empty3;
    std::swap(wind_queue, empty3);
    Serial.println("As filas foram limpas.");
}

