#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right){
    int pivot_index = right;
    int pivot = array[pivot_index];
    int stored_index = left;
    for(int i = left; i < right; i++){
        if(array[i] < pivot){
            swap(&array[i], &array[stored_index]);
            stored_index++;
        }
    }

    swap(&array[stored_index], &array[pivot_index]);
    
    return stored_index;
}

int quick_sort(int array[], int left, int right){
    if(left < right){
        int pivot_index = partition(array, left, right);
        quick_sort(array, left, pivot_index - 1);
        quick_sort(array, pivot_index + 1, right);
    }
}

int main(){
    int array[7] = {8, 89, 35, 105, 43, 7, 84};
    quick_sort(array, 0, 6);
    for(int i = 0; i < 7; i++){
        printf("%d ", array[i]);
    }
}