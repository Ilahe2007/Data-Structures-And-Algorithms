#include<stdio.h>
#include<stdbool.h>
int rear = -1, front = -1;

bool isfull(int size){
    bool full = false;
    if(rear == size - 1){
        full = true;
    }return full;
}

bool isempty(){
    bool empty = false;
    if(rear == -1 || front > rear){
        empty = true;
    }return empty;
}

void push(int queue[],int size, int element){

    if(front == -1){
        front = 0;
    }
    if(!isfull(size)){
        rear++;
        queue[rear] = element;
    }
}

int pop(int queue[]){
    int element = 0;
    if(!isempty()){
        element = queue[front];
        front++;
    }
    if(rear > front){
        front = -1;
    }
    return element;
}

int main(){
    int queue[5], size = 5;
    push(queue, 5, 3);
    push(queue, 5,43);
    push(queue, 5, 5);
    push(queue, 5, 76);
    push(queue, 5, 92);
    printf("enqueued elements: ");
    for(int i = 0 ; i < 5; i++){
        printf("%d ", queue[i]);
    }
    printf("\nDequed elements: ");
    printf("%d ", pop(queue));
    printf("%d ", pop(queue));
    printf("%d ", pop(queue));
    printf("%d ", pop(queue));
    printf("%d ", pop(queue));
}