#include "images.h"

#ifndef SPI_H
#include <SPI.h>
#endif
#ifndef WIRE_H
#include <Wire.h>
#endif
#ifndef ADAFRUIT_GFX_H
#include <Adafruit_GFX.h>
#endif
#ifndef Adafruit_SSD1306_H
#include <Adafruit_SSD1306.h>
#endif


namespace GUI{

	typedef struct animation_struct{
		Adafruit_SSD1306 screen;
		int fps;
		int frames;
		unsigned char &images[frames][]
	} animation;

	class MatriceMenu{
		private:
			int background_anim_frame;
			void* functions[][];
			int frames_anims[][];
			int coordinates_anims[][][2];

		public:
			MatriceMenu(Adafruit_SSD1306 &screen_to_use, int dimension_x, int dimension_y);
			void set_background(animation &bg_anim);
			void set_button(int position_x, int position_y, void &function, int sprite_pos_x, int sprite_pos_y, animation &idle_anim, animation &hover_anim);
			void select();
			int cursor[2];
			bool correct_cursor();
			~MatriceMenu();
	};
};
