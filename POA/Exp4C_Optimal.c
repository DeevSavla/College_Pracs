#include <stdio.h>
#define frame_size 3
#define page_size 14
int pages[page_size] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
int frames[frame_size];
int future_reference[frame_size];

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
        future_reference[i] = -1;
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
                count++;
            }
            else
            {
                int farthest = -1;
                int replaceIndex = -1;
                for (int j = 0; j < frame_size; j++)
                {
                    int futureFound = 0;
                    for (int k = i + 1; k < page_size; k++)
                    {
                        if (frames[j] == pages[k])
                        {
                            future_reference[j] = k;
                            futureFound = 1;
                            break;
                        }
                    }
                    if (!futureFound)
                    {
                        future_reference[j] = 999;
                    }
                    if (future_reference[j] > farthest)
                    {
                        farthest = future_reference[j];
                        replaceIndex = j;
                    }
                }
                frames[replaceIndex] = pages[i];
            }
        }
        for (int i = 0; i < frame_size; i++)
        {
            printf("%d ", frames[i]);
        }
        printf("\n");
    }
    printf("Hits:%d Miss:%d", (14 - miss), miss);
}
