#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sana {
    int visitado;
    unsigned long atual, ant, prox;
}node;

static int separa(unsigned long *vector, int left, int right);
void mergeAB(unsigned long *vector_f, unsigned long *vector_a, int size_a, 
             unsigned long *vector_b,int size_b);
void merge(unsigned long *vector, int left, int meio, int right);
void mergeSort(unsigned long *vector, int left, int right);
void eec(int index, unsigned long *vector, int left, int right);
void corrigirVetor(unsigned long *vetor, int size);
unsigned long buscarBin(struct sana* arr, int l, int r, unsigned long x);

struct sana arraySanidade[1000000];

int main(){

  
    int i = 0;
    while(scanf("%x%*c", &arraySanidade[i].atual) != 1){
        
        scanf("%x%*c", &arraySanidade[i].ant); 
        scanf("%x%*c", &arraySanidade[i].prox); 
        i++;
    }

    unsigned long current[i], anterior[i], proximo[i];
    int sizeArr = 0; 
    for(sizeArr=0; sizeArr < i; sizeArr++){
        unsigned long atual = arraySanidade[sizeArr].atual;
        current[sizeArr] = atual;
    }

    mergeSort(current, 0,i);

    //corrigir o 0 que vem no array depois da ordenação
    corrigirVetor(current, sizeArr);

    for (int j = 0; j < sizeArr; i++){
        printf("%d\n", current[j]);
    }
    
    
    
    return 0;
}


static int separa(unsigned long *vector, int left, int right){
    unsigned long aux = vector[right];
    int j = left;
    for (int i = left; i <= right; i++){
        if(vector[i] <= aux){
            unsigned long auxTroca = vector[j];
            vector[j] = vector[i];
            vector[i] = auxTroca;
            j++;
        }
    }
    unsigned long auxTroca = vector[right];
    vector[right] = vector[j];
    vector[j] = auxTroca;
    return j;
    
}

void mergeAB(unsigned long *vector_f, unsigned long *vector_a, int size_a, unsigned long *vector_b,int size_b){
    unsigned long aux_f = 0, aux_a = 0, aux_b = 0;
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

void mergeSort(unsigned long *vector, int left, int right){
    if(left == right){
        return;
    }
    int meio = (left+right)/2;
    mergeSort(vector, left, meio);
    mergeSort(vector, meio+1,right);
    merge(vector, left, meio, right);

}

void eec(int index, unsigned long *vector, int left, int right){
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

void merge(unsigned long *vector, int left, int meio, int right){
    unsigned long *C = malloc(sizeof(unsigned long) * (right-left+1));
    mergeAB(C, &vector[left], (meio-left+1), &vector[meio+1],(right-meio));
    int k = 0, i = left;
    while (i <= right){
        vector[i] = C[k];
        i++;
        k++;
    }
    free(C);   
}

unsigned long buscarBin(struct sana* arr, int l, int r, unsigned long x){
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid].atual == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid].atual > x) 
            return buscarBin(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return buscarBin(arr, mid + 1, r, x); 
    }
    // We reach here when element is not 
    // present in array 
    return -1; 
}

void corrigirVetor(unsigned long *vetor, int size){
    int i = 0;
    for(i = 1; i < size; i++){
        int aux = vetor[i];
        vetor[i-1] = aux;
    }
}