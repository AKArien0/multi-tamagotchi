#include <stdlib.h>
#include <time.h>
#include "tama_text.h"

#define BOX_AMOUNT 12
#define PER_BOX 16

#define MAX_SLEEP 16*60*60
#define MAX_FOOD 5*60*60
#define MAX_LOVE 1000
#define MAX_MOOD 1000

#define NB_PERSONALITIES 4

char *random_text_in(char *liste[]);

typedef struct tama_struct tama;

typedef struct box_struct box;

int past_value_score(tama *t, int c_value);

tama init_tama();

box init_box();

void tama_advance_second(tama *t);

char *feed(tama *t, int value);

char *inject(tama *t, int inj_id, int time);

char *check(tama *t);
