#ifndef HASHGEN_H
#define HASHGEN_H

#include "Includes.h"
#include "RandFill.h"

	/*
	 *	This will contain randomized values for certain values at certain squares.
	 *	This will be referred to when a key is being generated from a position.
	 *	See http://en.wikipedia.org/wiki/Zobrist_hashing for info.
	 */

namespace ZobristHash
{
		// Array of random values for every position of every element
		// on the board used for key generation.
	// KeyType PieceKeys[NUM_SQUARES][NUM_VALUES];
};

void HashInit();
KeyType GenerateKey(SquareType* pos); // Input a position to be used


#endif