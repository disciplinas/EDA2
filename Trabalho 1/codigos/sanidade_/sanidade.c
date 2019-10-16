#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct sana {
    int visitado;
    unsigned long atual, ant, prox;
}node;

static int separa(node* vector, int left, int right);
void mergeAB(node* vector_f, node* vector_a, int size_a, node* vector_b,int size_b);
void mergeSort(node* vector, int left, int right);
void eec(int index, node* vector, int left, int right);
void merge(node* vector, int left, int meio, int right);


int main(){
    struct sana *arraySanidade;
    unsigned long *array;
    unsigned att, ante, proxi;

    int i = 0;
    while(scanf("%x%*c", &arraySanidade[i].atual) > 0){
        
        scanf("%x%*c", &arraySanidade[i].ant); 
        scanf("%x%*c", &arraySanidade[i].prox); 
        i++;
    }
    mergeSort(arraySanidade, 0, i);
    
    int j = 0;
    while (j < i ){
        array[i] = arraySanidade[j].atual;
        printf("%d\n", array[i]);
        j++;
    }



    
    return 0;
}

static int separa(node* array, int left, int right){
    int aux = array[right].atual;
    int j = left;
    for (int i = left; i <= right; i++){
        if(array[i].atual <= aux){
            int auxTroca = array[j].atual;
            array[j].atual = array[i].atual;
            array[i].atual = auxTroca;
            j++;
        }
    }
    int auxTroca = array[right].atual;
    array[right].atual = array[j].atual;
    array[j].atual = auxTroca;
    return j;
    
}

void mergeAB(node* vector_f, node* vector_a, int size_a, node* vector_b,int size_b){
    int aux_f = 0, aux_a = 0, aux_b = 0;
    while(aux_a < size_a && aux_b < size_b){
        if(vector_a[aux_a].atual <= vector_b[aux_b].atual){
            vector_f[aux_f].atual = vector_a[aux_a].atual;
            aux_a++;
            aux_f++;
        }else{
            vector_f[aux_f].atual = vector_b[aux_b].atual;
            aux_b++;
            aux_f++;
        }
    }
    while (aux_a < size_a){
        vector_f[aux_f].atual = vector_a[aux_a].atual;
        aux_a++;
        aux_f++;
    }

    while (aux_b < size_b){
        vector_f[aux_f].atual = vector_b[aux_b].atual;
        aux_b++;
        aux_f++;
    }   
}

void mergeSort(node* vector, int left, int right){
    if(left == right){
        return;
    }
    int meio = (left+right)/2;
    mergeSort(vector, left, meio);
    mergeSort(vector, meio+1,right);
    merge(vector, left, meio, right);

}

void eec(int index, node* vector, int left, int right){
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

void merge(node *vector, int left, int meio, int right){
    struct sana *C = malloc(sizeof(int) * (right-left+1));
    mergeAB(C, &vector[left].atual, (meio-left+1), &vector[meio+1].atual,(right-meio));
    int k = 0, i = left;
    while (i <= right){
        vector[i].atual = C[k].atual;
        i++;
        k++;
    }
    free(C);
    
}