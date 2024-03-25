#include "display.hpp"

int TestBit(unsigned int number, int nth){
	int alias = number;
	return ((alias >> nth) & 1);
}

void draw_image(Adafruit_SSD1306 &screen, image *to_draw, int pixel_colour, int origin_x, int origin_y){
	for (int i = 0 ; i < 32 ; i++){
		Serial.print(i);
		Serial.print(" : ");
		Serial.println(to_draw->size);
		Serial.println(to_draw->break_point);
		Serial.println(to_draw->data[0]);

		delay(250);
	}
	//~ for (int number = 0 ; number < to_draw.size ; number++){
		//~ for (int bit = 0 ; bit < 32 ; bit++){
			//~ int b = TestBit(to_draw.data[number], bit);
			//~ Serial.println(b);
			//~ if (b){
				//~ screen.drawPixel(origin_x+bit+(number*32), origin_y, pixel_colour);
			//~ }
		//~ }
	//~ }
}
