#include<stdio.h>
#include<stdlib.h>

typedef int Item;
#define key(A)(A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item T = B; B=A; A=T;}
#define compexch(A,B) (if(less(B,A) exch(A,B)))

void insertionSort(Item *v, int l, int r);

int main(){
    int *v;
    int i = 0;
    v = (int *) malloc(sizeof(int) * 1000);
    while (scanf("%d\n", &v[i])==1 && i<=1000){
        i++;
    }
    insertionSort(v, 0, 5);

    for (int j = 0; j < 6; j++)
    {
        if((j+1) < i){
            printf("%d ", v[j]);
        }else{
            printf("%d\n", v[j]);
        } 
    }
    

    return 0;
}

void insertionSort(Item *v, int l, int r){
    int i, j;
    for(i=l+1; i <= r; i++){
        for(j=i; j > l; j--){
           if(v[j] < v[j-1]){
               int aux = v[j-1];
               v[j-1] = v[j];
               v[j] = aux;
           }
        }
    }
}