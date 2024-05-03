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
			void reposition(int add_pos_x, int add_pos_t);
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
				void change_pos(int new_pos_x, int new_pos_y);
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
					void (*cursor_move_callback)();
					Widget* cursor_widget;
					int cursor_origin_x;
					int cursor_origin_y;
					int cursor_step_x;
					int cursor_step_y;
					std::vector<int> children_pos_x;
					std::vector<int> children_pos_y;
					std::vector<int> children_dim_x;
					std::vector<int> children_dim_y;
					std::vector<void(*)()> children_callbacks;

				public:

					CursorMenu(int set_pos_x, int set_pos_y, int bound_x, int bound_y, Widget* set_cursor_widget, int set_cursor_origin_x, int set_cursor_origin_y, int set_cursor_step_x, int set_cursor_step_y);
					void set_cursor_move_callback(void(*set_callback)());
					void add_child(Widget* new_child, int rel_pos_x, int rel_pos_y, int dim_x, int dim_y, void (*callback)());
					void add_movement_cancel(int x, int y, int xx, int yy);
					void add_instant_callback(int x, int y, int xx, int yy, void (*callback)());
					//~ #define add_movement_cancel(x, y, xx, yy) add_child(NULL, x, y, xx, yy, NULL)
					//~ #define add_instant_callback(x, y, xx, yy, callback) add_child(NULL, x, y, xx, yy, callback);
					int get_index_from_coords(int x, int y);
					int move_cursor_by(int add_x, int add_y);
					int move_cursor_to(int new_pos_x, int new_pos_y);
					int get_cursor_x();
					int get_cursor_y();
					int get_cursor_step_x();
					int get_cursor_step_y();
					Widget* get_cursor_widget();
					void set_cursor_step(int x, int y);
					Widget* get_item_at(int x, int y);
					Widget* get_item_at_cursor();
					void activate();
					~CursorMenu();

			};
};
