#define PLAYERS 1
#define AI_1    germ
#define AI_2    linxcat
#define AI_3    ivy
#define AI_4    bot

#if PLAYERS >= 1
  #include "AI_1.c"
#endif

#if PLAYERS >= 2
  #include "AI_2.c"
#endif

#if PLAYERS >= 3
  #include "AI_3.c"
#endif

#if PLAYERS >= 3
  #include "AI_4.c"
#endif
