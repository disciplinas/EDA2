/* Implementação de árvore binária */

#include <stdio.h>
#include <stdlib.h>

/* Cada nó armazena três informações:
   nesse caso um número (num),
   ponteiro para subárvore à direita (sad)
   e ponteiro para subárvore à esquerda (sae).*/
typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore */
Tree* createTree()
{
  /* Uma árvore é representada pelo endereço do nó raiz,
     essa função cria uma árvore com nenhum elemento,
     ou seja, cria uma árvore vazia, por isso retorna NULL. */
  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int treeIsEmpty(Tree* t)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  return t == NULL;

}

/* Função que mostra a informação da árvore */
void showTree(Tree* t)
{
  /* Essa função imprime os elementos de forma recursiva */
  
  printf("<"); /* notação para organizar na hora de mostrar os elementos */
  if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
  {
    /* Mostra os elementos em pré-ordem */
    printf("%d ", t->num); /* mostra a raiz */
    showTree(t->sae); /* mostra a sae (subárvore à esquerda) */
    showTree(t->sad); /* mostra a sad (subárvore à direita) */
  }
  printf(">"); /* notação para organizar na hora de mostrar os elementos */
}

/* Função que insere um dado na árvore */
int insertTree(Tree** t, int num)
{
  Tree *novoNo, *atual, *p;
  novoNo = malloc(sizeof(Tree));
  if(novoNo == NULL){
      return 0;
  }

  novoNo->num = num;
  novoNo->sae = NULL;
  novoNo->sad = NULL;

  if(*t == NULL){
      *t = novoNo;
      return 1;
  }
  atual = *t;
  while (atual != NULL){}
  {
      p = atual;
      if(atual->num > num){
          atual = atual->sae;
      }else{
          atual = atual->sad;
      }
      printf("A");
  }

  if(p->num > num){
      p->sae = novoNo;
  }else{
      p->sad = novoNo;
  }

    return 1;

}

/* Função que verifica se um elemento pertence ou não à árvore */
int isInTree(Tree* t, int num) {
  
  if(treeIsEmpty(t)) { /* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  }
  
  /* O operador lógico || interrompe a busca quando o elemento for encontrado */
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}

void exibePreOrdem(Tree* t){
    if(t == NULL){
        return;
    }

    printf("%d ", t->num);
    if(t->sae != NULL){
        exibePreOrdem(t->sae);
    }
    if(t->sad != NULL){
        exibePreOrdem(t->sad);
    }
}

void exibeInOrder(Tree* t){
    if(t == NULL){
        return ;
    }

    if(t->sae != NULL){
        exibeInOrder(t->sae);
    }
    printf("%d ", t->num);
    if(t->sad != NULL){
        exibeInOrder(t->sad);
    }
}

void exibePosOrder(Tree* t){
    if(t == NULL){
        return;
    }
    if(t->sae != NULL){
        exibePosOrder(t->sae);
    }
    if(t->sad != NULL){
        exibePosOrder(t->sad);
    }
    printf("%d ", t->num);
}

void exibeOrdernado(Tree* t){
    if(t != NULL){
        exibeOrdernado(t->sae);
        printf("%d ", t->num);
        exibeOrdernado(t->sad);
    }
}

int main()
{
  Tree* t = createTree(); /* cria uma árvore */
  
  insertTree(&t, 12); /* insere o elemento 12 na árvore */
  insertTree(&t, 15); /* insere o elemento 15 na árvore */
  insertTree(&t, 10); /* insere o elemento 10 na árvore */
  insertTree(&t, 13); /* insere o elemento 13 na árvore */
   
  printf("Exibição normal.!\n");
  showTree(t); /* Mostra os elementos da árvore em pré-ordem */
  
  if(treeIsEmpty(t)) /* Verifica se a árvore está vazia */
  {
    printf("\n\nArvore vazia!!\n");
  } else {
    printf("\n\nArvore NAO vazia!!\n");
  }
  
  /*if(isInTree(t, 15)) { // Verifica se o número 15 pertence a árvore //
    printf("\nO numero 15 pertence a arvore!\n");
  } else {
     printf("\nO numero 15 NAO pertence a arvore!\n");
  }
  
  if(isInTree(t, 22)) { // Verifica se o número 22 pertence a árvore 
    printf("\nO numero 22 pertence a arvore!\n\n");
  } else {
     printf("\nO numero 22 NAO pertence a arvore!\n\n");
  }*/

  printf("Exibição em pre-ordem\n");
  exibePreOrdem(t);
  //free(t);
  printf("\nExibição in-order\n");
  exibeInOrder(t);
  printf("\nExibição pos-ordem\n");
  exibePosOrder(t);
  
  free(t); /* Libera a memória alocada pela estrutura árvore */
  
  return 0;
}