#include <stdio.h>
#include <omp.h>
#include <ctype.h> 
#define SIZE 6 
int main() {

#pragma omp parallel for
	char arr[6] = { 'H', 'e', 'L', 'L', 'o', '\0' };
	printf("Input string: %s\n", arr);
for (int i = 0; i < 6 - 1; i++) {
#pragma omp critical
	{
		if (isalpha(arr[i])) {
			if (islower(arr[i])) {
				arr[i] = toupper(arr[i]);
			}
			else {
				arr[i] = tolower(arr[i]);
			}
			printf("Toggled character '%c' (thread %d)\n", arr[i], omp_get_thread_num());
		}
	}
}
printf("Output string: %s\n", arr);
return 0;
}