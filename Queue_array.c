#include<stdio.h>
#define max 10

int queue[max],front=-1,rear=-1;

void enQ(){
    int n;
    if(rear==max-1)
        printf("overflow\n");
    else{
        printf("Enter data:"); 
        scanf("%d",&n);
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else 
            rear=rear+1;
        queue[rear]=n;
    }
}

void deQ(){
    int d;
    if(front==-1|| front>rear)
        printf("underflow\n");
    else{
        d=queue[front];
        front=front+1;
        printf("The dequeued element is %d\n", d);
    }
}

void display(){
    printf("____________________________________________\n");
    if(front==-1 && rear==-1)
        printf("Queue is empty");
    else{
        printf("Queue:\n");
        printf("Front <-  ");
        for(int i=front;i<=rear;i++){
            printf("%d  ",queue[i]);
        }
        printf("<- Back");
    }
    printf("\n____________________________________________\n");
}

int main()
{
    int menu;
    while(menu!=4){
        printf("Enter: 1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d", &menu);
        if(menu == 1)
            enQ();
        if(menu == 2)
            deQ();
        if(menu == 3)
            display();
    }
    display();
    printf("Program Terminated.");
    return 0;
}
