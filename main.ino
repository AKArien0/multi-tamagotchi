#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdbool.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define b_up 12
#define b_down 26
#define b_left 27
#define b_right 14
#define b_select 13

#define B_UP_ID 0
#define B_DOWN_ID 1
#define B_LEFT_ID 2
#define B_RIGHT_ID 3
#define B_SEL_ID 4

bool b_last_state[5];

int cursor[2] = {0, 0};

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, WHITE);
  display.display();
  delay(2000);
  pinMode(b_up, INPUT_PULLUP);
  pinMode(b_down, INPUT_PULLUP);
  pinMode(b_left, INPUT_PULLUP);
  pinMode(b_right, INPUT_PULLUP);
  pinMode(b_select, INPUT_PULLUP);
}

void loop(){
  if (!digitalRead(b_up)){
    if (b_last_state[B_UP_ID]){
      cursor[1]--;
      Serial.println("up");
    }
    b_last_state[B_UP_ID] = false;
  }
  else{
    b_last_state[B_UP_ID] = true;
  }
  if (!digitalRead(b_down)){
    if (b_last_state[B_DOWN_ID]){
      cursor[1]++;
    }
    b_last_state[B_DOWN_ID] = false;
  }
  else{
    b_last_state[B_DOWN_ID] = true;
  }
  if (!digitalRead(b_left)){
    if (b_last_state[B_LEFT_ID]){
      cursor[0]--;
    }
    b_last_state[B_LEFT_ID] = false;
  }
  else{
    b_last_state[B_LEFT_ID] = true;
  }
  if (!digitalRead(b_right)){
    if (b_last_state[B_RIGHT_ID]){
      cursor[0]++;
    }
    b_last_state[B_RIGHT_ID] = false;
  }
  else{
    b_last_state[B_RIGHT_ID] = true;
  }

  if (cursor[0] < 0){
    cursor[0] = 0;
  }
  if (cursor[0] > 127){
    cursor[0] = 127;
  }
  if (cursor[1] < 0){
    cursor[1] = 0;
  }
  if (cursor[1] > 63){
    cursor[1] = 63;
  }
  
  if (!digitalRead(b_select)){
    if (b_last_state[B_SEL_ID]){
      display.drawPixel(cursor[0], cursor[1], WHITE);
    }
    b_last_state[B_SEL_ID] = false;
  }
  else{
    b_last_state[B_SEL_ID] = true;
  }
  display.display();
}
