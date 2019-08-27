#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *v, int l, int r);

int main(){
    int *v;
    int i = 0;
    v = (int *) malloc(sizeof(int) * 1000);
    
    while (scanf("%d\n", &v[i])==1 && i<=1000){
        i++;
    }
    insertionSort(v, 0, 5);
    for (int j = 0; j < i; j++){
        if((j+1) < i){
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

