#include "BitFuncs.h"

unsigned int Log2Fast(unsigned int Value)
{
	const unsigned int b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
	const unsigned int S[] = {1, 2, 4, 8, 16};

	unsigned int Result = 0; // result of log2(Value) will go here

	for (int i = 4; i >= 0; i--) // unroll for speed...
	{
		if (Value & b[i])
		{
			Value >>= S[i];
			Result |= S[i];
		}
	}

	return Result;
}

	// For slow computers

unsigned int Log2Slow(unsigned int Value)
{
	unsigned int Result; // result of log2(v) will go here
	unsigned int shift;

	Result = (Value > 0xFFFF) << 4; Value >>= Result;
	shift = (Value > 0xFF) << 3; Value >>= shift; Value |= shift;
	shift = (Value > 0xF) << 2; Value >>= shift; Result |= shift;
	shift = (Value > 0x3) << 1; Value >>= shift; Result |= shift;
	Result |= (Value >> 1);

	return Result;
}

	// If Value is a known power of 2

unsigned int Log2Pow2(unsigned int Value)
{
	static const unsigned int b[] = {0xAAAAAAAA, 0xCCCCCCCC, 0xF0F0F0F0, 
									 0xFF00FF00, 0xFFFF0000};

	unsigned int Result = (Value & b[0]) != 0;

	for (int i = 4; i > 0; i--) // unroll for speed...
	{
		Result |= ((Value & b[i]) != 0) << i;
	}
	return Result;
}