#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "RandomFloatGenerator.h"

class Configuration {
private:
    // Dados de conexão WiFi
    const char* ssid;
    const char* password;
    // Dados do servidor MQTT
    const char* mqtt_server;
    const char* mqtt_user;
    const char* mqtt_topic;
    // Tempo de led e coleta de dados
    unsigned long time_now;
    unsigned long led_time;
    unsigned long last_led_time;
    unsigned long temp_time;
    unsigned long last_temp_time;
    unsigned long humidity_time;
    unsigned long last_humidity_time;
    unsigned long wind_time;
    unsigned long last_wind_time;

public:
    Configuration(); // Construtor
};

#endif
