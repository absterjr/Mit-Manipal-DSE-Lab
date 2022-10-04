#include <stdio.h>
#include<stdlib.h>
//-------------------------------------------
//Name: Aryaman
//Reg. No: 200968048
//-------------------------------------------
int tavail[3];
int talloc[10][3];
int tmax[10][3];
int tneed[10][3];
int i,j;

void need_calc(int n, int max[][3], int alloc[][3], int need[][3])
{
        for(i=0;i<n;i++) for(j=0;j<3;j++) need[i][j] = max[i][j] - alloc[i][j];
}
int bank(int n)
{
        int F[10];
        for(i=0;i<10;i++) F[i]=0;
        int work[3];
        for(i=0;i<3;i++) work[i]=tavail[i];
        int flag, pflag=0, k;
        for(k=0;k<n;k++){
                for(i=0;i<n;i++){
                        if(F[i] == 0){
                                flag=0;
                                for(j=0;j<3;j++){
                                        if(tneed[i][j]>work[j])
                                                flag=1;
                                }
                                if(flag == 0 && F[i] == 0){
                                        for(j=0;j<3;j++)
                                                work[j]+=talloc[i][j];
                                        F[i]=1;
                                        pflag++;
                                }
                        }
                }
                if(pflag == n)
                        return 1;
        }
        return 0;
}
int request(int n, int pid, int req[3])
{
        for(i=0;i<3;i++)
                if(tneed[pid][i]<req[i] || tavail[i]<req[i])
                        return 0;
                else
                {
                        for(i=0;i<3;i++)
                        {
                                tavail[i] -= req[i];
                                talloc[pid][i] += req[i];
                                tneed[pid][i] -= req[i];
                        }
                        return bank(n);
                }
}
void display(int n, int avail[3], int alloc[][3], int max[][3], int need[][3])
{
        printf("Available: "); for(i=0;i<3;i++) printf("%d\t", avail[i]); printf("\n");
        printf("Allocated:\n");
        for(i=0;i<n;i++){for(j=0;j<3;j++){printf("%d ", alloc[i][j]);   } printf("\n"); }
        printf("Maximum:\n");
        for(i=0;i<n;i++){for(j=0;j<3;j++){printf("%d ", max[i][j]);     } printf("\n"); }
        printf("Need:\n");
        for(i=0;i<n;i++){for(j=0;j<3;j++){printf("%d ", need[i][j]);    } printf("\n"); }
}
int main()
{
        int max[10][3];
        int alloc[10][3];
        int need[10][3];
        int avail[3];
        int n;
        printf("Processes: \n");
        scanf("%d", &n);
        printf("Available Resources: \n");
        for(i=0;i<3;i++) scanf("%d", &avail[i]);
        for(i=0;i<3;i++) tavail[i] = avail[i];
        printf("Allocated Resources(A): \n");
        for(i=0;i<n;i++) scanf("%d", &(alloc[i][0]));
        printf("Allocated Resources(B): \n");
        for(i=0;i<n;i++) scanf("%d", &(alloc[i][1]));
        printf("Allocated Resources(C): \n");
        for(i=0;i<n;i++) scanf("%d", &(alloc[i][2]));
        for(i=0;i<n;i++) for(j=0;j<3;j++) talloc[i][j] = alloc[i][j];
        printf("Maximum Resources(A): \n");
        for(i=0;i<n;i++) scanf("%d", &(max[i][0]));
        printf("Maximum Resources(B): \n");
        for(i=0;i<n;i++) scanf("%d", &(max[i][1]));
        printf("Maximum Resources(C): \n");
        for(i=0;i<n;i++) scanf("%d", &(max[i][2]));
        for(i=0;i<n;i++) for(j=0;j<3;j++) tmax[i][j] = max[i][j];
        need_calc(n, max, alloc, need);
        for(i=0;i<n;i++) for(j=0;j<3;j++) tneed[i][j] = need[i][j];
        int flag;
        flag = bank(n);
        if(flag==1) printf("System Safe...\n");
        else printf("System Not Safe!!!!!\n");
        if(flag==1 )for(i=0;i<3;i++) tavail[i] = avail[i];
        else
                exit(0);
        int req1[] = {1, 0, 2};
        flag = request(n, 1, req1);
        if(flag==1) printf("Request A: Granted\n");
        else printf("Request A: Not Granted\n");
        if(flag==1)
        {
                for(i=0;i<3;i++)
                {
                        avail[i] -= req1[i];
                        alloc[1][i] += req1[i];
                        need[1][i] -= req1[i];
                }
        }
        for(i=0;i<3;i++)
        {
                tavail[i] = avail[i];
                talloc[1][i] = alloc[1][i];
                tneed[1][i] = need[1][i];
        }
        printf("Matrices:\n");
        display(n, avail, alloc, max, need);
        int req2[] = {3, 3, 0};
        flag = request(n, 4, req2);
        if(flag==1) printf("Request B: Granted\n");
        else printf("Request B: Not Granted\n");
        if(flag==1)
        {
                for(i=0;i<3;i++)
                {
                        avail[i] -= req1[i];
                        alloc[1][i] += req1[i];
                        need[1][i] -= req1[i];
                }
        }
        for(i=0;i<3;i++)
        {
                tavail[i] = avail[i];
                talloc[1][i] = alloc[1][i];
                tneed[1][i] = need[1][i];
        }
        int req3[] = {0, 2, 0};
        flag = request(n, 0, req3);
        if(flag==1) printf("Request C: Granted\n");
        else printf("Request C: Not Granted\n");
        if(flag==1)
        {
                for(i=0;i<3;i++)
                {
                        avail[i] -= req1[i];
                        alloc[1][i] += req1[i];
                        need[1][i] -= req1[i];
                }
        }
        for(i=0;i<3;i++)
        {
                tavail[i] = avail[i];
                talloc[1][i] = alloc[1][i];
                tneed[1][i] = need[1][i];
        }
        return 0;
}