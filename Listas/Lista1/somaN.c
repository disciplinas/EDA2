#include<stdio.h>
#include<stdlib.h>

int main(){
    int n_input=0, soma=0, i=0;
    scanf("%d", &n_input);
    while (i < n_input)
    {
        int num = 0;
        scanf("%d", &num);
        soma += num;
        i++;
    }

    printf("%d\n", soma);
    
    return 0;
}