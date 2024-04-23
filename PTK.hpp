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

namespace PTK{

	class Widget{
		protected:

		public:
			Widget();
			virtual void display() = 0;
			virtual void hide() = 0;
			~Widget();
	};

	class Image : public Widget{
		protected:
			unsigned char * image;
			int x, y, xx, yy;

		public:
			Image(unsigned char * set_image, int pos_x, int pos_y, int dim_x, int dim_y);
			~Image();
	};

	class Animation : public Widget{
		protected:
			unsigned char ** anim;
			int x, y, xx, yy;
			int current_frame;
			Image current_image;

		public:
			Animation(unsigned char ** set_anim, int pos_x, int pos_y, int dim_x, int dim_y);
			void display_next_frame();
			~Animation();
	};

	//~ class AnimationPreCharged : public Widget{
		//~ protected:
			//~ std::vector<Image> anim;
			//~ int current_frame;

		//~ public:
			//~ AnimationPreCharged(unsigned char ** set_anim, int pos_x, int pos_y);
			//~ void display_next_frame();
			//~ ~AnimationPreCharged();
	//~ };

	class TextBox : public Widget{
		protected:
			std::string text;
			int x, y, xx, yy;

		public:
			TextBox(string default_string, int pos_x, int pos_y, int span_x, int span_y);
			void set_text(string new_text);
			~TextBox();
	};

	class CursorMenuItem : public Widget{
		protected:
			Widget child;
			void* callback;

		public:
			CursorMenuItem(Widget set_child, void* set_callback);
			Widget get_child();
			void update_child(Widget new_child);
			void change_callback(void* new_callback);
			void activate();
			~CursorMenuItem();
	};

	class Container : public Widget{
		protected:
		std::vector<Widget> children;

		public:
			Container();
			Container(std::vector<Widget> set_children);
			std::vector<Widget> get_children();
			void add_child(Widget new_child);
			void add_children(std::vector<Widget> new_children);
			~Container();
	};

		class CursorMenu : public Container{
			protected:
				int cursor[2];
				CursorMenuItem ** matrice;

			public:
				CursorMenu(int bound_x, int bound_y);
				void add_item(CursorMenuItem int pos_x, int pos_y);
				void add_redirection(int pos_x, int pos_y, int to_x, int to_y);
				void add_movement_cancel(int pos_x, int pos_y);
				void move_cursor_by(int add_x, int add_y);
				void move_cursor_to(int pos_x, int pos_y);
				CursorMenuItem get_item_at_cursor();
				~CursorMenu();
		};


};
