#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "text.h"
#include <math.h>
#include <stdarg.h>

#define BOX_AMOUNT 12
#define PER_BOX 16

#define MAX_SLEEP 16*60*60
#define MAX_FOOD 5*60*60
#define MAX_LOVE 1000
#define MAX_MOOD 1000

#define NB_PERSONALITIES 5

int random_text_in(char *liste[]){
	srand(time(NULL));
	return rand()%sizeof(*liste)/sizeof(*liste[0]);
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
	t.pers_type = rand()%NB_PERSONALITIES;
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

void tama_advance_second(tama *t){
	srand(time(NULL));
	if (!t->sleeping){
		t->food -= 1;
	}
	else if (!t->age %4){
		t->food -= 1;
	}

	t->sleep -= 1;
	t->disease_time_elapsed += 1;
	t->drugs_time -= 1;
	t->age += 1;



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
	t->fragility -= 1;
}

char feed_tama(tama *t, int value){
	if (t->love > MAX_LOVE/2){
		t->food += value;
		if (t->food > MAX_FOOD){
			t->fragility += t->food - MAX_FOOD;
			t->food = MAX_FOOD;
			return random_text_in(text_feed[FEED_TOO_MUCH]);
		}

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

//~ string check(tama t){
	//~ if (){
		//~ return random_text_in(text_check_warnings[]);
	//~ }


	//~ return random_text_in(text_check[]);
//~ }

char inject(tama *t, int inj_id, int time){
	if (t->drugs > 300){
		return random_text_in(text_inject[INJECT_STOP]);
	}
	if (t->love < MAX_LOVE/1.7){
		if (!rand()%t->love/100){
			return random_text_in(text_inject[INJECT_FIGHT]);
		}
	}

	t->drugs = inj_id;
	t->drugs_time = time;

	if (t->love > MAX_LOVE/1.3){
		return random_text_in(text_inject[INJECT_BRAVE]);
	}

	return random_text_in(text_inject[INJECT_NORMAL_REACTION]);
}

