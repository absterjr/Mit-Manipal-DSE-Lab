
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int num_procs, rank, number;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        // Send a number to each of the slaves
        for (int i = 1; i < num_procs; i++) {
            number = i;
            MPI_Send(&number, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        // Receive the number from the master
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Process %d received number %d\n", rank, number);
    }

    MPI_Finalize();
    return 0;
}
