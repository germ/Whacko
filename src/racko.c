#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <assert.h>
#include "racko.h"

int RAND_SEEDED = 0;
int deck_sizes[5] = {0, 30, 40, 45, 60};

int      rand_init(void) {
  if (RAND_SEEDED == 0) {
    struct timeb* sys_time = calloc((size_t)1, sizeof(struct timeb));

    assert(sys_time != NULL);

    (void)ftime(sys_time);
    (void)srand((unsigned int)sys_time->millitm);
    RAND_SEEDED = 1;

    free(sys_time);
    return 0;
  }
  return 1;
}
Pile*    create_deck(int length, int isOrdered, int isEmpty) {
  Pile *pile;     
  int   i;

  pile = (Pile *)calloc((size_t)1, sizeof(Pile));
  assert(pile != NULL);

  pile->length    = length;
  pile->deck      = (int *)calloc((size_t)length, sizeof(int));
  pile->index     = 0;
  assert(pile->deck != NULL);

  if (isEmpty == 1) {
    return pile;
  } 
  else if (isOrdered == 1) {
    for (i = 0; i < length; i++) 
      pile->deck[i] = i+1;

    return pile;
  } 
  else {
    for (i = 0; i < length; i++) {
      int deck_pos;

      (void)rand_init();
      do {
        deck_pos = (rand() % length);
      } while (pile->deck[deck_pos] != 0);

      pile->deck[deck_pos] = i+1;
    }

    return pile;
  }
}
int      free_deck(Pile** deck) {
  Pile* pile = *deck;

  assert(pile != NULL);
  assert(pile->deck != NULL);

  free(pile->deck);
  free(pile);

  *deck = NULL;

  return 0;
}
int      draw_card(Pile* deck) {
  int returnVar;

  if (deck->index == deck->length)
    return 0;

  returnVar = deck->deck[deck->index];

  deck->deck[deck->index] = 0;
  deck->index += 1;

  return returnVar;
}
int      place_card(int card, Pile* deck) {
  if (deck->index != 0) {
    deck->deck[deck->index] = card;
    deck->index--;

    return 0;
  }
  return 1;
}
int      swap_cards(Pile* dest, Pile* source, int destIndex, int sourceIndex) {
  int cardTemp = dest->deck[destIndex];
  dest->deck[destIndex] = source->deck[sourceIndex];
  source->deck[sourceIndex] = cardTemp;

  return 0;
}
void     print_deck(Pile* deck) {
  int i;

  for (i = deck->index; i < deck->length; i++) 
    printf("%d ", deck->deck[i]);
  printf("\n");

  return;
}
