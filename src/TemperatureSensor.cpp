#include "TemperatureSensor.h"
#include "RandomFloatGenerator.h"

TemperatureSensor::TemperatureSensor() : rng(5.0f, 15.99f) {
    //Faixa: randômico entre 5.00ºC e 15.99ºC
}

float TemperatureSensor::GetTemperature() {
    return rng.generate();
}
