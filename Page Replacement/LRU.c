#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 100
#define MAX_PAGES 1000

int findLRU(int time[], int n) 
{
    int min = time[0], pos = 0;
    for (int i = 1; i < n; ++i) 
    {
        if (time[i] < min) 
        {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

bool check(int frames[], int num, int page) 
{
    for (int i = 0; i < num; i++) 
    {
        if (frames[i] == page) 
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    int num;
    printf("Enter the number of frames: ");
    scanf("%d", &num);

    int frames[MAX_FRAMES], time[MAX_FRAMES];
    int page_fault = 0, page_hit = 0, counter = 0;
    int len;
    
    printf("Enter the length of the reference string: ");
    scanf("%d", &len);
    
    int pages[MAX_PAGES];
    printf("Enter the reference string: ");
    for (int i = 0; i < len; i++) 
    {
        scanf("%d", &pages[i]);
    }
    
    for (int i = 0; i < num; i++) 
    {
        frames[i] = -1;
    }
    
    for (int i = 0; i < len; i++) 
    {
        int page = pages[i];
        if (check(frames, num, page)) 
        {
            page_hit++;
            for (int j = 0; j < num; j++) 
            {
                if (frames[j] == page) 
                {
                    time[j] = counter;
                }
            }
        } 
        else 
        {
            page_fault++;
            int pos = findLRU(time, num);
            frames[pos] = page;
            time[pos] = counter;
        }
        counter++;
    }
    
    printf("Total Page Hits: %d\n", page_hit);
    printf("Total Page Faults: %d\n", page_fault);
    return 0;
}
