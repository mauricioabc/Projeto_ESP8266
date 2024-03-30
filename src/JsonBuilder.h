#ifndef JSONBUILDER_H
#define JSONBUILDER_H

#include <cstddef>

class JsonBuilder {
public:
    JsonBuilder(); // Construtor
    void JsonMessageBuilder(const char* tag, float value, char* jsonBuffer, size_t bufferSize);
};

#endif
