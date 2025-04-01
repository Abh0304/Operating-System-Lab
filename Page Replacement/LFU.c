#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct Seq 
{
    int data;
    int freq;
    int time;
};

struct Frame 
{
    int val;
    int freq;
    int time_st;
};

bool check(struct Frame frames[], int num, int page, int *index) 
{
    for (int i = 0; i < num; i++) 
    {
        if (frames[i].val == page) 
        {
            *index = i;
            return true;
        }
    }
    return false;
}

//multiple pages have same frequency
int find_LFU(struct Frame frames[], int num) 
{
    int min_freq = INT_MAX, min_time = INT_MAX;
    int replace_index = -1;
    
    for (int i = 0; i < num; i++) 
    {
        if (frames[i].freq < min_freq || 
            (frames[i].freq == min_freq && frames[i].time_st < min_time)) 
            {
            min_freq = frames[i].freq;
            min_time = frames[i].time_st;
            replace_index = i;
        }
    }
    return replace_index;
}

int main() 
{
    int page_hit = 0, page_fault = 0;
    int num;

    printf("Enter the number of frames: ");
    scanf("%d", &num);
    struct Frame frames[num];

    int pages;
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    struct Seq seq[pages];

    printf("Enter the page sequence:\n");
    for (int i = 0; i < pages; i++) 
    {
        scanf("%d", &seq[i].data);
        seq[i].freq = 0;
        seq[i].time = -1;
    }

    for (int i = 0; i < num; i++) 
    {
        frames[i].val = -1;
        frames[i].freq = 0;
        frames[i].time_st = -1;
    }

    int time_stamp = 0; 

    for (int i = 0; i < pages; i++) 
    {
        time_stamp++;
        int index;

        if (check(frames, num, seq[i].data, &index)) 
        {
            page_hit++;
            frames[index].freq++;
            frames[index].time_st = time_stamp;
        } 

        else 
        {
            page_fault++;
            bool inserted = false;
            for (int j = 0; j < num; j++) 
            {
                if (frames[j].val == -1) 
                {
                    frames[j].val = seq[i].data;
                    frames[j].freq = 1;
                    frames[j].time_st = time_stamp;
                    inserted = true;
                    break;
                }
            }

            if (!inserted) 
            {
                int replace_index = find_LFU(frames, num);
                frames[replace_index].val = seq[i].data;
                frames[replace_index].freq = 1;
                frames[replace_index].time_st = time_stamp;
            }
        }
    }

    printf("\nTotal Page Hits: %d\n", page_hit);
    printf("Total Page Faults: %d\n", page_fault);

    return 0;
}