#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
int main(int argc, char** argv) {
    int rank, size, n = 5;
    double numbers[5], * loc_cubes, * cubes;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    loc_cubes = (double*)malloc(n * sizeof(double));
    cubes = (double*)malloc(n * size * sizeof(double));
    if (rank == 0) {
        printf("Enter 5 different numbers: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%lf", &numbers[i]);
        }
    }
    MPI_Bcast(numbers, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    for (int i = 0; i < n; i++) {
        loc_cubes[i] = pow(numbers[i], 3);
    }
    MPI_Gather(loc_cubes, n, MPI_DOUBLE, cubes, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Cubes of the given numbers:\n");
        for (int i = 0; i < n; i++) {
            printf("%.2lf ", cubes[i]);
        }
        printf("\n");
    }
    free(loc_cubes);
    free(cubes);
    MPI_Finalize();
    return 0;
}
