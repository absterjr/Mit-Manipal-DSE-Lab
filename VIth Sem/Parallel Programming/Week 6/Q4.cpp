#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

#define NUM_POINTS 100
#define NUM_THREADS 4

int main() {
    int i, count = 0;
    double x, y, pi, start_time, end_time;

    // Set the number of threads
    omp_set_num_threads(NUM_THREADS);

    // Seed the random number generator
    srand(time(NULL));

    // Sequential computation of p
    start_time = omp_get_wtime();
    for (i = 0; i < NUM_POINTS; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            count++;
        }
    }
    pi = 4.0 * count / NUM_POINTS;
    end_time = omp_get_wtime();
    printf("Sequential Pi = %f, Time taken = %f seconds\n", pi, end_time - start_time);

    // Parallel computation of p
    count = 0;
    start_time = omp_get_wtime();
    #pragma omp parallel for private(x, y) reduction(+:count)
    for (i = 0; i < NUM_POINTS; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            count++;
        }
    }
    pi = 4.0 * count / NUM_POINTS;
    end_time = omp_get_wtime();
    printf("Parallel Pi = %f, Time taken = %f seconds\n", pi, end_time - start_time);

    return 0;
}

