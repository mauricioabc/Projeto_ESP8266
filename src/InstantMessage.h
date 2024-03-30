#ifndef INSTANTMESSAGEBUILDER_H
#define INSTANTMESSAGEBUILDER_H

#include <cstddef>

class InstantMessage {
public:
    InstantMessage(); // Construtor
    void InstantMessageBuilder(const char* tag, float value, char* jsonBuffer, size_t bufferSize);
};

#endif
