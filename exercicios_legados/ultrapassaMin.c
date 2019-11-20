#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int *input, i, minimo, *aux, soma, k, index = 0;
    int num = 10000;
    FILE *fp = argc > 1 ? fopen(argv[1], "r") : stdin;
    input = (int *) malloc(sizeof(int) * num);
    aux = (int *) malloc(sizeof(int) * 500);


    while (!feof(fp)){
        fscanf(fp,"%d", &input[i]);
        i++;
    }
    fclose(fp);

    int cont;
    for(cont=0; cont <= i-2; cont++){
        if(input[cont] > 90){
            aux[index] = input[cont];
            index++;
        }else{           
            soma += input[cont];
            if(soma > 90){
                aux[index] = input[cont];
                soma = 0;
                index++;
                //printf("second");

            }
        }
    }

   /* for(int g = 0; g < i-2; g++){
        printf("%d\n", input[g]);
    }*/

    for(int i = index-1; i >= 0; i--){
        printf("%d ", aux[i]);
    }
    printf("\n");

    return 0;
}