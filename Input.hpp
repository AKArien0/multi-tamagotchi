#include <Arduino.h>

namespace Input{

	static void interrupt_change_handler(void *p);
	//~ static void interrupt_falling_handler(void *p);
	//~ static void interrupt_rising_handler(void *p);

	class Button{
		private:
			volatile int pin;
			//~ volatile int debounce_time, debounce_last_measure;
			volatile bool current_state, last_state;

		public:
			Button(int set_pin);
			void interrupt_change();
			//~ void interrupt_falling();
			//~ void interrupt_rising();
			void begin();
			bool is_pressed();
			bool is_just_pressed();
			bool is_just_released();
			//~ void verify();
			~Button();
	};

}
