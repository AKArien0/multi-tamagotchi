#define FEED_FULL 0
#define FEED_TOO_MUCH 1
#define FEED_STILL_V_HUNGRY 2
#define FEED_STILL_L_HUNGRY 3
#define FEED_STILL_HUNGRY 4
#define FEED_REFUSE 5
#define FEED_ALMOST_REFUSE 6

const char * text_feed[7][2] =
{
	{
		"Il n'a plus faim.",
		"Il est repus."
	},

	{
		"Il a trop mangé, il a l'air pataud...",
		"Il a l'air de regretter sa gourmandise..."
	},

	{
		"Il est encore affamé.",
		"Il a encore besoin de beaucoup manger."
	},

	{
		"Il remangerait encore bien quelque chose.",
		"Coming soon"
	},

	{
		"Il a encore faim.",
		"Coming soon"
	},

	{
		"Il refuse de s'approcher... il n'a pas l'air de vous faire confiance.",
		"Il n'ose pas s'approcher assez près pour manger."
	},

	{
		"Il s'approche avec méfiance, mais mange quand même.",
		"Il mange en vous surveillant du coin de l'œuil."
	}

};

#define INJECT_STOP 0
#define INJECT_NORMAL_REACTION 1
#define INJECT_BRAVE 2
#define INJECT_FIGHT 3

const char * text_inject[4][3] =
{
	{
		"Ce n'est pas raisonnable.",
		"Il vaut mieux éviter.",
		"Ce serait dangereux."
	},

	{
		"Il gémit de douleur.",
		"Il ne réagit pas.",
		"Coming soon"
	},

	{
		"Il grimace mais mais reste calme.",
		"Il tient bon pour vous.",
		"Coming soon"
	},

	{
		"Il se débat trop pour injecter.",
		"Coming soon",
		"Coming soon"
	}
};

#define PRS_GENERAL 0 // can show up for all
#define PRS_UPBEAT 1
#define PRS_CLINGY 2
#define PRS_CALM 3
#define PRS_IMPULSIVE 4

#define CHECK_FOOD 0
#define CHECK_SLEEP 1
#define CHECK_DISEASE 2
#define CHECK_DRUGS 3
#define CHECK_PAST_FOOD 4
#define CHECK_PAST_LOVE 5
#define CHECK_PAST_SLEEP 6

const char * text_check_warnings[7][3] = // value, value %
{
	{
		"warning food 0",
		"warning food 1",
		"warning food 2"
	},

	{
		"check sleep 0",
		"check sleep 1",
		"check sleep 2"
	},

	{
		"check disease 0",
		"check disease 1",
		"check disease 2"
	},

	{
		"check drugs 0",
		"check drugs 1",
		"check drugs 2"
	},

	{
		"check past_food 0",
		"check past_food 1",
		"check past_food 2"
	},

	{
		"check past_love 0",
		"check past_love 1",
		"check past_love 2"
	},

	{
		"check past_sleep 0",
		"check past_sleep 1",
		"check past_sleep 2"
	}
};
