#include <stdlib.h>
#include <stdio.h>

struct node{
	int x;
	struct node *to;
};

void printList(struct node *begin){
    int i = 0;
    printf("_____________________________________________________\n");
    printf("List... \n"); 
    while (begin!= NULL) {
        i++;
        printf("%d)  ", i);
        printf("%d\n", begin->x);
        begin = begin->to; 
    }
    printf("_____________________________________________________\n");
}

struct node* insert(struct node* list,int data){
    struct node *next;
    next = list;
    struct node *new = malloc(sizeof(struct node));
    new->x = data;
    new->to = NULL;
    next->to = new;
    return new;
}

void delete(struct node *begin, int loc){
    int i = 2;
    struct node* parser = begin;
    while (1) {
        if(loc == 1){
            free(parser);
            break;
        }
        parser = parser->to;
        if(i == loc){
            begin->to = parser->to;
            free(parser);
            break;
        }
        if(parser->to == NULL){
            printf("Invalid index\n");
            break;
        }
        begin = begin->to; 
        i++;
    }
}

void modify(struct node *begin, int loc){
    int i = 0;
    int newdata;
    while (1) {
        i++;
        if(i == loc){
            printf("Enter new data: ");
            scanf("%d", &newdata);
            begin->x = newdata; 
            break;
        }
        if(begin->to == NULL){
            printf("Invalid index\n");
            break;
        }
        begin = begin->to; 
    }
}

int main() {
    int d;
    int menu;
    struct node *SLL = malloc(sizeof(struct node));
    struct node *end;
    end = SLL;
    printf("Start Listing! (enter 's' to stop):\n");
    printf("_____________________________________________________\n");
    printf("Enter Data: ");
    scanf("%d", &d);
    SLL->x = d; 
    SLL->to = NULL;
    while(1){
        printf("Enter Data: ");
        scanf("%d", &d);
        if(getchar() == 's')
            break;
        end = insert(end, d);
    }
    printList(SLL);
    while(menu!=4){
        printf("Enter: 1.Insert  2.Delete  3.Modify  4.Exit\n");
        scanf("%d", &menu);
        if(menu == 1){
            printf("Enter Data: ");
            scanf("%d", &d);
            end = insert(end, d);
        }
        if(menu == 2){
            printf("Enter item index to be deleted: ");
            scanf("%d", &d);
            delete(SLL, d);            
        }
        if(menu == 3){
            printf("Enter item index to be modified: ");
            scanf("%d", &d);
            
            modify(SLL, d);            
        }
        printList(SLL);
    }
    printf("Program terminated.");
    return 0;
}
