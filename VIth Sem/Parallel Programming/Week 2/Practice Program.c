#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>
int main()
{
	clock_t start, end;
	double t_seq;

	start = clock();
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		printf("Hello World\n");
	}
	end = clock();
	t_seq = ((double)(end - start)) / CLOCKS_PER_SEC;



	double t_par;
	start = clock();
#pragma omp parallel num_threads(8) 
	{
		int id = omp_get_thread_num();
		int total_thread = omp_get_num_threads();
		int i = 0;
		for (i = id; i < 1000; i = i + total_thread)
		{
			printf("Hello World---%d: thread Id--%d\n", i, id);
		}

	}
	end = clock();
	t_par = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time taken for sequential execution:%f\n", t_seq);
	printf("Time taken for parallel execution:%f\n", t_par);

	double speed_up = 0;
	speed_up = (t_seq) / (t_par);
	printf("SpeedUp:%f\n", speed_up);

	double efficiency = 0;
	int num_threads = 8;
	efficiency = (speed_up) / (num_threads);
	printf("Efficiency:%f\n", efficiency);
	return 0;
}