#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <time.h>

#define TAMA_BOXES_AMOUNT 6
#define TAMA_PER_BOX 16

#define MAX_SLEEP 12*60*60
#define MAX_FOOD 5*60*60
#define MAX_LOVE 1000
#define MAX_MOOD 1000

#define FRAGILITY_DEATH_BORDER 30000

#define DISEASE_NORMAL 0
#define DISEASE_DEAD -1
#define DISEASE_COUNT 1
#define DISEASE_1 1
#define DISEASE_2 2
#define DISEASE_3 3

#define NB_PERSONALITIES 4

typedef struct box_struct box;

typedef struct tama_struct{
	unsigned int food, love, mood, pers_type, sleep, disease_type, disease_time_left, drugs, drugs_time, form, fragility;
	int64_t age;
	struct box_struct* parent;
	char* next_check_override;
} tama;

typedef struct box_struct{
	int light;
	tama tamas[TAMA_PER_BOX];
	int64_t food_ready;
	int dirty;
} box;

char *random_text_in(char *liste[]);

tama init_tama();

box init_box();


void box_advance_second(box *b);

char *leave_food(box *b, int value);

char *check_box(box *b);

char *distribute_meds(box *b, int inj_id, int time);

char *switch_light(box *b);

char *clean_box(box *b);


void tama_advance_second(tama *t);

char *feed(tama *t, int value);

char *check(tama *t);

char *inject(tama *t, int inj_id, int time);

char *switch_light_from_tama(tama *t);

char *clean_tama(tama *t);

#ifdef __cplusplus
}
#endif
