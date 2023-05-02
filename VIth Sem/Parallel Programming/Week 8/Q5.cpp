
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    int i;
    int limit = sqrt(num);
    for (i = 2; i <= limit; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    int num_procs, rank;
    int N;
    int *arr = NULL;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        // Master process reads the size of the array
        printf("Enter the size of the array: ");
        scanf("%d", &N);

        // Allocate memory for the array
        arr = (int*)malloc(N * sizeof(int));

        // Read the array elements from the console
        int i;
        for (i = 0; i < N; i++) {
            printf("Enter element %d: ", i);
            scanf("%d", &arr[i]);
        }

        // Distribute the array elements to all processes
        MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(arr, N, MPI_INT, 0, MPI_COMM_WORLD);

    } else {
        // Receive the size of the array
        MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

        // Allocate memory for the array
        arr = (int*)malloc(N * sizeof(int));

        // Receive the array elements
        MPI_Bcast(arr, N, MPI_INT, 0, MPI_COMM_WORLD);
    }

    // Check if the received element is prime or not
    int i;
    for (i = 0; i < N; i++) {
        if (is_prime(arr[i])) {
            printf("Process %d: Element %d is prime\n", rank, arr[i]);
        } else {
            printf("Process %d: Element %d is not prime\n", rank, arr[i]);
        }
    }

    free(arr);

    MPI_Finalize();
    return 0;
}
