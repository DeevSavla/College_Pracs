#include<stdio.h>
int memory[5]={100,500,200,300,600};
int allocation[5];
int process[4];
int visited[5];

void main(){
    for(int i=0;i<5;i++){
        allocation[i]=0;
        visited[i]=0;
    }
    for(int i=0;i<4;i++){
        printf("Enter process %d:",i+1);
        scanf("%d",&process[i]);
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
        if(process[i]<=memory[j] && visited[j]==0){
            allocation[j]=process[i];
            visited[j]=1;
            break;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",memory[i]);
    }
    printf("\n");
        for(int i=0;i<5;i++){
        printf("%d ",allocation[i]);
    }
}
