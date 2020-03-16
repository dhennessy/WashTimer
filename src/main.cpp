#include <Arduino.h>
#include "MD_Parola.h"

#if  DEBUG
#define PRINT(s, x) { Serial.print(F(s)); Serial.print(x); }
#define PRINTS(x) Serial.print(F(x))
#define PRINTD(x) Serial.println(x, DEC)

#else
#define PRINT(s, x)
#define PRINTS(x)
#define PRINTD(x)

#endif

// #define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define HARDWARE_TYPE MD_MAX72XX::ICSTATION_HW

#define CLK_PIN   2  // or SCK
#define CS_PIN    3  // or SS
#define DATA_PIN  4  // or MOSI
#define SENSOR    5   // Sharp sensor

#define MAX_DEVICES	4

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void countdown() {
  uint8_t maxCols = mx.getColumnCount();
  unsigned long tick = 20000 / (maxCols * 4);
  for (uint8_t col=0; col<maxCols; col++) {
    mx.setColumn(col, 0xff);
  }
  for (uint8_t col=0; col<maxCols; col++) {
    mx.setColumn(maxCols-col-1, 0x7e);
    delay(tick);
    mx.setColumn(maxCols-col-1, 0x3c);
    delay(tick);
    mx.setColumn(maxCols-col-1, 0x18);
    delay(tick);
    mx.setColumn(maxCols-col-1, 0x00);
    delay(tick);
  }
}

bool checkPresence() {
  return digitalRead(SENSOR) == LOW;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SENSOR, INPUT);
  mx.begin();
  mx.clear();
  Serial.begin(9600);
}

void loop() {
  delay(1);
  if (checkPresence()) {
    countdown();
  }
}

