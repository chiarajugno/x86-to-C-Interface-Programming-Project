#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

extern void callAssembly(unsigned long long int n, double* x, double* y, double* sdot);

void initializeVectors(unsigned long long int n, double* x, double* y) {
    for (int i = 0; i < n; i++) {
        x[i] = 2.0;
        y[i] = 1.0;
    }
}

void callC(unsigned long long int n, double* x, double* y, double* sdot) {
    for (int i = 0; i < n; i++) {
        *sdot += x[i] * y[i];
    }
}

void computeTimeC(unsigned long long int n, double* x, double* y, double* sdot) {
    clock_t start, end;
    double time;
    double t_avg_c = 0.0;

    printf("------------ C Version ------------\n");

    for (int i = 0; i < 20; i++) {
        *sdot = 0.0;
        start = clock();
        callC(n, x, y, sdot);
        end = clock();
        time = (end - start) * 1000 / CLOCKS_PER_SEC;
        t_avg_c += time;
    }

    t_avg_c /= 20;

    printf("\nC dot product = %lf\n", *sdot);
    printf("Average Execution Time for C = %lf milliseconds\n", t_avg_c);
}


void computeTimeAssembly(unsigned long long int n, double* x, double* y, double* sdot) {
    clock_t start, end;
    double time;
    double t_avg_c = 0.0;

    printf("\n------------ Assembly Version ------------\n");

    for (int i = 0; i < 20; i++) {
        *sdot = 0.0;
        start = clock();
        callAssembly(n, x, y, sdot);
        end = clock();
        time = (end - start) * 1000 / CLOCKS_PER_SEC;
        t_avg_c += time;
    }

    t_avg_c /= 20;

    printf("\nAssembly dot product = %lf\n", *sdot);
    printf("Average Execution Time for Assembly = %lf milliseconds\n\n", t_avg_c);
}

int checkCorrectness(double cDotProduct, double assemblyDotProduct) {
    if (cDotProduct == assemblyDotProduct) { 
        return 1;
    }
    else {
        return -1;
    }
}


int main() {
    unsigned long long int nSizes[] = { (1 << 20), (1 << 24), (1 << 27) };
    int exponents[] = { 20, 24, 27 };

    double* x;
    double* y;
    double cDotProduct, assemblyDotProduct;

    for (int i = 0; i < 3; i++) {
        unsigned long long int bytes = nSizes[i] * sizeof(double);

        x = (double*)malloc(bytes);
        y = (double*)malloc(bytes);

        printf("\n[ Vector size: 2^%d ]\n\n", exponents[i]);

        initializeVectors(nSizes[i], x, y);     // initialize vector values

        cDotProduct = 0.0;
        computeTimeC(nSizes[i], x, y, &cDotProduct);    // get C dot product and average execution time

        assemblyDotProduct = 0.0;
        computeTimeAssembly(nSizes[i], x, y, &assemblyDotProduct); // get assembly dot product and average execution time

        int correctness = checkCorrectness(cDotProduct, assemblyDotProduct);    // check if answers are the same
        printf("Correctness: ");
        if (correctness == 1) {
            printf("Answers are the same.\n\n");
        }
        else {
            printf("Answers are different.\n\n");
        }

        free(x);
        free(y);
    }

    return 0;
}
