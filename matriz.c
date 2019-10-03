#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

int main(){
    int N = 0;
    scanf("%d", &N);
    int matriz1[N][N];
    int matriz2[N][N];
    int i = 0;
    while(i < N){
        scanf("%d", &matriz1[i][i]);
        scanf("%d", &matriz1[i][i+1]);
        i++;
    }
    printf("%d ", matriz1[0][0]);
    printf("%d\n", matriz1[0][1]);
    printf("%d ", matriz1[1][1]);
    printf("%d\n", matriz1[1][2]);
    
    return 0;
}