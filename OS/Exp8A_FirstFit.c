#include <stdio.h>

int process[5] = {1, 2, 3, 4,5};
int incoming[5] = {450,417,112,290,10};
int memory[5] = {125,500,200,300,600};
int remaining[5] = {125,500,200,300,600};
int visited[5] = {0};

void firstfit()
{
    printf("P\tIncoming\tMemory Block\n");
    for (int i = 0; i < 5; i++)
    {
        printf("P%d\t%d\t", process[i], incoming[i]);
        for(int j=0;j<5;j++)
        {
            if(incoming[i]<=remaining[j])
            {
                printf("%d",memory[j]);
                printf("\n");
                remaining[j]-=incoming[i];
                break;
            }
        }
    }
}

int main()
{
    firstfit();
    return 0;
}
