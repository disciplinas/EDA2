#include<stdio.h>
#include<stdlib.h>

int main(){
    int *output;
    int i=0, j=0, k=0;
    int soma = 0, stop = 1, minimo = 0;

    int nr_elementos = 10000;
    //input = (int *) malloc(sizeof(int) * nr_elementos);
    output = (int *) malloc(sizeof(int) * nr_elementos);

    int input[11] = {33, 51, 23, 94, 66, 28, 11, 73, 19, 8, 31};

    /* while (stop != 0){
        int var = 0;
        scanf("%d", &var);
        if (var == 0){
           break;
        }
        input[i] = var;
        ++i;
    }
    scanf("%d", &minimo); */
    minimo = 90;

    for(j=i; j >= i-2; j--){
        if(input[j] > minimo){
            output[k] = input[j];
            //printf("%d\n", input[j]);
            k++;
        }else{           
            soma += input[j];
            if(soma > minimo){
                output[k] = input[j];
                //printf("%d\n", input[j]);
                soma = 0;
                //printf("%d\n", output[k]);
                k++;
            }
        }
    }

    /*for(int l = k-1; l >= 0; l--){
        printf("%d\n", output[l]);
    }*/
    printf("%d\n",output[0]);
    printf("%d\n",output[1]);
    printf("%d\n",output[2]);
    printf("%d\n",output[3]);
    printf("%d\n",output[4]);
    printf("%d\n",output[5]);
    printf("%d\n",output[6]);



    return 0;
    
}