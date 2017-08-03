#include "dominion.h"
#include "dominion_helpers.h"
//#include "cardEffects.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

#define FNAME "NUMHANDCARD"


int main() {
	int allAssertsPassed = 1; 
	int seed = 99;
	struct gameState game;
	int k[10] = { adventurer, smithy, village, minion, mine, cutpurse, gardens, tribute, feast, outpost };
	int numPlayers = 2;

	initializeGame(numPlayers, k, seed, &game);

	printf("---------------------STARTING %s TESTS----------------------\n", FNAME);
	printf("TEST 1\n");
	printf("STARTING GAME... EXPECTING 5 CARDS IN HAND.\n");
	printf("THERE ARE %d CARDS\n", game.handCount[0]);
	if (game.handCount[0] != 5) {
		allAssertsPassed = 0;
		printf("TEST FAILED\n");
	}
	else printf("TEST PASSED\n");
	
	printf("TEST 2\n");
	printf("ADDING 1 CARD. EXPECTING 4 CARDS.\n");
	discardCard(0, 0, &game, 0);
	printf("THERE ARE %d CARDS\n", game.handCount[0]);
	if (game.handCount[0] != 4) {
		allAssertsPassed = 0;
		printf("TEST FAILED\n");
	}
	else printf("TEST PASSED\n");
	if (allAssertsPassed)
		printf("----------------------ALL %s TESTS PASSED-----------------------\n", FNAME);
	else
		printf("----------------------SOME %s TESTS FAILED-----------------------------------\n", FNAME);

	return 0;
}
