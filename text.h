#define URGENT_FOOD 0
#define URGENT_SLEEP 1
#define URGENT_DISEASE 2

char * text_check_warnings_urgent[3][2] = {
	{
		"Il faut qu'il mange.",
		"Il faut le nourrir."
	}

	{
		"Il tombe de fatigue.",
		"Il a besoin de repos."
	}

	{
		"Il faut traiter sa maladie immédiatement.",
		"Il est terriblement malade."
	}
};

#define WARNING_FOOD 0
#define WARNING_MOOD 1
#define WARNING_LOVE 2
#define WARNING_SLEEP 3
#define WARNING_DISEASE 4
#define WARNING_DRUGS 5
#define WARNING_PAST_FOOD 6
#define WARNING_PAST_LOVE 7
#define WARNING_PAST_SLEEP 8
#define WARNING_PAST_DISEASE 9
#define WARNING_FRAGILITY 10

char * text_check_warnings[][] = {

}

char * text_check_flavour[][] = {

};

#define INJECT_STOP 0
#define INJECT_NORMAL_REACTION 1
#define INJECT_BRAVE 2
#define INJECT_FIGHT 3

char * text_inject[4][3] = {
	{
		"Ce n'est pas raisonnable."
	},

	{
		"Il gémit de douleur.",
		"Il ne réagit pas.",
		"Il accepte sans broncher."
	},

	{
		"Il grimace mais mais reste calme.",
		"Il tient bon pour vous."
	},

	{
		"Il se débat trop pour injecter."
	}
};

#define FEED_FULL 0
#define FEED_TOO_MUCH 1
#define FEED_STILL_V_HUNGRY 2
#define FEED_STILL_L_HUNGRY 3
#define FEED_STILL_HUNGRY 4
#define FEED_REFUSE 5
#define FEED_ALMOST_REFUSE 6

char * text_feed[7][3] = {
	{
		"Il n'a plus faim."

	},

	{
		"Il a trop mangé, il a l'air pataud..."

	},

	{
		"Il est encore affamé."

	},

	{
		"Il a l'air satisfait, mais vous lorgne encore..."

	},

	{
		"Il a encore faim."
	},

	{
		"Il refuse de s'approcher... il n'a pas l'air de vous faire confiance.",
		"Il n'ose pas s'approcher assez près pour manger.",

	},

	{
		"Il s'approche avec méfiance, mais mange quand même.",
		"Il mange en vous surveillant du coin de l'œuil."
	}

};
