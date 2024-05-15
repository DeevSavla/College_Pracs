#include <stdio.h>
#define frame_size 3
#define page_size 14
int pages[page_size] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
int time[frame_size];
int frames[frame_size];

int found(int pageNumber)
{
    for (int i = 0; i < frame_size; i++)
    {
        if (frames[i] == pageNumber)
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    int miss = 0, hits = 0, count = 0;
    for (int i = 0; i < frame_size; i++)
    {
        frames[i] = -1;
        time[i] = -1;
    }
    for (int i = 0; i < page_size; i++)
    {
        int pagePosition = found(pages[i]);
        if (pagePosition == -1)
        {
            miss++;
            if (count < frame_size)
            {
                frames[count] = pages[i];
                time[count] = i;
                count++;
            }
            else
            {
                int lruIndex = 0;
                for (int j = 1; j < frame_size; j++)
                {
                    if (time[j] < time[lruIndex])
                    {
                        lruIndex = j;
                    }
                }
                frames[lruIndex] = pages[i];
                time[lruIndex] = i;
            }
        }
        else
        {
            time[pagePosition] = i;
        }
        for (int i = 0; i < frame_size; i++)
        {
            printf("%d ", frames[i]);
        }
        printf("\n");
    }
    printf("Hits:%d Miss:%d", (14 - miss), miss);
}
