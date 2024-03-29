#include "HumiditySensor.h"
#include "RandomFloatGenerator.h"

HumiditySensor::HumiditySensor() : rng(40.0f, 89.99f) {
    //Faixa: randômico entre 40.00% e 89.99%
}

float HumiditySensor::GetHumidity() {
    return rng.generate();
}
