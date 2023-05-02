#include <stdio.h>
#include <string.h>
#include <mpi.h>
#define MAX_STRING_LENGTH 100
void reverseString(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = (int)strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void toggleString(char* str) {
    int i;
    for (i = 0; i < (int)strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}
int main(int argc, char** argv) {
    int rank, size, i;
    char strings[3][MAX_STRING_LENGTH + 1], loc_strings[3][MAX_STRING_LENGTH + 1];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        printf("Enter three strings: ");
        fflush(stdout);
        for (int i = 0; i < 3; i++) {
            fgets(strings[i], MAX_STRING_LENGTH, stdin);
            strings[i][(int)strlen(strings[i]) - 1] = '\0'; // remove newline character
        }
    }
    MPI_Scatter(strings, MAX_STRING_LENGTH + 1, MPI_CHAR, loc_strings, MAX_STRING_LENGTH + 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    for (i = 0; i < 3; i++) {
        reverseString(loc_strings[i]);
        toggleString(loc_strings[i]);
    }
    MPI_Gather(loc_strings, MAX_STRING_LENGTH + 1, MPI_CHAR, strings, MAX_STRING_LENGTH + 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Modified strings:\n");
        for (i = 0; i < 3; i++) {
            printf("%s\n", strings[i]);
        }
    }
    MPI_Finalize();
    return 0;
}
