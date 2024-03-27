#include "display.hpp"

int TestBit(unsigned int number, int nth){
	int alias = number;
	return ((alias >> nth) & 1);
}

void draw_image(Adafruit_SSD1306 &screen, image *to_draw, int pixel_colour, int origin_x, int origin_y){
	for (int number = 0 ; number < to_draw->size ; number++){
		for (int bit = 0 ; bit < 32 ; bit++){
			if (TestBit(to_draw->data[number], bit)){
				screen.drawPixel(origin_x+((bit+(number*32))/to_draw->break_point), origin_y+((bit+(number*32))%to_draw->break_point), pixel_colour);
			}
		}
	}
}
