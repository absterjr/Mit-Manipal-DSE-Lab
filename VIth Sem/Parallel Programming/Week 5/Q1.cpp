#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int i, num_threads;
    double start_time, end_time;
    int *a = (int*) malloc(N * sizeof(int));
    int *b = (int*) malloc(N * sizeof(int));
    int *c = (int*) malloc(N * sizeof(int));
    int *d = (int*) malloc(N * sizeof(int));
    int *e = (int*) malloc(N * sizeof(int));

    // Initialize vectors
    for (i = 0; i < N; i++) {
        a[i] = i;
        b[i] = N - i;
    }

    // Serial addition
    start_time = omp_get_wtime();
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }
    end_time = omp_get_wtime();
    printf("Serial addition time: %f\n", end_time - start_time);

    // Parallel addition
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        d[i] = a[i] + b[i];
    }
    end_time = omp_get_wtime();
    printf("Parallel addition time: %f\n", end_time - start_time);

    // Serial subtraction
    start_time = omp_get_wtime();
    for (i = 0; i < N; i++) {
        e[i] = a[i] - b[i];
    }
    end_time = omp_get_wtime();
    printf("Serial subtraction time: %f\n", end_time - start_time);

    // Parallel subtraction
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        e[i] = a[i] - b[i];
    }
    end_time = omp_get_wtime();
    printf("Parallel subtraction time: %f\n", end_time - start_time);

    // Serial multiplication
    start_time = omp_get_wtime();
    for (i = 0; i < N; i++) {
        e[i] = a[i] * b[i];
    }
    end_time = omp_get_wtime();
    printf("Serial multiplication time: %f\n", end_time - start_time);

    // Parallel multiplication
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        e[i] = a[i] * b[i];
    }
    end_time = omp_get_wtime();
    printf("Parallel multiplication time: %f\n", end_time - start_time);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

    return 0;
}

