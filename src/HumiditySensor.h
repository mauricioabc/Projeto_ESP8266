#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "RandomFloatGenerator.h"

class HumiditySensor {
private:
    RandomFloatGenerator rng;

public:
    HumiditySensor(); // Construtor.
    float GetHumidity(); // Método para obter a umidade.
};

#endif
