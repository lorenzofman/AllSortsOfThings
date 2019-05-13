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
		while (v[lo] <= key) lo++;
		while (v[hi] >= key) hi--;
		if (lo < hi) {
			Swap(&v[lo], &v[hi]);
		}
	} while (lo < hi);
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

#pragma region CountSort
void FindMinMax(int *p, int size, int*min, int*max) 
{
	*max = *min = *p;
	for (int i = 1; i < size; i++)
	{
		if (p[i] < *min) *min = p[i];
		if (p[i] > *max) *max = p[i];
	}
}
void CountSort(int *p, int size)
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

#pragma region InsertionSort
void InsertionSort(int* v, int size)
{
	for (int i = 1; i < size; i++) 
	{
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && key < v[j]) 
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	}
}
#pragma endregion

#pragma region SelectionSort
int FindMax(int* v, int size) {
	int max = v[0];
	int idx = 0;
	for (int i = 1; i < size; i++) 
	{
		if (v[i] > max) 
		{
			max = v[i];
			idx = i;
		}
	}
	return idx;
}
void SelectionSort(int* v, int size)
{
	for (int i = 0; i < size; i++) 
	{
		int idx = FindMax(v, size-i);
		Swap(&v[idx], &v[size -(i + 1)]);
	}
}
#pragma endregion

#pragma region ShellSort
void ShellSort(int* v, int size)
{
	for (int range = size / 2; range > 0; range /= 2) 
	{
		for (int i = range; i < size; i++) 
		{
			int key = v[i];
			int j = i - range;
			while (j >= 0 && key < v[j]) 
			{
				v[j + range] = v[j];
				j -= range;
			}
			v[j + range] = key;
		}
	}
}
#pragma endregion
