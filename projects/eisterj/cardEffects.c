#include "cardEffects.h"
#include "dominion_helpers.h"


int adventurerCard(int drawntreasure, int currentPlayer, struct gameState *state) {
	int z = 0;
	int temphand[MAX_HAND];
	while (drawntreasure<=2) {
		if (state->deckCount[currentPlayer] <= 1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
	return 0;
}

int smithyCard(int handPos, int currentPlayer, struct gameState *state) {
	int i;
	for (i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}
	
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

int minionCard(int choice1, int choice2, int handPos, int currentPlayer, struct gameState *state) {
	//+1 action
	state->numActions++;

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);

	if (choice1)		//+2 coins
	{
		state->coins = state->coins + 2;
	}

	else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
	{
		//discard hand
		while (numHandCards(state) > 0)
		{
			discardCard(handPos, currentPlayer, state, 0);
		}

		//draw 4
		int i;
		for (i = 0; i < 4; i++)
		{
			drawCard(currentPlayer, state);
		}

		//other players discard hand and redraw if hand size > 4
		for (i = 0; i < state->numPlayers; i++)
		{
			if (i != currentPlayer)
			{
				if (state->handCount[i] > 4)
				{
					//discard hand
					while (state->handCount[i] > 0)
					{
						discardCard(handPos, i, state, 0);
					}

					//draw 4
					int j;
					for (j = 0; j < 4; j++)
					{
						drawCard(i, state);
					}
				}
			}
		}

	}
	return 0;
}

int greatHallCard(int handPos, int currentPlayer, struct gameState *state){
		//+1 Card
		drawCard(currentPlayer, state);

		//+1 Actions
		state->numActions++;

		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
}

int villageCard(int handPos, int currentPlayer, struct gameState *state){      
	//+1 Card
	drawCard(currentPlayer, state);

	//+2 Actions
	state->numActions = state->numActions + 2;

	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

