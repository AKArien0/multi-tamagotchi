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
#define CHECK_ 7

char * text_check[8][8] = // value, value %
{
	{
		"check food 0",
		"check food 1",
		"check food 2",
		"check food 3",
		"check food 4",
		"check food 5",
		"check food 6",
		"check food 7"
	},

	{
		"check sleep 0",
		"check sleep 1",
		"check sleep 2",
		"check sleep 3",
		"check sleep 4",
		"check sleep 5",
		"check sleep 6",
		"check sleep 7"
	},

	{
		"check disease 0",
		"check disease 1",
		"check disease 2",
		"check disease 3",
		"check disease 4",
		"check disease 5",
		"check disease 6",
		"check disease 7"
	},

	{
		"check drugs 0",
		"check drugs 1",
		"check drugs 2",
		"check drugs 3",
		"check drugs 4",
		"check drugs 5",
		"check drugs 6",
		"check drugs 7"
	},

	{
		"check past_food 0",
		"check past_food 1",
		"check past_food 2",
		"check past_food 3",
		"check past_food 4",
		"check past_food 5",
		"check past_food 6",
		"check past_food 7"
	},

	{
		"check past_love 0",
		"check past_love 1",
		"check past_love 2",
		"check past_love 3",
		"check past_love 4",
		"check past_love 5",
		"check past_love 6",
		"check past_love 7"
	},

	{
		"check past_sleep 0",
		"check past_sleep 1",
		"check past_sleep 2",
		"check past_sleep 3",
		"check past_sleep 4",
		"check past_sleep 5",
		"check past_sleep 6",
		"check past_sleep 7"
	},

	{
		"check x 0",
		"check x 1",
		"check x 2",
		"check x 3",
		"check x 4",
		"check x 5",
		"check x 6",
		"check x 7"
	}
};

char * text_check_fun[5][2][8][3] = // personality, mood || love (own / interaction), value%, possibilites
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
