#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *v, int l, int r);

int main(){
    int v[6] = {7, 3, 2, 5, 4, 3};
    int i = 5;
    int aux2 = 6;
    //v = (int *) malloc(sizeof(int) * 1000);
    
    /*while (scanf("%d", &v[i])==1 && i < 1000){
      //  printf("NUm: %d i: %d ", v[i], i);
      printf("%d\n", v[i]);
        aux = i;
        i++;
    }*/
    //printf("0: %d", v[0]);
    insertionSort(v, 0, i);
    for (int j = 0; j <= aux2; j++){
        if(j < aux2){
            printf("%d ", v[j]);
        }else{
            printf("%d\n", v[j]);
        } 
    }
    return 0;
}

void insertionSort(int *v, int l, int r){
    int i=0, j=0;
    for (i = r; i > l; i--){
        if(v[i] < v[i-1]){
            int aux = v[i-1];
            v[i-1] = v[i];
            v[i] = aux;
        }
    }
    for(i=l;i<=r;i++){
        int menor = v[i], j=i;
        int boolean;
        while (menor < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = menor;
    }    
}

