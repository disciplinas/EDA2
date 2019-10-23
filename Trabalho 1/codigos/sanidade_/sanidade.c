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
    //struct sana arraySanidade[199999];
    //unsigned long *array;
    unsigned att, ante, proxi;

    //scanf("%x%*c", &arraySanidade[2].atual);
    int i = 0;
    while(scanf("%x%*c", &arraySanidade[i].atual) > 0){
        
        scanf("%x%*c", &arraySanidade[i].ant); 
        scanf("%x%*c", &arraySanidade[i].prox); 
        i++;
    }
    //mergeSort(arraySanidade, 0, i);

    /* arraySanidade[0].atual = 'a';
    arraySanidade[1].atual = 'f';
    arraySanidade[2].atual = 'e';
    arraySanidade[3].atual = 'b';
    arraySanidade[4].atual = 'c';
    //arraySanidade[5].atual = 'd';

    arraySanidade[0].ant = '0';
    arraySanidade[1].ant = 'e';
    arraySanidade[2].ant = 'd';
    arraySanidade[3].ant = 'a';
    arraySanidade[4].ant = 'b';
    //  arraySanidade[5].ant = 'c';

    arraySanidade[0].prox = 'b';
    arraySanidade[1].prox = '0';
    arraySanidade[2].prox = 'f';
    arraySanidade[3].prox = 'c';
    arraySanidade[4].prox = 'd';
   // arraySanidade[5].prox = 'e'; */
    
    //int i = 6;

    //array= malloc((sizeof(unsigned long) * i));
    unsigned long array[i];   
    int sizeArr = 0; 
    for(sizeArr=0; sizeArr < i; sizeArr++){
        unsigned long atual = arraySanidade[sizeArr].atual;
        //printf("%d\n", atual);
        array[sizeArr] = atual;
    }

    //printf("%d\n\n", array[1]);
    mergeSort(array, 0,i);
    //corrigir o 0 que vem no array depois da ordenação
    corrigirVetor(array, sizeArr);

    for(int j = 0; j <= i; j++){
        printf("%d\n", array[j]);
    }

    int tam = sizeof(array) / sizeof(array[1]);
    //printf("Tam: %d\n", tam);
    /* int result = buscarBin(arraySanidade, 0, tam, 98);
    
    printf("Result: %d\n", result); */
    int checked = 0;

    for(int k = 0; k < sizeArr; k++){
        if(buscarBin(arraySanidade, 0, tam, array[k]) != -1){
            if(arraySanidade[k+1].ant == arraySanidade[k].atual){
                checked = 1;
            }
        }
    }

    if(checked){
        printf("sana");
    }else
    {
        printf("insana");
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
