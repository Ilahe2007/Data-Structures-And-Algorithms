#include<stdio.h>
#include<stdlib.h>

int main(){
    float *array1, *array2;
    int size;
    scanf("%d", &size);

    //allocate memory
    array1 = malloc(size * sizeof(float));
    array2 = calloc(size, sizeof(float));

    int size_array1 = sizeof(array1)/sizeof(array1[0]);
    int size_array2 = sizeof(array2)/sizeof(array2[0]);

    //print first dynamic array
    for(int i = 0; i < size_array1; i++){
        printf("%lf ", array1[i]);
    }

    printf("\n");
    
    //print second dynamic array
    for(int i = 0; i < size_array2; i++){
        printf("%lf ", array2[i]);
    }

    free(array1);
    return 0;
}