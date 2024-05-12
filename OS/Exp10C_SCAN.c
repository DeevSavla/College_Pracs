#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define SIZE 8

void main(){
    int first_track,last_track,current,list[SIZE],distance=0;
    printf("Enter first track:");
    scanf("%d",&first_track);
    printf("Enter last track:");
    scanf("%d",&last_track);
    printf("Enter current head position:");
    scanf("%d",&current);
    printf("Enter list of tracks:\n");
    for(int i=0;i<SIZE-1;i++){
        printf("Enter list %d:",i+1);
        scanf("%d",&list[i]);
    }
    list[SIZE-1]=current;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(list[j]>list[j+1]){
                int temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
    printf("\nSCAN:\n");
    distance=distance+last_track-current;
    distance=distance+last_track-list[0];
    printf("Total overhead movement:%d",distance);
}
