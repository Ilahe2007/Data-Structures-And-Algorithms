#include<stdio.h>

int merge(int array[], int left, int right, int middle){
    int size1 = middle - left + 1, size2  = right - middle;
    int temp1[size1], temp2[size2];

    for(int i = 0 ; i < size1; i++){
        temp1[i] = array[left + i];
    }
    
    for(int i = 0; i < size2; i++){
        temp2[i] = array[middle + i + 1];
    }

    int i = 0, j = 0, c = left;

    while(i < size1 && j < size2){
        if(temp1[i] <= temp2[j]){
            array[c] = temp1[i];
            i++;
        }
        
        else{
            array[c] = temp2[j];
            j++;
        }
        c++;
    }

    while(i < size1){
        array[c] = temp1[i];
        i++;
        c++;
    }

    while(j < size2){
        array[c] = temp2[j];
        j++;
        c++;
    }
}

int merge_sort(int array[], int left, int right){
    if(left < right){   //this continues till the size of divided arrays are 1 or 2
        int middle = left + (right - left) / 2;
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        merge(array, left, right, middle);
    }
}

int main(){
    int array[5] = {5, 7, 3, 9, 4};
    merge_sort(array, 0, 4);
    for(int i = 0 ; i < 5; i++){
        printf("%d ", array[i]);
    }
}