#include <stdio.h>
#include<stdlib.h>
//-----------------------------------------
//Name: Aryaman
//Reg. No: 200968048
//-----------------------------------------

int i, j;
int avail[3];
int alloc[10][3];
int req[10][3];
int n;

void display()
{
        printf("Available: "); for(i=0;i<3;i++) printf("%d\t", avail[i]); printf("\n");
        printf("Allocated:\n");
        for(i=0;i<n;i++){for(j=0;j<3;j++){printf("%d ", alloc[i][j]);   } printf("\n"); }
        printf("Request:\n");
        for(i=0;i<n;i++){for(j=0;j<3;j++){printf("%d ", req[i][j]);     } printf("\n"); }
}

int detect_deadlock(int n)
{
        int work[3];
        for(i=0;i<3;i++) work[i] = avail[i];

        int mark[10];
        for(i=0;i<n;i++) mark[i] = 0;

        for(i=0;i<n;i++)
        {
                int count=0;
                for(j=0;j<3;j++)
            {
              if(alloc[i][j]==0)
                count++;
              else
                break;
            }
                if(count==3)
                mark[i]=1;
        }

        int canbeprocessed = 0, k;
        for(k=0;k<n;k++)
        {
                for(i=0;i<n;i++)
                {
                        canbeprocessed=0;
                        if(mark[i]!=1)
                        {
                                for(j=0;j<3;j++)
                        {
                                if(req[i][j]<=work[j])
                                        canbeprocessed=1;
                                else
                                {
                                        canbeprocessed=0;
                                        break;
                                }
                        }
                                if(canbeprocessed==1)
                                {
                                        mark[i]=1;

                                        for(j=0;j<3;j++)
                                                work[j]+=alloc[i][j];
                                }
                        }
                }
        }

        int deadlock=0;
        for(i=0;i<n;i++)
                if(mark[i]!=1)
                        deadlock=1;

        return deadlock;
}

void main()
{

        printf("Processes: \n");
    scanf("%d", &n);

    printf("Available: \n");
    for(i=0;i<3;i++) scanf("%d", &avail[i]);

    printf("Allocated(A): \n");
    for(i=0;i<n;i++) scanf("%d", &(alloc[i][0]));
    printf("Allocated(B): \n");
    for(i=0;i<n;i++) scanf("%d", &(alloc[i][1]));
    printf("Allocated(C): \n");
    for(i=0;i<n;i++) scanf("%d", &(alloc[i][2]));

    printf("Requested(A): \n");
    for(i=0;i<n;i++) scanf("%d", &(req[i][0]));
    printf("Requested(B): \n");
    for(i=0;i<n;i++) scanf("%d", &(req[i][1]));
    printf("Requested(C): \n");
    for(i=0;i<n;i++) scanf("%d", &(req[i][2]));

    int flag;

    printf("Initially:\n");
    flag = detect_deadlock(n);
    if(flag==1) {printf("System: No Safe!\n"); }
    else printf("System: Safe\n");

    printf("Requesting one additional Type C Resource for Process 2.\n");
    req[2][2] += 1;
    flag = detect_deadlock(n);
    if(flag==1) {printf("System: Not Safe!\n"); exit(0);}
    else printf("System: Safe\n");
}