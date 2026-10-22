#ifndef PORT_GAME_TIME_H
#define PORT_GAME_TIME_H

#include <dolphin/os.h>

// The clock for whatever feeds the game's state (random seeds, timed waits,
// save timestamps). In the web build the peers of an online match must agree
// on it, so there it comes from the match's seed and frame count while online
// (the web port's port/src/net_state.c); everywhere else it's the console clock.
#ifdef __EMSCRIPTEN__
#ifdef __cplusplus
extern "C" {
#endif
OSTime port_game_time(void);
OSTick port_game_tick(void);
#ifdef __cplusplus
}
#endif
#else
static inline OSTime port_game_time(void) { return OSGetTime(); }
static inline OSTick port_game_tick(void) { return OSGetTick(); }
#endif

#endif
