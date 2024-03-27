#include "tama.h"

#include "input.hpp"

#include "display.hpp"
#include "images.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

TaskHandle_t Task_values_handle;

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

	// Show initial display buffer contents on the screen --
	// the library initializes this with an Adafruit splash screen.
	display.display();
	delay(2000); // Pause for 2 seconds

	// Clear the buffer
	display.clearDisplay();
	//draw_image(display, big_square, SIZE_BIG_SQUARE, WHITE, 0, 0);
	display.display();

	xTaskCreatePinnedToCore(
		Task_values,
		"Updating values in memory",
		8192,
		NULL,
		1,
		&Task_values_handle,
		1
	);

	b_up.begin();
	b_down.begin();
	b_left.begin();
	b_right.begin();
	b_select.begin();

	Serial.println("Setup complete");
}

void loop(){
    if (b_up.is_just_pressed()){
        Serial.println("up just pressed");
    }

    if (b_up.is_pressed()){
        Serial.println("up pressed");
    }

    if (b_up.is_just_released()){
        Serial.println("up just released");
    }

    if (b_down.is_just_pressed()){
        Serial.println("down just pressed");
    }

    if (b_down.is_just_released()){
        Serial.println("down just released");
    }

    if (b_left.is_just_pressed()){
        Serial.println("left just pressed");
    }

    if (b_left.is_just_released()){
        Serial.println("left just released");
    }

    if (b_right.is_just_pressed()){
        Serial.println("right just pressed");
    }

    if (b_right.is_just_released()){
        Serial.println("right just released");
    }

    if (b_select.is_just_pressed()){
        Serial.println("select just pressed");
    }

    if (b_select.is_just_released()){
        Serial.println("select just released");
    }

    //~ b_up.verify();
    //~ b_down.verify();
    //~ b_left.verify();
    //~ b_right.verify();
    //~ b_select.verify();
}

void Task_values(void * pvParameters){
	static long unsigned int seconds_counted = 0;
	for (;;){
		if (millis() > (seconds_counted*1000)){
			seconds_counted++;
		}
	}
}
