#include "WindSensor.h"
#include "RandomFloatGenerator.h"

WindSensor::WindSensor() : rng(0.00f, 19.99f) {
    //Faixa: randômico entre 0.00Km/h e 19.99Km/h
}

float WindSensor::GetWind() {
    return rng.generate();
}
