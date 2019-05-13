#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Sorting.h"
#include "HighOrderFunctions.h"

constexpr int NumberOfElements = 4000;
constexpr int MaxValue = 100000;
int *CreateRandomArray(int *size)
{
	*size = NumberOfElements;
	int *array = new int[*size];
	for (int i = 0; i < *size; i++) 
	{
		array[i] = rand() % MaxValue;
	}
	return array;
}

void Start() 
{
	srand(time(0));
}

int main() 
{
	Start();
	int n;
	int* originalUnsortedArray = CreateRandomArray(&n);
	Benchmark(&CountSort, originalUnsortedArray, n, "RangeSort");
	// Benchmark(&QuickSort, originalUnsortedArray, n, "QuickSort");
	Benchmark(&BubbleSort, originalUnsortedArray, n, "BubbleSort");
	Benchmark(&SelectionSort, originalUnsortedArray, n, "SelectionSort");
	Benchmark(&InsertionSort, originalUnsortedArray,n, "InsertionSort");
	Benchmark(&ShellSort, originalUnsortedArray,n, "ShellSort");
	scanf_s("x", 1);
}