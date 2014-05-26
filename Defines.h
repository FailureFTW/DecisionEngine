#ifndef DEFINES_H
#define DEFINES_H

#include <stdint.h>

#define KeyType uint32_t
#define ScoreType uint16_t
#define MoveType uint8_t
#define DepthType uint8_t
#define GenType uint16_t

// below here is game-specific

#define SquareType uint8_t

#define NUM_VALUES 18	// All values possible on the grid, including empty, 2^1 up to 2^17
#define NUM_SQUARES 16	// 4x4 grid

enum Move
{
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT
}

#endif
