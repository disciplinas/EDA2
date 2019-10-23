#include<stdio.h>
#include<stdlib.h>

typedef struct tempNo
{
    float valor;
    int coluna;
    struct tempNo* prox;
} NO;

typedef NO* PONT;

typedef struct
{
    PONT* A;
    int linhas;
    int colunas;
}MATRIZ;

void inicializarMatriz(MATRIZ* m, int lin, int col){
    int i;
    m->linhas = lin;
    m->colunas = col;
    m->A = (PONT*) malloc(lin*sizeof(PONT));
    for (i = 0; i < lin; i++)
    {
        m->A[i] = NULL;
    }
    
}

int atribuiMatriz(MATRIZ* m, int lin, int col, float val){
    if(lin<0 || lin >= m->linhas || col<0 || col >= m->colunas)
        return -1;
    PONT ant = NULL;
    PONT atual = m->A[lin];
    while (atual != NULL && atual->coluna<col){
        ant = atual;
        atual = atual->prox;
    }
    if(atual != NULL && atual->coluna == col){
        if(val == 0){
            if(ant==NULL){
                m->A[lin] = atual->prox;
            }else{
                ant->prox = atual->prox;
            }
            free(atual);
        }
        else{
            atual->valor = val;
        }
    }
}

