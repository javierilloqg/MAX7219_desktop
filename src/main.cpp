
#include <MD_MAX72xx.h>
#include <MD_Parola.h>
#include <SPI.h>
#include <Wire.h>
#include <RTClib.h>
#include <SmallDigits.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

// Defining size, and output pins
#define MAX_DEVICES 4
#define CS_PIN 10
#define CLK_PIN 13
#define DATA_PIN 11

// Object declaration
MD_Parola Display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
RTC_DS1307 rtc;

void setup() {
 
  Display.begin();
  Display.setIntensity(0);
  Display.setTextAlignment(PA_CENTER);
  Display.print("Jasi vX");
  delay(1000);
  Display.displayClear();
  if (! rtc.begin()){
    Display.print("Error 1");
    while (1) delay(10);
  } else {
    Display.print("OK!");
    delay(1000);
    Display.displayClear();
  };
}

void loop() {
  DateTime now = rtc.now();
  String complete_hour = String(now.hour(), DEC) + ":" + String(now.minute(), DEC);
  Display.getFont();
  Display.setTextAlignment(PA_CENTER);
  Display.print(complete_hour);
}