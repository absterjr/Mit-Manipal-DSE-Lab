#include <stdio.h>
#include <mpi.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main(int argc, char** argv) {
    int rank, size;
    int values[5];
    int local_factorial_result;
    int sum = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter 5 values: ");
        fflush(stdout);
        for (int i = 0; i < 5; i++) {
            scanf_s("%d", &values[i]);
        }
    }

    MPI_Bcast(values, 5, MPI_INT, 0, MPI_COMM_WORLD);

    local_factorial_result = factorial(values[rank]);

    MPI_Reduce(&local_factorial_result, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Factorial results: ");
        fflush(stdout);
        for (int i = 0; i < 5; i++) {
            printf("%d ", factorial(values[i]));
        }
        printf("\nSum of factorials: %d\n", sum);
    }

    MPI_Finalize();
    return 0;
}
