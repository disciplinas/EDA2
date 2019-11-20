#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int soma = 0;
    int aux;

    while (scanf("%d", &aux) == 1)
    {
        soma++;
    }
    printf("%d\n", soma);
    return 0;
}