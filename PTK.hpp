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

	class Widget{
		protected:
			int pos_x;
			int pos_y;

		public:
			Widget();
			Widget(int set_pos_x, int set_pos_y);
			virtual void display();
			virtual void hide();
			virtual void change_pos(int new_pos_x, int new_pos_y);
			int get_pos_x();
			int get_pos_y();
			~Widget();
	};

		class Image : public Widget{
			protected:
				const unsigned char * image;
				int xx, yy;

			public:
				Image(int set_pos_x, int set_pos_y, const unsigned char * set_image, int dim_x, int dim_y);
				void display();
				void hide();
				~Image();
		};

			class Animation : public Image{
				protected:
					const unsigned char ** anim;
					int current_frame;
					int anim_len;

				public:
					Animation(int set_pos_x, int set_pos_y, const unsigned char ** set_anim, int dim_x, int dim_y);
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

		//~ class CursorMenuItem : public Widget{
			//~ protected:
				//~ Widget *child;
				//~ void* callback;

			//~ public:
				//~ CursorMenuItem(int set_pos_x, int set_pos_y, Widget *set_child, void* set_callback);
				//~ void display();
				//~ void hide();

				//~ Widget* get_child();
				//~ void update_child(Widget *new_child);
				//~ void change_callback(void* new_callback);
				//~ void activate();
				//~ ~CursorMenuItem();
		//~ };

		//~ class CursorMenu : public Widget{
			//~ protected:
				//~ int cursor[2];
				//~ int bounds[2];
				//~ CursorMenuItem* matrice;

			//~ public:
				//~ CursorMenu(int set_pos_x, int set_pos_y, int set_bound_x, int set_bound_y);
				//~ #define CURSOR_MENU_REDIRECTION(x, y) CursorMenuItem(x, y, NULL, NULL)
				//~ #define CURSOR_MENU_CANCEL CursorMenuItem(-1, -1, NULL, NULL)
				//~ CursorMenu(int set_pos_x, int set_pos_y, int set_bound_x, int set_bound_y, CursorMenuItem *set_matrice);
				//~ void display();
				//~ void hide();
				//~ void add_item(CursorMenuItem new_item, int pos_x, int pos_y);
				//~ void add_redirection(int pos_x, int pos_y, int to_x, int to_y);
				//~ void add_movement_cancel(int pos_x, int pos_y);
				//~ void move_cursor_by(int add_x, int add_y);
				//~ void move_cursor_to(int new_pos_x, int new_pos_y);
				//~ CursorMenuItem get_item_at_cursor();
				//~ ~CursorMenu();
		//~ };

		class Container : public Widget{
			protected:
				std::vector<Widget*> children;

			public:
				Container(int set_pos_x, int set_pos_y);
				Container(int set_pos_x, int set_pos_y, std::vector<Widget*>* set_children);
				void display();
				void hide();
				void change_pos(int new_pos_x, int new_pos_y);
				std::vector<Widget*>* get_children();
				virtual void add_child(Widget* new_child);
				void add_children(std::vector<Widget*>* new_children);
				~Container();
		};

			class CursorMenu : public Container{
				protected:
					int bounds[2];
					int cursor[2];
					void* cursor_move_callback;
					int get_index_from_coords(int x, int y);

					std::vector<int> children_pos_x;
					std::vector<int> children_pos_y;
					std::vector<int> children_dim_x;
					std::vector<int> children_dim_y;
					std::vector<void(*)()> children_callbacks;

				public:
					CursorMenu(int set_pos_x, int set_pos_y, int bound_x, int bound_y);
					void set_cursor_move_callback(void* set_callback);
					void add_child(Widget* new_child, int rel_pos_x, int rel_pos_y, int dim_x, int dim_y, void (*callback)());
					#define add_movement_cancel(pos_x, pos_y, dim_x, dim_y) add_child(NULL, pos_x, pos_y, dim_x, dim_y, NULL)
					#define add_instant_callback(pos_x, pos_y, dim_x, dim_y, callback) add_child(NULL, pos_x, pos_y, dim_x, dim_y, callback)
					int move_cursor_by(int add_x, int add_y);
					int move_cursor_to(int new_pos_x, int new_pos_y);
					int get_cursor_x();
					int get_cursor_y();
					Widget* get_item_at(int x, int y);
					Widget* get_item_at_cursor();
					void activate();
					~CursorMenu();

			};
};
