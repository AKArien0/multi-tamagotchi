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
#define CHECK_PAST_DISEASE 7

char * text_check[5][8][8] =
{
	{// general
		{ // food
			"general food 0",
			"general food 1",
			"general food 2",
			"general food 3",
			"general food 4",
			"general food 5",
			"general food 6",
			"general food 7"
		},

		{ // sleep
			"general sleep 0",
			"general sleep 1",
			"general sleep 2",
			"general sleep 3",
			"general sleep 4",
			"general sleep 5",
			"general sleep 6",
			"general sleep 7"
		},

		{ // disease
			"general disease 0",
			"general disease 1",
			"general disease 2",
			"general disease 3",
			"general disease 4",
			"general disease 5",
			"general disease 6",
			"general disease 7"
		},

		{ // drugs
			"general drugs 0",
			"general drugs 1",
			"general drugs 2",
			"general drugs 3",
			"general drugs 4",
			"general drugs 5",
			"general drugs 6",
			"general drugs 7"
		},

		{ // past food
			"general past_food 0",
			"general past_food 1",
			"general past_food 2",
			"general past_food 3",
			"general past_food 4",
			"general past_food 5",
			"general past_food 6",
			"general past_food 7"
		},

		{ // past love
			"general past_love 0",
			"general past_love 1",
			"general past_love 2",
			"general past_love 3",
			"general past_love 4",
			"general past_love 5",
			"general past_love 6",
			"general past_love 7"
		},

		{ // past sleep
			"general past_sleep 0",
			"general past_sleep 1",
			"general past_sleep 2",
			"general past_sleep 3",
			"general past_sleep 4",
			"general past_sleep 5",
			"general past_sleep 6",
			"general past_sleep 7"
		},

		{ //
			"general past_disease 0",
			"general past_disease 1",
			"general past_disease 2",
			"general past_disease 3",
			"general past_disease 4",
			"general past_disease 5",
			"general past_disease 6",
			"general past_disease 7"
		}
	}
	,

	{ // upbeat
		{
			"upbeat food 0",
			"upbeat food 1",
			"upbeat food 2",
			"upbeat food 3",
			"upbeat food 4",
			"upbeat food 5",
			"upbeat food 6",
			"upbeat food 7"
		},

		{
			"upbeat sleep 0",
			"upbeat sleep 1",
			"upbeat sleep 2",
			"upbeat sleep 3",
			"upbeat sleep 4",
			"upbeat sleep 5",
			"upbeat sleep 6",
			"upbeat sleep 7"
		},

		{
			"upbeat disease 0",
			"upbeat disease 1",
			"upbeat disease 2",
			"upbeat disease 3",
			"upbeat disease 4",
			"upbeat disease 5",
			"upbeat disease 6",
			"upbeat disease 7"
		},

		{
			"upbeat drugs 0",
			"upbeat drugs 1",
			"upbeat drugs 2",
			"upbeat drugs 3",
			"upbeat drugs 4",
			"upbeat drugs 5",
			"upbeat drugs 6",
			"upbeat drugs 7"
		},

		{
			"upbeat past_food 0",
			"upbeat past_food 1",
			"upbeat past_food 2",
			"upbeat past_food 3",
			"upbeat past_food 4",
			"upbeat past_food 5",
			"upbeat past_food 6",
			"upbeat past_food 7"
		},

		{
			"upbeat past_love 0",
			"upbeat past_love 1",
			"upbeat past_love 2",
			"upbeat past_love 3",
			"upbeat past_love 4",
			"upbeat past_love 5",
			"upbeat past_love 6",
			"upbeat past_love 7"
		},

		{
			"upbeat past_sleep 0",
			"upbeat past_sleep 1",
			"upbeat past_sleep 2",
			"upbeat past_sleep 3",
			"upbeat past_sleep 4",
			"upbeat past_sleep 5",
			"upbeat past_sleep 6",
			"upbeat past_sleep 7"
		},

		{
			"upbeat past_disease 0",
			"upbeat past_disease 1",
			"upbeat past_disease 2",
			"upbeat past_disease 3",
			"upbeat past_disease 4",
			"upbeat past_disease 5",
			"upbeat past_disease 6",
			"upbeat past_disease 7"
		}
	}
	,

	{ // clingy
		{
			"clingy food 0",
			"clingy food 1",
			"clingy food 2",
			"clingy food 3",
			"clingy food 4",
			"clingy food 5",
			"clingy food 6",
			"clingy food 7"
		},

		{
			"clingy sleep 0",
			"clingy sleep 1",
			"clingy sleep 2",
			"clingy sleep 3",
			"clingy sleep 4",
			"clingy sleep 5",
			"clingy sleep 6",
			"clingy sleep 7"
		},

		{
			"clingy disease 0",
			"clingy disease 1",
			"clingy disease 2",
			"clingy disease 3",
			"clingy disease 4",
			"clingy disease 5",
			"clingy disease 6",
			"clingy disease 7"
		},

		{
			"clingy drugs 0",
			"clingy drugs 1",
			"clingy drugs 2",
			"clingy drugs 3",
			"clingy drugs 4",
			"clingy drugs 5",
			"clingy drugs 6",
			"clingy drugs 7"
		},

		{
			"clingy past_food 0",
			"clingy past_food 1",
			"clingy past_food 2",
			"clingy past_food 3",
			"clingy past_food 4",
			"clingy past_food 5",
			"clingy past_food 6",
			"clingy past_food 7"
		},

		{
			"clingy past_love 0",
			"clingy past_love 1",
			"clingy past_love 2",
			"clingy past_love 3",
			"clingy past_love 4",
			"clingy past_love 5",
			"clingy past_love 6",
			"clingy past_love 7"
		},

		{
			"clingy past_sleep 0",
			"clingy past_sleep 1",
			"clingy past_sleep 2",
			"clingy past_sleep 3",
			"clingy past_sleep 4",
			"clingy past_sleep 5",
			"clingy past_sleep 6",
			"clingy past_sleep 7"
		},

		{
			"clingy past_disease 0",
			"clingy past_disease 1",
			"clingy past_disease 2",
			"clingy past_disease 3",
			"clingy past_disease 4",
			"clingy past_disease 5",
			"clingy past_disease 6",
			"clingy past_disease 7"
		}
	}
	,

	{ // calm
		{
			"calm food 0",
			"calm food 1",
			"calm food 2",
			"calm food 3",
			"calm food 4",
			"calm food 5",
			"calm food 6",
			"calm food 7"
		},

		{
			"calm sleep 0",
			"calm sleep 1",
			"calm sleep 2",
			"calm sleep 3",
			"calm sleep 4",
			"calm sleep 5",
			"calm sleep 6",
			"calm sleep 7"
		},

		{
			"calm disease 0",
			"calm disease 1",
			"calm disease 2",
			"calm disease 3",
			"calm disease 4",
			"calm disease 5",
			"calm disease 6",
			"calm disease 7"
		},

		{
			"calm drugs 0",
			"calm drugs 1",
			"calm drugs 2",
			"calm drugs 3",
			"calm drugs 4",
			"calm drugs 5",
			"calm drugs 6",
			"calm drugs 7"
		},

		{
			"calm past_food 0",
			"calm past_food 1",
			"calm past_food 2",
			"calm past_food 3",
			"calm past_food 4",
			"calm past_food 5",
			"calm past_food 6",
			"calm past_food 7"
		},

		{
			"calm past_love 0",
			"calm past_love 1",
			"calm past_love 2",
			"calm past_love 3",
			"calm past_love 4",
			"calm past_love 5",
			"calm past_love 6",
			"calm past_love 7"
		},

		{
			"calm past_sleep 0",
			"calm past_sleep 1",
			"calm past_sleep 2",
			"calm past_sleep 3",
			"calm past_sleep 4",
			"calm past_sleep 5",
			"calm past_sleep 6",
			"calm past_sleep 7"
		},

		{
			"calm past_disease 0",
			"calm past_disease 1",
			"calm past_disease 2",
			"calm past_disease 3",
			"calm past_disease 4",
			"calm past_disease 5",
			"calm past_disease 6",
			"calm past_disease 7"
		}
	}
	,

	{ // impulsive
		{
			"impulsive food 0",
			"impulsive food 1",
			"impulsive food 2",
			"impulsive food 3",
			"impulsive food 4",
			"impulsive food 5",
			"impulsive food 6",
			"impulsive food 7"
		},

		{
			"impulsive sleep 0",
			"impulsive sleep 1",
			"impulsive sleep 2",
			"impulsive sleep 3",
			"impulsive sleep 4",
			"impulsive sleep 5",
			"impulsive sleep 6",
			"impulsive sleep 7"
		},

		{
			"impulsive disease 0",
			"impulsive disease 1",
			"impulsive disease 2",
			"impulsive disease 3",
			"impulsive disease 4",
			"impulsive disease 5",
			"impulsive disease 6",
			"impulsive disease 7"
		},

		{
			"impulsive drugs 0",
			"impulsive drugs 1",
			"impulsive drugs 2",
			"impulsive drugs 3",
			"impulsive drugs 4",
			"impulsive drugs 5",
			"impulsive drugs 6",
			"impulsive drugs 7"
		},

		{
			"impulsive past_food 0",
			"impulsive past_food 1",
			"impulsive past_food 2",
			"impulsive past_food 3",
			"impulsive past_food 4",
			"impulsive past_food 5",
			"impulsive past_food 6",
			"impulsive past_food 7"
		},

		{
			"impulsive past_love 0",
			"impulsive past_love 1",
			"impulsive past_love 2",
			"impulsive past_love 3",
			"impulsive past_love 4",
			"impulsive past_love 5",
			"impulsive past_love 6",
			"impulsive past_love 7"
		},

		{
			"impulsive past_sleep 0",
			"impulsive past_sleep 1",
			"impulsive past_sleep 2",
			"impulsive past_sleep 3",
			"impulsive past_sleep 4",
			"impulsive past_sleep 5",
			"impulsive past_sleep 6",
			"impulsive past_sleep 7"
		},

		{
			"impulsive past_disease 0",
			"impulsive past_disease 1",
			"impulsive past_disease 2",
			"impulsive past_disease 3",
			"impulsive past_disease 4",
			"impulsive past_disease 5",
			"impulsive past_disease 6",
			"impulsive past_disease 7"
		}
	}
};

char * text_check_fun[5][2][8][3] =
{
	{
		{
			{
				"general love 0 1",
				"general love 0 2",
				"general love 0 3"
			},

			{
				"general love 1 1",
				"general love 1 2",
				"general love 1 3"
			},

			{
				"general love 2 1",
				"general love 2 2",
				"general love 2 3"
			},

			{
				"general love 3 1",
				"general love 3 2",
				"general love 3 3"
			},

			{
				"general love 4 1",
				"general love 4 2",
				"general love 4 3"
			},

			{
				"general love 5 1",
				"general love 5 2",
				"general love 5 3"
			},

			{
				"general love 6 1",
				"general love 6 2",
				"general love 6 3"
			},

			{
				"general love 7 1",
				"general love 7 2",
				"general love 7 3"
			}
		}
		,
		{
			{
				"general mood 0 1",
				"general mood 0 2",
				"general mood 0 3"
			},

			{
				"general mood 1 1",
				"general mood 1 2",
				"general mood 1 3"
			},

			{
				"general mood 2 1",
				"general mood 2 2",
				"general mood 2 3"
			},

			{
				"general mood 3 1",
				"general mood 3 2",
				"general mood 3 3"
			},

			{
				"general mood 4 1",
				"general mood 4 2",
				"general mood 4 3"
			},

			{
				"general mood 5 1",
				"general mood 5 2",
				"general mood 5 3"
			},

			{
				"general mood 6 1",
				"general mood 6 2",
				"general mood 6 3"
			},

			{
				"general mood 7 1",
				"general mood 7 2",
				"general mood 7 3"
			}
		}
	}
	,

	{
		{
			{
				"upbeat love 0 1",
				"upbeat love 0 2",
				"upbeat love 0 3"
			},

			{
				"upbeat love 1 1",
				"upbeat love 1 2",
				"upbeat love 1 3"
			},

			{
				"upbeat love 2 1",
				"upbeat love 2 2",
				"upbeat love 2 3"
			},

			{
				"upbeat love 3 1",
				"upbeat love 3 2",
				"upbeat love 3 3"
			},

			{
				"upbeat love 4 1",
				"upbeat love 4 2",
				"upbeat love 4 3"
			},

			{
				"upbeat love 5 1",
				"upbeat love 5 2",
				"upbeat love 5 3"
			},

			{
				"upbeat love 6 1",
				"upbeat love 6 2",
				"upbeat love 6 3"
			},

			{
				"upbeat love 7 1",
				"upbeat love 7 2",
				"upbeat love 7 3"
			}
		}
		,
		{
			{
				"upbeat mood 0 1",
				"upbeat mood 0 2",
				"upbeat mood 0 3"
			},

			{
				"upbeat mood 1 1",
				"upbeat mood 1 2",
				"upbeat mood 1 3"
			},

			{
				"upbeat mood 2 1",
				"upbeat mood 2 2",
				"upbeat mood 2 3"
			},

			{
				"upbeat mood 3 1",
				"upbeat mood 3 2",
				"upbeat mood 3 3"
			},

			{
				"upbeat mood 4 1",
				"upbeat mood 4 2",
				"upbeat mood 4 3"
			},

			{
				"upbeat mood 5 1",
				"upbeat mood 5 2",
				"upbeat mood 5 3"
			},

			{
				"upbeat mood 6 1",
				"upbeat mood 6 2",
				"upbeat mood 6 3"
			},

			{
				"upbeat mood 7 1",
				"upbeat mood 7 2",
				"upbeat mood 7 3"
			}
		}
	}
	,

	{
		{
			{
				"clingy love 0 1",
				"clingy love 0 2",
				"clingy love 0 3"
			},

			{
				"clingy love 1 1",
				"clingy love 1 2",
				"clingy love 1 3"
			},

			{
				"clingy love 2 1",
				"clingy love 2 2",
				"clingy love 2 3"
			},

			{
				"clingy love 3 1",
				"clingy love 3 2",
				"clingy love 3 3"
			},

			{
				"clingy love 4 1",
				"clingy love 4 2",
				"clingy love 4 3"
			},

			{
				"clingy love 5 1",
				"clingy love 5 2",
				"clingy love 5 3"
			},

			{
				"clingy love 6 1",
				"clingy love 6 2",
				"clingy love 6 3"
			},

			{
				"clingy love 7 1",
				"clingy love 7 2",
				"clingy love 7 3"
			}
		}
		,
		{
			{
				"clingy mood 0 1",
				"clingy mood 0 2",
				"clingy mood 0 3"
			},

			{
				"clingy mood 1 1",
				"clingy mood 1 2",
				"clingy mood 1 3"
			},

			{
				"clingy mood 2 1",
				"clingy mood 2 2",
				"clingy mood 2 3"
			},

			{
				"clingy mood 3 1",
				"clingy mood 3 2",
				"clingy mood 3 3"
			},

			{
				"clingy mood 4 1",
				"clingy mood 4 2",
				"clingy mood 4 3"
			},

			{
				"clingy mood 5 1",
				"clingy mood 5 2",
				"clingy mood 5 3"
			},

			{
				"clingy mood 6 1",
				"clingy mood 6 2",
				"clingy mood 6 3"
			},

			{
				"clingy mood 7 1",
				"clingy mood 7 2",
				"clingy mood 7 3"
			}
		}
	}
	,

	{
		{
			{
				"calm love 0 1",
				"calm love 0 2",
				"calm love 0 3"
			},

			{
				"calm love 1 1",
				"calm love 1 2",
				"calm love 1 3"
			},

			{
				"calm love 2 1",
				"calm love 2 2",
				"calm love 2 3"
			},

			{
				"calm love 3 1",
				"calm love 3 2",
				"calm love 3 3"
			},

			{
				"calm love 4 1",
				"calm love 4 2",
				"calm love 4 3"
			},

			{
				"calm love 5 1",
				"calm love 5 2",
				"calm love 5 3"
			},

			{
				"calm love 6 1",
				"calm love 6 2",
				"calm love 6 3"
			},

			{
				"calm love 7 1",
				"calm love 7 2",
				"calm love 7 3"
			}
		}
		,
		{
			{
				"calm mood 0 1",
				"calm mood 0 2",
				"calm mood 0 3"
			},

			{
				"calm mood 1 1",
				"calm mood 1 2",
				"calm mood 1 3"
			},

			{
				"calm mood 2 1",
				"calm mood 2 2",
				"calm mood 2 3"
			},

			{
				"calm mood 3 1",
				"calm mood 3 2",
				"calm mood 3 3"
			},

			{
				"calm mood 4 1",
				"calm mood 4 2",
				"calm mood 4 3"
			},

			{
				"calm mood 5 1",
				"calm mood 5 2",
				"calm mood 5 3"
			},

			{
				"calm mood 6 1",
				"calm mood 6 2",
				"calm mood 6 3"
			},

			{
				"calm mood 7 1",
				"calm mood 7 2",
				"calm mood 7 3"
			}
		}
	}
	,

	{
		{
			{
				"impulsive love 0 1",
				"impulsive love 0 2",
				"impulsive love 0 3"
			},

			{
				"impulsive love 1 1",
				"impulsive love 1 2",
				"impulsive love 1 3"
			},

			{
				"impulsive love 2 1",
				"impulsive love 2 2",
				"impulsive love 2 3"
			},

			{
				"impulsive love 3 1",
				"impulsive love 3 2",
				"impulsive love 3 3"
			},

			{
				"impulsive love 4 1",
				"impulsive love 4 2",
				"impulsive love 4 3"
			},

			{
				"impulsive love 5 1",
				"impulsive love 5 2",
				"impulsive love 5 3"
			},

			{
				"impulsive love 6 1",
				"impulsive love 6 2",
				"impulsive love 6 3"
			},

			{
				"impulsive love 7 1",
				"impulsive love 7 2",
				"impulsive love 7 3"
			}
		}
		,
		{
			{
				"impulsive mood 0 1",
				"impulsive mood 0 2",
				"impulsive mood 0 3"
			},

			{
				"impulsive mood 1 1",
				"impulsive mood 1 2",
				"impulsive mood 1 3"
			},

			{
				"impulsive mood 2 1",
				"impulsive mood 2 2",
				"impulsive mood 2 3"
			},

			{
				"impulsive mood 3 1",
				"impulsive mood 3 2",
				"impulsive mood 3 3"
			},

			{
				"impulsive mood 4 1",
				"impulsive mood 4 2",
				"impulsive mood 4 3"
			},

			{
				"impulsive mood 5 1",
				"impulsive mood 5 2",
				"impulsive mood 5 3"
			},

			{
				"impulsive mood 6 1",
				"impulsive mood 6 2",
				"impulsive mood 6 3"
			},

			{
				"impulsive mood 7 1",
				"impulsive mood 7 2",
				"impulsive mood 7 3"
			}
		}
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
