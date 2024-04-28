#include "tama.h"
#include "images.h"
#include "Input.hpp"
#include "PTK.hpp"

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
Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

namespace PTK{
    void Image::display(){
        screen.drawBitmap(
            pos_x, pos_y,
            image,
            xx, yy,
            WHITE);
    }

    void Image::hide(){
        screen.drawBitmap(
            pos_x, pos_y,
            image,
            xx, yy,
            BLACK);
    }
};

TaskHandle_t Task_update_handle;

Input::Button b_up(18);
Input::Button b_down(5);
Input::Button b_left(17);
Input::Button b_right(16);
Input::Button b_select(4);

box[TAMA_BOXES_AMOUNT] tama_boxes;

PTK::Container world(0, 0);

void setup() {
    Serial.begin(9600);
    Serial.println("Alive");

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    screen.display();

    b_up.begin(INPUT_PULLUP, 0);
    b_down.begin(INPUT_PULLUP, 0);
    b_left.begin(INPUT_PULLUP, 0);
    b_right.begin(INPUT_PULLUP, 0);
    b_select.begin(INPUT_PULLUP, 0);

    for (int i = 0 ; i < TAMA_BOXES_AMOUNT ; i++){
        tama_boxes[i] = init_box;
    }

    PTK::CursorMenu tama_menu(0, 16, 4, 4);
    menu.add_child(PTK::Image(0, 16, icon_back, 16, 16), 0, 0, 1, 1, );
    menu.add_child(PTK::Image(24, 16, icon_feed, 16, 16), 0, 1, 1, 1;
    menu.add_child(PTK::Image())

    world.add_child()

    xTaskCreatePinnedToCore(
        Task_update,
        "Updating values and screen animations",
        8192,
        NULL,
        1,
        &Task_update_handle,
        1
    );

    screen.clearDisplay();
    screen.display();

    Serial.println("Setup complete");
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

}

void Task_update(void * pvParameters){
    long unsigned int seconds_counted = 0;
        for (;;){
        if (millis() > (seconds_counted*1000)){
            seconds_counted++;
            Serial.println(seconds_counted);
            for (int i = 0 ; i < TAMA_BOXES_AMOUNT ; i++){
                for (int a = 0 ; a < TAMA_PER_BOX ; a++){
                    tama_advance_second(tama_boxes->tamas[TAMA_PER_BOX])
                }
            }
        }
    }
}
