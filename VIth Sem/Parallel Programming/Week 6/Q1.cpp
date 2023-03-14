#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

void oddEvenSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) { // even phase
            #pragma omp parallel for shared(arr) private(j, temp)
            for (j = 2; j < n; j += 2) {
                if (arr[j] < arr[j-1]) {
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        } else { // odd phase
            #pragma omp parallel for shared(arr) private(j, temp)
            for (j = 1; j < n; j += 2) {
                if (arr[j] < arr[j-1]) {
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL)); // seed random number generator

    int n = 10; // change input size here

    int *arr = new int[n];

    // populate array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    double start = omp_get_wtime();

    oddEvenSort(arr, n);

    double end = omp_get_wtime();

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken: " << end - start << " seconds" << endl;

    delete[] arr;

    return 0;
}

