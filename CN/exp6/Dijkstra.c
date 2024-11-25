#include<stdio.h>
#include<limits.h>
# define SIZE 5

int min(int distance[],int visited[])
{
    int min=INT_MAX;
    int minIndex;
    for(int i=0;i<SIZE;i++){
        if(visited[i]==0 && distance[i]<min){
            minIndex=i;
            min=distance[i];
        }
    }
    return minIndex;
}

void dijkstra(int weight[SIZE][SIZE])
{
    int visited[SIZE];
    int parent[SIZE];
    int distance[SIZE];

    for(int i=0;i<SIZE;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }

    distance[0]=0;
    parent[0]=-1;

    for(int i=0;i<SIZE;i++){
        int minIndex=min(distance,visited);
        visited[minIndex]=1;
        for(int j=0;j<SIZE;j++){
            if(weight[minIndex][j]!=0 && visited[j]==0 && distance[j]>distance[minIndex]+weight[minIndex][j]){
                distance[j]=distance[minIndex]+weight[minIndex][j];
                parent[j]=minIndex;
            }
        }
    }
    
    for (int i = 1; i < SIZE; i++){
        printf("Parent(%d) - Vertex(%d) \t%d \n", (parent[i]), i,distance[i]);
    }
}

void main()
{
    int weight[SIZE][SIZE]={    
        {0,4,7,9,8},
        {4,0,1,0,0},
        {7,1,0,2,0},
        {9,0,2,0,6},
        {8,0,0,6,0},
        };
    dijkstra(weight);
}