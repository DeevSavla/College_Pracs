#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define max_frames 3
int numPages; 
int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};

bool isInFrame(int frame[], int pageNumber)
{
    for (int i = 0; i < max_frames; i++)
    {
        if (frame[i] == pageNumber)
        {
            return true;
        }
    }
    return false;
}

void optimal()
{
    int frame[max_frames]; 
    int futureReference[max_frames] = {0}; 
    int frameCount = 0;                                       
    int hits = 0;      
    int miss=0; 
    for (int i = 0; i < max_frames; i++)
    {
        frame[i] = -1; 
    }                  
    for (int i = 0; i < numPages; i++)
    {
        if (!isInFrame(frame, pages[i]))
        {
            miss++;
            if (frameCount < max_frames)
            {
                frame[frameCount] = pages[i];
                frameCount++;
            }
            else
            { 
                int farthest = -1;
                int replaceIndex = -1;
                for (int j = 0; j < max_frames; j++)
                {
                    bool found = false;
                    for (int k = i + 1; k < numPages; k++)
                    {
                        if (frame[j] == pages[k])
                        {
                            futureReference[j] = k;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        futureReference[j] = INT_MAX;
                    }
                    if (futureReference[j] > farthest)
                    {
                        farthest = futureReference[j];
                        replaceIndex = j;
                    }
                }
                frame[replaceIndex] = pages[i];
            }
        }
        else
        {
            hits++;
        }
        for (int i = 0; i < frameCount; i++)
        {
            printf("%d ", frame[i]);
        }
        printf("\n");
    }
    printf("Hits: %d  Miss:%d\n", hits,miss);
}

void main()
{
    numPages = sizeof(pages) / sizeof(pages[0]);
    optimal();
}
