#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int size, rank;
    char s1[100] = "SAHAJ", s2[100] = "sahaj", res[200], recv_res[200];
    int n, i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {

        n = strlen(s1);
        if (strlen(s2) != n) {
            printf("Error: Strings are not of equal length.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(s1, n, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Bcast(s2, n, MPI_CHAR, 0, MPI_COMM_WORLD);

    for (i = rank; i < n; i += size) {
        res[2 * i] = s1[i];
        res[2 * i + 1] = s2[i];
    }

    MPI_Allgather(res, 2 * n / size, MPI_CHAR, recv_res, 2 * n / size, MPI_CHAR, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Resultant string: %s\n", recv_res);
    }

    MPI_Finalize();
    return 0;
}
