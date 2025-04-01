#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    int frames[num];
    int page_fault = 0, page_hit = 0;
    int len, index = 0; // Index to track oldest page

    printf("Enter the length of the page sequence: ");
    scanf("%d", &len);

    int seq[len];
    printf("Enter the page sequence: ");
    for (int i = 0; i < len; i++) 
    {
        scanf("%d", &seq[i]);
    }

    for (int i = 0; i < num; i++) 
    {
        frames[i] = -1;
    }

    for (int i = 0; i < len; i++) 
    {
        if (check(frames, num, seq[i])) 
        {
            page_hit++;
        } 
        else 
        {
            page_fault++;
            frames[index] = seq[i]; 
            index = (index + 1) % num; 
        }

        printf("Frames: ");
        for (int j = 0; j < num; j++) 
        {
            if (frames[j] != -1) 
            {
                printf("%d ", frames[j]);
            } 
            else 
            {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Hits: %d\n", page_hit);
    printf("Total Page Faults: %d\n", page_fault);

    return 0;
}