#include<stdio.h>
#include<stdlib.h>

static int separa(int *vector, int left, int right);
void mergeAB(int *vector_f, int *vector_a, int size_a, 
             int *vector_b,int size_b);
void merge(int *vector, int left, int meio, int right);
void mergeSort(int *vector, int left, int right);
void eec(int index, int *vector, int left, int right);


int main(){
    int *v, i=0;
    v = malloc(sizeof(int) * 1000);

    while(scanf("%d", &v[i]) == 1){
        i++;
    }
    mergeSort(v, 0, i); 

    for(int y = 0; y < 1000; y++){
        printf("%d\n", v[y]);
    }

    return 0;
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

void mergeAB(int *vector_f, int *vector_a, int size_a, int *vector_b,int size_b){
    int aux_f = 0, aux_a = 0, aux_b = 0;
    while(aux_a < size_a && aux_b < size_b){
        if(vector_a[aux_a] <= vector_b[aux_b]){
            vector_f[aux_f] = vector_a[aux_a];
            aux_a++;
            aux_f++;
        }else{
            vector_f[aux_f] = vector_b[aux_b];
            aux_b++;
            aux_f++;
        }
    }
    while (aux_a < size_a){
        vector_f[aux_f] = vector_a[aux_a];
        aux_a++;
        aux_f++;
    }

    while (aux_b < size_b){
        vector_f[aux_f] = vector_b[aux_b];
        aux_b++;
        aux_f++;
    }
    
}

void mergeSort(int *vector, int left, int right){
    if(left == right){
        return;
    }
    int meio = (left+right)/2;
    mergeSort(vector, left, meio);
    mergeSort(vector, meio+1,right);
    merge(vector, left, meio, right);

}

void eec(int index, int *vector, int left, int right){
    int j = separa(vector, left, right);
    if(j == index){
        return;
    }
    if(j < index){
        eec(index, vector, j+1, right);
    }else {
        eec(index, vector, left, j-1);
    }
}

void merge(int *vector, int left, int meio, int right){
    int *C = malloc(sizeof(int) * (right-left+1));
    mergeAB(C, &vector[left], (meio-left+1), &vector[meio+1],(right-meio));
    int k = 0, i = left;
    while (i <= right){
        vector[i] = C[k];
        i++;
        k++;
    }
    free(C);
    
}
