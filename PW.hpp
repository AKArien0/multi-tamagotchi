/*
SPDX-FileCopyrightText : 2024 AKArien <skeptikal.monke@gmail.com>
SPDX-License-Identifier : GPL-3.0-or-later
*/

#include <vector>
#include <string>
#include <iostream>
#include <functional>

namespace PW{

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
			void add_pos(int add_pos_x, int add_pos_t);
			int get_pos_x();
			int get_pos_y();
			virtual ~Widget();
	};

		class Image : public Widget{
			protected:
				void* image;
				int xx, yy;

			public:
				Image(int set_pos_x, int set_pos_y, void* set_image, int dim_x, int dim_y);
				void display();
				void hide();
				void change_pos(int new_pos_x, int new_pos_y);
				~Image();
		};

			class Animation : public Image{
				protected:
					void** anim;
					int current_frame;
					int anim_len;

				public:
					Animation(int set_pos_x, int set_pos_y, void** set_anim, int lenght, int dim_x, int dim_y);
					int next_frame();
					~Animation();
			};

		class TextBox : public Widget{
			protected:
				std::string text;
				int xx, yy;

			public:
				TextBox(int set_pos_x, int set_pos_y, int span_x, int span_y);
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
					std::vector<std::function<void()>> children_callbacks;
					bool instant_callback_is_valid_position;

				public:
					CursorMenu(int set_pos_x, int set_pos_y, int bound_x, int bound_y, Widget* set_cursor_widget, int set_cursor_step_x, int set_cursor_step_y, bool init_instant_callback_is_valid_position);
					void set_cursor_move_callback(void(*set_callback)());
					void add_child(Widget* new_child, int rel_pos_x, int rel_pos_y, int dim_x, int dim_y, std::function<void()> callback);
					void add_movement_cancel(int x, int y, int xx, int yy);
					void add_instant_callback(int x, int y, int xx, int yy, std::function<void()> callback);
					void set_instant_callback_is_valid_position(bool set);
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
