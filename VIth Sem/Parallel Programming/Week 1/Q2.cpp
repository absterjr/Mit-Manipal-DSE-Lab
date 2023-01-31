# include <iostream>
#include <sys/time.h>
using namespace std;

int main() {
  float num1, num2;
  cout << "Enter Numbers: ";
  cin >> num1 >> num2;
// Start Measuring Time
    struct timeval begin, end;
    gettimeofday(&begin, 0);   
      cout << num1 << " + " << num2 << " = " << num1 + num2<<"\n";
      cout << num1 << " - " << num2 << " = " << num1 - num2<<"\n";
      cout << num1 << " * " << num2 << " = " << num1 * num2<<"\n";
      cout << num1 << " / " << num2 << " = " << num1 / num2<<"\n";
// Stop Measuring Time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    printf("\n Time measured: %.3f seconds.\n", elapsed);
  return 0;
}

