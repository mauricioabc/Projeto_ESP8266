#include "Configuration.h"

Configuration::Configuration() : 
  // Dados de conexão WiFi
  ssid("ATPlus-Mauricio-2.4G"), 
  password("98029804"), 
  // Dados do servidor MQTT
  mqtt_server("agrotechlab.lages.ifsc.edu.br"), 
  mqtt_user("er6spv48qqgxu1cw52yo"), 
  mqtt_topic("v1/devices/me/telemetry"), 
  // Tempo de led e coleta de dados
  time_now(0),
  led_time(1000), 
  last_led_time(0), 
  temp_time(5000), 
  last_temp_time(0), 
  humidity_time(10000), 
  last_humidity_time(0), 
  wind_time(15000), 
  last_wind_time(0) {

}
