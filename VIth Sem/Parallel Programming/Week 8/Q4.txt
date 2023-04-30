
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int num_procs, rank;
    int value;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        // Root process reads the integer value
        value = 7;

        // Send the value to Process 1
        MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        // Receive the value from the last process
        MPI_Recv(&value, 1, MPI_INT, num_procs - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Final value received by the root process is: %d\n", value);

    }
    else {
        int received_value;
        MPI_Status status;

        // Receive the value from the previous process
        MPI_Recv(&received_value, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &status);

        // Increment the received value by one
        received_value++;

        // If the current process is not the last process, send the value to the next process
        if (rank != num_procs - 1) {
            printf("Process %d sends %d to the next process\n", rank, received_value);
            MPI_Send(&received_value, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        }
        else {
            // If the current process is the last process, send the value back to the root process
            MPI_Send(&received_value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
