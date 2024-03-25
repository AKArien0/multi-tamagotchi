#include "input.hpp"

namespace input{
	Button::Button(int set_pin, int set_debounce_time){
		pin = set_pin;
		debounce_time = set_debounce_time;
	}

	void Button::interrupt_falling(){
		if (millis() - debounce_last_measure > debounce_time){
			current_state = true;
			last_state = false;
		}
		debounce_last_measure = millis();
	}

	void Button::interrupt_rising(){
		if (millis() - debounce_last_measure > debounce_time){
			current_state = false;
			last_state = true;
		}
		debounce_last_measure = millis();
	}

	void Button::begin(){
		pinMode(pin, INPUT_PULLUP);
		// since input mode is pullup, invert high and low
		attachInterrupt(digitalPinToInterrupt(pin), interrupt_falling, FALLING);
		attachInterrupt(digitalPinToInterrupt(pin), interrupt_rising, RISING);
	}

	bool Button::is_pressed(){
		return current_state;
	}

	bool Button::is_just_pressed(){
		if (last_state == false && current_state == true){
			last_state = current_state;
			return true;
		}
		return false;
	}
	bool Button::is_just_released(){
		if (last_state == true && current_state == false){
			last_state = current_state;
			return true;
		}
		return false;
	}

	Button::~Button(){

	}

}

