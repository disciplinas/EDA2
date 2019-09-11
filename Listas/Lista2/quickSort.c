#include<stdio.h>
#include<stdlib.h>

static int separa(int *v, int l, int r);
void quicksort(int *v, int l, int r);

int main(){
    //int v[] = {12, 7, 23, 1, 23, 102, 5};
    int i =0, aux = 0;
    int *vector;
    vector = malloc(sizeof(int)*100000);
    while (scanf(" %d\n", &vector[i]) == 1){
            
        aux = i;
        i++;
    }
    quicksort(vector, 0, i);
    for(int h = 1; h < i; h++){
        //printf("%d: %5.d\n", h, vector[h]);
        //printf("%d ", vector[h]);
        if(h < i){
            printf("%d ", vector[h]);
        }
        if(h+1 == i)
            printf("%d\n", vector[h+1]);

    }
    /* printf("%d\n",vector[0]);
    printf("%d\n",vector[1]);
    printf("%d\n",vector[2]);
    printf("%d\n",vector[3]);
    printf("%d\n",vector[4]);
    printf("%d\n",vector[5]);
    printf("%d\n",vector[6]); */

    return 0;
}

static int separa(int *v, int l, int r){
    int c =v[r];
    int j = l;
    for(int i = l; i < r; ++i){
        if(v[i] <= c){
            int aux = v[i];
            v[i] = v[j];
            v[j] = v[i];
            ++j;
        }
    }
    int aux = v[j];
    v[j] = v[r];
    v[r] = aux;
    return j;
    
}

void quicksort(int *v, int l, int r){
    if(l < r){
        int j = separa(v, l, r);
        quicksort(v, l, j-1);
        quicksort(v, j+1, r);
    }
}


int geraVetor(){
    /*int k = NULL, *matriz = NULL;


	printf("Tamanho do vetor: ");
	scanf("%i", &k);

	matriz = (int *)malloc(k * sizeof(int));

    srand(time(NULL));
	for (int i = 0; i < k; i++)
	{
		matriz[i] = rand() % k + 1;

		printf("Valor  %i : %i" , i+1,  matriz[i]);
		printf("\n");
	}*/
}