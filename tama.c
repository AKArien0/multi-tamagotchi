#include "tama.h"
#include "tama_text.h"

char *random_text_in(char *liste[]){
	srand(time(NULL));
	return liste[rand()%sizeof(*liste)/sizeof(*liste[0])];
}

typedef struct tama_struct{
	unsigned int food, love, mood, pers_type, sleep, sleeping, disease_type, disease_time_elapsed, drugs, drugs_time, form, past_food[8], past_love[8], past_sleep[8], past_disease[4][2], fragility;
	int64_t age;
} tama;

typedef struct box_struct{
	int light;
	tama tamas[PER_BOX];
	int64_t food_ready;
	int dirty;
} box;


tama init_tama(){
	srand(time(NULL));
	tama t;
	t.food = MAX_FOOD/4 + (rand()%MAX_FOOD/4);
	t.love = MAX_LOVE/4 + (rand()%MAX_LOVE/2);
	t.mood = MAX_MOOD/2 + (rand()%MAX_MOOD/4);
	t.pers_type = rand()%NB_PERSONALITIES + ((rand()%NB_PERSONALITIES)*10);
	t.sleep = MAX_SLEEP - (rand()%MAX_SLEEP/4);
	t.disease_type = 0;
	t.disease_time_elapsed = 0;
	t.drugs = 0;
	t.drugs_time = 0;
	t.age = rand()%1800; //jusqu'à 30min de décalage
	t.form = 0;
	for (int i = 0 ; i < 8 ; i++){
		t.past_food[i] = t.food;
		t.past_love[i] = t.love;
		t.past_sleep[i] = t.sleep;
		if (i%2){
			t.past_disease[i/2][0] = 0;
		}
		else{
			t.past_disease[i/2][1] = 0;
		}
	}
	t.fragility = 0;
	return t;
}

box init_box(){
  box b;
  b.light = 0;
  b.dirty = 0;
  b.food_ready = 0;
  for (int i = 0 ; i < PER_BOX ; i++){
    b.tamas[i] = init_tama();
  }
  return b;
}

void tama_advance_second(tama *t){
	srand(time(NULL));
	if (!t->sleeping){
		t->food--;
	}
	else{
		if (!t->age %4){
			t->food--;
		}
		t->sleep++;
	}

	t->sleep--;
	t->disease_time_elapsed++;
	t->drugs_time--;
	t->age++;

	if (!t->age%43200){
		for (int i = 1 ; i < 8 ; i++){
			t->past_food[i-1] = t->past_food[i];
			t->past_love[i-1] = t->past_love[i];
			t->past_sleep[i-1] = t->past_sleep[i];
		}
		t->past_food[8] = t->food;
		t->past_love[8] = t->love;
		t->past_sleep[8] = t->sleep;
	}
	t->fragility--;
}

char *feed(tama *t, int value){
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
	if (t->drugs > 300){
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


int past_value_score(tama *t, int c_value){

	return 0;
}


char *check(tama *t){
	srand(time(NULL));
	if (rand()%2){
    return text_check_warnings[0][0];
	}
	return text_check_warnings[0][1];
}
