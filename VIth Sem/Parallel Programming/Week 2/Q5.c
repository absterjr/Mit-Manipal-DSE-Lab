#include <stdio.h>
#include <omp.h> 
#define SIZE 4 
int main() {

#pragma omp parallel for
int A[4] = { 1, 2, 3, 4 };
int B[4] = { 5, 6, 7, 8 };
int C[4];
for (int i = 0; i < 4; i++) {
	C[i] = A[i] + B[i];
	printf("%d + %d = %d (thread %d)\n", A[i], B[i], C[i], omp_get_thread_num());
}
#pragma omp parallel for
for (int i = 0; i < 4; i++) {
	C[i] = A[i] - B[i];
	printf("%d - %d = %d (thread %d)\n", A[i], B[i], C[i], omp_get_thread_num());
}
#pragma omp parallel for
for (int i = 0; i < 4; i++) {
	C[i] = A[i] * B[i];
	printf("%d * %d = %d (thread %d)\n", A[i], B[i], C[i], omp_get_thread_num());
} 
#pragma omp parallel for
for (int i = 0; i < 4; i++) {
	C[i] = A[i] / B[i];
	printf("%d / %d = %d (thread %d)\n", A[i], B[i], C[i], omp_get_thread_num());
} 
return 0;
}