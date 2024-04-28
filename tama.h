#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <time.h>

#define TAMA_BOXES_AMOUNT 6
#define TAMA_PER_BOX 16

#define MAX_SLEEP 16*60*60
#define MAX_FOOD 5*60*60
#define MAX_LOVE 1000
#define MAX_MOOD 1000

#define NB_PERSONALITIES 4


typedef struct tama_struct{
	unsigned int food, love, mood, pers_type, sleep, sleeping, disease_type, disease_time_elapsed, drugs, drugs_time, form, past_food[8], past_love[8], past_sleep[8], past_disease[4][2], fragility;
	int64_t age;
} tama;

typedef struct box_struct{
	int light;
	tama tamas[TAMA_PER_BOX];
	int64_t food_ready;
	int dirty;
} box;

char *random_text_in(char *liste[]);

int past_value_score(tama *t, int c_value);

tama init_tama();

box init_box();

void tama_advance_second(tama *t);

char *feed(tama *t, int value);

char *inject(tama *t, int inj_id, int time);

char *clean(tama *t);

char *check(tama *t);

#ifdef __cplusplus
}
#endif
