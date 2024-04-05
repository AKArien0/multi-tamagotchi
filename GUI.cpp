#include "GUI.hpp"

namespace GUI{

	MatriceMenu::MatriceMenu(dimension_x, dimension_y){
		bounds[0] = dimension_x;
		bounds[1] = dimension_y;
		cursor[0] = 0;
		cursor[1] = 0;
		background_anim_frame = 0;
		//malloc
	}
		private:
			void* functions[][];
			int frames_anims[][];
			int anims_matrice[][];
			int coordinates_anims[][][2];


	void MatriceMenu::set_background(animation &bg_anim){

	}

	void MatriceMenu::set_button(int position_x, int position_y, void &function, int sprite_pos_x, int sprite_pos_y, animation &idle_anim, animation &hover_anim){

	}

	void MatriceMenu::select(){
		functions[cursor[0]][cursor[1]]();
	}

	bool MatriceMenu::correct_cursor(){

	}

	void MatriceMenu::next_animation_frame(){

	}

	MatriceMenu::~MatriceMenu(){

	}



};
