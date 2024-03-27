#include "input.hpp"

namespace Input{

	Button::Button(int set_pin, int set_debounce_time){
		pin = set_pin;
		debounce_time = set_debounce_time;
		current_state = false;
		last_state = false;
	}

	void Button::begin(){
		pinMode(pin, INPUT_PULLUP);
		attachInterruptArg(digitalPinToInterrupt(pin), interrupt_falling_handler, this, FALLING);
		attachInterruptArg(digitalPinToInterrupt(pin), interrupt_rising_handler, this, RISING);

	}

	void Button::interrupt_falling(){
		if (millis() - debounce_last_measure > debounce_time){
			current_state = true;
		}
		debounce_last_measure = millis();
	}

	void Button::interrupt_rising(){
		if (millis() - debounce_last_measure > debounce_time){
			current_state = true;
		}
		debounce_last_measure = millis();
	}

	bool Button::is_pressed(){
		return current_state;
	}

	bool Button::is_just_pressed(){
		if (last_state == false){
			return is_pressed();
		}
		return false;
	}

	bool Button::is_just_released(){
		if (last_state == true){
			return is_pressed();
		}
		return false;
	}

	Button::~Button(){
		detachInterrupt(pin);
	}

	void IRAM_ATTR interrupt_falling_handler(void *p){
		Button *bt = (Button*) p;
		bt->interrupt_falling();
	}

	void IRAM_ATTR interrupt_rising_handler(void *p){
		Button *bt = (Button*) p;
		bt->interrupt_rising();
	}
}

