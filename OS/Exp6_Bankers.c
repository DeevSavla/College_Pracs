#include <stdio.h>

int allocation[4][3] = {
    {1, 0, 1},
    {2, 1, 2},
    {3, 0, 0},
    {1, 0, 1},
};

int max[4][3] = {
    {2, 1, 1},
    {5, 4, 4},
    {3, 1, 1},
    {1, 1, 1},
};

int visited[4] = {0};
int need[4][3];
int available[3] = {2,1,1};
int safesequence[4];

void main()
{
    int n, m, i, j, k;
    int f[n];
    for (i = 0; i < n; i++)
    {
        f[i] = 0;
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    int y = 0;
    int count=0;
    for (k = 0; k < 4; k++)
    {
        for (i = 0; i < 4; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                
                for (j = 0; j < 3; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safesequence[count++]=i;
                    for (y = 0; y < 3; y++){
                        available[y] += allocation[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (i = 0; i < 4; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }
    if (flag == 1)
    {
        printf("\n");
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < 4; i++){
            printf("%d ",safesequence[i]);
        }
    
    }
}
