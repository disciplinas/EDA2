#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *array, int size);
void printAnArray(int *vector, int size);

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = n;
    insertionSort(arr, n);
    printAnArray(arr, m);
}

void insertionSort(int *array, int size){
    int i, j, key;
    for(i = 1; i < size; i++){
        key = array[i];
        j = i-1;
        while (j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
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