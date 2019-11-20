/* Implementação de árvore binária */

#include <stdio.h>
#include <stdlib.h>


typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;


Tree* createTree()
{
 
  return NULL;
}

int treeIsEmpty(Tree* t)
{
  return t == NULL;

}

void insertTree(Tree** t, int num)
{
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree)); 
    (*t)->sae = NULL; 
    (*t)->sad = NULL;
    (*t)->num = num; 
  } else {
    if(num < (*t)->num) 
    {
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num)
    {
      insertTree(&(*t)->sad, num);
    }
  }
}

int isInTree(Tree* t, int num) {
  
  if(treeIsEmpty(t)) {
    return 0;
  }
  
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

int main()
{
  Tree* t = createTree();
  
    int number = 0;

  while (scanf("%d", &number) == 1)
  {
    insertTree(&t, number);
  }

  exibePreOrdem(t);
  printf(".\n");
  exibeInOrder(t);
  printf(".\n");
  exibePosOrder(t);
  printf(".\n");

  
  free(t);
  
  return 0;
}