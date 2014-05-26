#include "HashGen.h"

	/*
	 * A hash table should be random, in order to provide good distinction of
	 * unique positions. A particular square position with a certain value should
	 * be random, but maintain that value so that the same position ganerates the same key,
	 * but a slightly different position will produce a completely different key.
	 * That way, small deviations in the board will be sure to make a difference in the key.
	 */

namespace ZobristHash
{
		// Array of random values for every position of every element
		// on the board used for key generation.
	KeyType LookupTable[NUM_SQUARES][NUM_VALUES];
}

void HashInit()
{
	// Sweep through the lookup table and generate random numbers
	// to be assigned to a unique square/value combination

	for (int i=0; i<NUM_VALUES; i++)
		FillRandom::FillArray(ZobristHash::LookupTable, i);
}

KeyType GenerateKey(SquareType* board)
{
	KeyType key = 0;
	SquareType *pos = board;

	for (int i=0; i<NUM_SQUARES; i++, pos++)
		key ^= ZobristHash::LookupTable[i][*pos];

	return key;
}