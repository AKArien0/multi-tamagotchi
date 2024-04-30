#include "PTK.hpp"

namespace PTK{

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

    int Widget::get_pos_x(){
	return pos_x;
    }

    int Widget::get_pos_y(){
	return pos_y;
    }

    Widget::~Widget(){
    }

	Image::Image(int set_pos_x, int set_pos_y, const unsigned char * set_image, int dim_x, int dim_y) : Widget(set_pos_x, set_pos_y){
	    image = set_image;
	    xx = dim_x;
	    yy = dim_y;
	}

		//~ void Image::display(){
			//~ screen.drawBitmap(
				//~ pos_x, pos_y,
				//~ image,
				//~ xx, yy,
				//~ WHITE);
		//~ }

		//~ void Image::hide(){
			//~ screen.drawBitmap(
				//~ pos_x, pos_y,
				//~ image,
				//~ xx, yy,
				//~ BLACK);
		//~ }

	Image::~Image(){
	    hide();
	}

	    Animation::Animation(int set_pos_x, int set_pos_y, const unsigned char ** set_anim, int dim_x, int dim_y) : Image(set_pos_x, set_pos_y, set_anim[0], dim_x, dim_y){
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

		//~ void TextBox::display(){

		//~ }

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


	Container::Container(int set_pos_x, int set_pos_y) : Widget(set_pos_x, set_pos_y){

	}

	Container::Container(int set_pos_x, int set_pos_y, std::vector<Widget*>* set_children) : Widget(set_pos_x, set_pos_y){
	    add_children(set_children);
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
		return &children;
	    }

	    void Container::add_child(Widget* new_child){
		//~ new_child->change_pos(new_child->get_pos_x()+pos_x, new_child->get_pos_y()+pos_y);
		new_child->get_pos_x();
		children.push_back(new_child); // random pixels problem
	    }

	    void Container::add_children(std::vector<Widget*>* new_children){
		children.insert(children.end(), new_children->begin(), new_children->end());
		for (int i = 0 ; i < children.size() ; i++){
			children[i]->change_pos(children[i]->get_pos_x()+pos_x, children[i]->get_pos_y()+pos_y);
		}
	    }

	Container::~Container(){
	    for (int i = 0 ; i < children.size() ; i++){
		    delete children[i];
	    }
	}

	    CursorMenu::CursorMenu(int set_pos_x, int set_pos_y, int bound_x, int bound_y) : Container(set_pos_x, set_pos_y){
		bounds[0] = bound_x;
		bounds[1] = bound_y;
		cursor_move_callback = NULL;
	    }

		int CursorMenu::get_index_from_coords(int x, int y){
		    for (int i = 0 ; i < children.size() ; i++){
			    if (x >= children_pos_x[i] && x <= children_pos_x[i]+children_dim_x[i]){
				    if (y >= children_pos_y[i] && y <= children_pos_y[i]+children_dim_y[i]){
					    return i;
				    }
			    }
		    }
		    return -1;
		}

		void CursorMenu::set_cursor_move_callback(void* set_callback){
		    cursor_move_callback = set_callback;
		}

		void CursorMenu::add_child(Widget* new_child, int rel_pos_x, int rel_pos_y, int dim_x, int dim_y, void (*callback)()){
		    children.push_back(new_child);
		    children_pos_x.push_back(rel_pos_x);
		    children_pos_y.push_back(rel_pos_y);
		    children_dim_x.push_back(dim_x);
		    children_dim_y.push_back(dim_y);
		    children_callbacks.push_back(callback);
		}

		int CursorMenu::move_cursor_by(int add_x, int add_y){
		    return move_cursor_to(get_cursor_x()+add_x, get_cursor_y()+add_y);
		}

		int CursorMenu::move_cursor_to(int new_pos_x, int new_pos_y){
		    int index = get_index_from_coords(new_pos_x, new_pos_y);
		    if (children[index] == NULL){
			if (children_callbacks[index] == NULL){
			    return 2;
			}
			children_callbacks[index]();
			return 1;
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
		    return 0;
		}

		int CursorMenu::get_cursor_x(){
		    return cursor[0];
		}

		int CursorMenu::get_cursor_y(){
		    return cursor[1];
		}

		Widget* CursorMenu::get_item_at(int x, int y){
		    return children[get_index_from_coords(x, y)];
		}

		Widget* CursorMenu::get_item_at_cursor(){
		    get_item_at(cursor[0], cursor[1]);
		}

		void CursorMenu::activate(){
		    children_callbacks[get_index_from_coords(cursor[0], cursor[1])]();
		}

	    CursorMenu::~CursorMenu(){
		    // codegemma's proposal :
		// Clean up allocated memory for children and their callbacks
		for (auto& child : children) {
		    delete child;
		}
		children.clear();
		delete[] children_pos_x.data();
		delete[] children_pos_y.data();
		delete[] children_dim_x.data();
		delete[] children_dim_y.data();
	    }
};
