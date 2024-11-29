#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

extern void callAssembly(unsigned long long int n, double* x, double* y, double* sdot);

void callC(unsigned long long int n, double* x, double* y, double* sdot) {
	for (int i = 0; i < n; i++) {
		*sdot += x[i] * y[i];
	}
}

int main() {
	unsigned long long int n = 1 << 30;
	unsigned long long int bytes = n * sizeof(double);

	double* x; 
	double* y;
	double sdot = 0.0;

	x = (double*)malloc(bytes);
	y = (double*)malloc(bytes);

	// initialize
	for (int i = 0; i < n; i++) {
		x[i] = 2.0;
		y[i] = 1.0;
	}

	callC(n, x, y, &sdot);
	printf("answer is %lf\n", sdot);

	// reinitialize
	sdot = 0.0;
	for (int i = 0; i < n; i++) {
		x[i] = 2.0;
		y[i] = 1.0;
	}

	callAssembly(n, x, y, &sdot);
	printf("answer is %lf", sdot);

	return 0;
}