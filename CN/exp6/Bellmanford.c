#include <stdio.h>
# define SIZE 5
int parent[SIZE];
int distance[SIZE];
int weight[SIZE][SIZE]={    
    {0,4,7,9,8},
    {4,0,1,0,0},
    {7,1,0,2,0},
    {9,0,2,0,6},
    {8,0,0,6,0},
};

void main() {

    for (int i = 1; i < SIZE; i++) {
        distance[i] = 999;
        parent[i] = -1;
    }
    
    distance[0] = 0;
    int k = 0;
    while (k < SIZE) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (weight[i][j] != 0) {
                    if (distance[j] > distance[i] + weight[i][j]) {
                        distance[j] = distance[i] + weight[i][j];
                        parent[j] = i;
                    }
                }
            }
        }
        k++;
    }
    
    // Check for negative cycle
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (weight[i][j] != 0) {
                if (distance[j] > distance[i] + weight[i][j]) {  
                //check if it can reduced more 
                //even after finding for all vertices it can still be reduced means that it is a negative cycle
                    printf("The graph has a negative cycle\n");  
                }
            }
        }
    }
    
    printf("The graph does not have a negative cycle\n");
    for (int i = 1; i < SIZE; i++) {
        printf("Vertex:%d Distance:%d Parent:%d\n", i,distance[i], parent[i]);
    }
}
