#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, max;
    printf("\nSCAN Disk Scheduling\n\n");
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the maximum disk value: ");
    scanf("%d", &max); 

    n = n + 1;  
    int arr[n];

    printf("Enter the disk requests: ");
    for (int i = 1; i < n-1; i++) 
    {
        scanf("%d", &arr[i]);
    }

    arr[n-1] = max;
    int start;
    printf("Enter the initial head position: ");
    scanf("%d", &start);
    arr[0] = start;

   
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
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == start)
        {
            indx = i;
            break;
        }
    }

    int result = 0;
    printf("\nHead Movement:\n");

    
    for (int i = indx; i < n - 1; i++)
    {
        printf("Head moved from %d to %d\n", arr[i], arr[i + 1]);
        result += abs(arr[i] - arr[i + 1]);
    }

    
    for (int i = n - 1; i > 0; i--)
    {
        printf("Head moved from %d to %d\n", arr[i], arr[i - 1]);
        result += abs(arr[i] - arr[i - 1]);
    }

    printf("\nTotal Seek Time: %d\n", result);
    return 0;
}