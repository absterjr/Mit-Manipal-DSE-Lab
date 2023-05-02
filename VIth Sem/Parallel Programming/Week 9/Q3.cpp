#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    char str[100];
    int local_non_vowels = 0;
    int total_non_vowels = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter a string: ");
        fflush(stdout);
        fgets(str, sizeof(str), stdin);
        // Remove trailing newline
        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }
    }

    // Broadcast the string to all processes
    MPI_Bcast(str, sizeof(str), MPI_CHAR, 0, MPI_COMM_WORLD);

    // Calculate local non-vowels count
    int local_len = strlen(str) / size;
    int local_start = rank * local_len;
    int local_end = (rank == size - 1) ? strlen(str) : local_start + local_len;
    for (int i = local_start; i < local_end; i++) {
        if (!isalpha(str[i]) || !strchr("AEIOUaeiou", str[i])) {
            local_non_vowels++;
        }
    }

    // Reduce the local non-vowels count to root process
    MPI_Reduce(&local_non_vowels, &total_non_vowels, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Non-vowels found by each process: ");
        fflush(stdout);
        for (int i = 0; i < size; i++) {
            printf("%d ", i == 0 ? local_non_vowels : 0);
        }
        printf("\nTotal non-vowels: %d\n", total_non_vowels);
    }

    MPI_Finalize();
    return 0;
}
