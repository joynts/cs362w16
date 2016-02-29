/* -----------------------------------------------------------------------
 * Unit test for updateCoins function. Highly based on a similar test
 * linked in the week 3 course materials along with lecture 11.
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int testUpdateCoins(int p, struct gameState *game, int bonus);

int main() {
	
	
  int n, i, p, bonus;
  int maxBonus = 10;
  struct gameState game;
  
  SelectStream(2);
  PutSeed(3);
  
  
  for (n = 0; n < 2000; n++) { //runs 2000 tests
	  printf ("--------------------------\n");
      printf ("Running test series %d ...\n", n+1);
	  //The below code manually initializes a game
	  for (i = 0; i < sizeof(struct gameState); i++) { 
	  ((char*)&game)[i] = floor(Random() * 256);
	  }
	  p = floor(Random() * 2);
	  game.handCount[p] = floor(Random() * MAX_HAND);
	  for (bonus = 0; bonus <= maxBonus; bonus++){ //Sets the bonus coin count
		testUpdateCoins(p, &game, bonus);  
	  }
	  printf ("--------------------------\n\n");
	  
  }
  return 0;
}

int testUpdateCoins(int p, struct gameState *game, int bonus){
	int randCoin, i;
	int total = 0;
	
	/*This loop will randomly assign a copper, silver, or gold to
	  the player's hand as it loops through it. It also adds the 
	  vaule of the treasure card to the total. */
	for (i = 1; i < game->handCount[p]; i++){
		randCoin = floor((Random() * 3) + 1);
		
		
		if (randCoin == 1) {
			game->hand[p][i] = copper;
			total += 1;
		}
		
		else if (randCoin == 2) {
			game->hand[p][i] = silver;
			total += 2;
		}
		
		else if (randCoin == 3) {
			game->hand[p][i] = gold;
			total += 3;
		}
	}
	
	total += bonus; //Adds the bonus coins to the manually calculated coin count
	updateCoins(p, game, bonus);
	
	if(game->coins == total){ //Compares the manual count to the count generated by updateCoins
		printf ("Test passed\n\n");
	}
	else
		printf ("Test failed\n\n");
	
	return 0;
}