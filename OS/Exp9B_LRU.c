#include <stdio.h>
#include <stdbool.h>

#define SIZE 3
int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
int numPages;

int isInFrame(int frame[], int pageNumber, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (frame[i] == pageNumber)
        {
            return i; 
        }
    }
    return -1; 
}

void lru()
{
    int frame[SIZE] = {0};    
    int usageInfo[SIZE] = {0}; 
    int count = 0;             
    int miss = 0;             

    for (int i = 0; i < numPages; i++)
    {
        int pagePosition = isInFrame(frame, pages[i], count);
        if (pagePosition == -1)
        {
            miss++;
            if (count < SIZE)
            {
                frame[count] = pages[i];
                usageInfo[count] = i; 
                count++;
            }
            else
            {
                int lruIndex = 0;
                for (int j = 1; j < SIZE; j++)
                {
                    if (usageInfo[j] < usageInfo[lruIndex])
                    {
                        lruIndex = j;
                    }
                }
                frame[lruIndex] = pages[i];
                usageInfo[lruIndex] = i;
            }
        }
        else
        { 
            usageInfo[pagePosition] = i;
        }
        for (int i = 0; i < count; i++)
        {
            printf("%d ", frame[i]);
        }
        printf("\n");
    }
    printf("Total page faults using LRU: %d\n", miss);
}

void main()
{
    numPages = sizeof(pages) / sizeof(pages[0]);
    lru();
}
