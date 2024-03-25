#include "tama.h"

#include "input.hpp"

#include "display.hpp"
#include "images.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

TaskHandle_t Task_values_handle;

#define DEBOUNCE 10
input::Button b_up(15, DEBOUNCE);
input::Button b_down(2, DEBOUNCE);
input::Button b_left(4, DEBOUNCE);
input::Button b_right(16, DEBOUNCE);
input::Button b_select(17, DEBOUNCE);

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
	//~ Serial.println(b_up.is_pressed());
	//~ Serial.println(digitalRead(15));
  //~ Serial.println(small_full.data[1]);

	draw_image(display, &small_full, WHITE, 56, 16);
	display.display();
	delay(500);
	draw_image(display, &small_full, BLACK, 56, 16);
	display.display();
	delay(500);
}

void Task_values(void * pvParameters){
	static long unsigned int seconds_counted = 0;
	for (;;){
		if (millis() > (seconds_counted*1000)){
			seconds_counted++;
		}
	}
}
