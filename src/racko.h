#ifndef RACKO_H
#define RACKO_H

extern int RAND_SEEDED;
extern int deck_sizes[];

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
* @brief A function to be called before calling create_deck
*
* @return 0 on sucessful seed, 1 if already seeded
*/
int rand_init(void);

/**
* @brief Create a new deck of cards
*
* @param length     Desired size of deck
* @param isOrdered  Non zero is deck should be sorted low to high
*
* @return the newley created pile
*/
Pile* create_deck(int length, int isOrdered, int isEmpty);

/**
* @brief Free up the memory associated with a deck and null its pointer
*
* @param deck deck to free
*
* @return 0 on sucess, 1 on failure
*/
int free_deck(Pile** deck);

/**
* @brief Return a card value from the specified deck
* @param deck the pile to draw from
* @return the interger value of the card
*/
int draw_card(Pile* deck);

/**
* @brief Place a card into a deck
*
* @param card Value of the card to place
* @param deck Deck to place card into
*
* @return 
*/
int place_card(int card, Pile* deck);

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
int swap_cards(Pile* dest, Pile* source, int destIndex, int sourceIndex);

/**
* @brief Print the contents of a deck
*
* @param deck     The deck to print
*
* @return 0
*/
void print_deck(Pile* deck);

#endif /* RACKO_H */
