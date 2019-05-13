#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Sorting.h"
#include "HighOrderFunctions.h"

constexpr int NumberOfElements = 100000;
int *CreateShuffledArray(int *size)
{
	*size = NumberOfElements;
	int *array = new int[*size];
	for (int i = 0; i < *size; i++) 
	{
		array[i] = i;
	}
	for (int i = 0; i < *size; i++) 
	{
		int temp = array[i];
		int randomIndex = rand() % *size;
		array[i] = array[randomIndex];
		array[randomIndex] = temp;
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
	int* originalUnsortedArray = CreateShuffledArray(&n);
	Benchmark(&CountSort, originalUnsortedArray, n, "RangeSort");
	Benchmark(&QuickSort, originalUnsortedArray, n, "QuickSort");
	Benchmark(&BubbleSort, originalUnsortedArray, n, "BubbleSort");
	Benchmark(&SelectionSort, originalUnsortedArray, n, "SelectionSort");
	Benchmark(&InsertionSort, originalUnsortedArray,n, "InsertionSort");
	Benchmark(&ShellSort, originalUnsortedArray,n, "ShellSort");
	Benchmark(&HeapSort, originalUnsortedArray, n, "HeapSort");
	printf("Press any key to exit\n");
	scanf_s("x", 1);
}