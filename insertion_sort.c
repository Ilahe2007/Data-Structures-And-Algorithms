#include<stdio.h>

int main(){
    int array[5] = {4,2,1,5,3};
    for(int i = 1; i < 5; i++){
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j = j - 1;
        }array[j + 1] = key;
    }
}