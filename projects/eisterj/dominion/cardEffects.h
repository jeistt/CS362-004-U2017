#ifndef CARDEFFECTS_H
#define CARDEFFECTS_H
#include "dominion.h"

int minionCard(int choice1, int choice2, int handPos, int currentPlayer, struct gameState *state);
int smithyCard(int handPos, int currentPlayer, struct gameState *state);
int adventurerCard(int drawntreasure, int currentPlayer, struct gameState *state);
int greatHallCard(int handPos, int currentPlayer, struct gameState *state);
int villageCard(int handPos, int currentPlayer, struct gameState *state);

#endif
