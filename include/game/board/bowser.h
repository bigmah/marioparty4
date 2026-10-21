#ifndef _BOARD_BOWSER_H
#define _BOARD_BOWSER_H

#include "game/process.h"

#ifdef TARGET_PC
s32 BoardBowserExec(s32 player, s32 space);
#else
void BoardBowserExec(s32 player, s32 space);
#endif

#endif
