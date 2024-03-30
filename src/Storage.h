#ifndef STORAGE_H
#define STORAGE_H

#include <queue>

class Storage {
private:
    std::queue<float> temperature_queue;
    std::queue<float> humidity_queue;
    std::queue<float> wind_queue;

public:
    Storage(); // Construtor
    void SaveNewTemperature(float new_temperature);
    void SaveNewHumidity(float new_humidity);
    void SaveNewWind(float new_wind);
    bool IsFull();
    void GenerateLastReadingsMessage(char* jsonBuffer, size_t bufferSize);
    void ClearAll();
};

#endif
