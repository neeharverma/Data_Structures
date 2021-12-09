#include <stdlib.h>
#include <stdio.h>

struct node{
	int x;
	struct node *to;
};

struct node* pop(struct node* top){
    struct node* temp;
    temp = top;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("%d popped from the stack\n", top->x);
        top = top->to;
        free(temp);
    }
    return top;
}

struct node* push(struct node* top,int data){
    struct node *new = malloc(sizeof(struct node));
    new->x = data;
    new->to = top;
    return new;
}

void printStack(struct node *top){
    printf("\n_____________________________________________________\n");
    printf("Stack... \n"); 
    while (top!= NULL) {
        printf("%d\n", top->x);
        top = top->to; 
    }
    printf("_____________________________________________________\n");
} 

int main() {
    int menu,d;
    struct node* top = NULL;
    while(menu!=4){
        printf("Enter: 1.Push  2.Pop  3.View 4. Exit\n");
        scanf("%d", &menu);
        if(menu == 1){
            printf("Enter Data: ");
            scanf("%d", &d);
            top = push(top, d);
        }
        if(menu == 2)
            top = pop(top);            
        if(menu == 3)
            printStack(top);        
    }
    printStack(top);
    return 0;
}
