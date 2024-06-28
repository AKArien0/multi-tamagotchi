#include "tama.h"
#include "images.h"
#include "Input.hpp"
#include "PW.hpp"

#include <string>

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
        screen.setTextColor(WHITE);
        screen.setCursor(0, 0);
        screen.println(text.c_str());
    }

    void TextBox::hide(){
        screen.fillRect(pos_x, pos_y, 128, 16, BLACK);
    }

};

TaskHandle_t Task_update_handle;

Input::Button b_up(5);
Input::Button b_down(4);
Input::Button b_left(14);
Input::Button b_right(17);
Input::Button b_select(16);

//~ PW::Container world(0, 0);

std::vector<PW::Animation*> to_animate;

PW::CursorMenu* current_menu;

PW::TextBox* text_view;

static box boxes[TAMA_BOXES_AMOUNT];

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

    void back(){
        switch_to_box_menu_from_tama();
    }

    void feed(){
        Serial.println("feed_callback");
        text_view->set_text(feed((tama*)current_element, MAX_FOOD/8));
        Serial.println(((tama*)current_element)->food);
    }

    void check(){
        Serial.println("check_callback");
        text_view->set_text(check((tama*)current_element));
        if (((tama*)current_element)->disease_type == DISEASE_DEAD){
            return;
        }
        HERE
        Serial.println(((tama*)current_element)->fragility);
        Serial.println(((tama*)current_element)->form);
        void** animation;
        switch (((tama*)current_element)->form){
            case 0:
                return;

            case 1:
                animation = (void**)animation_tama_1_1_event;
                break;

            case 2:
                animation = (void**)animation_tama_2_1_event;
                break;

            case 3:
                animation =  (void**)animation_tama_2_2_event;
                break;
        }
        int remem_x = to_animate[0]->get_pos_x();
        int remem_y = to_animate[0]->get_pos_y();
        to_animate[0]->change_pos(128, 64);
        PW::Animation answer(76, 16, (void**)animation, 4, 48, 48);
        answer.display();
        while (answer.next_frame() != 0){
            delay(300);
        }
        answer.hide();
        to_animate[0]->change_pos(remem_x, remem_y);
    }

    void light(){
        Serial.println("light callback");
        text_view->set_text(switch_light_from_tama((tama*)current_element));
        ((PW::Animation*)(current_menu->get_item_at_cursor()))->next_frame();
    }

    void clean(){
        Serial.println("clean");
        text_view->set_text(clean_tama((tama*)current_element));
    }

    void inject(){
        Serial.println("inject");
        text_view->set_text(inject((tama*)current_element, INJECT_MEDS, 1*24*60*60));
    }

}

namespace box_callbacks{

    void back(){
        Serial.println("box back");
        switch_to_barn_selector();
    }

    void feed(){
        Serial.println("box feed");
        text_view->set_text(leave_food((box*)current_element, MAX_FOOD));
    }

    void check(){
        Serial.println("box check");
        text_view->set_text(check_box((box*)current_element));
    }

    void light(){
        Serial.println("box light");
        text_view->set_text(switch_light((box*)current_element));
        ((PW::Animation*)(current_menu->get_item_at_cursor()))->next_frame();

    }

    void clean(){
        Serial.println("box clean");
        text_view->set_text(clean_box((box*)current_element));
    }

    void inject(){
        Serial.println("box inject");
        text_view->set_text(distribute_meds((box*)current_element, INJECT_MEDS, 1*24*60*60));
    }

}

PW::CursorMenu* create_box_menu(box* b){
    PW::Image* cursor = new PW::Image(0, 0, (void*)image_cursor, 16, 16);
    PW::CursorMenu* box_menu = new PW::CursorMenu(8, 24, 4, 1, cursor, 20, 20, false);
    box_menu->set_cursor_move_callback(&cursor_mov_callback);

    PW::Image* little_cursor = new PW::Image(0, 0, (void*)image_little_cursor, 12, 12);
    PW::CursorMenu* tama_selector = new PW::CursorMenu(68-12, -8, 5, 4, little_cursor, 12, 12, false);
    tama_selector->set_cursor_move_callback(&cursor_mov_callback);
    little_cursor->hide();

    auto switch_to_tama_selector = [=]() {
        Serial.println("switching to tama selector");
        tama_selector->move_cursor_to(1, 0);
        current_menu = tama_selector;
        cursor->hide();
        little_cursor->display();
    };

    auto switch_to_box_menu = [=]() {
        Serial.println("Switching to box control");
        current_menu = box_menu;
        little_cursor->hide();
        cursor->display();
    };

    box_menu->add_instant_callback(3, 0, 1, 2, switch_to_tama_selector);
    tama_selector->add_instant_callback(0, 0, 1, 4, switch_to_box_menu);

    box_menu->add_child(new PW::Image(0, 0, (void*)image_icon_back, 16, 16), 0, 0, 1, 1, box_callbacks::back);
    box_menu->add_child(new PW::Image(20, 0, (void*)image_icon_feed, 16, 16), 1, 0, 1, 1, box_callbacks::feed);
    box_menu->add_child(new PW::Image(40, 0, (void*)image_icon_check, 16, 16), 2, 0, 1, 1, box_callbacks::check);
    box_menu->add_child(new PW::Animation(0, 20, (void**)animation_icon_light, 2, 16, 16), 0, 1, 1, 1, box_callbacks::light);
    if (b->light){
        ((PW::Animation*)(box_menu->get_item_at(0, 1)))->next_frame();
    }
    box_menu->add_child(new PW::Image(20, 20, (void*)image_icon_rake, 16, 16), 1, 1, 1, 1, box_callbacks::clean);
    box_menu->add_child(new PW::Image(40, 20, (void*)image_icon_inject, 16, 16), 2, 1, 1, 1, box_callbacks::inject);

    for (int i = 0 ; i < 16 ; i++){
        void** animation_to_place;
        switch (b->tamas[i].form){

            case 0:
                animation_to_place = (void**)animation_tama_0_1_mini;
                break;

            case 1:
                animation_to_place = (void**)animation_tama_1_1_mini;
                break;

            case 2:
                animation_to_place = (void**)animation_tama_2_1_mini;
                break;

            case 3:
                animation_to_place = (void**)animation_tama_2_2_mini;
                break;
        }
        if (b->tamas[i].disease_type == DISEASE_DEAD){
            animation_to_place = (void**)animation_skull;
        }

        PW::Animation* widget = new PW::Animation(((i%4)*12)+12, (i/4)*12, animation_to_place, 2, 12, 12);
        to_animate.push_back(widget);
        tama_selector->add_child(widget, (i%4)+1, (i/4), 1, 1, switch_to_tama_menu);
    }

    box_menu->add_child(tama_selector, 4, 0, 1, 1, NULL);

    box_menu->move_cursor_to(0, 0);
    box_menu->add_pos(0, 0);

    box_menu->display();
    tama_selector->display();

    return box_menu;
}

PW::CursorMenu* create_tama_menu(tama* t){

    PW::Image* cursor = new PW::Image(0, 0, (void*)image_cursor, 16, 16);
    PW::CursorMenu* tama_menu = new PW::CursorMenu(8, 24, 4, 1, cursor, 20, 20, false);
    tama_menu->set_cursor_move_callback(&cursor_mov_callback);

    void** animation;

    switch (t->form){
        case 0:
            animation = (void**)egg_animation;
            break;

        case 1:
            animation = (void**)animation_tama_1_1_idle;
            break;

        case 2:
            animation = (void**)animation_tama_2_1_idle;
            break;

        case 3:
            animation = (void**)animation_tama_2_2_idle;
            break;
    }

    if (t->disease_type == DISEASE_DEAD){
        animation = (void**)animation_trash_bag;
    }

    PW::Animation* tama_animation = new PW::Animation(68, -8, animation, 2, 48, 48);
    tama_menu->add_child(tama_animation, 4, 0, 1, 1, NULL);

    to_animate.push_back(tama_animation);

    tama_menu->add_child(new PW::Image(0, 0, (void*)image_icon_back, 16, 16), 0, 0, 1, 1, tama_callbacks::back);
    tama_menu->add_child(new PW::Image(20, 0, (void*)image_icon_feed, 16, 16), 1, 0, 1, 1, tama_callbacks::feed);
    tama_menu->add_child(new PW::Image(40, 0, (void*)image_icon_check, 16, 16), 2, 0, 1, 1, tama_callbacks::check);
    tama_menu->add_child(new PW::Animation(0, 20, (void**)animation_icon_light, 2, 16, 16), 0, 1, 1, 1, tama_callbacks::light);
    if (t->parent->light){
        ((PW::Animation*)(tama_menu->get_item_at(0, 1)))->next_frame();
    }
    tama_menu->add_child(new PW::Image(20, 20, (void*)image_icon_comb, 16, 16), 1, 1, 1, 1, tama_callbacks::clean);
    tama_menu->add_child(new PW::Image(40, 20, (void*)image_icon_inject, 16, 16), 2, 1, 1, 1, tama_callbacks::inject);

    tama_menu->move_cursor_to(0, 0);

    HERE
    tama_menu->add_pos(0, 0);
    HERE

    tama_menu->display();
    return tama_menu;
}

PW::CursorMenu* create_barn_menu(){
    Serial.println("made it here");
    PW::Image* cursor = new PW::Image(0, 0, (void*)image_big_cursor, 32, 24);
    PW::CursorMenu* barn_menu = new PW::CursorMenu(0, 16, 5, 1, cursor, 48, 24, false);
    barn_menu->set_cursor_move_callback(&cursor_mov_callback);

    barn_menu->add_child(new PW::Image(0, 0, (void*)image_barn, 32, 24), 0, 0, 1, 1, switch_to_box_menu_from_barn);
    barn_menu->add_child(new PW::Image(48, 0, (void*)image_barn, 32, 24), 1, 0, 1, 1, switch_to_box_menu_from_barn);
    barn_menu->add_child(new PW::Image(96, 0, (void*)image_barn, 32, 24), 2, 0, 1, 1, switch_to_box_menu_from_barn);
    barn_menu->add_child(new PW::Image(0, 24, (void*)image_barn, 32, 24), 0, 1, 1, 1, switch_to_box_menu_from_barn);
    barn_menu->add_child(new PW::Image(48, 24, (void*)image_barn, 32, 24), 1, 1, 1, 1, switch_to_box_menu_from_barn);
    barn_menu->add_child(new PW::Image(96, 24, (void*)image_barn, 32, 24), 2, 1, 1, 1, switch_to_box_menu_from_barn);

    barn_menu->display();

    Serial.println("made it here");

    barn_menu->move_cursor_to(0, 0);

    Serial.println("made it here");
    barn_menu->add_pos(0, 0);


    return barn_menu;
}

void switch_to_tama_menu(){
    to_animate.clear();
    screen.clearDisplay();

    if (current_element == NULL){
        Serial.println("Current element is null");
    }
    current_element = (void*)&((box*)current_element)->tamas[((current_menu->get_cursor_x()-1)*4)+current_menu->get_cursor_y()];

    if (current_menu == NULL){
        Serial.println("Current menu is null");
    }

    delete current_menu;
    current_menu = create_tama_menu((tama*)current_element);
    //~ world.add_child(current_menu);
    current_menu->display();
    text_view->hide();
}

void switch_to_box_menu_from_tama(){
    to_animate.clear();
    screen.clearDisplay();
    if (current_element == NULL){
        Serial.println("Current element is null");
    }
    current_element = (void*)(((tama*)current_element)->parent);
    if (current_menu == NULL){
        Serial.println("Current menu is null");
    }
    delete current_menu;
    current_menu = create_box_menu((box*)current_element);
    //~ world.add_child(current_menu);
    current_menu->display();
    text_view->hide();
}

void switch_to_barn_selector(){
    to_animate.clear();
    screen.clearDisplay();
    if (current_element == NULL){
        Serial.println("Current element is null");
    }
    current_element = (void*)boxes;
    if (current_menu == NULL){
        Serial.println("Current menu is null");
    }
    delete current_menu;
    current_menu = create_barn_menu();
    current_menu->display();
    text_view->set_text("Barns");
}

void switch_to_box_menu_from_barn(){
    to_animate.clear();
    screen.clearDisplay();
    if (current_element == NULL){
        Serial.println("Current element is null");
    }
    current_element = (void*)&boxes[(current_menu->get_cursor_x())];
    if (current_menu == NULL){
        Serial.println("Current menu is null");
    }
    delete current_menu;
    current_menu = create_box_menu((box*)current_element);
    //~ world.add_child(current_menu);
    current_menu->display();
    text_view->hide();
}

void setup() {
    Serial.begin(9600);
    Serial.println("Alive");

    srand(time(NULL));

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    screen.clearDisplay();
    screen.display();

    text_view = new PW::TextBox(0, 0, 128, 16);

    b_up.begin(INPUT_PULLUP, 0);
    b_down.begin(INPUT_PULLUP, 0);
    b_left.begin(INPUT_PULLUP, 0);
    b_right.begin(INPUT_PULLUP, 0);
    b_select.begin(INPUT_PULLUP, 0);

    for (int i = 0 ; i < TAMA_BOXES_AMOUNT ; i++){
        init_box(&(boxes[i]));
        for (int a = 0 ; a < TAMA_PER_BOX ; a++){
            boxes[i].tamas[a].parent = &boxes[i];
        }
    }

    Serial.println("Creating menu");

    current_element = (void*)&(boxes[0]);
    current_menu = create_barn_menu();
    switch_to_barn_selector();
    //~ current_menu->display();
    Serial.print(current_menu->get_pos_x());Serial.print(" ");Serial.println(current_menu->get_pos_y());
    //~ world.add_child(text_view);
    //~ world.add_child(current_menu);
    Serial.print(current_menu->get_pos_x());Serial.print(" ");Serial.println(current_menu->get_pos_y());
    //~ world.display();
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

long unsigned int seconds_counted = 0;

void loop(){
    if (current_menu){

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

}

void Task_update(void * pvParameters){
    long unsigned int seconds_counted = 0;
    for (;;){
        if (millis() > (seconds_counted*1000)){
            seconds_counted++;
            Serial.println(seconds_counted);
            for (int i = 0 ; i < TAMA_BOXES_AMOUNT ; i++){
                box_advance_second(&boxes[i]);
                //~ for (int a = 0 ; a < TAMA_PER_BOX ; a++){
                    //~ if (boxes[i].tamas[a].form )
                //~ }
            }

            for (auto& item : to_animate) {
                if (item) {
                    item->next_frame();
                }
            }
        }

        screen.display();
    }
}
