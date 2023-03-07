#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10;
    long long fact = 1;

    // Critical section
    #pragma omp parallel shared(fact) num_threads(4)
    {
        int tid = omp_get_thread_num();
        int i;
        long long local_fact = 1;

        #pragma omp for
        for (i = 1; i <= n; i++) {
            local_fact *= i;
        }

        #pragma omp critical
        fact *= local_fact;

        printf("Thread %d: factorial of %d = %lld\n", tid, n, local_fact);
    }

    printf("Factorial using critical section: %lld\n", fact);

    // Atomic
    fact = 1;

    #pragma omp parallel shared(fact) num_threads(4)
    {
        int tid = omp_get_thread_num();
        int i;

        #pragma omp for
        for (i = 1; i <= n; i++) {
            #pragma omp atomic
            fact *= i;

            printf("Thread %d: factorial of %d = %lld\n", tid, i, fact);
        }
    }

    printf("Factorial using atomic: %lld\n", fact);

    // Reduction
    fact = 1;

    #pragma omp parallel for reduction(*:fact) num_threads(4)
    for (int i = 1; i <= n; i++) {
        fact *= i;

        printf("Thread %d: factorial of %d = %lld\n", omp_get_thread_num(), i, fact);
    }

    printf("Factorial using reduction: %lld\n", fact);

    // Master
    fact = 1;

    #pragma omp parallel shared(fact) num_threads(4)
    {
        int tid = omp_get_thread_num();
        int i;
        long long local_fact = 1;

        #pragma omp for
        for (i = 1; i <= n; i++) {
            local_fact *= i;
        }

        #pragma omp master
        {
            fact *= local_fact;
        }

        printf("Thread %d: factorial of %d = %lld\n", tid, n, local_fact);
    }

    printf("Factorial using master: %lld\n", fact);

    // Locks
    fact = 1;
    omp_lock_t lock;
    omp_init_lock(&lock);
    int i;

    #pragma omp parallel for private(i) num_threads(4)
    for (int i = 1; i <= n; i++) {
        long long local_fact = 1;

        for (int j = 1; j <= i; j++) {
            local_fact *= j;
        }

        omp_set_lock(&lock);
        fact *= local_fact;
        omp_unset_lock(&lock);

        printf("Thread %d: factorial of %d = %lld\n", omp_get_thread_num(), i, local_fact);
    }

    printf("Factorial using locks: %lld\n", fact);

    omp_destroy_lock(&lock);

    return 0;
}

