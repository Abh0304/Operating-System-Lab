#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,max;
    printf("\n C-SCAN Disk Scheduling\n\n");
    printf("Enter the length\n");
    scanf("%d",&n);
    printf("Enter the max value\n");
    scanf("%d",&max); 

    n = n+2;
    int arr[n];
    
    printf("Enter the request\n");
    for(int i=2;i<n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
    arr[n-1] = max;

    int start = 0;
    printf("Enter the inital head position\n");
    scanf("%d",&start);
    arr[1] = start;
    arr[0] = 0;

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int indx = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == start)
        {
            indx = i;
            break;
        }
    }

    int x = n-1;
    int result = 0;
    while(x>0)
    {
        if(indx == n-1)
        {
            result += abs(arr[n-1] - arr[0]);
            printf("Head moved from %d to %d\n",arr[n-1],arr[0]);
        }
        else
        {
            result += abs(arr[indx] - arr[indx + 1]);
            printf("Head moved from %d to %d\n",arr[indx],arr[indx+1]);
        }
        indx = (indx+1) % n;
        x--;
    }
    printf("Total seek : %d",result);
    return 0;
}