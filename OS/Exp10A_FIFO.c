#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define SIZE 7

void main(){
    int first_track,last_track,current,list[SIZE],distance=0;
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
    printf("\nFCFS\n");
    printf("%d->%d->",current,list[0]);
    distance=abs(current-list[0]);
    for(int i=1;i<SIZE;i++){
        printf("%d->",list[i]);
        distance=distance+abs(list[i]-list[i-1]);
    }
    printf("\nTotal overhead movement:%d",distance);
}
