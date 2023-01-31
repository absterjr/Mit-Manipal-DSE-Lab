#include<iostream>
#include<math.h>
#include <sys/time.h>
using namespace std;
int main()
{
int c[3];
int a[5][5],n,m,i,j;
cout<<"Enter MxN:\n";
cin>>m>>n;
cout<<"\nEnter Matrix Elements \n";
for(i=0;i<m;++i)
for(j=0;j<n;++j)
cin>>a[i][j];
cout<<"\nThe Matrix is:\n";
for(i=0;i<m;++i)
{
for(j=0;j<n;++j)
cout<<a[i][j]<<" ";
cout<<"\n";
}
int b[3];
cout<<"\nEnter Vector Elements: \n";
for(i=0; i<3;i++){
	cin>>b[i];
}
// Start Measuring Time
	struct timeval begin, end;
	gettimeofday(&begin, 0);

    for (int i=0;i<3;i++)
    {
         c[i]=0;
    }
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            c[i]+=(a[i][j]*b[j]);
        }
    }
    cout<<"\nOutput: \n";
    for (int i=0;i<3;i++){
        cout<<c[i]<<"  "<<endl;
    }
// Stop Measuring Time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    printf("\n Time measured: %.3f seconds.\n", elapsed);
    return 0;

}
