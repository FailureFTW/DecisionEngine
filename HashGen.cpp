#include "HashGen.h"

	/*
	 * A hash table should be random, in order to provide good distinction of
	 * unique positions. A particular square position with a certain value should
	 * be random, but maintain that value so that the same position ganerates the same key,
	 * but a slightly different position will produce a completely different key.
	 * That way, small deviations in the board will be sure to make a difference in the key.
	 */


void HashInit()
{
	// Sweep through the lookup table and generate random numbers
	// to be assigned to a unique square/value combination

	//int size = sizeof(ZobristHash::PieceKeys)/sizeof(ZobristHash::PieceKeys[0]);

	//for (int i=0; i<size; i++)
	//	FillRandom::FillArray(ZobristHash::PieceKeys[i]);
}

