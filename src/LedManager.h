#ifndef LEDMANAGER_H
#define LEDMANAGER_H

class LedManager {
private:
    int pin; // Pino do Led

public:
    LedManager(int pin); // Construtor
    void On(); // Acende
    void Off(); // Apaga
    void Change(); // Inverte o estado
};

#endif
