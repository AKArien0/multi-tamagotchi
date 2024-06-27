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
		"Il a l'air de regretter d'avoir tant mangé..."
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
		"Il refuse de s'approcher....",
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
		"Il grimace mais reste calme.",
		"Il tient bon pour vous.",
		"Il grimace mais reste calme"
	},

	{
		"Il se débat trop pour injecter.",
		"Il vous échappe",
		"Il vous fuit"
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
#define CHECK_FRAGILITY 4

#define CHECK_WARNINGS_TEXT_LEVELS 4
char * text_check_warnings[5][CHECK_WARNINGS_TEXT_LEVELS] = // value, value %
{
	{
		"Il a vraiment faim",
		"Il cherche à manger",
		"Il a un petit creux",
		"En pleine digestion !"

	},

	{
		"Il a sommeil",
		"La fatigue du jour commence à se faire sentir",
		"Il est en forme !",
		"Il semble avoir de l'énergie pour des jours !"
	},

	{
		"check disease 0",
		"check disease 1",
		"check disease 2",
		"check disease 3"
	},

	{
		"check drugs 0",
		"check drugs 1",
		"check drugs 2",
		"check drugs 3"
	},

	{
		"check fragility 0",
		"check fragility 1",
		"check fragility 2",
		"check fragility 3"
	},
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
	"Il pétrit le sol de ses pattes.",
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
    "Il vous donne un petit coup de langue.",
    "Il s'accroche à votre épaule."
};

char * text_dead[] =
{
	"Il est mort",
	"Le corps est froid",
	"Il faut nettoyer ça"
}

//~ #define CANCEL_BECAUSE_DEAD text_dead[0]
#define CANCEL_BECAUSE_DEAD random_text_in(text_dead)
#define CLEAN_ALREADY "C'est propre."
#define CLEAN_BETTER "C'est déjà mieux comme ça."
#define LIGHT_OFF "Au lit !"
#define LIGHT_ON "Debout !"

#define OVERRIDE_SICK "Il est tombé malade..."
#define OVERRIDE_FOUGHT "Ces blessures... il s'est battu."
#define OVERRIDE_NEXT_STAGE "Il a grandi !"
