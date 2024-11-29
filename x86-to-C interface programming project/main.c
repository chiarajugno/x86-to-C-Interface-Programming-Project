#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

// n -> rcx
// A -> address of rdx
// B -> address of r8
// sdot -> address of r9


extern void assemblyKernel(int n, double* A, double* B, double* sdot);


int main() {

	//int vectorSizes[] = {(1 << 20), (1 << 24), (1 << 30)};
	int n = 2;
	double A[] = {2.0, 1.0};
	double B[] = {2.0, 1.0};
	double sdot = 0.0;

	assemblyKernel(n, A, B, &sdot);

	printf("Assembly dot product = %lf", sdot);


	return 0;
}