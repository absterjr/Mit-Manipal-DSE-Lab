#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void* generate_fibonacci(void* param)
{
int* arr=(int*) param;
arr[1]=0;
arr[2]=1;
int i;
for(i=3; i<=arr[0]; i++)
{
arr[i]=arr[i-1] + arr[i-2];
}
return NULL;
}
int main()
{
int n;
printf("No. of Fibonacci Terms:\n");
scanf("%d", &n);
int *arr;
arr=(int*)malloc((n+1)*sizeof(int));
arr[0]=n;
pthread_t thread;
pthread_create(&thread, 0, &generate_fibonacci, (void*)arr);
pthread_join(thread, 0);
printf("Fibonacci Series:\n");
int i;
for(i=1; i<=n; i++)
{
printf("%d  ",arr[i]);
}
printf("\n");
return 0;
}
