#include "PTK.hpp"

namespace PTK{

	Widget::Widget(){
	}

	Widget::~Widget(){
	}

		Image::Image(unsigned char * set_image, int pos_x, int pos_y, int dim_x, int dim_y){
			image = set_image;
			x = pos_x;
			y = pos_y;
			xx = dim_x;
			yy = dim_y;

			display();
		}

			void Image::display(){
				display.drawBitmap(
					x, y,
					image,
					xx, yy,
					1);
			}

			void Image::hide(){
				display.drawBitmap(
					x, y,
					image,
					xx, yy,
					0);
			}

			Image::~Image(){
			}

			Animation::Animation(unsigned char ** set_anim, int pos_x, int pos_y, int dim_x, int dim_y){
				anim = set_anim;
				x = pos_x;
				y = pos_y;
				xx = dim_x;
				yy = dim_y;
				current_frame = 0;
				current_image = Image(anim[0], x, y, xx, yy);
			}

			void Animation::display(){
				current_image.display();
			}

			void Animation::hide(){
				current_image.hide();
			}

			void Animation::display_next_frame(){
				delete current_image;
				current_frame++;
				current_image = Image(anim[current_frame], x, y, xx, yy);
			}

		Animation::~Animation(){
			delete current_image;
		}

		TextBox::TextBox(string default_string, int pos_x, int pos_y, int span_x, int span_y){
			text = set_string;
			x = pos_x;
			y = pos_y;
			xx = span_x;
			yy = span_y;

			display();
		}

			void TextBox::display(){

			}

			void TextBox::hide(){
				set_text("");
				display();
			}

			void TextBox::set_text(string new_text){
				text = new_text;
				display();
			}

		TextBox::~TextBox(){
			hide();
		}

		CursorMenuItem::CursorMenuItem(Widget set_child, void* set_callback){
			child = set_child;
			callback = set_callback;
		}

			void CursorMenuItem::display(){
				child.display();
			}

			void CursorMenuItem::hide(){
				child.hide();
			}

			Widget CursorMenuItem::get_child(){
				return child;
			}

			void CursorMenuItem::update_child(Widget new_child){
				delete child;
				child = new_child;
				child.display();
			}

			void CursorMenuItem::change_callback(void* new_callback){
				callback = new_callback;
			}

			void CursorMenuItem::activate(){
				callback();
			}

		CursorMenuItem::~CursorMenuItem(){
			hide();
			delete child;
		}

		Container::Container(){
		}

		Container::Container(std::vector<Widget> set_children){
			children = set_children;
		}

			void Container::display(){
				for (auto &child : children){
					child.display();
				}
			}

			void Container::hide(){
				for (auto &child : children){
					child.hide();
				}
			}

			std::vector<Widget> Container::get_children(){
				return children;
			}

			void Container::add_child(Widget new_child){
				children.push_back(new_child);
			}

			void Container::add_children(std::vector<Widget> new_children){
				children.insert(children.end(), new_children.begin(), new_children.end());
			}

		Container::~Container(){
			hide();
		}

			CursorMenu::CursorMenu(int bound_x, int bound_y){

			}

				void CursorMenu::add_item(CursorMenuItem int pos_x, int pos_y){

				}

				void CursorMenu::add_redirection(int pos_x, int pos_y, int to_x, int to_y){

				}

				void CursorMenu::add_movement_cancel(int pos_x, int pos_y){

				}

				void CursorMenu::move_cursor_by(int add_x, int add_y){

				}

				void CursorMenu::move_cursor_to(int pos_x, int pos_y){

				}

				CursorMenuItem CursorMenu::get_item_at_cursor(){

				}

			CursorMenu::~CursorMenu(){

			}
};
