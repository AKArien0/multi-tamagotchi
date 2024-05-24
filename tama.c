#include "tama.h"
#include "tama_text.h"
;
char *random_text_in(char *liste[]){
	srand(time(NULL));
	return liste[rand()%sizeof(*liste)/sizeof(*liste[0])];
}

tama init_tama(){
	srand(time(NULL));
	tama t;
	t.food = MAX_FOOD/4 + (rand()%MAX_FOOD/4);
	t.love = MAX_LOVE/4 + (rand()%MAX_LOVE/2);
	t.mood = MAX_MOOD/2 + (rand()%MAX_MOOD/4);
	t.pers_type = rand()%NB_PERSONALITIES + ((rand()%NB_PERSONALITIES)*10);
	t.sleep = MAX_SLEEP - (rand()%MAX_SLEEP/4);
	t.disease_type = 0;
	t.disease_time_left = 0;
	t.drugs = 0;
	t.drugs_time = 0;
	t.age = rand()%1800; //jusqu'à 30min de décalage
	t.form = 0;
	t.fragility = 0;
	return t;
}

box init_box(){
  box b;
  b.light = 0;
  b.dirty = 0;
  b.food_ready = 0;
  for (int i = 0 ; i < TAMA_PER_BOX ; i++){
    b.tamas[i] = init_tama();
    b.tamas[i].parent = &b;
  }
  return b;
}

void tama_advance_second(tama *t){

	if (t->fragility > FRAGILITY_DEATH_BORDER){
		t->disease_type = DISEASE_DEAD;
		t->next_check_override = random_text_in(text_dead);
		return;
	}

	//general

	if (t->parent->light){
		t->food--;
		t->sleep--;
	}
	else{
		if (!t->age %4){
			t->food--;
		}
		t->sleep++;
	}

	if (t->sleep <= 0){
		t->fragility++;
	}

	t->disease_time_left--;
	t->drugs_time--;
	t->age++;

	// special / events

	srand(time(NULL));

	switch (t->disease_type){

		case DISEASE_DEAD:

			return;

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
	if (!rand()%43200+(t->mood*1000)){ // 12 hours to 15 days
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
		t->fragility--;
	}

	// state adjusments

	if (t->disease_time_left <= 0){ // return to non sick
		t->disease_type = DISEASE_NORMAL;
		t->disease_time_left = 0;
	}

	if (!t->age%(2*24*60*60)){ // update form
		t->next_check_override = OVERRIDE_NEXT_STAGE;
		switch (t->form){
			case 0: // egg
				t->form++;
				break;

			case 1: // baby
				t->form += 1 + rand()%2;

			case 2: // child type 1
				t->form += 1 + rand()%3;

			case 3: //child type 2
				t->form += 4 + rand()%3;
		}

	}

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
				t->fragility += t->food - MAX_FOOD;
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

	srand(time(NULL));
	if (!rand()%2){
	    // hard checks
	}
	// ai
}

char *fun(tama *t){

	if (t->disease_type == DISEASE_DEAD){
		return CANCEL_BECAUSE_DEAD;
	}

	srand(time(NULL));
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
