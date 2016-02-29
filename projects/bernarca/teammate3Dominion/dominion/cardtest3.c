
/*
card test 3
village



int playVillage(struct gameState *state)
{
     int currentPlayer = whoseTurn(state);
          drawCard(currentPlayer, state);

      //+2 Actions
      state->numActions = state->numActions + 2;
    return 0;
}
}


Description:
finds current player
call draw card

adds 2 to action total

Assumes Dependencies functions work;

 whoseTurn()
 drawCard()

*/



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int testVillage(struct gameState *pre)
{

     //create test game
    struct gameState post;
    memcpy(&post,pre,sizeof(struct gameState));
    assert (memcmp(&post,pre, sizeof(struct gameState))==0);

    // play Village;
    playVillage(&post);

    //update pre

    int currentPlayer = pre->whoseTurn;



    drawCard(currentPlayer,pre);
    pre->numActions += 2;



     if(memcmp(&post,pre, sizeof(struct gameState))==0)
    {
        printf("village Test PASS\n");
    }
    else
    {
        printf("village Test FAIL\n");
    }

    return 0;
}





int main()
{
     printf("PlayVillage test - cardTest3\n");

    //array of cards
      int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    struct gameState preState;

    int i, n;

    //create random seed
  SelectStream(2);
  PutSeed(3);
    for (n = 0; n < 2000; n++)
    {
        for (i = 0; i < sizeof(struct gameState); i++) {
          //fill game state with random bits
          ((char*)&preState)[i] = floor(Random() * 256);
        }
    //fill in required preconditions
        //set players and current play
        preState.numPlayers = floor(Random() * (MAX_PLAYERS));
        preState.whoseTurn = floor(Random() * preState.numPlayers);
        preState.numActions = floor(Random() * 100);

        for (i = 0; i < MAX_PLAYERS; i++)
        {
            preState.handCount[i] = floor(Random() * (MAX_HAND)); // non zero handcount
            preState.deckCount[i] = floor(Random() * MAX_DECK);
            preState.discardCount[preState.whoseTurn] = floor(Random() * MAX_DECK);
        }

        for(i=0;i<preState.handCount[preState.whoseTurn];i++)
        {
        preState.hand[preState.whoseTurn][i] = floor(Random() * 10);
        }
         for(i=0;i<preState.deckCount[preState.whoseTurn];i++)
        {
        preState.hand[preState.whoseTurn][i] = floor(Random() * 10);
        }
        for(i=0;i<preState.discardCount[preState.whoseTurn];i++)
        {
        preState.discard[preState.whoseTurn][i] = floor(Random() * 10);
        }



        //run test
        testVillage(&preState);
    }
    return 0;

}


