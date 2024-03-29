#include "RandomFloatGenerator.h"

// Construtor que inicializa o gerador de números aleatórios e a distribuição.
RandomFloatGenerator::RandomFloatGenerator(float min, float max)
: gen(std::random_device{}()), dis(min, max) {
}

// Método para gerar o número aleatório.
float RandomFloatGenerator::generate() {
    return dis(gen);
}
