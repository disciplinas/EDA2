#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int conteudo;
    struct no *esq;
    struct no *dir;
} tNo;

typedef tNo *tArvBin;

void cria(tArvBin *T){
    *T = NULL;
}

int vazia(tArvBin T){
    return(1);
}

tArvBin busca(tArvBin T, int dado){
    tArvBin achou;
    if(T==NULL){
        return NULL;
    }

    if(T->conteudo == dado){
        return T;
    }

    achou = busca(T->esq, dado);
    if(achou == NULL){
        achou = busca(T->dir,dado);
    }
    return achou;
}

int insereRaiz(tArvBin *T, int dado){
    tNo *novoNo;
    if(*T != NULL){
        return (0);
    }

    novoNo = malloc(sizeof(tNo));
    if(novoNo == NULL){
        return 0;
    }

    novoNo->conteudo = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    *T = novoNo;
    return 1;
}

int insereDireita(tArvBin T, int vPai, int vFilho){
    tNo *f, *p, *novoNo;

    f = busca(T, vFilho);
    if(f != NULL){
        return 0;
    }

    p = busca(T, vPai);
    if(p == NULL)
        return 0;
    if(p->dir != NULL){
        return 0;
    }
    novoNo = malloc(sizeof(tNo));
    if(novoNo == NULL){
        return (0);
    }

    novoNo->conteudo = vFilho;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    p->dir = novoNo;
    return 1;
}

int insereEsquerda(tArvBin T, int vPai, int vFilho){
    tNo *f, *p, *novoNo;

    f = busca(T, vFilho);
    if(f != NULL){
        return 0;
    }

    p = busca(T, vPai);
    if(p == NULL)
        return 0;
    if(p->esq != NULL){
        return 0;
    }
    novoNo = malloc(sizeof(tNo));
    if(novoNo == NULL){
        return (0);
    }

    novoNo->conteudo = vFilho;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    p->esq = novoNo;
    return 1;
}

int main(){
    tArvBin *root;
    //root raiz;
    cria(root);
    int isVazia = vazia(root);
    if(isVazia){
        printf("ok\n");
    }
    return 0;
}