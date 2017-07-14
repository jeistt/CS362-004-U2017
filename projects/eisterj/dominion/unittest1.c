#include "dominion.h"
#include "dominion_helpers.h"
#include "cardEffects.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

#define FNAME "COMPARE"


int main() {
	int eighty = 80;
	int twenty = 20;

	int allAssertsPassed = 1;

	printf("---------------------STARTING %s TESTS----------------------\n", FNAME);
	printf("TEST 1: 20 GREATER THAN 80\n");
	
	int t1 = compare(&eighty, &twenty);
	if (t1 == 1)
		printf("TRUE - TEST PASSED\n");
	else {
		printf("FALSE - TEST FAILED\n");
		allAssertsPassed = 0;
	}

	printf("TEST2: 80 LESS THAN 20\n");
	t1 = compare(&twenty, &eighty);
	if (t1 == -1)
		printf("TRUE - TEST PASSED\n"); 
	else {
		printf("FALSE - TEST FAILED\n");
		allAssertsPassed = 0;
	}
	
	printf("TEST3: 80 IS EQUAL TO 80\n");
	t1 = compare(&twenty, &twenty);
	if (t1 == 0)
		printf("TRUE - TEST PASSED\n");
	else {
		printf("FALSE - TEST FAILED\n");
		allAssertsPassed = 0;
	}

	if (allAssertsPassed)
		printf("----------------------ALL %s TESTS PASSED-----------------------\n", FNAME);
	else
		printf("----------------------SOME %s TESTS FAILED-----------------------------------\n", FNAME);

	return 0;
}