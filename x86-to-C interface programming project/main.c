#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

extern void callAssembly(unsigned long long int n, double* x, double* y, double* sdot);

void callC(unsigned long long int n, double* x, double* y, double* sdot) {
	for (int i = 0; i < n; i++) {
		*sdot += x[i] * y[i];
	}
}

void computeTimeC(unsigned long long int n, double* x, double* y) {
	clock_t start, end;
	double time;
	double t_avg_c = 0.0;
	double sdot;

	printf(" ---------------------- C ---------------------- \n");

	for (int i = 0; i < 20; i++) {
		sdot = 0.0;
		start = clock();
		callC(n, x, y, &sdot);
		end = clock();
		time = (end - start) * 1000 / CLOCKS_PER_SEC;
		t_avg_c += time;
		printf("Time Record #%d = %lf milliseconds\n", i, time);
	}

	t_avg_c /= 20;

	printf("Answer = %lf\n", sdot);
	printf("Average Time for C = %lf milliseconds\n", t_avg_c);
}

int main() {
	unsigned long long int n = 1 << 25;
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

	// insert C kernel here
	computeTimeC(n, x, y);

	// insert assembly kernel here
	
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