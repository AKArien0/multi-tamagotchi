#include "tama.h"
#include "images.h"
#include "Input.hpp"
#include "PTK.hpp"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin
Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define HERE Serial.println("here");

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

    void TextBox::display(){
        //~ screen.setTextColor(WHITE);
        //~ screen.setCursor(0, 0);
        //~ screen.println(text);
    }

};

TaskHandle_t Task_update_handle;

Input::Button b_up(18);
Input::Button b_down(5);
Input::Button b_left(17);
Input::Button b_right(16);
Input::Button b_select(4);

PTK::Container world(0, 0);

PTK::CursorMenu* current_menu;

PTK::TextBox* text_view;

box tama_boxes[TAMA_BOXES_AMOUNT];

void* current_element;

void cursor_mov_callback(){
    //~ Serial.print("Index : ");
    //~ Serial.println(current_menu->get_index_from_coords(current_menu->get_cursor_x(), current_menu->get_cursor_y()));
    //~ Serial.println(current_menu->get_cursor_widget()->get_pos_x());
}

void test(){
    Serial.println("test");
}

void back_callback(){
    Serial.println("back_callback");
    text_view->set_text("");
}

void feed_indv_callback(){
    Serial.println("feed_callback");
    text_view->set_text(feed((tama*)current_element, MAX_FOOD/8));
}

void check_indv_callback(){
    Serial.println("check_callback");
    text_view->set_text(check((tama*)current_element));
}

void inject_indv_callback(){
    Serial.println("inject_callback");

}

void fun_indv_callback(){
    text_view->set_text(fun((tama*)current_element));
}

void switch_light_callback(){
    text_view->set_text(switch_light(((tama*)current_element)->parent));
    ((PTK::Animation*)(current_menu->get_item_at_cursor()))->next_frame();
}

void setup() {
    Serial.begin(9600);
    Serial.println("Alive");

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    screen.clearDisplay();
    screen.display();

    b_up.begin(INPUT_PULLUP, 0);
    b_down.begin(INPUT_PULLUP, 0);
    b_left.begin(INPUT_PULLUP, 0);
    b_right.begin(INPUT_PULLUP, 0);
    b_select.begin(INPUT_PULLUP, 0);

    for (int i = 0 ; i < TAMA_BOXES_AMOUNT ; i++){
        tama_boxes[i] = init_box();
    }

    PTK::Image* cursor = new PTK::Image(0, 0, image_cursor, 16, 16);
    PTK::CursorMenu* tama_menu = new PTK::CursorMenu(8, 24, 2, 1, cursor, 7, 7, 20, 20);
    current_menu = tama_menu;
    tama_menu->set_cursor_move_callback(&cursor_mov_callback);
    PTK::Image* widget_back = new PTK::Image(0, 0, image_icon_back, 16, 16);
    PTK::Image* widget_feed = new PTK::Image(20, 0, image_icon_feed, 16, 16);
    PTK::Image* widget_check = new PTK::Image(40, 0, image_icon_check, 16, 16);
    PTK::Image* widget_inject = new PTK::Image(40, 20, image_icon_inject, 16, 16);
    PTK::Animation* widget_light = new PTK::Animation(0, 20, animation_icon_light, 16, 16);

    text_view = new PTK::TextBox(0, 0, 128, 64);

    tama_menu->add_child(widget_back, 0, 0, 1, 1, &back_callback);
    tama_menu->add_child(widget_feed, 1, 0, 1, 1, &feed_indv_callback);
    tama_menu->add_child(widget_check, 2, 0, 1, 1, &check_indv_callback);
    tama_menu->add_child(widget_inject, 2, 1, 1, 1, &inject_indv_callback);
    tama_menu->add_child(widget_light, 0, 1, 1, 1, &switch_light_callback);
    world.add_child(tama_menu);
    world.add_child(text_view);
    world.display();
    screen.display();

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
}

void loop(){
    if (b_up.is_just_pressed()){
        Serial.println("up");
        Serial.println(current_menu->move_cursor_by(0, -1));
    }
    if (b_down.is_just_pressed()){
        Serial.println("down");
        Serial.println(current_menu->move_cursor_by(0, 1));
    }
    if (b_left.is_just_pressed()){
        Serial.println("left");
        Serial.println(current_menu->move_cursor_by(-1, 0));
    }
    if (b_right.is_just_pressed()){
        Serial.println("right");
        Serial.println(current_menu->move_cursor_by(1, 0));
    }
    if (b_select.is_just_pressed()){
        Serial.println("select");
        current_menu->activate();
    }
}

void Task_update(void * pvParameters){
    long unsigned int seconds_counted = 0;
        for (;;){
        if (millis() > (seconds_counted*1000)){
            seconds_counted++;
            Serial.println(seconds_counted);
            for (int i = 0 ; i < TAMA_BOXES_AMOUNT ; i++){
                box_advance_second(&tama_boxes[i]);
            }
            Serial.println("Done updating tamas");
        }
        screen.display();
    }
}
