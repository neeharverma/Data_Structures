#include <stdlib.h>
#include <stdio.h>

struct node{
	int x;
	int y;
	int nonzero;
	struct node *next;
};

struct node* newnode(struct node *prev, int xcoord, int ycoord, int nonZ){
    //creating a new node that points to the previously created/predefined node
    struct node *new = malloc(sizeof(struct node));
    new->x = xcoord;
    new->y = ycoord;
    new->nonzero = nonZ;
    new->next = prev;
    return new;
}

void printNregen(struct node *begin){
    printf("Nonzero values in the sparse array:\n"); 
    int recreated[5][5] = {0};//creating a 5x5 matrix filled with zeroes
    while (begin!= NULL) {
        printf(" %d ", begin->nonzero);//printing the nonzero values stored in the list
        recreated[begin->x][begin->y]=begin->nonzero;
        //storing nonzero values at the appropriate locations
        begin = begin->next; 
    }
    
    printf("\n\nThe recreated array:\n"); 
    for(int i=0;i<5;i++){//printing the recreated matrix
        printf("["); 
        for(int j=0;j<5;j++){
            printf(" %d ", recreated[i][j]); 
        }
        printf("]\n"); 
    }
}
int main() {
    struct node *final = malloc(sizeof(struct node));//last node in the list(NULL pointer)
    struct node *penultimate;//a temporary node which keeps updating to create new nodes
    penultimate = final;//starting condition
    int k=0;
    //initializing a sparse array 5x5 in this case
    int element[5][5] = {{0 , 0 , 4 , 0 , 0},
                         {0 , 0 , 0 , 0 , 3}, 
                         {0 , 2 , 0 , 0 , 1}, 
                         {0 , 0 , 5 , 0 , 0}, 
                         {0 , 7 , 0 , 9 , 0}}; 
                         
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(element[i][j]!=0){//finding nonzero elements
                k++;
                if(k==1){//first nonzero element to be stored in the final node
                    final->x = i;
                    final->y = j;
                    final->nonzero = element[i][j];
                    final->next = NULL;
                }
                else{//subsequent nonzero elements stored in new nodes
                    penultimate = newnode(penultimate,i,j,element[i][j]);
                    //the function returns a 'struct node*' which is stored as the new penultimate node
                }
            }
        }
    } 
    //penultimate is now the first node
    printNregen(penultimate);//method to regenerate and print the matrix 
    return 0;
}
