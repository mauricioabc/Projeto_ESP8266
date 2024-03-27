#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char* ssid = "ATPlus-Mauricio-2.4G";
const char* password = "98029804";
const char* mqtt_server = "agrotechlab.lages.ifsc.edu.br";
const char* mqtt_user = "er6spv48qqgxu1cw52yo";
const char* mqtt_topic = "v1/devices/me/telemetry";
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long time_now;
unsigned long led_1_sec = 1000;
unsigned long last_led_1_sec = 0;
unsigned long led_5_sec = 5000;
unsigned long last_led_5_sec = 0;

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Tentando conectar... ");
  }
  Serial.println("WiFi conectado. IP: " + String(WiFi.localIP().toString()));
}

void connectMQTT() {
  client.setServer(mqtt_server, 1883);
  while (!client.connected()) {
    Serial.println("Conectando ao MQTT...");

    if (client.connect("ESPClient", mqtt_user, nullptr)) {
      Serial.println("Conectado ao MQTT");
    } else {
      Serial.print("Ocorreu um erro inesperado: ");
      Serial.println(client.state());
      Serial.println("Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void sendLedStatus(boolean ledStatus){
  // Monta o JSON
  StaticJsonDocument<100> jsonDoc;
  jsonDoc["led_status"] = ledStatus;

  char jsonBuffer[100];
  serializeJson(jsonDoc, jsonBuffer);

  // Envia a mensagem
  if (client.publish(mqtt_topic, jsonBuffer)) {
    Serial.println("Mensagem enviada com sucesso: ");
    serializeJsonPretty(jsonDoc, Serial);
    Serial.print("\n");
  } else {
    Serial.println("Falha ao enviar a mensagem.");
  }
}

void setup() {
  //Led
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  //WiFi
  setup_wifi();
  //MQTT
  connectMQTT();

}

void pisca(){
  time_now = millis();
  if (time_now >= led_1_sec + last_led_1_sec){
    last_led_1_sec = time_now;
      if (time_now >= led_5_sec + last_led_5_sec){
          last_led_5_sec = time_now;
          digitalWrite(LED_BUILTIN, LOW);
          Serial.println("LED 5 SEC ON");
          sendLedStatus(true);
          delay(100);
          digitalWrite(LED_BUILTIN, HIGH);
          Serial.println("LED 5 SEC OFF");
          sendLedStatus(false);
          delay(100);
          digitalWrite(LED_BUILTIN, LOW);
          Serial.println("LED 5 SEC ON");
          sendLedStatus(true);
          delay(100);
          digitalWrite(LED_BUILTIN, HIGH);
          Serial.println("LED 5 SEC OFF");
          sendLedStatus(false);
          return;
      }
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED 1 SEC ON");
      sendLedStatus(true);
      delay(100);
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED 1 SEC OFF");
      sendLedStatus(false);
  }
}

void loop() {
  pisca();
  if (!client.connected()) {
    connectMQTT();
  }
  client.loop();
}
