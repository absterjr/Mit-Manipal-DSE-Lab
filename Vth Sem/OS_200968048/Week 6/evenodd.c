#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
void *even(void *param)
{
int *arr = (int *)param;
int size = arr[0];
int sum = 0;
int i;
for ( i = 1; i <= size; i++)
if (arr[i] % 2 == 0)
sum += arr[i];
return (void*)sum;
}
void *odd(void *param)
{
int *arr = (int *)param;
int size = arr[0];
int sum = 0;
int i;
for ( i = 1; i <= size; i++)
if (arr[i] % 2 != 0)
sum += arr[i];
return (void*)sum;
}
int main()
{
int n, evenSum, oddSum;
printf("No. of Elements: \n");
scanf("%d", &n);
int arr[n + 1];
arr[0] = n;
printf("Elements:\n");
int i;
for (i = 1; i <= n; i++)
scanf("%d", &arr[i]);
pthread_t t1, t2;
pthread_create(&t1, 0, &even, (void *)arr);
pthread_create(&t2, 0, &odd, (void *)arr);
pthread_join(t1, (void *)&evenSum);
pthread_join(t2, (void *)&oddSum);
printf("EvenSum: %d\n", (int)evenSum);
printf("OddSum: %d\n", (int)oddSum);
}
