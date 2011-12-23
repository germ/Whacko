#ifndef AI_H
#define AI_H

typedef struct player_t {
  void (*ai_handoff)(Pile* rack, int draw, int discard);
} Player;

void germ_ai(Pile* rack, int draw, int discard);

#endif /* AI_H */
