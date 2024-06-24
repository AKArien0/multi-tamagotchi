#include "tama.h"
#include "images.h"
#include "Input.hpp"
#include "PW.hpp"

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

namespace PW{
    void Image::display(){
        screen.drawBitmap(
            pos_x, pos_y,
            (unsigned char *)image,
            xx, yy,
            WHITE);
    }

    void Image::hide(){
        screen.drawBitmap(
            pos_x, pos_y,
            (unsigned char *)image,
            xx, yy,
            BLACK);
    }

    void TextBox::display(){
        //~ screen.setTextColor(WHITE);
        //~ screen.setCursor(0, 0);
        //~ screen.println(text);
    }

    void TextBox::hide(){

    }

};

TaskHandle_t Task_update_handle;

Input::Button b_up(18);
Input::Button b_down(5);
Input::Button b_left(17);
Input::Button b_right(16);
Input::Button b_select(4);

PW::Container world(0, 0);

PW::CursorMenu* current_menu;

PW::TextBox* text_view;

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

namespace tama_callbacks{

    void feed(){
        Serial.println("feed_callback");
        text_view->set_text(feed((tama*)current_element, MAX_FOOD/8));
    }

    void check(){
        Serial.println("check_callback");
        text_view->set_text(check((tama*)current_element));
    }

    void inject(){
        Serial.println("inject_callback");
    }

    void fun(){
        text_view->set_text(fun((tama*)current_element));
    }

    void clean(){

    }

    void back(){
        //~ text_view->set_text("Barn");
        //~ delete current_menu;
        //~ current_menu = create_box_menu((tama*)current_element->parent);
    }
}

void switch_light_callback(){
    text_view->set_text(switch_light(((tama*)current_element)->parent));
    ((PW::Animation*)(current_menu->get_item_at_cursor()))->next_frame();
}

PW::CursorMenu* create_box_menu(box* b){

    PW::Image* cursor = new PW::Image(0, 0, (void*)image_cursor, 16, 16);
    PW::CursorMenu* box_menu = new PW::CursorMenu(8, 24, 3, 1, cursor, 20, 20, false);
    box_menu->set_cursor_move_callback(&cursor_mov_callback);

    PW::Image* little_cursor = new PW::Image(0, 0, (void*)image_little_cursor, 12, 12);
    PW::CursorMenu* tama_selector = new PW::CursorMenu(60, 0, 5, 4, little_cursor, 12, 12, false);
    tama_selector->set_cursor_move_callback(&cursor_mov_callback);

    auto switch_to_tama_selector = [&]() {
        tama_selector->move_cursor_to(1, 0);
        current_menu = tama_selector;
        cursor->hide();
        little_cursor->display();
    };

    auto switch_to_box_menu = [&]() {
        current_menu = tama_selector;
        little_cursor->hide();
        cursor->display();
    };

    box_menu->add_instant_callback(3, 0, 1, 2, switch_to_tama_selector);
    tama_selector->add_instant_callback(0, 0, 4, 1, switch_to_box_menu);

    box_menu->add_child(new PW::Image(0, 0, (void*)image_icon_back, 16, 16), 0, 0, 1, 1, &box_callbacks::back);
    box_menu->add_child(new PW::Image(20, 0, (void*)image_icon_feed, 16, 16), 1, 0, 1, 1, &box_callbacks::feed);
    box_menu->add_child(new PW::Image(40, 0, (void*)image_icon_check, 16, 16), 2, 0, 1, 1 &box_callbacks::check);
    box_menu->add_child(new PW::Animation(0, 20, (void*)animation_icon_light, 16, 16), 0, 1, 1, 1, &box_callbacks::light);
    box_menu->add_child(new PW::Image(20, 20, (void*)image_icon_rake, 16, 16), 1, 1, 1, 1, &box_callbacks::clean);
    box_menu->add_child(new PW::Image(40, 20, (void*)image_icon_inject, 16, 16), 2, 1, 1, 1, &box_callbacks::inject);

    for (int i = 0 ; i < 16 ; i++){
        char** animation_to_place;
        switch (b->tamas[i]->form){
            case 1:
                animation_to_place = animation_tama_1_1_mini;
                break;

            case 2:
                animation_to_place = animation_tama_2_1_mini;
                break;

            case 3:
                animation_to_place = animation_tama_2_2_mini;
        }

        tama_selector->add_child(new PW::Animation(0, 0, (void**)animation_to_place, 12, 12), i%4, i/4, 1, 1, /*However the fuck we switch to tama menu, god i love lambas*/)
    }

}

PW::CursorMenu* create_tama_menu(tama* t){

    PW::Image* cursor = new PW::Image(0, 0, (void*)image_cursor, 16, 16);
    PW::CursorMenu* tama_menu = new PW::CursorMenu(8, 24, 2, 1, cursor, 20, 20, false);
    tama_menu->set_cursor_move_callback(&cursor_mov_callback);

    PW::Animation* tama_animation = new PW::Animation(60, 0, (void**)animation_tama_1_1_idle, 48, 48);

    PW::Image* widget_back = new PW::Image(0, 0, (void*)image_icon_back, 16, 16);
    PW::Image* widget_feed = new PW::Image(20, 0, (void*)image_icon_feed, 16, 16);
    PW::Image* widget_check = new PW::Image(40, 0, (void*)image_icon_check, 16, 16);
    PW::Image* widget_inject = new PW::Image(40, 20, (void*)image_icon_inject, 16, 16);
    PW::Image* widget_rake = new PW::Image(0, 20, (void*)image_icon_rake, 16, 16);

    tama_menu->add_child(widget_back, 0, 0, 1, 1, &tama_callbacks::back);
    tama_menu->add_child(widget_feed, 1, 0, 1, 1, &tama_callbacks::feed);
    tama_menu->add_child(widget_check, 2, 0, 1, 1, &tama_callbacks::check);
    tama_menu->add_child(widget_inject, 2, 1, 1, 1, &tama_callbacks::inject);
    tama_menu->add_child(widget_rake, 0, 1, 1, 1, &tama_callbacks::clean);

    return tama_menu;
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

    text_view = new PW::TextBox(0, 0, 128, 64);

    b_up.begin(INPUT_PULLUP, 0);
    b_down.begin(INPUT_PULLUP, 0);
    b_left.begin(INPUT_PULLUP, 0);
    b_right.begin(INPUT_PULLUP, 0);
    b_select.begin(INPUT_PULLUP, 0);

    for (int i = 0 ; i < TAMA_BOXES_AMOUNT ; i++){
        tama_boxes[i] = init_box();
    }

    current_menu = create_tama_menu(&(tama_boxes[0].tamas[0]));

    world.add_child(current_menu);
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
