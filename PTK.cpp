#include "PTK.hpp"

namespace PTK{

	Adafruit_SSD1306 screen;

	void Begin(Adafruit_SSD1306 ssd){
		screen = ssd;
	}

	Widget::Widget(){
		pos_x = 0;
		pos_y = 0;
	}

	Widget::Widget(int set_pos_x, int set_pos_y){
		pos_x = set_pos_x;
		pos_y = set_pos_y;
	}

	void Widget::change_pos(int new_pos_x, int new_pos_y){
		hide();
		pos_x = new_pos_x;
		pos_y = new_pos_y;
		display();
	}

	int Widget::get_pos_x(){
		return pos_x;
	}

	int Widget::get_pos_y(){
		return pos_y;
	}

	Widget::~Widget(){
	}

		Image::Image(int set_pos_x, int set_pos_y, unsigned char * set_image, int dim_x, int dim_y) : Widget(set_pos_x, set_pos_y){
			image = set_image;
			xx = dim_x;
			yy = dim_y;
		}

			void Image::display(){
				screen.drawBitmap(
					pos_x, pos_y,
					image,
					xx, yy,
					WHITE);
			}

			void Image::hide(){
				screen.drawBitmap(
					pos_x, pos_y,
					image,
					xx, yy,
					BLACK);
			}

		Image::~Image(){
			hide();
		}

		Animation::Animation(int set_pos_x, int set_pos_y, unsigned char ** set_anim, int dim_x, int dim_y) : Image(set_pos_x, set_pos_y, set_anim[0], dim_x, dim_y){
			anim = set_anim;
			current_frame = 0;
			anim_len = sizeof(set_anim)/sizeof(set_anim[0]);
		}

			void Animation::next_frame(){
				hide();
				current_frame++;
				if (current_frame > anim_len){
					current_frame = 0;
				}
				display();
			}

		Animation::~Animation(){
		}

		TextBox::TextBox(int set_pos_x, int set_pos_y, std::string set_string, int span_x, int span_y) : Widget(set_pos_x, set_pos_y){
			text = set_string;
			xx = span_x;
			yy = span_y;
		}

			void TextBox::display(){

			}

			void TextBox::hide(){
				set_text("");
				display();
			}

			void TextBox::set_text(std::string new_text){
				text = new_text;
				display();
			}

		TextBox::~TextBox(){
			hide();
		}

		CursorMenu::CursorMenu(int set_pos_x, int set_pos_y, int set_bound_x, int set_bound_y) : Widget(set_pos_x, set_pos_y){
			bounds[0] = set_bound_x;
			bounds[1] = set_bound_y;
			cursor[0] = 0;
			cursor[1] = 0;
			matrice = (CursorMenuItem *)malloc(bounds[0]*bounds[1]*sizeof(CursorMenuItem));
		}

		CursorMenu::CursorMenu(int set_pos_x, int set_pos_y, int set_bound_x, int set_bound_y, CursorMenuItem *set_matrice) : Widget(set_pos_x, set_pos_y){
			bounds[0] = set_bound_x;
			bounds[1] = set_bound_y;
			cursor[0] = 0;
			cursor[1] = 0;

			matrice = set_matrice;
		}

			void CursorMenu::add_item(CursorMenuItem new_item, int pos_x, int pos_y){
				matrice[pos_x*(pos_y*pos_x)] = new_item;
			}

			void CursorMenu::add_redirection(int pos_x, int pos_y, int to_x, int to_y){
				add_item(CURSOR_MENU_REDIRECTION(to_x, to_y), pos_x, pos_y);
			}

			void CursorMenu::add_movement_cancel(int pos_x, int pos_y){
				add_item(CURSOR_MENU_CANCEL, pos_x, pos_y);
			}

			void CursorMenu::move_cursor_by(int add_x, int add_y){
				if (get_item_at_cursor().get_child() == NULL){
					if ((get_item_at_cursor().get_pos_x() == -1) && (get_item_at_cursor().get_pos_y() == -1)){
						return;
					}
					move_cursor_to(get_item_at_cursor().get_pos_x(), get_item_at_cursor().get_pos_y()); // special case : childless CursorMenuItem who's position values are representative of where to place the cursor
					return;
				}
				cursor[0] += pos_x;
				cursor[1] += pos_y;
				if (cursor[0] < 0){
					cursor[0] = 0;
				}
				if (cursor[0] > bounds[0]){
					cursor[0] = bounds[0];
				}
				if (cursor[1] < 0){
					cursor[1] = 0;
				}
				if (cursor[1] > bounds[1]){
					cursor[1] = bounds[1];
				}

			}

			void CursorMenu::move_cursor_to(int new_pos_x, int new_pos_y){
				if (get_item_at_cursor().get_child() == NULL){
					if ((get_item_at_cursor().get_pos_x() == -1) && (get_item_at_cursor().get_pos_y() == -1)){
						return;
					}
					move_cursor_to(get_item_at_cursor().get_pos_x(), get_item_at_cursor().get_pos_y()); // special case : childless CursorMenuItem who's position values are representative of where to place the cursor
					return;
				}
				cursor[0] = new_pos_x;
				cursor[1] = new_pos_y;
			}

			CursorMenuItem CursorMenu::get_item_at_cursor(){
				return matrice[pos_x*(pos_y*pos_x)];
			}

		CursorMenu::~CursorMenu(){
			free(matrice);
		}

		CursorMenuItem::CursorMenuItem(int set_pos_x, int set_pos_y, Widget *set_child, void* set_callback) : Widget(set_pos_x, set_pos_y){
			child = set_child;
			callback = set_callback;
		}

			void CursorMenuItem::display(){
				child->display();
			}

			void CursorMenuItem::hide(){
				child->hide();
			}

			Widget* CursorMenuItem::get_child(){
				return child;
			}

			void CursorMenuItem::update_child(Widget* new_child){
				delete child;
				child = new_child;
				child->display();
			}

			void CursorMenuItem::change_callback(void* new_callback){
				callback = new_callback;
			}

			void CursorMenuItem::activate(){
				void (callback)();
			}

		CursorMenuItem::~CursorMenuItem(){
			delete child;
		}

		Container::Container(int set_pos_x, int set_pos_y) : Widget(set_pos_x, set_pos_y){

		}

		Container::Container(int set_pos_x, int set_pos_y, std::vector<Widget*>* set_children) : Widget(set_pos_x, set_pos_y){
			children = set_children;
			for (int i = 0 ; i < children.size() ; i++){
				children[i]->change_pos(children[i]->get_pos_x()+pos_x, children[i]->get_pos_y()+pos_y);
			}
		}

			void Container::change_pos(int new_pos_x, int new_pos_y){
				Widget::change_pos(new_pos_x, new_pos_y);
				for (int i = 0 ; i < children.size() ; i++){
					children[i]->change_pos(children[i]->get_pos_x()+pos_x, children[i]->get_pos_y()+pos_y);
				}
			}

			void Container::display(){
				for (int i = 0 ; i < children.size() ; i++){
					children[i]->display();
				}
			}

			void Container::hide(){
				for (int i = 0 ; i < children.size() ; i++){
					children[i]->hide();
				}
			}

			std::vector<Widget*>* Container::get_children(){
				return children;
			}

			void Container::add_child(Widget* new_child){
				new_child->change_pos(new_child->get_pos_x()+pos_x, new_child->get_pos_y()+pos_y);
				children.push_back(new_child); // random pixels problem
			}

			void Container::add_children(std::vector<Widget*>* new_children){
				children.insert(children.end(), new_children.begin(), new_children.end());
			}

		Container::~Container(){
			for (int i = 0 ; i < children.size() ; i++){
				delete children[i];
			}
		}


};
