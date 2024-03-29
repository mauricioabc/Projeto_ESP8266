#ifndef JSONBUILDER_H
#define JSONBUILDER_H

class JsonBuilder {
private:
    int pin; // Pino do Led

public:
    JsonBuilder(); // Construtor
    char* JsonMessageBuilder(char* tag, float value);
};

#endif
