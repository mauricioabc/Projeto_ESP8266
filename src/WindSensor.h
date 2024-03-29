#ifndef WINDSENSOR_H
#define WINDSENSOR_H

#include "RandomFloatGenerator.h"

class WindSensor {
private:
    RandomFloatGenerator rng;
    
public:
    WindSensor(); // Construtor.
    float GetWind(); // Método para obter a temperatura.
};

#endif
