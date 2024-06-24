/*
SPDX-FileCopyrightText : 2024 AKArien <skeptikal.monke@gmail.com>
SPDX-License-Identifier : GPL-3.0-or-later
*/

#include "PW.hpp"

namespace PW{

    Widget::Widget(){
	pos_x = 0;
	pos_y = 0;
    }

    Widget::Widget(int set_pos_x, int set_pos_y){
	pos_x = set_pos_x;
	pos_y = set_pos_y;
    }

    void Widget::display(){
    }

    void Widget::hide(){
    }

    void Widget::change_pos(int new_pos_x, int new_pos_y){
	hide();
	pos_x = new_pos_x;
	pos_y = new_pos_y;
	display();
    }

    void Widget::add_pos(int add_pos_x, int add_pos_y){
	change_pos(pos_x+add_pos_x, pos_y+add_pos_y);
    }

    int Widget::get_pos_x(){
	return pos_x;
    }

    int Widget::get_pos_y(){
	return pos_y;
    }

    Widget::~Widget(){
    }

	Image::Image(int set_pos_x, int set_pos_y, void* set_image, int dim_x, int dim_y) : Widget(set_pos_x, set_pos_y){
	    image = set_image;
	    xx = dim_x;
	    yy = dim_y;
	}

	    void Image::change_pos(int new_pos_x, int new_pos_y){
		hide();
		pos_x = new_pos_x;
		pos_y = new_pos_y;
		display();
	    }

	Image::~Image(){
	    hide();
	}

	    Animation::Animation(int set_pos_x, int set_pos_y, void** set_anim, int dim_x, int dim_y) : Image(set_pos_x, set_pos_y, set_anim[0], dim_x, dim_y){
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
		    image = anim[current_frame];
		    display();
		}

	    Animation::~Animation(){
	    }

	TextBox::TextBox(int set_pos_x, int set_pos_y, int span_x, int span_y) : Widget(set_pos_x, set_pos_y){
	    text = "";
	    xx = span_x;
	    yy = span_y;
	}

	    void TextBox::set_text(std::string new_text){
		text = new_text;
		display();
	    }

	TextBox::~TextBox(){
	    hide();
	}


	Container::Container(int set_pos_x, int set_pos_y) : Widget(set_pos_x, set_pos_y){

	}

	Container::Container(int set_pos_x, int set_pos_y, std::vector<Widget*>* set_children) : Widget(set_pos_x, set_pos_y){
	    add_children(set_children);
	}

	    void Container::change_pos(int new_pos_x, int new_pos_y){
		Widget::change_pos(new_pos_x, new_pos_y);
		for (int i = 0 ; i < children.size() ; i++){
		    if (children[i] != NULL){
			children[i]->change_pos(children[i]->get_pos_x()+pos_x, children[i]->get_pos_y()+pos_y);
		    }
		}
	    }

	    void Container::display(){
		for (int i = 0 ; i < children.size() ; i++){
		    if (children[i] != NULL){
			children[i]->display();
		    }
		}
	    }

	    void Container::hide(){
		for (int i = 0 ; i < children.size() ; i++){
		    if (children[i] != NULL){
			children[i]->hide();
		    }
		}
	    }

	    std::vector<Widget*>* Container::get_children(){
		return &children;
	    }

	    void Container::add_child(Widget* new_child){
		children.push_back(new_child);
		if (new_child != NULL){
		    new_child->change_pos(new_child->get_pos_x()+pos_x, new_child->get_pos_y()+pos_y);
		}
	    }

	    void Container::add_children(std::vector<Widget*>* new_children){
		for (int i = 0 ; i < new_children->size() ; i++){
		    add_child(new_children->at(i));
		}
	    }

	Container::~Container(){
	    for (int i = 0 ; i < children.size() ; i++){
		if (children[i] != NULL){
		    delete children[i];
		}
	    }
	}

	    CursorMenu::CursorMenu(int set_pos_x, int set_pos_y, int bound_x, int bound_y, Widget* set_cursor_widget,
		    int set_cursor_step_x, int set_cursor_step_y,
		    bool init_instant_callback_is_valid_position) : Container(set_pos_x, set_pos_y){
		bounds[0] = bound_x;
		bounds[1] = bound_y;
		cursor_move_callback = NULL;
		cursor_step_x = set_cursor_step_x;
		cursor_step_y = set_cursor_step_y;
		cursor_widget = set_cursor_widget;
		cursor_widget->add_pos(pos_x, pos_y);
		instant_callback_is_valid_position = init_instant_callback_is_valid_position;
	    }

		void CursorMenu::set_cursor_move_callback(void(*set_callback)()){
		    cursor_move_callback = set_callback;
		}

		void CursorMenu::add_child(Widget* new_child, int rel_pos_x, int rel_pos_y, int dim_x, int dim_y, std::function<void()> callback){
		    //~ Container::add_child(new_child);
		    children.push_back(new_child);
		    children_pos_x.push_back(rel_pos_x);
		    children_pos_y.push_back(rel_pos_y);
		    children_dim_x.push_back(dim_x);
		    children_dim_y.push_back(dim_y);
		    children_callbacks.push_back(callback);
		}

		int CursorMenu::get_index_from_coords(int x, int y){
		    for (int i = 0 ; i < children.size() ; i++){
			//~ if (((x >= children_pos_x[i]) && (x <= children_pos_x[i]+children_dim_x[i])) && ((y >= children_pos_y[i]) && (y <= children_pos_y[i]+children_dim_y[i]))){
			if (((x >= children_pos_x[i] && x < children_pos_x[i] + children_dim_x[i]) && (y >= children_pos_y[i] && y < children_pos_y[i] + children_dim_y[i]))){ //corrected by codegemma. idfk
			    return i;
			}
		    }
		    return -1;
		}


		int CursorMenu::move_cursor_by(int add_x, int add_y){
		    return move_cursor_to(get_cursor_x()+add_x, get_cursor_y()+add_y);
		}

		int CursorMenu::move_cursor_to(int new_pos_x, int new_pos_y){
		    int index = get_index_from_coords(new_pos_x, new_pos_y);
		    if (index == -1){
			return 3;
		    }
		    if (children[index] == NULL){
			if (children_callbacks[index] == NULL){
			    return 2;
			}
			children_callbacks[index]();
			if (!instant_callback_is_valid_position){
			    return 1;
			}
		    }

		    if (new_pos_x < 0){
			new_pos_x = 0;
		    }
		    if (new_pos_y < 0){
			new_pos_y = 0;
		    }
		    if (new_pos_x > bounds[0]){
			new_pos_x = bounds[0];
		    }
		    if (new_pos_y > bounds[1]){
			new_pos_y = bounds[1];
		    }
		    cursor[0] = new_pos_x;
		    cursor[1] = new_pos_y;

		    cursor_widget->change_pos((cursor[0]*cursor_step_x)+pos_x, (cursor[1]*cursor_step_y)+pos_y);

		    cursor_move_callback();
		    return 0;
		}

		void CursorMenu::add_movement_cancel(int x, int y, int xx, int yy){
		    add_child(NULL, x, y, xx, yy, NULL);
		}

		void CursorMenu::add_instant_callback(int x, int y, int xx, int yy, std::function<void()> callback){
		    add_child(NULL, x, y, xx, yy, callback);
		}

		void CursorMenu::set_instant_callback_is_valid_position(bool set){
		    instant_callback_is_valid_position = set;
		}

		int CursorMenu::get_cursor_x(){
		    return cursor[0];
		}

		int CursorMenu::get_cursor_y(){
		    return cursor[1];
		}

		int CursorMenu::get_cursor_step_x(){
		    return cursor_step_x;
		}

		int CursorMenu::get_cursor_step_y(){
		    return cursor_step_y;
		}

		void CursorMenu::set_cursor_step(int x, int y){
		    cursor_step_x = x;
		    cursor_step_y = y;
		}

		Widget* CursorMenu::get_item_at(int x, int y){
		    return children[get_index_from_coords(x, y)];
		}

		Widget* CursorMenu::get_cursor_widget(){
		    return cursor_widget;
		}

		Widget* CursorMenu::get_item_at_cursor(){
		    get_item_at(cursor[0], cursor[1]);
		}

		void CursorMenu::activate(){
		    int index = get_index_from_coords(cursor[0], cursor[1]);
		    if (index > -1){
			return;
		    }
		    if (children_callbacks[index] == NULL){
			return;
		    }
		    children_callbacks[index]();
		}

	    CursorMenu::~CursorMenu(){
		    // codegemma's proposal :
		// Clean up allocated memory for children and their callbacks
		delete cursor;
		for (auto& child : children) {
		    delete child;
		}
		children.clear();
		delete[] children_pos_x.data();
		delete[] children_pos_y.data();
		delete[] children_dim_x.data();
		delete[] children_dim_y.data();
		delete[] children_callbacks.data();
	    }

};
