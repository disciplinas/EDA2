#include<stdio.h>
#include<stdlib.h>
#define size 10000000


int main(){

    int qtd_sementes;
    int codigoSemente[1000000];
    int qualidadeSemente[1000000];

    int i = 0;

    scanf("%d", &qtd_sementes);

    while(scanf("%d", &codigoSemente[i]) == 1){
        scanf("%d", &qualidadeSemente[i]);
        i++;
    }

    printf("%d\n", codigoSemente[0]);    
    printf("%d\n", qualidadeSemente[0]);    

    return 0;
}