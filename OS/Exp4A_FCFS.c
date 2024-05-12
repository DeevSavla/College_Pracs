#include<stdio.h>
# define SIZE 5
int AT[SIZE];
int BT[SIZE];
int process[SIZE];
int waiting[SIZE];

void main(){
    int temp,sum=0,total=0,t=0,k=0,wait=0;
    float AWT=0;
    float ATAT=0;
    for(int i=0;i<SIZE;i++){
        printf("Enter AT and BT of %d:",i+1);
        scanf("%d %d",&AT[i],&BT[i]);
        process[i]=i+1;
    }    
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(AT[j]>AT[j+1]){
                temp=AT[j];
                AT[j]=AT[j+1];
                AT[j+1]=temp;
                temp=BT[j];
                BT[j]=BT[j+1];
                BT[j+1]=temp;
                temp=process[j];
                process[j]=process[j+1];
                process[j+1]=temp;
            }
        }
    }
    waiting[0]=0;
    for(int i=1;i<SIZE;i++){
        k=0;
        wait=0;
        while(k<i){
            wait=wait+BT[k];
            k++;
        }
        wait=wait-AT[i];
        waiting[i]=wait;
    }
    for(int i=0;i<SIZE;i++){
        sum=sum+waiting[i];
    }
    AWT=(float)sum/SIZE;
    printf("\nAWT:%.2f",AWT);
    total=total+BT[0]-AT[0];
    for(int i=1;i<SIZE;i++){
        t=0;
        while(t<=i){
            total=total+BT[t];
            t++;
        }
        total=total-AT[i];
    }
    ATAT=(float)total/SIZE;
    printf("\nATAT:%.2f",ATAT);
}
