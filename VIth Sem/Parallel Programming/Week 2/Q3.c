#include <stdio.h>
#include <omp.h> 
#define SIZE 10 
int main() {

#pragma omp parallel sections
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int even_sum = 0;
int odd_sum = 0;
   #pragma omp section
   {
	  for (int i = 0; i < 10; i++) {
		 if (arr[i] % 2 == 0) {
			even_sum += arr[i];
		 }
	  }
	  printf("Sum of even numbers: %d (thread %d)\n", even_sum, omp_get_thread_num());
   }
#pragma omp section
   {
	  for (int i = 0; i < 10; i++) {
		 if (arr[i] % 2 != 0) {
			odd_sum += arr[i];
		 }
	  }
	  printf("Sum of odd numbers: %d (thread %d)\n", odd_sum, omp_get_thread_num());
   }
}
return 0;
}