#include<stdio.h>   
#include<stdlib.h>  

struct node{  
    int x;   
    struct node *to;  
};  
struct node *front;  
struct node *rear;   

void enQ(int data)  
{  
    struct node *ptr;  
    int item;   
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL){  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        ptr -> x = data;  
        if(front == NULL){  
            front = ptr;  
            rear = ptr;   
            front -> to = NULL;  
            rear -> to = NULL;  
        }  
        else{  
            rear -> to = ptr;  
            rear = ptr;  
            rear->to = NULL;  
        }  
    }  
}

void deQ ()  
{  
    struct node *ptr;  
    if(front == NULL){  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else{  
        ptr = front;  
        front = front -> to;  
        free(ptr);  
    }  
}

void display()  
{  
    struct node *ptr;  
    ptr = front;     
    printf("____________________________________________\n");
    if(front == NULL){  
        printf("\nEmpty queue\n");  
    }  
    else{ 
        printf("Queue:\n");  
        printf("Front <-");
        while(ptr != NULL){  
            printf(" %d ",ptr -> x);  
            ptr = ptr -> to;  
        }
        printf("<- Back");
    }
    printf("\n____________________________________________\n");
}  
 
void main ()  
{  
    int menu;  
    int d;
    while(menu!=4){
        printf("Enter: 1.Enqueue  2.Dequeue  3.View 4. Exit\n");
        scanf("%d", &menu);
        if(menu == 1){
            printf("Enter Data: ");
            scanf("%d", &d);
            enQ(d);
        }
        if(menu == 2)
            deQ();
        if(menu <= 3)
            display();        
    } 
    display();
    printf("Program terminated.");
}
