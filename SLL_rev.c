#include <stdlib.h>
#include <stdio.h>

struct node{
	int x;
	struct node *to;
};

void printList(struct node *begin){
    printf("List : "); 
    while (begin!= NULL) {
        printf("%d ", begin->x);
        begin = begin->to; 
    }
}

struct node* createList(int n){
    int data;
    struct node *head = malloc(sizeof(struct node));
    struct node *next;
    next = head;
    for(int i = 0; i<n; i++){
        printf("Enter data: ");
        scanf("%d",&data);
        if(i==0){
            head->x = data;
            head->to = NULL;
        }
        else{
            struct node *new = malloc(sizeof(struct node));
            new->x = data;
            new->to = NULL;
            next->to = new;
            next = new;
        }
    }
    return head;
}

struct node* revList(struct node* begin, int n){
    int data;
    struct node *final = malloc(sizeof(struct node));
    for(int i = 0; i<n; i++){
        if(i==0){
            final->x = begin->x;
            final->to = NULL;
        }
        else{
            struct node *new = malloc(sizeof(struct node));
            new->x = begin->x;
            new->to = final;
            final = new;   
        }
        begin = begin->to;
    }
    return final;
}

int main() {
    int n;
    printf("Enter # of nodes(Atleast 7): ");
    scanf("%d", &n);
    while(n<7){
       printf("Renter # of nodes: ");
       scanf("%d", &n); 
    }
    struct node* creation;
    creation = createList(n);//method to create list
    printList(creation);//method to print created list
    struct node* reverseReplica;
    reverseReplica = revList(creation,n);//method to replicate & reverse list
    printf("\nReversed ");
    printList(reverseReplica);
    return 0;
}
