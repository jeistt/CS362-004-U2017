#include "dominion.h"
#include "dominion_helpers.h"
#include "cardEffects.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

#define FNAME "DISCARD"

int main() {
	int allAssertsPassed = 1;
	int seed = 99;
	struct gameState game;
	int k[10] = { adventurer, smithy, village, minion, mine, cutpurse, gardens, tribute, feast, outpost };
	int numPlayers = 2;

	initializeGame(numPlayers, k, seed, &game);

	printf("---------------------STARTING %s TESTS----------------------\n", FNAME);
	printf("TEST 1\n");
	printf("STARTING GAME... WITH 5 CARDS IN HAND.\n");
	printf("THERE ARE %d CARDS\n", game.handCount[0]);
	
	int expected = 4;
	int sameVal = 1;

	while (game.handCount[0] > 0) {
		printf("DISCARDING CARD. THERE SHOULD BE %d CARDS NOW.\n", expected);
		discardCard(0, 0, &game, 0);
		printf("YOU HAVE %d CARDS\n", game.handCount[0]);
		if (game.handCount[0] != expected) {
			sameVal = 0;
			allAssertsPassed = 0;
		}
		expected--;

	}

	if (sameVal)
		printf("TEST PASSED\n");

	if (allAssertsPassed)
		printf("----------------------ALL %s TESTS PASSED-----------------------\n", FNAME);
	else
		printf("----------------------SOME %s TESTS FAILED-----------------------------------\n", FNAME);

	return 0;
}