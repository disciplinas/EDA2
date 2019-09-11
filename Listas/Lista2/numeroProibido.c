#include<stdio.h>
#include<stdlib.h>

int busca(int *vetor, int l, int r, int x);

int main(){
    int qtd_input=0, *vetor, *search, i=0;
    //casos teste
    /*
    int vector[7] = {10, 0, 50, 25, 121, 0, 3000};
    int search[5] = {1 , 2, 3, 10, 0};*/

    scanf("%d", &qtd_input);

    vetor = malloc(sizeof(int) * qtd_input);  

    while (i < qtd_input){
        scanf("%d", &vetor[i]);
        i++;
    }
    int j=0;

    search = malloc(sizeof(int) * 140000);

    while (scanf("%d\n", &search[j]) == 1){
        j++;
    }

    /*for(int k=0; k <= j; k++){
        //printf("%d\n", vetor[k]);
        int res = busca(vetor, 0, qtd_input, search[k]);
        if(res == -1){
            printf("nao\n");
        }else{
            printf("sim\n");
        }
        
    }*/
    for(int u = 0; u < 7; u++){
        int l = vetor[u];
        int t = busca(vetor, 1, 7, l);
        printf("%d\n", t);
    }
    

    
    
    return 0;
}

int busca(int *vetor, int l, int r, int x){
    if(r >= l){
        int mid = l + (r - l)/2;

        if(vetor[mid] == x){
            return mid;
        }

        if(vetor[mid] > x){
            return busca(vetor, l, mid - 1, x);
        }else
        {
            return busca(vetor,mid + 1, r, x);
        }
    }
    return -1;
}