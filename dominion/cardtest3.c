#include "dominion.h"
#include "dominion_helpers.h"
#include "cardEffects.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

#define CARD "GREAT HALL"

int main() {
	//initial values to initialize game
	int seed = 99;
	struct gameState game;
	int choice1 = 1,
		choice2 = 0,
		choice3 = 0;
	int k[10] = { adventurer, smithy, village, minion, mine, cutpurse, gardens, tribute, feast, outpost };
	int numPlayers = 2;

	//initialize a gamestate. This will be copied and mannipulated for each test.
	initializeGame(numPlayers, k, seed, &game);

	int currentHandcount = game.handCount[0];
	int currentDeckCount = game.deckCount[0];
	int draw = 1;
	int discard = 1;


	printf("---------------------STARTING %s TESTS----------------------\n", CARD);
	printf("TEST 1: ADDING 2 TREASURE CARDS\n");
	int allAssertsPassed = 1; //set to 0 if an assert fails
	int assertCount = 1;

	int expectedHand = currentHandcount + draw - discard;

	cardEffect(great_hall, choice1, choice2, choice3, &game, 0, 0);
	printf("Current hand count: %d\nExpected hand count: %d\n", game.handCount[0], expectedHand);
	if (!assertTrue(expectedHand, game.handCount[0], &assertCount))
		allAssertsPassed = 0;
	assertCount++;

	int expectedDeck = currentDeckCount - draw;

	printf("TEST 2: CHECKING DECK COUNT\n");
	printf("Current deck count: %d\nExpected deck count: %d\n", game.deckCount[0], expectedDeck);
	if (!assertTrue(expectedDeck, game.deckCount[0], &assertCount))
		allAssertsPassed = 0;

	printf("TEST 3: ABLE TO MAKE ANOTHER ACTION\n");
	if (game.numActions < 1){
		printf("ASSERT FAILED - NOT GRANTED ANOTHER ACTION\n");
		allAssertsPassed = 0;
	}
	else
		printf("TEST 3 PASSED\n");
	if (allAssertsPassed)
		printf("----------------------ALL %s TESTS PASSED-----------------------\n", CARD);
	else
		printf("----------------------SOME %s TESTS FAILED-----------------------------------\n", CARD);

	return 0;
}