#include <stdio.h>
#include <omp.h>

int main(void)
{
    printf("Before: No. of Threads: %d\n", omp_get_num_threads());

    #pragma omp parallel
    {
        printf("Thread ID: %d\n", omp_get_thread_num());
    }

    printf("After: No. of Threads: %d\n", omp_get_num_threads());

    return 0;
}