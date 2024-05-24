#define FEED_FULL 0
#define FEED_TOO_MUCH 1
#define FEED_STILL_V_HUNGRY 2
#define FEED_STILL_L_HUNGRY 3
#define FEED_STILL_HUNGRY 4
#define FEED_REFUSE 5
#define FEED_ALMOST_REFUSE 6

char * text_feed[7][2] =
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

char * text_inject[4][3] =
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

char * text_check_warnings[7][3] = // value, value %
{
	{
		"Il vraiment faim",
		"Il a un peu faim",
		"En pleine digestion !"
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

char * text_fun_refusal[] =
{
	"Il rechigne.",
	"Vous lui faites peur",
	"Il hésite",
};

char * text_fun[] =
{
	"Vous le peignez affectueusement.",
	"Vous le décoiffez affectueusement.",
	"Il sautille entre vos mains.",
	"Il court tout autour de vous."	,
	"Il regarde quelque-chose au loin.",
	"Il rêvasse",
    "Vous le bercez",
    "Vous le câlinez.",
    "Il vous regarde intensément.",
    "Il se laisse aller et tourne en rond.",
    "Il faufile entre vos jambes.",
    "Il vous fait une petite grimace.",
    "Il se dresse sur ses pattes arrières.",
    "Il vous donnera un petit coup de langue.",
    "Il s'accroche à votre épaule."
};

char * text_dead[] =
{
	"Il est mort",
	"Le corps est froid",
	"Il faut nettoyer ça"
}

#define CANCEL_BECAUSE_DEAD text_dead[0]
#define CLEAN_ALREADY "C'est propre."
#define CLEAN_BETTER "C'est déjà mieux comme ça."
#define LIGHT_OFF "Au lit !"
#define LIGHT_ON "Debout !"

#define OVERRIDE_SICK "Il est tombé malade..."
#define OVERRIDE_FOUGHT "Ces blessures... il s'est battu."
#define OVERRIDE_NEXT_STAGE "Il a grandi !"
