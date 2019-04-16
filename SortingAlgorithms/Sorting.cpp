#include "Sorting.h"
#pragma region Common

void Swap(int *a, int *b) 
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

#pragma endregion

#pragma region QuickSort

int Partition(int * v, int lo, int hi) 
{
	int key = v[(lo + hi) / 2];
	do 
	{
		while (v[lo] < key) lo++;
		while (v[hi] > key) hi--;
		if (lo <= hi) {
			Swap(&v[lo], &v[hi]);
			lo++; hi--;
		}
	} while (lo <= hi);
	return lo;
}

void QuickSort(int * v, int lo, int hi)
{
	if (lo >= hi)
		return;
	int pivotIdx = Partition(v, lo, hi);
	QuickSort(v, lo , pivotIdx - 1);
	QuickSort(v, pivotIdx + 1, hi);
}

void QuickSort(int * v, int size)
{
	QuickSort(v, 0, size-1);
}
#pragma endregion

#pragma region BubbleSort
void BubbleSort(int * v, int size)
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size - (i + 1); j++) 
		{
			if (v[j] > v[j + 1])
				Swap(&v[j], &v[j + 1]);
		}
	}
}
#pragma endregion

#pragma region RangeSort
void FindMinMax(int *p, int size, int*min, int*max) 
{
	*max = *min = *p;
	for (int i = 1; i < size; i++)
	{
		if (p[i] < *min) *min = p[i];
		if (p[i] > *max) *max = p[i];
	}
}
void RangeSort(int *p, int size)
{
	int min, max;
	FindMinMax(p,size,&min,&max);
	int *count = new int[max+1] {0};
	for (int i = 0; i < size; i++)
	{
		count[p[i]]++;
	}
	for (int i = 0, j = 0; i <= max; i++) 
	{
		while (count[i]-- > 0) 
		{
			p[j++] = i;
		}
	}
}
#pragma endregion
