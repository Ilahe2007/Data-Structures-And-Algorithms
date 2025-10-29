#include<stdio.h>

int main(){
    int n = 5, 
    array[5] = {4, 2, 5 , 1 , 3}, min_index = 0, temp = 0;
    for(int i = 0 ; i < n - 1; i++){
        min_index = i;
        for(int j = i + 1; j < n; j++){
            if(array[j] < array[min_index]){
                temp = array[j];
                array[j] = array[min_index];
                array[min_index] = temp;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }
}