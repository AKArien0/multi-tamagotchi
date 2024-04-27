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

#include <vector>
#include <string>
#include <iostream>

namespace PTK{

	void Begin(Adafruit_SSD1306 ssd);

	class Widget{
		protected:
			int pos_x;
			int pos_y;

		public:
			Widget();
			Widget(int set_pos_x, int set_pos_y);
			virtual void display() = 0;
			virtual void hide() = 0;
			virtual void change_pos(int new_pos_x, int new_pos_y);
			int get_pos_x();
			int get_pos_y();
			~Widget();
	};

		class Image : public Widget{
			protected:
				unsigned char * image;
				int xx, yy;

			public:
				Image(int set_pos_x, int set_pos_y, unsigned char * set_image, int dim_x, int dim_y);
				void display();
				void hide();
				~Image();
		};

			class Animation : public Image{
				protected:
					unsigned char ** anim;
					int current_frame;
					int anim_len;

				public:
					Animation(int set_pos_x, int set_pos_y, unsigned char ** set_anim, int dim_x, int dim_y);
					void next_frame();
					~Animation();
			};

		class TextBox : public Widget{
			protected:
				std::string text;
				int xx, yy;

			public:
				TextBox(int set_pos_x, int set_pos_y, std::string set_string, int span_x, int span_y);
				void display();
				void hide();

				void set_text(std::string new_text);
				~TextBox();
		};

		class CursorMenuItem : public Widget{
			protected:
				Widget *child;
				void* callback;

			public:
				CursorMenuItem(int set_pos_x, int set_pos_y, Widget *set_child, void* set_callback);
				void display();
				void hide();

				Widget* get_child();
				void update_child(Widget *new_child);
				void change_callback(void* new_callback);
				void activate();
				~CursorMenuItem();
		};

		class CursorMenu : public Widget{
			protected:
				int cursor[2];
				int bounds[2];
				CursorMenuItem* matrice;

			public:
				CursorMenu(int set_pos_x, int set_pos_y, int set_bound_x, int set_bound_y);
				#define CURSOR_MENU_REDIRECTION(x, y) CursorMenuItem(x, y, NULL, NULL)
				#define CURSOR_MENU_CANCEL CursorMenuItem(-1, -1, NULL, NULL)
				CursorMenu(int set_pos_x, int set_pos_y, int set_bound_x, int set_bound_y, CursorMenuItem *set_matrice);
				void display();
				void hide();
				void add_item(CursorMenuItem new_item, int pos_x, int pos_y);
				void add_redirection(int pos_x, int pos_y, int to_x, int to_y);
				void add_movement_cancel(int pos_x, int pos_y);
				void move_cursor_by(int add_x, int add_y);
				void move_cursor_to(int new_pos_x, int new_pos_y);
				CursorMenuItem get_item_at_cursor();
				~CursorMenu();
		};

		class Container : public Widget{
			protected:
				std::vector<Widget*> children;

			public:
				Container(int set_pos_x, int set_pos_y);
				Container(int set_pos_x, int set_pos_y, std::vector<Widget*> set_children);
				void display();
				void hide();
				void change_pos(int new_pos_x, int new_pos_y);
				std::vector<Widget*> get_children();
				void add_child(Widget* new_child);
				void add_children(std::vector<Widget*> new_children);
				~Container();
		};
};
