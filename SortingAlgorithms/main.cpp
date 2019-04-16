#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Sorting.h"
#include "HighOrderFunctions.h"

constexpr int NumberOfElements = 1000000;
constexpr int MaxValue = 10000;
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
void PrintArray(int *v, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		std::cout <<  v[i] << "\t";
	}
}
int main() 
{
	Start();
	int n;

	int *originalUnsortedArray = CreateRandomArray(&n);
	Benchmark(&CountSort, originalUnsortedArray, n, "RangeSort");
	Benchmark(&QuickSort, originalUnsortedArray, n, "QuickSort");
	Benchmark(&BubbleSort, originalUnsortedArray, n, "BubbleSort");
	system("pause");
}