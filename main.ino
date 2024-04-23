#include "tama.h"
#include "images.h"
#include "Input.hpp"

#ifndef SPI_H
#include <SPI.h>
#endif
#ifndef WIRE_H
#include <Wire.h>
#endif
#ifndef ADAFRUIT_GFX_H
#include <Adafruit_GFX.h>
#endif
#ifndef Adafruit_SSD1306_H
#include <Adafruit_SSD1306.h>
#endif

#ifndef SPI_H
#include <SPI.h>
#endif
#ifndef WIRE_H
#include <Wire.h>
#endif
#ifndef ADAFRUIT_GFX_H
#include <Adafruit_GFX.h>
#endif
#ifndef Adafruit_SSD1306_H
#include <Adafruit_SSD1306.h>
#endif

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

TaskHandle_t Task_update_handle;

Input::Button b_up(18);
Input::Button b_down(5);
Input::Button b_left(17);
Input::Button b_right(16);
Input::Button b_select(4);


void setup() {
  Serial.begin(9600);
  Serial.println("Alive");

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();

  b_up.begin(INPUT_PULLUP, 0);
  b_down.begin(INPUT_PULLUP, 0);
  b_left.begin(INPUT_PULLUP, 0);
  b_right.begin(INPUT_PULLUP, 0);
  b_select.begin(INPUT_PULLUP, 0);

  xTaskCreatePinnedToCore(
    Task_update,
    "Updating values and screen animations",
    8192,
    NULL,
    1,
    &Task_update_handle,
    0
    );

  Serial.println("Setup complete");

  display.clearDisplay();
  display.display();
  }

void loop(){
  if (b_up.is_just_pressed()){

  }

  if (b_down.is_just_pressed()){

  }
  if (b_left.is_just_pressed()){

  }
  if (b_right.is_just_pressed()){

  }

  if (b_select.is_just_pressed()){

  }

  delay(2000);
  Serial.print("Hello from loop on core ");
  Serial.println(xPortGetCoreID());
}

void Task_update(void * pvParameters){
  long unsigned int seconds_counted = 0;
  for (;;){
    if (millis() > (seconds_counted*1000)){
      seconds_counted++;
      Serial.println(seconds_counted);
      Serial.print("Hello from task on core ");
      Serial.println(xPortGetCoreID());
    }
  }
}
