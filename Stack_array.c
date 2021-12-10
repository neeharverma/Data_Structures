#include<stdio.h>
#define max 10
int stack[max],top=-1;

void push(){
    int n;
    printf("Enter data:");
    scanf("%d",&n);
    if(top==max-1)
        printf("overflow\n");
    else{
        top=top+1;
        stack[top]=n;
    }
}

void pop(){
    int val;
    if(top==-1)
        printf("underflow\n");
    else{
        val=stack[top];
        top=top-1;
        printf("The popped element is %d\n", val);
    }
}

void peak(){
    if(top==-1)
        printf("Stack is empty");
    else
        printf("Top element is %d\n",stack[top]);
}

void display(){
    int i;
    printf("\n__________________________________________________________\n");
    if(top==-1)
        printf("Stack is empty");
    else{
        printf("Stack:\n");
        for(i=0;i<=top;i++){
            printf("%d\t",stack[i]);
        }
    }
    printf("\n__________________________________________________________\n");
}

int main(){
    int menu;
    while(menu!=5){
        printf("Enter: 1.Push  2.Pop  3.Peak  4.View  5.Exit\n");
        scanf("%d", &menu);
        if(menu == 1)
            push();
        if(menu == 2)
            pop();
        if(menu == 3)
            peak();
        if(menu == 4)
            display();
        }
    display();
    printf("Program terminated.");
    return 0;
}
