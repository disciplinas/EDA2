#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct pilha {
    unsigned ant, atual, prox;
    struct pilha *next;
    struct pilha *back; 
    struct pilha *current;
}pilha;

pilha *sanity;

void criaPilha();
void empilha(unsigned long atual);
unsigned long desempilha();

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
void imprimir();

struct sana arraySanidade[1000000];

int main(){


    criaPilha();


    unsigned att, ante, proxi;

    /* int i = 0;
    while(scanf("%x%*c", &arraySanidade[i].atual) > 0){
        
        scanf("%x%*c", &arraySanidade[i].ant); 
        scanf("%x%*c", &arraySanidade[i].prox); 
        i++;
    } */

    //teste
    arraySanidade[0].ant = 0;
    arraySanidade[0].atual = 1;
    arraySanidade[0].prox = 2;

    arraySanidade[1].ant = 4;
    arraySanidade[1].atual = 5;
    arraySanidade[1].prox = 0;

    arraySanidade[2].ant = 2;
    arraySanidade[2].atual = 3;
    arraySanidade[2].prox = 4;

    arraySanidade[3].ant = 3;
    arraySanidade[3].atual = 4;
    arraySanidade[3].prox = 5;

    arraySanidade[4].ant = 1;
    arraySanidade[4].atual = 2;
    arraySanidade[4].prox = 3;

    int i = 5;


    if(arraySanidade[0].ant != arraySanidade[i].prox){
        printf("insana\n");
        return 0;
    }

    unsigned long current[i], anterior[i], proximo[i];
    int sizeArr = 0; 
    for(sizeArr=0; sizeArr < i; sizeArr++){
        unsigned long atual = arraySanidade[sizeArr].atual;
        unsigned long ant = arraySanidade[sizeArr].ant;
        unsigned long prox = arraySanidade[sizeArr].prox;
        current[sizeArr] = atual;
        anterior[sizeArr] = ant;
        proximo[sizeArr] = prox;
    }

    mergeSort(current, 0,i);

    //corrigir o 0 que vem no array depois da ordenação
    corrigirVetor(current, sizeArr);
    //corrigirVetor(anterior, sizeArr);
    //corrigirVetor(proximo, sizeArr);

    for(int j = 0; j < i; j++){
        printf("%d\n", current[j]);
    }

   // imprimir();

    int tam = sizeof(current) / sizeof(current[1]);
    
    int checked = 0;

    //O anterior do próximo sou eu ?
    /* Podemos usar pilha ? armazeno o atual, pecorro a lista procurando o anterior, se tiver coloco na pilha, 
    *  
    */
   //printf("%d", proximo[i]);
    /* int achou = 1;
    for(int k = 0; k < sizeArr; k++){
        achou = 1;
        if(buscarBin(arraySanidade, 0, tam, current[k]) != -1){
            printf("ok Busca\n");
            for (int aux = 0; aux < sizeArr; aux++)
            {
                printf("for\n");
                if(current[k] == arraySanidade[aux].atual){
                            printf("ok atual\n");

                    if(k == 0){
                        printf("kk == 0\n");
                        if(arraySanidade[aux].ant == 0 && buscarBin(arraySanidade, 0, tam, proximo[aux]) != -1){
                            printf("ok\n");
                            empilha(current[k]);
                        }
                    }else if(k == sizeArr-1){
                        printf("ok\n");
                        if(arraySanidade[aux].prox == 0 && buscarBin(arraySanidade, 0, tam, anterior[aux]) != -1){
                            empilha(current[k]);
                        }
                    }
                    if(buscarBin(arraySanidade, 0, tam, anterior[k])!=-1 && buscarBin(arraySanidade, 0, tam, proximo[k]) != -1){
                            printf("ok tt\n");
                        
                        empilha(current[k]);
                    }
                }
            }
            
        }
    }
 */
    /* if(checked){
        printf("sana\n");
    }else
    {
        printf("insana\n");
    } */
    
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

void criaPilha(){
    sanity = malloc(sizeof(pilha));
    sanity->back = NULL;
    sanity->current = NULL;
    sanity->next = NULL;
}

void empilha(unsigned long atual){
    pilha *p = malloc(sizeof(sanity));
    //p->ant = ant;
    p->atual = atual;
    //printf("%d\n", p->atual);
    //p->prox = prox;
    p->next = sanity->next;
    sanity->next = p;
}

unsigned long desempilha(){
    pilha *p;
    p = sanity->next;
    unsigned x = p->atual;
    sanity->prox = p->prox;
    free(p);
    return x;
}

void imprimir(){
    pilha *pont;
    pont = sanity;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", pont->atual);
        pont = pont->next; 
    }
    
}
