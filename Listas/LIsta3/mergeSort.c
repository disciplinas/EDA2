#include<stdio.h>
#include<stdlib.h>

void merge(int *array, int l, int m, int r);
void mergeSort(int *array, int l, int r);

int main(){
    int arr[6] = { 7, 3, 2, 5, 4, 3};
    mergeSort(arr, 0, 6);
    return 0;
}

void merge(int array[], int l, int m, int r){
    int i, j, k;
    int m1 = m-l+1;
    int m2 = r-m;

    int left[m1], right[m2];

    for(i=0; i < m1; i++){
        left[i] = array[l+i];

    }
    for(j=0; j < m2; j++){
        right[j] = array[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < m1 && j < m2 ){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i++;
        }else{
            array[r] = right[j];
            j++;
        }
        k++;
    }
    
}

void mergeSort(int *array, int l, int r){
    if(r > l){
        int m = l+(r-1)/2;

        mergeSort(array, l, m);
        mergeSort(array, m+1, r);
        merge(array, l, m, r);
    }
}