#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define SIZE 7

void nearest(int list[],int current,int visited[],int *minDistance,int *minIndex ){
    for(int i=0;i<SIZE;i++){
        if (!visited[i]) {
            int distance = abs(list[i] - current);
            if (distance < *minDistance) {
                *minDistance = distance;
                *minIndex = i;
            }
        }
    }
}

void main(){
    int first_track,last_track,current,list[SIZE],distance=0;
    int visited[SIZE];
    for(int i=0;i<SIZE;i++){
        visited[i]=0;
    }
    printf("Enter first track:");
    scanf("%d",&first_track);
    printf("Enter last track:");
    scanf("%d",&last_track);
    printf("Enter current head position:");
    scanf("%d",&current);
    printf("Enter list of tracks:\n");
    for(int i=0;i<SIZE;i++){
        printf("Enter list %d:",i+1);
        scanf("%d",&list[i]);
    }
    printf("\nSSTF\n");
    printf("%d->",current);
    for(int i=0;i<SIZE;i++){
        int minDistance=999;
        int minIndex=-1;
        nearest(list,current,visited,&minDistance,&minIndex);
        distance=distance+abs(current-list[minIndex]);
        visited[minIndex]=1;
        current=list[minIndex];
        printf("%d->",current);
    }
    printf("\nTotal overhead movement:%d",distance);
}
