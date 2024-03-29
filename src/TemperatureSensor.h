#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "RandomFloatGenerator.h"

class TemperatureSensor {
private:
    RandomFloatGenerator rng;
    
public:
    TemperatureSensor(); // Construtor.
    float GetTemperature(); // Método para obter a temperatura.
};

#endif
