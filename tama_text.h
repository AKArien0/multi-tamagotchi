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
		"Il a trop mange, il a l'air pataud...",
		"Il a l'air de regretter d'avoir tant mange..."
	},

	{
		"Il est encore affame.",
		"Il a encore besoin de beaucoup manger."
	},

	{
		"Il remangerait encore bien quelque chose.",
		"Il a toujours un petit creux"
	},

	{
		"Il a encore faim.",
		"Il a toujours un petit creux"
	},

	{
		"Il refuse de s'approcher...",
		"Il n'ose pas s'approcher assez pres."
	},

	{
		"Il s'approche avec mefiance, mais mange quand même.",
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
		"Il vaut mieux eviter.",
		"Ce serait dangereux."
	},

	{
		"Il gemit de douleur.",
		"Il ne reagit pas.",
		"Coming soon"
	},

	{
		"Il grimace mais reste calme.",
		"Il tient bon pour vous.",
		"Il grimace mais reste calme"
	},

	{
		"Il se debat trop pour injecter.",
		"Il vous echappe",
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
		"Il cherche a manger",
		"Il a un petit creux",
		"En pleine digestion !"

	},

	{
		"Il a sommeil",
		"La fatigue commence a se faire sentir",
		"Il est en forme !",
		"Il semble avoir de l'energie pour des jours !"
	},

	{
		"Il n'est pas malade",
		"Il est malade",
		"check disease 2",
		"check disease 3"
	},

	{
		"",
		"Les medicaments font toujours effet",
		"check drugs 2",
		"check drugs 3"
	},

	{
		"Il est en bonne sante",
		"Il a l'air un peu faible",
		"ca n'a pas l'air d'aller...",
		"Il est en piteux etat"
	},
};

char * text_fun_refusal[] =
{
	"Il rechigne.",
	"Vous lui faites peur",
	"Il hesite",
};

char * text_fun[] =
{
	"Vous le peignez affectueusement.",
	"Vous le decoiffez affectueusement.",
	"Il petrit le sol de ses pattes.",
	"Il court tout autour de vous."	,
	"Il regarde quelque-chose au loin.",
	"Il rêvasse",
    "Vous le bercez",
    "Vous le câlinez.",
    "Il vous regarde intensement.",
    "Il se laisse aller et tourne en rond.",
    "Il faufile entre vos jambes.",
    "Il vous fait une petite grimace.",
    "Il se dresse sur ses pattes arrieres.",
    "Il vous donne un petit coup de langue.",
    "Il s'accroche a votre epaule."
};

char * text_dead[] =
{
	"Il est mort",
	"Le corps est froid",
	"Il faut nettoyer ca"
};

//~ #define CANCEL_BECAUSE_DEAD text_dead[0]
#define CANCEL_BECAUSE_DEAD random_text_in(text_dead)
#define CLEAN_ALREADY "C'est propre."
#define CLEAN_BETTER "C'est deja mieux comme ca."
#define LIGHT_OFF "Au lit !"
#define LIGHT_ON "Debout !"

#define OVERRIDE_SICK "Il est tombe malade..."
#define OVERRIDE_FOUGHT "Ces blessures... il s'est battu."
#define OVERRIDE_NEXT_STAGE "Il a grandi !"

char * not_yet_hatched[] =
{
	"L'eclosion ne devrait plus tarder !",
	"Quand eclora-t-il ?",
	"Il n'est encore qu'un oeuf"
};

#define MEDS_DISTRIBUTED "Des medicaments pour tout le monde !"
