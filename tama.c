#include "tama.h"
#include "tama_text.h"
;

char *random_text_in(char *liste[]){
	return liste[rand()%sizeof(*liste)/sizeof(*liste[0])];
}

void init_tama(tama* target){
	target->food = MAX_FOOD/4 + (rand()%MAX_FOOD/8);
	target->love = MAX_LOVE/4 + (rand()%MAX_LOVE/2);
	target->mood = MAX_MOOD/4 + (rand()%MAX_MOOD/2);
	target->pers_type = rand()%NB_PERSONALITIES + ((rand()%NB_PERSONALITIES)*10);
	target->sleep = MAX_SLEEP - (rand()%MAX_SLEEP/4);
	target->disease_type = 0;
	target->disease_time_left = 0;
	target->drugs = 0;
	target->drugs_time = 0;
	target->age = rand()%1800; //jusqu'à 30min de décalage
	target->form = 0;
	target->fragility = 0;
}

void init_box(box* target){
	target->light = 0;
	target->dirty = 0;
	target->food_ready = 0;
	for (int i = 0 ; i < TAMA_PER_BOX ; i++){
		init_tama(&(target->tamas[i]));
		//~ b.tamas[i].parent = &b;
	}
}

void tama_advance_second(tama *t){

	if (t->form == 0){
		return;
}

	if (t->disease_type == DISEASE_DEAD){
		t->next_check_override = random_text_in(text_dead);
		return;
	}

	if (t->fragility > FRAGILITY_DEATH_BORDER){
		t->disease_type = DISEASE_DEAD;
		return;
	}

	//general

	if (t->parent->light){
		if (t->food == 0){
			t->fragility++;
		}
		else{
			t->food--;
		}

		if (t->sleep == 0){
			t->fragility++;
		}
		else{
			t->sleep--;
		}
	}
	else{
		if (!t->age %4){
			if (t->food == 0){
				t->fragility++;
			}
			else{
				t->food--;
			}

			if (t->sleep == 0){
				t->fragility++;
			}
			else{
				t->sleep--;
			}
		}
	}

	if (t->drugs_time != 0){
		t->drugs_time--;
	}
	else{
		t->drugs = 0;
	}

	t->age++;

	// special / events


	switch (t->disease_type){

		case DISEASE_NORMAL:

			// fall sick
			// contagion reroll
			for (int i = 0 ; i < t->parent->dirty ; i++){ // unsanitary reroll
				if (!rand()%604800-(t->fragility)){ // best case scenario, 7 days
					t->disease_type = rand()%DISEASE_COUNT+1;
					t->disease_time_left = rand()%259200; //up to 3 days
					t->next_check_override = OVERRIDE_SICK;
				break;
				}
			}

		case DISEASE_1:

			if (!rand()%3600){
				t->parent->dirty++;
			}
	}

	if (!rand()%86400){
		t->parent->dirty++;
	}

	// fights
	if (!rand()%(43200+(t->mood*1000))){ // 12 hours to 15 days
		t->fragility += rand()%(int)(FRAGILITY_DEATH_BORDER*0.5);
		t->next_check_override = OVERRIDE_FOUGHT;
	}

	//check for mistreating

	int reduce_fragility_flag = 1;

	if (t->food <= 0){
		t->fragility++;
		reduce_fragility_flag = 0;
	}

	if (t->sleep <= 0){
		t->fragility++;
		reduce_fragility_flag = 0;
	}

	if (reduce_fragility_flag){
		if (t->fragility != 0){
			t->fragility--;
		}
	}

	// state adjusments

	if (t->disease_time_left == 0){ // return to non sick
		t->disease_type = DISEASE_NORMAL;
		t->disease_time_left = 0;
	}
	else{
		t->disease_time_left--;
	}

	if (t->age > 1800 && t->form == 0){
		t->form = 1;
		t->next_check_override = OVERRIDE_NEXT_STAGE;
	}

	if (t->age > 2*24*60*60 && t->form == 1){
		t->form = 2+rand()%2;
		t->next_check_override = OVERRIDE_NEXT_STAGE;
	}

	//~ if (!t->age%(2*24*60*60)){ // update form
		//~ switch (t->form){
			//~ case 0: // egg
				//~ t->form++;
				//~ break;

			//~ case 1: // baby
				//~ t->form += 1 + rand()%2;

			//~ case 2: // child type 1
				//~ t->form += 1 + rand()%3;

			//~ case 3: //child type 2
				//~ t->form += 4 + rand()%3;
		//~ }

	//~ }
}

void box_advance_second(box *b){
	for (int i = 0 ; i < TAMA_PER_BOX ; i++){
		tama_advance_second(&(b->tamas[i]));
		if (b->food_ready > 0){ // nested ifs. oops. cannot use feed() function, feeding has to be impersonnal
			if (b->tamas[i].food < MAX_FOOD*0.66){
				if (b->food_ready > MAX_FOOD*0.3){
					b->food_ready -= MAX_FOOD*0.3;
					b->tamas[i].food += MAX_FOOD*0.3;
				}
				else{
					b->tamas[i].food += b->food_ready;
					b->food_ready = 0;
				}
			}
		}
	}
}

char *feed(tama *t, int value){

	if (t->form == 0){
		return random_text_in(not_yet_hatched);
	}

	if (t->disease_type == DISEASE_DEAD){
		return CANCEL_BECAUSE_DEAD;
	}

	t->love += value * MAX_LOVE / MAX_FOOD / 5;

	if (t->love > MAX_LOVE/2){
		t->mood += value * MAX_MOOD / MAX_FOOD / 2;

		t->food += value;
		if (t->food > MAX_FOOD){
			t->fragility += t->food - MAX_FOOD;
			t->food = MAX_FOOD;
			t->mood = t->mood / 1.1;
			return random_text_in(text_feed[FEED_TOO_MUCH]);
		}

		t->mood += value * MAX_MOOD / MAX_FOOD / 2;

		if (t->food > MAX_FOOD/1.1){
			return random_text_in(text_feed[FEED_FULL]);
		}

		if (t->food > MAX_FOOD/1.3){
			return random_text_in(text_feed[FEED_STILL_L_HUNGRY]);
		}

		if (t->food > MAX_FOOD/1.7){
			return random_text_in(text_feed[FEED_STILL_HUNGRY]);
		}

		return random_text_in(text_feed[FEED_STILL_V_HUNGRY]);
	}
	else{
		if (!rand()%t->love/50){
			t->mood += value * MAX_MOOD / MAX_FOOD / 2;
			t->food += value;
			if (t->food > MAX_FOOD){
				t->fragility += (t->food - MAX_FOOD)/4;
				t->food = MAX_FOOD;
			}
			return random_text_in(text_feed[FEED_ALMOST_REFUSE]);
		}
		else{
			return random_text_in(text_feed[FEED_REFUSE]);
		}
	}
}

char *inject(tama *t, int inj_id, int time){

	if (t->form == 0){
		return random_text_in(not_yet_hatched);
	}

	if (t->drugs_time > 300){
		return random_text_in(text_inject[INJECT_STOP]);
	}
	if (t->love < MAX_LOVE/1.7){
		t->mood -= MAX_MOOD/5;
		if (!rand()%t->love/100){
			t->love -= MAX_LOVE/10;
			return random_text_in(text_inject[INJECT_FIGHT]);
		}
	}

	t->drugs = inj_id;
	t->drugs_time = time;

	if (t->love > MAX_LOVE/1.3){
		t->mood -= MAX_MOOD/10;
		return random_text_in(text_inject[INJECT_BRAVE]);
	}

	t->mood -= MAX_MOOD/7;
	t->love -= MAX_LOVE/10;
	return random_text_in(text_inject[INJECT_NORMAL_REACTION]);
}

char *check(tama *t){

	if (t->form == 0){
		return random_text_in(not_yet_hatched);
	}

	if (t->disease_type == DISEASE_DEAD){
		return CANCEL_BECAUSE_DEAD;
	}

	if (t->next_check_override == ""){
		char* value = t->next_check_override;
		t->next_check_override = "";
		return value;
	}

	if (t->disease_type == DISEASE_DEAD){
		return random_text_in(text_dead);
	}


	if (rand()%3){
		switch (rand()%5){
			case CHECK_FOOD:
				return text_check_warnings[CHECK_FOOD][(int)(((float)t->food/(MAX_FOOD+t->food))*CHECK_WARNINGS_TEXT_LEVELS)];

			case CHECK_SLEEP:
				return text_check_warnings[CHECK_SLEEP][(int)(((float)t->sleep/(MAX_SLEEP+t->sleep))*CHECK_WARNINGS_TEXT_LEVELS)];

			case CHECK_DISEASE:
				if (t->disease_type == 0){
					return text_check_warnings[CHECK_DISEASE][0];
				}
				else{
					return text_check_warnings[CHECK_DISEASE][1];
				}

			case CHECK_DRUGS:
				if (t->drugs_time == 0){
					return text_check_warnings[CHECK_DRUGS][0];
				}
				else{
					return text_check_warnings[CHECK_DRUGS][1];
				}

			case CHECK_FRAGILITY:
				return text_check_warnings[CHECK_FRAGILITY][(int)(((float)t->fragility/(FRAGILITY_DEATH_BORDER+t->fragility))*CHECK_WARNINGS_TEXT_LEVELS)];
		}

	}

	int refusal_score = (t->love*0.75)+(t->mood*0.25);
	if (refusal_score < MAX_LOVE+MAX_MOOD/4){
		if (!rand()%(refusal_score%100)){
			return random_text_in(text_fun_refusal);
		}
	}

	t->mood += MAX_MOOD/10;
	t->love += MAX_LOVE/40;
	return random_text_in(text_fun);
}

char *clean(box *b){
	b->dirty -= 3;
	if (b->dirty <= 0){
		return CLEAN_ALREADY;
		b->dirty = 0;
	}
	return CLEAN_BETTER;
}

char *switch_light(box *b){
	if (b->light){
		b->light = 0;
		return LIGHT_OFF;
	}
	else{
		b->light = 1;
		return LIGHT_ON;
	}
}

char *distribute_meds(box *b, int inj_id, int time){

}

char *check_box(box *b){

}

char *switch_light_from_tama(tama *t){
	return switch_light(t->parent);
}

char *clean_tama(tama *t){

	if (t->form == 0){
		return random_text_in(not_yet_hatched);
	}


}
