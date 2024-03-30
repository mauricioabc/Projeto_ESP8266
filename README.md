# Projeto de Estação Meteorológica com ESP8266

Este projeto consiste em uma estação meteorológica simples que utiliza o módulo ESP8266 para coletar dados de temperatura, umidade e velocidade do vento, e publicá-los em um servidor MQTT. O sistema também inclui um gerenciamento de LED para indicar o status da conexão.

## Componentes

- ESP8266
- Sensor de Temperatura
- Sensor de Umidade
- Sensor de Velocidade do Vento
- LED (incorporado ao ESP8266)

## Bibliotecas Necessárias

- `Arduino.h` - Biblioteca padrão do Arduino.
- `ESP8266WiFi.h` - Para conectar o ESP8266 à rede WiFi.
- `PubSubClient.h` - Cliente MQTT para o Arduino.
- `ArduinoJson.h` - Para construir e parsear JSON facilmente.

Além das bibliotecas personalizadas:
- `Configuration.h` - Configurações de rede e MQTT.
- `LedManager.h` - Gerenciador do LED.
- `TemperatureSensor.h` - Gerenciador do sensor de temperatura.
- `HumiditySensor.h` - Gerenciador do sensor de umidade.
- `WindSensor.h` - Gerenciador do sensor de velocidade do vento.
- `JsonBuilder.h` - Para construir as mensagens JSON a serem enviadas.

## Configuração

1. Antes de carregar o código no seu ESP8266, você precisa preencher o arquivo `Configuration.h` com as informações da sua rede WiFi e servidor MQTT.

2. Instale as bibliotecas necessárias utilizando o Gerenciador de Bibliotecas do PlatformIO.

3. Carregue o código para o ESP8266 usando o PlatformIO.

## Funcionamento

Após a inicialização, o sistema tenta conectar-se à rede WiFi especificada e ao servidor MQTT. Uma vez conectado, ele periodicamente lê os valores dos sensores de temperatura, umidade e velocidade do vento, e envia esses dados ao servidor MQTT em formato JSON. O LED incorporado é usado para indicar o status da conexão: ligado durante a tentativa de conexão e desligado uma vez conectado.

## Customização

Você pode ajustar os intervalos de leitura dos sensores e a lógica de alternância do LED modificando as configurações no arquivo `Configuration.h`.
