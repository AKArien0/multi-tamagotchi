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


    PTK::Image t_im(0, 0, icon_back, 16, 16);
    screen.drawBitmap(16, 0, icon_back, 16, 16, WHITE);
    screen.display();
    delay(2000);

    t_im.~Image();
    screen.drawBitmap(16, 0, icon_back, 16, 16, BLACK);
    screen.display();

    delay(2000);

    PTK::Image i1(16, 32, icon_back, 16, 16);
    PTK::Image i2(16, 16, icon_back, 16, 16);
    PTK::Image itest(48, 0, test, 0, 0);

    std::vector<PTK::Widget*> list;
    list.push_back(&i1);
    list.push_back(&i2);
    list.push_back(&itest);
    world.add_child(&i1);
    world.add_child(&i2);
    world.add_children(&list);

    world.display();
    screen.display();

    delay(1000);

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
        }
    }
}
