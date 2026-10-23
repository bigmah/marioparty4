#ifndef PORT_UNLOCK_ALL_H
#define PORT_UNLOCK_ALL_H

// The web build starts with everything unlocked: every minigame, Bowser's
// Gnarly Party, Very Hard computers, the Present Room's presents and every
// song in the sound test (port/src/unlock.c). Applied to a new save and to
// every save loaded from the card.
#ifdef __EMSCRIPTEN__
struct game_stat;
void port_game_unlock_all(struct game_stat* stat);
#else
#define port_game_unlock_all(stat) ((void)0)
#endif

#endif
