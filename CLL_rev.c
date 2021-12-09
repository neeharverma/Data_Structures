#include <stdlib.h>
#include <stdio.h>

struct node{
	int x;
	struct node *to;
};

void printList(struct node *begin){
    printf("List : "); 
    struct node *temp;
    int i = 0;
    temp = begin;
    do{
        printf("%d ", begin->x);
        begin = begin->to; 
    }
    while (begin!=temp);
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
    next->to = head;
    return head;
}

struct node* revList(struct node* begin, int n){
    int data;
    struct node *final = malloc(sizeof(struct node));
    struct node *temp;
    temp = final;
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
    temp->to = final;
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

/* 
Changes made: 
The last node was made to point to the initial node to complete the cicular link.
The printList() function was changed to check when the list has been completely traversed, to avoid an infinite loop.

Advantages:
-The entire list can be traversed regardless of the starting node
-We can go around the list more than once without having to specifically rerun the list.

Disadvantages:
-More memory is required for the storage of the extra pointer
-If not accessed carefully we may get stuck in an infinite loop  

Due to the extra pointer in a CLL we can reach any node regardless of our starting node, unlike in a SLL. CLL uses less memory than a DLL. The reverseReplica() method used is the same as in SLL and CLL with the added final pointer. 
*/