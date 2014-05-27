#ifndef BITFUNCS_H
#define BITFUNCS_H

#include "Includes.h"
	/*
	 *	Several bitwise functions for specific tasks such as individual bit manipulation
	 *	and fast Logbase 2 functions.
	 *	See http://graphics.stanford.edu/~seander/bithacks.html
	 *	for the source of some of these bit twiddling algorithms
	 *	like the Logbase2 functions as well as others.
	 */

#define PresetBit(num, bit) (num |= 1<<bit)
#define ResetBit(num, bit) (num &= ~(1<<bit))
#define ToggleBit(num, bit) (num ^= 1<<bit)
#define GetBit(num, bit) ((num & (1<<bit))>>bit)

#define SetBit(num, bit, state) (num = (state == 0) ? ResetBit(num, bit) : PresetBit(num, bit))
#define CopyBit(dest, src, bit) (SetBit(dest, bit, (GetBit(src, bit))));

#define SetUpper4Bits(num, val) (val < 16 ? (num & 48) & (val & 15) : 0)
#define SetLower4Bits(num, val) (val < 16 ? (num & 15) & ((val << 4) & 48) : 0)

#define GetLower4Bits (num) (num & 15)
#define GetUpper4Bits (num) (num >> 4) & 15)

unsigned int Log2Fast(unsigned int Value);
unsigned int Log2Slow(unsigned int Value);
unsigned int Log2Pow2(unsigned int Value);

template <typename T> void displayBits(T number)
{
	int sz = 8*sizeof(T);
	for (int i=0; i<sz; i++)
	{
		if (i%4==0) cout << " ";
		cout << GetBit(number, i);
	}
}

#endif
