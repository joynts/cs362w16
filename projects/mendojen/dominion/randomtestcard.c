/* -----------------------------------------------------------------------
 *  Jennifer Mendoza
 *	CS 325
 *	Description: This is a test program that tests the playSmithy() function.
 *	
 *	Note: Code was taken from the testDrawCard.c file provided in the dominion folder. 
 *	Code can also be found in lecture notes. I included both random and fix tests.
 *	Business requirements
 *  1) Current player gets 3 cards 
 *  2) 3 cards will only come from current player's pile
 *  3) Other player's state remains unchanged
 *
 * randomtestSmithy: randomtestcard.c dominion.o rngs.o
 *      gcc -o card3 -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)
 *
 * -----------------------------------------------------------------------
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1
 
void testSmithy(struct gameState *post,int p, int a ) {

	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));
	
	playSmithy(post, 0);
#if (NOISY_TEST == 1)
	printf("Testing when player %d plays Smithy card\n",p);
	if(p==1)
	{
		printf("Initial values for player 1 are handCount:%d, discardCount:%d, deckCount:%d\n",pre.handCount[1], pre.discardCount[1], pre.deckCount[1]);
		printf("Initial values for player 2 are handCount:%d, discardCount:%d, deckCount:%d\n",pre.handCount[2], pre.discardCount[2], pre.deckCount[2]);
	}
	else{
		printf("Initial values for player 2 are handCount:%d, discardCount:%d, deckCount:%d\n",pre.handCount[2], pre.discardCount[2], pre.deckCount[2]);
		printf("Initial values for player 1 are handCount:%d, discardCount:%d, deckCount:%d\n",pre.handCount[1], pre.discardCount[1], pre.deckCount[1]);
	}
	if (p==1)
	{
		printf("Testing if player 1 handCount increased");
		if (pre.handCount[1]<post->handCount[1])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.handCount[1],post->handCount[1]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.handCount[1],post->handCount[1]);
		}
		
		printf("Testing player 2 handCount remains unchanged");		
		if (pre.handCount[2]==post->handCount[2])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.handCount[2],post->handCount[2]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.handCount[2],post->handCount[2]);
		}
		
		printf("Testing if player 1 discardCount remains unchanged");
		if (pre.discardCount[1]==post->discardCount[1])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.discardCount[1],post->discardCount[1]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.discardCount[1],post->discardCount[1]);
		}
		
		printf("Testing player 2 discardCount remains unchanged");		
		if (pre.discardCount[2]==post->discardCount[2])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.discardCount[2],post->discardCount[2]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.discardCount[2],post->discardCount[2]);
		}
		
		
		printf("Testing if player 1 deckCount remains unchanged");
		if (pre.deckCount[1]==post->deckCount[1])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.deckCount[1],post->deckCount[1]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.deckCount[1],post->deckCount[1]);
		}
		
		printf("Testing player 2 deckCount remains unchanged");		
		if (pre.deckCount[2]==post->deckCount[2])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.deckCount[2],post->deckCount[2]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.deckCount[2],post->deckCount[2]);
		}
		
	}
	if (p==2)
	{
		printf("Testing player 2 handCount increased");
		if (pre.handCount[2]<post->handCount[2])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.handCount[2],post->handCount[2]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.handCount[2],post->handCount[2]);
		}
		
		printf("Testing player 1 handCount remains unchanged");
		if (pre.handCount[1]==post->handCount[1])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.handCount[1],post->handCount[1]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.handCount[1],post->handCount[1]);
		}
		
		
		printf("Testing if player 2 discardCount remains unchanged");
		if (pre.discardCount[2]==post->discardCount[2])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.discardCount[2],post->discardCount[2]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.discardCount[2],post->discardCount[2]);
		}
		
		printf("Testing player 1 discardCount remains unchanged");		
		if (pre.discardCount[1]==post->discardCount[1])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.discardCount[1],post->discardCount[1]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.discardCount[1],post->discardCount[1]);
		}
		
		
		printf("Testing if player 2 deckCount remains unchanged");
		if (pre.deckCount[2]==post->deckCount[2])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.deckCount[2],post->deckCount[2]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.deckCount[2],post->deckCount[2]);
		}
		
		printf("Testing player 2 deckCount remains unchanged");		
		if (pre.deckCount[1]==post->deckCount[1])
		{
			printf("....PASSED\n");
			printf("pre: %d, post:%d\n", pre.deckCount[1],post->deckCount[1]);
		}
		else{
			printf("....FAILED\n");
			printf("pre: %d, post:%d\n", pre.deckCount[1],post->deckCount[1]);
		}
	}
	printf("Testing playedCardCount for player %d.",p);
	if (post->playedCardCount==1)
	{
		printf("....PASSED\n");
		printf("Number of Cards Played = %d, expected = %d\n", post->playedCardCount, 1);
	}
	else{
		printf("....FAILED\n");
		printf("Number of Cards Played = %d, expected = %d\n", post->playedCardCount, 1);	
	}
#endif
	endTurn(&post);
#if (NOISY_TEST == 1)
	printf("Testing adventurer card supply Count");
	if (pre.supplyCount[adventurer]==post->supplyCount[adventurer])
	{
		printf("....PASSED\n");
		printf("pre: %d, post:%d\n", pre.supplyCount[adventurer],post->supplyCount[adventurer]);
	}
	else{
		printf("....FAILED\n");
		printf("pre: %d, post:%d\n", pre.supplyCount[adventurer],post->supplyCount[adventurer]);
	}
	printf("Testing outpost count");
	if (pre.outpostPlayed==post->outpostPlayed)
	{
		printf("....PASSED\n");
		printf("pre: %d, post:%d\n", pre.outpostPlayed,post->outpostPlayed);
	}
	else{
		printf("....FAILED\n");
		printf("pre: %d, post:%d\n", pre.outpostPlayed,post->outpostPlayed);
	}
	printf("Testing if numActions is unchanged");
	if (pre.numActions==post->numActions)
	{
		printf("....PASSED\n");
		printf("pre: %d, post:%d\n", pre.numActions,post->numActions);
	}
	else{
		printf("....FAILED\n");
		printf("pre: %d, post:%d\n", pre.numActions,post->numActions);
	}
	printf("Testing if Coin count is unchanged");
	if (pre.coins==post->coins)
	{
		printf("....PASSED\n");
		printf("pre: %d, post:%d\n", pre.coins,post->coins);
	}
	else{
		printf("....FAILED\n");
		printf("pre: %d, post:%d\n", pre.coins,post->coins);
	}
	printf("Testing if numBuys is unchanged");
	if (pre.numBuys==post->numBuys)
	{
		printf("....PASSED\n");
		printf("pre: %d, post:%d\n", pre.numBuys,post->numBuys);
	}
	else{
		printf("....FAILED\n");
		printf("pre: %d, post:%d\n", pre.numBuys,post->numBuys);
	}	
	printf("\n\n");
#endif
}
 
 
 
 
 
 
 int main () {

  int n, p;
  struct gameState G;
  time_t t;
  srand((unsigned)time(&t));
  printf ("Testing Smithy.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
	int* k=kingdomCards(1,2,3,4,5,6,7,8,9,10);
	initializeGame(2,k,1000,&G);
	p = rand() % 2+1;
	G.numPlayers=rand() % 3+1;
    G.deckCount[p] = rand() % MAX_DECK;
    G.discardCount[p] = rand() % MAX_DECK;
    G.handCount[p] = rand() % MAX_HAND;
    testSmithy(&G,p,n);
  }

  printf ("ALL TESTS COMPLETE\n");
  return 0;
}