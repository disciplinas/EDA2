#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y);
void bubleSort(int *v, int size);

int main(){
    int vector[5] = { 5, 1, 4, 2, 8};
    bubleSort(vector, 5);

    for(int l = 0; l < 5; l++){
        printf("%d ", vector[l]);
    }
    return 0;
}

void swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

void bubleSort(int *v, int size){
    int cont = 0;
    int comp = 0;
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            comp++;
            if(v[j] > v[j+1]){
                swap(&v[j], &v[j+1]);
                cont++;
            }
        }
        
    }
    printf("Comparações: %d\n", comp);
    printf("Trocas: %d\n", cont);
}