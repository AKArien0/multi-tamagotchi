#include "tama.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdbool.h>
#include "images.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define B_UP_ID 0
#define B_DOWN_ID 1
#define B_LEFT_ID 2
#define B_RIGHT_ID 3
#define B_SEL_ID 4

TaskHandle_t Task_values_handle;


bool b_last_state[5];

int TestBit(unsigned int a, int k ){
  return -(a >> k)%2;
}

void draw_8_8(Adafruit_SSD1306 &screen, unsigned int image[2], int pixel_colour, int origin_x, int origin_y){
  for (int i = 0 ; i < 8 ; i++){
    for (int a = 0 ; a < 8 ; a++){
      if (TestBit(image[(i > 3)], (i*8)+a)){
        screen.drawPixel(a+origin_x, i+origin_y, pixel_colour);
      }
    }
  }
}

void draw_image(Adafruit_SSD1306 &screen, unsigned int image[][2], int image_size, int pixel_colour, int origin_x, int origin_y){
  for (int i = 0; i < image_size ; i++){
    for (int a = 0 ; a < image_size ; a++){
      draw_8_8(screen, image[i], pixel_colour, origin_x + i*8, origin_y + a*8);
    }
  }
}

unsigned long int last_second_counted = millis();

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
  //draw_image(display, big_square, SIZE_BIG_SQUARE, WHITE, 0, 0);
  display.display();
  delay(2000);
  
  //pinMode(b_up, INPUT_PULLUP);
  //pinMode(b_down, INPUT_PULLUP);
  //pinMode(b_left, INPUT_PULLUP);
  //pinMode(b_right, INPUT_PULLUP);
  //pinMode(b_select, INPUT_PULLUP);

  xTaskCreatePinnedToCore(
      Task_values,
      "Updating values in memory",
      8192,
      NULL,
      1,
      &Task_values_handle,
      1
  );

  last_second_counted = millis();

  Serial.println("Setup complete");
}

void loop(){
  Serial.println(text_feed[0][0]);
}


void Task_values(void * pvParameters){
  for (;;){
    if ((millis()-last_second_counted)%1000){
      last_second_counted = millis();
      Serial.println(last_second_counted);
    }
  }
}