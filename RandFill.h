#ifndef RANDFILL_H
#define RANDFILL_H

#include "Includes.h"
#include "rng.h"

	// This contains functions for filling arrays with random numbers.
	// Many different cases are handled here.

	// Writing " template<typename T> void function(T foo) " allows you to work with unknown data types
	// where 'T' takes on the type of your unknown datatype.

	// Writing " void function(void (&foo)[int N]) " allows you to pass an array and work with it.
	// 'N' takes on the size of the array, eliminating the need to pass the array size as a parameter.

namespace FillRandom
{
		// Fill a 1D array with no value boundaries
	template<typename T, int N> void FillArray (T (&data)[N]);

		// Fill a 1D array with a max and min value bound
	template<typename T, int N1, int N2> void FillArray (T (&data)[N1][N2], int index);

		// Fill a 2D array, filling element [i][index], where 'i' iterates through the array, and 'index' is constant.
	template<typename T1, int N, typename T2,typename T3> void FillArray (T1 (&data)[N], T2 lower, T3 upper);

		// Fill a 2D array, filling element [i][index], where 'i' iterates through the array, and 'index' is constant.
		// The value is bounded by lower and upper.
	template<typename T1, int N1, int N2, typename T2,typename T3> void FillArray (T1 (&data)[N1][N2], T2 lower, T3 upper, int index);
};

	// T = datatype, N = array size
template<typename T, int N> void FillRandom::FillArray (T (&data)[N])
{
	for (int i=0; i<N; i++)
	{
		data[i] = T(RNG());
	}
}

	// T = datatype, N1 = array size in 1st dimension, N2 = array size in 2nd dimension
	// index = 2nd dimension element that is being modified
template<typename T, int N1, int N2> void FillRandom::FillArray (T (&data)[N1][N2], int index)
{
	for (int i=0; i<N1; i++)
	{
		data[i][index] = T(RNG());
	}
}

	// T = datatype, N = array size
	// lower = lower limit of range, upper = upper limit of range
template<typename T1, int N, typename T2,typename T3> void FillRandom::FillArray (T1 (&data)[N], T2 lower, T3 upper)
{
	for (int i=0; i<N; i++)
	{
		data[i] = T1(RNG())%(upper-lower) + lower;
	}
}

	// T = datatype, N1 = array size in 1st dimension, N2 = array size in 2nd dimension
	// index = 2nd dimension element that is being modified
	// lower = lower limit of range, upper = upper limit of range
template<typename T1, int N1, int N2, typename T2,typename T3> void FillRandom::FillArray (T1 (&data)[N1][N2], T2 lower, T3 upper, int index)
{
	for (int i=0; i<N1; i++)
	{
		data[i][index] = T1(RNG())%(upper-lower) + lower;
	}
}

#endif
