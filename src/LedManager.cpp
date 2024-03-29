#include "LedManager.h"
#include <Arduino.h>

LedManager::LedManager(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void LedManager::On() {
    digitalWrite(pin, LOW);
}

void LedManager::Off() {
    digitalWrite(pin, HIGH);
}

void LedManager::Change(){
  if (digitalRead(pin) == LOW){
    digitalWrite(pin, HIGH);
    return;
  }
  digitalWrite(pin, LOW);
}
