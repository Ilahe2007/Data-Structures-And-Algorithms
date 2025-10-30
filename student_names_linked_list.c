#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char name[50];
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
        char value[50];
        printf("Enter the names:\n");
        scanf("%s", value);
        strcpy(head -> name, value);
        head -> next = NULL;
        nodetemp = head;

        for(int i = 1; i < size; i++){
            scanf("%s", value);
            temp = (struct node*) malloc(sizeof(struct node));
            
            if(temp == NULL){
                printf("Memory allocation not successfull");
                exit(0);
            }
            
            nodetemp -> next = temp;
            strcpy(temp -> name, value);
            temp -> next = NULL;
            nodetemp = temp;
        }

        printf("\nThe linked list is: ");
        temp = head;
        int count = 0;
        while(temp != NULL){
            printf("%s ", temp -> name);
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