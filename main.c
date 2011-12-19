#include <stdio.h>
#include <stdlib.h>

#define PLAYERS 4

const static int deck_sizes[5] = {0, 30, 40, 45, 60};

/**
* @brief A deck of cards. Note: In racko the size of the deck will never grow 
*        past its initial size.
*/
typedef struct pile_t {
  int       index;    /* Starting position of the first card */
  int       length;   /* The Length of the deck */
  int      *deck;
} Pile;


/**
* @brief Create a new deck of cards
*
* @param length     Desired size of deck
* @param isOrdered  Non zero is deck should be sorted low to high
*
* @return the newley created pile
*/
Pile* create_deck(int length, int isOrdered, int isEmpty) {
  Pile *pile      = (Pile *)malloc(sizeof(Pile));
  int   i;

  pile->length    = length;
  pile->deck      = (int *)calloc(length, sizeof(int));
  pile->index     = 0;

  if (isEmpty) {
    return pile;
  }
  if (!isOrdered) {
    for (i = 0; i < length; i++) 
      pile->deck[i] = i;

    return pile;
  } else {
    for (i = 0; i < length; i++) {
      int deck_pos;
      do {
        deck_pos = (rand() % length);
      } while (pile->deck[deck_pos] != 0);

      pile->deck[deck_pos] = i+1;
    }

    return pile;
  }
}

/**
* @brief Return a card value from the specified deck
* @param deck the pile to draw from
* @return the interger value of the card
*/
int draw_card(Pile* deck) {
  int returnVar;

  if (deck->index == deck->length)
    return 0;

  returnVar = deck->deck[deck->index];

  deck->deck[deck->index] = 0;
  deck->index += 1;

  return returnVar;
}

/**
* @brief Place a card into a deck
*
* @param card Value of the card to place
* @param deck Deck to place card into
*
* @return 
*/
int place_card(int card, Pile* deck) {
  if (deck->index != 0) {
    deck->deck[deck->index] = card;
    deck->index--;

    return 0;
  }
  return 1;
}

/**
* @brief Swap two cards from different Piles (There is no difference in code 
*        between the source and dest piles, they are interchangable
*
* @param dest         The first pile
* @param source       The second pile
* @param destIndex    Location of card to be swapped in dest
* @param sourceIndex  Location of card to be swapped in source
*
* @return 0
*/
int swao_cards(Pile* dest, Pile* source, int destIndex, int sourceIndex) {
}

/**
* @brief Print the contents of a deck
*
* @param deck     The deck to print
* @param format   The format call to printf
*
* @return 0
*/
int print_deck(Pile* deck, char* format) {
  int i;

  for (i = deck->index; i < deck->length; i++) 
    printf(format, deck->deck[i]);
  printf("\n");

  return 0;
}

int main() {
  Pile *players[PLAYERS],
       *deck,
       *discard;
  int i, j;

  /* Initilize game state memory */
  for (i = 0; i < PLAYERS; i++) 
    players[i] = create_deck(10, 0, 1);

  discard = create_deck(deck_sizes[PLAYERS], 0, 1);
  deck    = create_deck(deck_sizes[PLAYERS], 0, 0);

  /* Set game to initial state */
  for (i = 0; i < PLAYERS; i++) 
    for (j = 0; j < 10; j++) 
      players[i]->deck[j] = draw_card(deck);

  for (i = 0; i < PLAYERS; i++) 
    print_deck(players[i], "%d, ");
  print_deck(deck, "%d, ");
  print_deck(discard, "%d, ");

  for (i = 0; i < PLAYERS; i++) 
    for (j = 0; j < 10; j++) 
      place_card(

  for (i = 0; i < PLAYERS; i++) 
    print_deck(players[i], "%d, ");
  print_deck(deck, "%d, ");
  print_deck(discard, "%d, ");
  return 0;

}
