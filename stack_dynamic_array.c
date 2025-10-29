#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int top = -1, size = 5;

bool isfull(){
    return top == size - 1;
}

int* push(int stack[], int element){
    if(isfull()){
        size++;
        stack = (int*) realloc(stack, sizeof(int) * size);
        if (stack == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    
    top++;
    stack[top] = element;
    return stack;
}

bool isempty(){
    return top == -1;
}

int pop(int stack[]){
    if(!isempty()){
        size--;
        top--;
        return stack[top];
    }
}

int main(){
    int *stack;
    stack = (int*) malloc(sizeof(int) * size);
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    push(stack,6);
    push(stack,7);
    push(stack,8);
    push(stack,9);
    push(stack,10);
    push(stack,11);
    for(int i = 0; i < size;i++){
        printf("%d ", stack[i]);
    }

    printf("\n");
    pop(stack);
    for(int i = 0; i < size;i++){
        printf("%d ", stack[i]);
    }
}