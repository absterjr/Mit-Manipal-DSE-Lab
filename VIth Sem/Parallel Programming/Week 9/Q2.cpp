#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int size, rank, i, j, M = 6;
    int* data = NULL;
    int* recv_data = NULL;
    int recv_count;
    double avg, total_avg = 0.0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        data = (int*)malloc(size * M * sizeof(int));
        printf("Array:\n");
        for (i = 0; i < size * M; i++) {
            data[i] = rand() % 100;
            printf("%d\t", data[i]);
        }
    }

    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);

    recv_count = M;
    recv_data = (int*)malloc(recv_count * sizeof(int));

    MPI_Scatter(data, recv_count, MPI_INT, recv_data, recv_count, MPI_INT, 0, MPI_COMM_WORLD);

    avg = 0.0;
    for (i = 0; i < recv_count; i++) {
        avg += recv_data[i];
    }
    avg /= recv_count;

    MPI_Reduce(&avg, &total_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        total_avg /= (size * 1.0);
        printf("\nTotal average: %f\n", total_avg);
        free(data);
    }
    free(recv_data);

    MPI_Finalize();
    return 0;
}
