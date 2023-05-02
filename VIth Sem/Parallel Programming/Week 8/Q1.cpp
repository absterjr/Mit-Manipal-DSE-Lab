
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size, i, j;
    char *s1, *s2, *result, *local_result;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter the first string: ");
        fflush(stdout);
        char buffer1[1000];
        fgets(buffer1, 1000, stdin);
        s1 = (char*)malloc(strlen(buffer1) * sizeof(char));
        sscanf(buffer1, "%s", s1);

        printf("Enter the second string: ");
        fflush(stdout);
        char buffer2[1000];
        fgets(buffer2, 1000, stdin);
        s2 = (char*)malloc(strlen(buffer2) * sizeof(char));
        sscanf(buffer2, "%s", s2);
    }

    int len = strlen(s1);

    MPI_Bcast(&len, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int local_len = len / size;

    char* local_s1 = (char*)malloc((local_len + 1) * sizeof(char));
    char* local_s2 = (char*)malloc((local_len + 1) * sizeof(char));

    MPI_Scatter(s1, local_len, MPI_CHAR, local_s1, local_len, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(s2, local_len, MPI_CHAR, local_s2, local_len, MPI_CHAR, 0, MPI_COMM_WORLD);

    local_result = (char*)malloc((local_len + 1) * sizeof(char));

    for (i = 0, j = 0; i < local_len; i++, j++) {
        if (j % 2 == 0) {
            local_result[i] = local_s1[j];
        }
        else {
            local_result[i] = local_s2[j];
        }
    }

    MPI_Gather(local_result, local_len, MPI_CHAR, result, local_len, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        result[len] = '\0';
        printf("The resultant string: %s\n", result);
    }

    MPI_Finalize();

    return 0;
}
