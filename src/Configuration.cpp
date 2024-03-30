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
  led_time(1000), 
  temp_time(5000), 
  humidity_time(10000),  
  wind_time(15000),
  low_power(false),
  temperature_tag("temp"),
  humidity_tag("umid"),
  wind_tag("vel_vento"){
 
}
