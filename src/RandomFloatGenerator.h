#ifndef RANDOMFLOATGENERATOR_H
#define RANDOMFLOATGENERATOR_H

#include <random>

class RandomFloatGenerator {
private:
    std::mt19937 gen; // Motor de geração de números aleatórios baseado no algoritmo Mersenne Twister.
    std::uniform_real_distribution<float> dis; // Distribuição de números reais uniforme.

public:
    RandomFloatGenerator(float min, float max); // Construtor.
    float generate(); // Método para gerar o número aleatório.
};

#endif
