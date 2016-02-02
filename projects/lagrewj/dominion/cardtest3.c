/*Jonathan Lagrew
 *cardtest3.c
 *test playVillage()
 *Notes:
 *Village is an Action card from the Base set. Village gives you +1 card from the deck and +2 actions, 
 *allowing you to play more than one terminal action each turn.
 */
 /*
 * Basic Requirements of Village:
 * 1. Current player should receive a total of 1 cards from the deck.
 * 2. Current player should receive plus 2 actions. 
 * 3. No state change should occur for other players.
 * 4. No state change should occur to the victory drawnCard piles and kingdom card piles.
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define TESTCARD "Adventurer"

int testplayVillage(struct gameState *after, int handPos)
{
	int p = after->whoseTurn;
	struct gameState before;
	memcpy(&before, after, sizeof(struct gameState));
	
	playVillage(after, handPos);
	
	//after hand should have same net hand count. Plus a draw card, minus a village card
	if(before.handCount[p] != after->handCount[p])
	{
		printf("ERROR: hand counts should match. before: %d, after: %d\n", before.handCount[p], after->handCount[p]);
	}
	//numActions should be 2 more
	before.numActions = before.numActions + 2;
	if(before.numActions != after->numActions)
	{
		printf("ERROR: number of actions should match. before: %d, after: %d\n", before.numActions, after->numActions);
	}
	//still current player?
	if(before.whoseTurn != after->whoseTurn)
		printf("ERROR: Current player has changed from %i to %i", before.whoseTurn, after->whoseTurn);
	
	//check coins
	if(before.coins != after->coins)
		printf("ERROR: Number of coins changed from %i to %i", before.coins, after->coins);
	//check number of buys
	if(before.numBuys != after->numBuys)
		printf("ERROR: Number of buys has changed from %i, to %i", before.numBuys, after->numBuys);
	
	return 0;
}

int main()
{
	int p = 0;
	int numTests = 500;
	struct gameState G;
	int handPos;
	int i, j, k, m, n, q;
	
	//generates random tests
	printf("STARTING RANDOM TESTS.\n");
	
	SelectStream(2);
	PutSeed(3);
	printf("Testing playVillage() cardtest3.\n");
	
	for(k = 0; k < numTests; k++)
	{
		for (i = 0; i < sizeof(struct gameState); i++) { //from the lessons, random gameState
			((char*)&G)[i] = floor(Random() * 256);
		}
		G.whoseTurn = p;
		G.numActions = 1;
		//filling in random cards based on lecture 11 and 12 Random Testing 
		G.handCount[p] = floor(Random() * MAX_HAND)+1;//need at least one village in our hand
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.playedCardCount = floor(Random() * MAX_DECK);
		
		for(m = 0; m < G.handCount[p]; m++)
		{
			G.hand[p][m] = floor(Random() * treasure_map) + 1;
		}
		
		for(j = 0; j < G.discardCount[p]; j++)
		{
			G.discard[p][j] = floor(Random() * treasure_map) + 1;
		}

		for(n = 0; n < G.deckCount[p]; n++)
		{
			G.deck[p][n] = floor(Random() * treasure_map) + 1;
		}
		for(q = 0; q < G.playedCardCount; q++)
		{
			G.playedCards[q] = floor(Random() * treasure_map) + 1;
		}
		
		//place village in a random pos
		handPos = floor(Random() * G.handCount[p]);
		G.hand[p][handPos] = village;
		
		testplayVillage(&G, handPos);
		
	}
	
	printf("PLAYVILLAGE TESTS FINISHED.\n\n");
	return 0;
}