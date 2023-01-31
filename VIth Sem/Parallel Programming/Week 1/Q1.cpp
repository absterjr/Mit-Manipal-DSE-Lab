#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

int reverse(int x)
{
    string str = to_string(x);
    reverse(str.begin(), str.end());
    return stoi(str);
}

int main()
{
    int sizeofarray = 9, a[9], i;
    cout << "Enter array elements:" << endl;
    for (i = 0; i < sizeofarray; ++i)
    {
        cin >> a[i];
    }

    // Start Measuring Time
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    for (i = 0; i < sizeofarray; ++i)
    {
        a[i] = reverse(a[i]);
    }

    cout << "Reversed array elements:" << endl;
    for (i = 0; i < sizeofarray; ++i)
    {
        cout << a[i] << " ";
    }

    // Stop Measuring Time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    printf("\n Time measured: %.3f seconds.\n", elapsed);

    return 0;
}
