#include <iostream>
#include <string.h>
#include <sys/time.h>
using namespace std;
 
int main()
{
char str[100];
int i;
cout<<"Enter String: ";
gets(str);
// Start Measuring Time
struct timeval begin, end;
gettimeofday(&begin, 0);

for (i = 0; str[i]!='\0'; i++)
{
 if(str[i] >= 'A' && str[i] <= 'Z') { str[i] = str[i] + 32; } else if(str[i] >= 'a' && str[i] <= 'z')
 {
str[i] = str[i] - 32;
}			
}
cout<<"\nToggled string: "<<str<<endl;
  // Stop Measuring Time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    printf("\n Time measured: %.3f seconds.\n", elapsed);
return 0;
}
