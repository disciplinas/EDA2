#include<stdio.h>
#include<stdlib.h>

void selectionR(int *v, int left, int right);
int acha_menor(int *vector, int menor, int left, int right);
static int separa(int *vector, int left, int right);

int main(){
    int *v, i=0;
    v = malloc(sizeof(int) * 1000);

    while(scanf("%d", &v[i]) == 1){
        i++;
    }
    selectionR(v, 0, i);

    for(int y = 0; y < 1000; y++){
        printf("%d\n", v[y]);
    }

    return 0;
}

void selectionR(int *vector, int left, int right){
    if(left == right){
        return;
    }

    int menor = acha_menor(vector, menor, left+1, right);
    int auxTroca = vector[menor];
    vector[menor] = vector[left];
    vector[left] = auxTroca;

    selectionR(vector, left+1, right);
}

int acha_menor(int *vector, int menor, int left, int right){
    if(left > right){
        return menor;
    }
    if(vector[left] < vector[menor]){
        menor = left;
    }
    return acha_menor(vector, menor, left+1, right);
}

static int separa(int *vector, int left, int right){
    int aux = vector[right];
    int j = left;
    for (int i = left; i <= right; i++){
        if(vector[i] <= aux){
            int auxTroca = vector[j];
            vector[j] = vector[i];
            vector[i] = auxTroca;
            j++;
        }
    }
    int auxTroca = vector[right];
    vector[right] = vector[j];
    vector[j] = auxTroca;
    return j;
    
}