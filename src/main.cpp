#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include <Configuration.h>
#include <LedManager.h>
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <WindSensor.h>
#include <InstantMessage.h>
#include <Storage.h>

Configuration config;
LedManager led = LedManager(LED_BUILTIN);
InstantMessage instant_message;
Storage storage;
TemperatureSensor temperature;
HumiditySensor humidity;
WindSensor wind;
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long time_now;
unsigned long last_led_time = 0;
unsigned long last_temp_time = 0;
unsigned long last_humidity_time = 0;
unsigned long last_wind_time = 0;

void setup_wifi() {
  Serial.println("Iniciando processo de conexão com o Wifi.");
  led.On();
  Serial.println("Rede: " + String(config.ssid));
  WiFi.begin(config.ssid, config.password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Tentando conectar... ");
  }
  Serial.println("WiFi conectado. IP: " + String(WiFi.localIP().toString()));
  led.Off();
}

void connectMQTT() {
  Serial.println("Iniciando processo de conexão com o servidor MQTT.");
  led.On();
  Serial.println("Servidor: " + String(config.mqtt_server));
  client.setServer(config.mqtt_server, 1883);
  while (!client.connected()) {
    Serial.println("Conectando ao MQTT...");
    if (client.connect("ESPClient", config.mqtt_user, nullptr)) {
      Serial.println("Conectado ao MQTT.");
      led.Off();
    } else {
      Serial.print("Ocorreu um erro inesperado: ");
      Serial.println(client.state());
      Serial.println("Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void SendAccumulatedInformation(){
  char jsonBuffer[512];
  storage.GenerateLastReadingsMessage(jsonBuffer, sizeof(jsonBuffer));
  Serial.println("Conteúdo da mensagem:" + String(jsonBuffer));

  // Envia a mensagem
  if (client.publish(config.mqtt_topic, jsonBuffer)) {
    Serial.println("Mensagem enviada com sucesso.");
  } else {
    Serial.println("Falha ao enviar a mensagem.");
  }
}

void SendInstantInformation(const char* tag, float value){
  char jsonBuffer[100];
  instant_message.InstantMessageBuilder(tag, value, jsonBuffer, sizeof(jsonBuffer));
  Serial.println("Conteúdo da mensagem:" + String(jsonBuffer));

  // Envia a mensagem
  if (client.publish(config.mqtt_topic, jsonBuffer)) {
    Serial.println("Mensagem enviada com sucesso.");
  } else {
    Serial.println("Falha ao enviar a mensagem.");
  }
}

void ProcessAccumulatedInformation(){
  if(storage.IsFull()){
    SendAccumulatedInformation();
    storage.ClearAll();
  }
}

void setup() {
  //Serial
  Serial.begin(9600);
  //WiFi
  setup_wifi();
  //MQTT
  connectMQTT();
}

void ProcessTemperature(){
  time_now = millis();
  if (time_now >= config.temp_time + last_temp_time){
      last_temp_time = time_now;
      //Lógica de leitura e envio
      float new_temperature = temperature.GetTemperature();
      if(!config.low_power){
        SendInstantInformation(config.temperature_tag, new_temperature);
      }
      storage.SaveNewTemperature(new_temperature);
  }
}

void ProcessHumidity(){
  time_now = millis();
  if (time_now >= config.humidity_time + last_humidity_time){
      last_humidity_time = time_now;
      //Lógica de leitura e envio
      float new_humidity = humidity.GetHumidity();
      if(!config.low_power){
        SendInstantInformation(config.humidity_tag, new_humidity);
      }
      storage.SaveNewHumidity(new_humidity);
  }
}

void ProcessWind(){
  time_now = millis();
  if (time_now >= config.wind_time + last_wind_time){
      last_wind_time = time_now;
      //Lógica de leitura e envio
      float new_wind = wind.GetWind();
      if(!config.low_power){
        SendInstantInformation(config.wind_tag, new_wind);
      }
      storage.SaveNewWind(new_wind);
  }
}

void AlterLed(){
  time_now = millis();
  if (time_now >= config.led_time + last_led_time){
    last_led_time = time_now;
    led.Change();
  }
}

void loop() {
  if (!client.connected()) {
    connectMQTT();
  }
  AlterLed();
  ProcessTemperature();
  AlterLed();
  ProcessHumidity();
  AlterLed();
  ProcessWind();
  AlterLed();
  ProcessAccumulatedInformation();
  AlterLed();
  client.loop();
}
