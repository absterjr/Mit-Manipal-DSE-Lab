#include <stdio.h>
#include <omp.h> 
long long fibonacci(int n) {
if (n <= 1) return n;
long long f0 = 0, f1 = 1, fn = 0;
for (int i = 2; i <= n; i++) {
	fn = f0 + f1;
	f0 = f1;
	f1 = fn;
}
return fn;
}
int main() {

#pragma omp parallel for
	int A[] = { 10, 13, 5, 6 };
	int n = sizeof(A) / sizeof(A[0]);
	for (int i = 0; i < n; i++) {
		long long fib = fibonacci(A[i]);
		printf("Fibonacci(%d) = %lld (thread %d)\n", A[i], fib, omp_get_thread_num());
	}
	return 0;
}