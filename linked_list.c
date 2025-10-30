#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    struct node *head, *nodetemp, *temp;

    head = (struct node*) malloc(sizeof(struct node));
    if(head == NULL){
        printf("Memory allocation is not successfull.");
        exit(0);
    }else{
        int value;
        printf("Enter the values:\n");
        scanf("%d", &value);
        head -> data = value;
        head -> next = NULL;
        nodetemp = head;

        for(int i = 1; i < size; i++){
            scanf("%d", &value);
            temp = (struct node*) malloc(sizeof(struct node));
            
            if(temp == NULL){
                printf("Memory allocation not successfull");
                exit(0);
            }
            
            nodetemp -> next = temp;
            temp -> data = value;
            temp -> next = NULL;
            nodetemp = temp;
        }

        printf("\nThe linked list is: ");
        temp = head;
        int count = 0;
        while(temp != NULL){
            printf("%d ", temp -> data);
            temp = temp -> next;
            count++;
        }

        printf("\nThere is %d nodes", count);

        temp = head;
        while(temp != NULL){
            struct node *nextNode = temp -> next;
            free(temp);
            temp = nextNode;
        }

        return 0;
    }
}