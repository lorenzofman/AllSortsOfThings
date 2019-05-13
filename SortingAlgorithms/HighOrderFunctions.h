#pragma once
void Benchmark(void(*method) (int*, int), int* v, int n, std::string name);
bool IsSorted(int* v, int size);
void PrintArray(int* v, int n);