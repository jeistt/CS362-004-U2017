#include "dominion.h"
#include "dominion_helpers.h"
#include "cardEffects.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

#define CARD "ADVENTURER"

int main() {
	//initial values to initialize game
	int seed = 99;
	struct gameState game;
	int choice1 = 1,
		choice2 = 0,
		choice3 = 0;
	int k[10] = { adventurer, smithy, village, minion, mine, cutpurse, gardens, tribute, feast, outpost };

	int t;
	int passed = 1;
	for (t = 0; t < 10; t++) {
		int numPlayers = rand() % 4;

		//initialize a gamestate. This will be copied and mannipulated for each test.
		initializeGame(numPlayers, k, seed, &game);

		int currentHandcount = rand() % 10;
		int currentDeckCount = game.deckCount[0];
		int draw = 2;
		int discard = 1;


		printf("---------------------STARTING %s TESTS----------------------\n", CARD);
		printf("TEST 1: ADDING 2 TREASURE CARDS\n");
		int allAssertsPassed = 1; //set to 0 if an assert fails
		int assertCount = 1;

		int expectedHand = currentHandcount + draw - discard;

		cardEffect(adventurer, choice1, choice2, choice3, &game, 0, 0);
		printf("Current hand count: %d\nExpected hand count: %d\n", game.handCount[0], expectedHand);
		if (!assertTrue(expectedHand, game.handCount[0], &assertCount))
			allAssertsPassed = 0;
		assertCount++;

		int expectedDeck = currentDeckCount - draw;


		printf("TEST 2: ENSURE ONLY TREASURE CARDS ADDED\n");
		int cardDrawn = game.hand[0][game.handCount[0] - 1];
		int cardDrawn2 = game.hand[0][game.handCount[0] - 2];
		if ((cardDrawn != silver && cardDrawn != copper && cardDrawn != gold)
			&& (cardDrawn2 != silver && cardDrawn2 != copper && cardDrawn2 != gold)) {
			printf("ASSERT FAILED - NON-TREASURE CARD ADDED\n");
			allAssertsPassed = 0;
		}
		else
			printf("TEST 2 PASSED\n");
		if (!allAssertsPassed)
			passed = 0;
	}
	if (passed == 0)
		printf("RANDOM TEST FAILED\n");
	else
		printf("ALL RANDOM TESTS PASSED");
}