#include<stdio.h>
#include<stdbool.h>
int top = -1;

bool isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(int n){
    if(top == n - 1){
        return true;
    }else{
        return false;
    }
}

void push(char stack[], int size, char data){
    if(!isFull(size)){
        top++;
        stack[top] = data;
    }else{
        printf("Stack is full");
    }
}

int pop(char stack[]){
    char data;
    if(!isEmpty()){
        data = stack[top];
        top--;
        return data;
    }else{
        printf("Stack is empty!");
    }
}

int peek(char stack[]){
    return stack[top];
}

void compare(char string[], char stack[], int size){
    bool equal = true;
    for(int i = 0 ; i <= size / 2; i++){
        if(string[i] != stack[i]){
            equal = false;
            break;
        }
    }if(equal){
        printf("They are a palindrom.");
    }else{
        printf("They are not a palindrom.");
    }
}

int main(){
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    char element, string1[size], stack[size], string[size + 1];
    printf("Enter the string: ");
    scanf("%s", string1);
    for(int i = 0; i < size; i++){
        push(stack, size, string1[i]);
    }

    for(int i = 0; i < size; i++){
        string[i] = pop(stack);
    }
    
    compare(string, stack, size);
}