#include <time.h>
#include <chrono>
#include <string>
#include <iostream>
int *CopyArray(int*v, int n)
{
	int *v1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		v1[i] = v[i];
	}
	return v1;
}
void Benchmark(void (*method) (int*,int), int* v, int n, std::string name)
{
	int *copy = CopyArray(v, n);
	std::chrono::high_resolution_clock::time_point start(std::chrono::high_resolution_clock::now());
	(*method)(copy, n);
	double time = (std::chrono::high_resolution_clock::now() - start).count() / 1000000.0;
	std::cout << name << ":\t\t\t" << time << "ms\n";
	delete copy;
}