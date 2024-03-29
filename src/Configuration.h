#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "RandomFloatGenerator.h"

class Configuration {
public:
    Configuration(); // Construtor
    // Dados de conexão WiFi
    const char* ssid;
    const char* password;
    // Dados do servidor MQTT
    const char* mqtt_server;
    const char* mqtt_user;
    const char* mqtt_topic;
    // Tempo de led e coleta de dados
    unsigned long led_time;
    unsigned long temp_time;
    unsigned long humidity_time;
    unsigned long wind_time;
};

#endif
