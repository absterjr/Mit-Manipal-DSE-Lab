#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_BINS 10
#define BIN_WIDTH 10

int main()
{
    int A[1000]; // Assume A has 1000 elements
    int histogram[NUM_BINS] = {0}; // Initialize histogram bins to 0
    int i, bin;

    // Populate array A with random integers between 0 and 99
    #pragma omp parallel for
    for (i = 0; i < 1000; i++) {
        A[i] = rand() % 100;
    }

    // Compute the histogram using OpenMP
    #pragma omp parallel for private(bin)
    for (i = 0; i < 1000; i++) {
        bin = A[i] / BIN_WIDTH; // Determine which bin the value belongs to
        #pragma omp atomic
        histogram[bin]++; // Increment the corresponding bin count atomically
    }

    // Print the histogram
    for (bin = 0; bin < NUM_BINS; bin++) {
        printf("[%2d-%2d]: %d\n", bin*BIN_WIDTH, (bin+1)*BIN_WIDTH-1, histogram[bin]);
    }

    return 0;
}

