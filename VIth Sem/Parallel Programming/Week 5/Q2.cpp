#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10

int main() {
    int i, sum = 0;

    // Using parallel for with reduction
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < N; i++) {
        sum += i;
    }
    printf("Sum using parallel for with reduction: %d\n", sum);

    sum = 0;

    // Using critical section
    #pragma omp parallel shared(sum)
    {
        int local_sum = 0;
        #pragma omp for
        for (i = 0; i < N; i++) {
            local_sum += i;
        }
        #pragma omp critical
        {
            sum += local_sum;
        }
    }
    printf("Sum using critical section: %d\n", sum);

    sum = 0;

    // Using atomic
    #pragma omp parallel shared(sum)
    {
        int local_sum = 0;
        #pragma omp for
        for (i = 0; i < N; i++) {
            #pragma omp atomic
            sum += i;
        }
    }
    printf("Sum using atomic: %d\n", sum);

    sum = 0;

    // Using locks
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel shared(sum)
    {
        int local_sum = 0;
        #pragma omp for
        for (i = 0; i < N; i++) {
            local_sum += i;
        }
        omp_set_lock(&lock);
        sum += local_sum;
        omp_unset_lock(&lock);
    }
    omp_destroy_lock(&lock);
    printf("Sum using locks: %d\n", sum);

    sum = 0;

    // Using master
    #pragma omp parallel shared(sum)
    {
        #pragma omp master
        {
            printf("Running with %d threads\n", omp_get_num_threads());
        }
        int local_sum = 0;
        #pragma omp for
        for (i = 0; i < N; i++) {
            local_sum += i;
        }
        #pragma omp master
        {
            printf("Sum using master: %d\n", sum);
        }
        #pragma omp critical
        {
            sum += local_sum;
        }
    }

    return 0;
}

