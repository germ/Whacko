#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "racko.h"
#include "ai.h"
#include "config.c"

int main(void) {
  Pile *players[PLAYERS],
       *deck,
       *discard;
  int i, j, k;
  Player* 

  /* Initilize game state memory */
  k = rand_init();
  assert(k == 0);

  for (i = 0; i < PLAYERS; i++) 
    players[i] = create_deck(10, 0, 1);

  discard = create_deck(deck_sizes[PLAYERS], 0, 1);
  deck    = create_deck(deck_sizes[PLAYERS], 0, 0);

  /* Set game to initial state */
  for (i = 0; i < PLAYERS; i++) 
    for (j = 0; j < 10; j++) 
      players[i]->deck[j] = draw_card(deck);

  /* Free up allocated memory */
  (void)free_deck(&deck);
  (void)free_deck(&discard);
  for (i = 0; i < PLAYERS; i++)
    if (players[i] != NULL) 
      (void)free_deck(&players[i]);
  
  return 0;
}
