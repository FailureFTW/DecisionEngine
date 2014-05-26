#ifndef SORTING_H
#define SORTING_H

#include "Includes.h"

	/*
	 *	This uses the quicksort algorithm to sort various kinds of data in arrays.
	 *	Arrays of any size and type are compatible.
	 *	There are options for sorting according to different elements in the array.
	 *	See http://en.wikipedia.org/wiki/Quicksort for info on the algorithm.
	 */

class Sorting
{
public:
		// This is the function being called from the rest of the program.
		// This sorts the array from lowest to highest value.
	template<typename T, int N> void Quicksort(T (&data)[N]);

		// This variant of the function sorts a 2D array according to [i][index]
		// where 'i' iterates through the array, and 'index' is constant.
		// When elements are arranged, all the other elements in that first dimensional index are
		// brought along with it.
	template<typename T, int N1, int N2> void Quicksort(T (&data)[N1][N2], int sortIndex);

private:
		// This function sorts elements within the specified bounds.
		// Recurring this function is part of the quicksort algorithm.
	template<typename T, int N> void sort(T (&data)[N], int leftIndex, int rightIndex);
	template<typename T, int N1, int N2> void sort(T (&data)[N1][N2], int leftIndex, int rightIndex, int sortIndex);
	
		// This function is used by the quicksort algorithm to find the splitpoint.
	template<typename T, int N> int split(T (&data)[N], int leftIndex, int rightIndex);
	template<typename T, int N1, int N2> int split(T (&data)[N1][N2], int leftIndex, int rightIndex, int sortIndex);
} sorting;

	// Templated functions have to be defined in the header because they cannot be compiled.

template<typename T, int N> void Sorting::Quicksort(T (&data)[N])
{
	if (N > 1)
		sort(data, 0, N-1);
}

template<typename T, int N1, int N2> void Sorting::Quicksort(T (&data)[N1][N2], int sortIndex)
{
	if (N1 > 1)
		sort(data, 0, N1-1, sortIndex);
}

template<typename T, int N> void Sorting::sort(T (&data)[N], int leftIndex, int rightIndex)
{
	if (rightIndex > leftIndex)
	{
		int splitPoint = split(data, leftIndex, rightIndex);
		sort(data, leftIndex, splitPoint - 1);
		sort(data, splitPoint + 1, rightIndex);
	}
}

template<typename T, int N1, int N2> void Sorting::sort(T (&data)[N1][N2], int leftIndex, int rightIndex, int sortIndex)
{
	if (rightIndex > leftIndex)
	{
		int splitPoint = split(data, leftIndex, rightIndex, sortIndex);
		sort(data, leftIndex, splitPoint - 1, sortIndex);
		sort(data, splitPoint + 1, rightIndex, sortIndex);
	}
}

template<typename T, int N> int Sorting::split(T (&data)[N], int leftIndex, int rightIndex)
{
	T pivot = data[rightIndex];

	while (leftIndex < rightIndex)
	{
		while (data[leftIndex] < pivot)
			leftIndex++;
		while (data[rightIndex] > pivot)
			rightIndex--;
		if (data[leftIndex] == data[rightIndex])
			leftIndex++;
		else if (leftIndex < rightIndex)
		{
			T temp = *data[leftIndex];
			data[leftIndex] = data[rightIndex];
			data[rightIndex] = temp;
		}
	}
	return rightIndex;
}

template<typename T, int N1, int N2> int Sorting::split(T (&data)[N1][N2], int leftIndex, int rightIndex, int sortIndex)
{
	T pivot = data[rightIndex][sortIndex];

	while (leftIndex < rightIndex)
	{
		while (data[leftIndex][sortIndex] < pivot)
			leftIndex++;
		while (data[rightIndex][sortIndex] > pivot)
			rightIndex--;
		if (data[leftIndex][sortIndex] == data[rightIndex][sortIndex])
			leftIndex++;
		else if (leftIndex < rightIndex)
		{
			for (int i=0; i<N2; i++)
			{
				T temp = data[leftIndex][i];
				data[leftIndex][i] = data[rightIndex][i];
				data[rightIndex][i] = temp;
			}
		}
	}
	return rightIndex;
}
	// This makes sorting available outside the class
extern Sorting sorting;

#endif
