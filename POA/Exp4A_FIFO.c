#include <stdio.h>
#define frame_size 3
#define page_size 14
int pages[page_size] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
int frames[frame_size];

void main()
{
    int miss = 0, hits = 0, z = 0;
    for (int i = 0; i < frame_size; i++)
    {
        frames[i] = -1;
    }
    for (int i = 0; i < page_size; i++)
    {
        int pageFound = 0;
        for (int j = 0; j < frame_size; j++)
        {
            if (pages[i] == frames[j])
            {
                pageFound = 1;
                hits++;
                break;
            }
        }
        if (!pageFound)
        {
            miss++;
            frames[z] = pages[i];
            z = (z + 1) % frame_size;
        }
        for (int i = 0; i < frame_size; i++)
        {
            printf("%d ", frames[i]);
        }
        printf("\n");
    }
    printf("Hits:%d Miss:%d", hits, miss);
}
