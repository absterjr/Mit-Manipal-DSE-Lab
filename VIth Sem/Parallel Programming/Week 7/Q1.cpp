#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank, size;
    int x = 2;
    int result;

    // Initialize MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Get the total number of processes in the communicator
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Compute pow(x, rank) for the current process
    result = pow(x, rank);

    // Print the result for each process
    printf("Process %d: pow(%d, %d) = %d\n", rank, x, rank, result);

    // Finalize MPI environment
    MPI_Finalize();

    return 0;
}

