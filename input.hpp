#include <Arduino.h>

namespace input{
	class Button{
		private:
			int pin;
			inline static volatile int debounce_time, debounce_last_measure;
			inline static volatile bool current_state, last_state;
			static void interrupt_falling();
			static void interrupt_rising();

		public:
			Button(int set_pin, int set_debounce_time);
			void begin();
			bool is_pressed();
			bool is_just_pressed();
			bool is_just_released();
			~Button();
	};

}
