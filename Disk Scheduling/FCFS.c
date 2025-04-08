#include<stdlib.h>
#include<stdio.h>

int main()
{
    printf("FCFS Disk Scheduling\n");
    int arr[100];
    int n;
    printf("Enter the length\n");
    scanf("%d",&n);

    printf("Enter the sequence\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the initial head position\n");
    scanf("%d",&arr[0]);

    int result = 0;
    for(int i=0;i<n;i++)
    {
        result += abs(arr[i] - arr[i+1]);
        printf("Head moved from %d to %d\n",arr[i],arr[i+1]);
    }

    printf("Total seek time : %d",result);
    return 0;
}