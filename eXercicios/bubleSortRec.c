#include<stdio.h>
#include<stdlib.h>

void swap(int *vector, int *vector_2);
void bubleSort(int *vector, int size);
void printAnArray(int *vector, int size);

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = n;
    //printf("%d", n);
    bubleSort(arr, n);
    printAnArray(arr, m);
    return 0;
}

void swap(int *vector, int *vector_2){
    int aux = *vector;
    *vector = *vector_2;
    *vector_2 = aux;
}

void bubleSort(int *vector, int size){
    if(size == 1)
        return;

    for(int j = 0; j < size; j++){
        if(vector[j]>vector[j+1]){
            swap(&vector[j], &vector[j+1]);
        }
    }
    bubleSort(vector, size-1);
}

void printAnArray(int *vector, int size){
    for(int l = 0; l < size; l++){
        printf("%d ", vector[l]);
        /*if(l+1 < size)
            printf("%d ", vector[l]);
        else{
            printf("%d\n", vector[l]);
        }*/
    }
}