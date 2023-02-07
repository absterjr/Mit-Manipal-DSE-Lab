#include <stdio.h>
#include <omp.h>
#include <math.h> 
int main() {

#pragma omp parallel
{
		int i;
		printf("Enter an integer value of i: ");
		scanf_s("%d", &i);
   int x = omp_get_thread_num();
   double result = pow(i, x);
   printf("pow(%d, %d) = %lf (thread %d)\n", i, x, result, x);
}
return 0;
}