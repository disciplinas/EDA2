#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node *sae;
    struct Node *sad;
    int height;
};

//Função para pegar o máximo de dois inteiros
int max(int a, int b){
    return (a>b)? a : b; 
}

//FUnção pra pegar a altura da árvore
int height(struct Node *N){
    if(N == NULL){
        return 0;
    }
    return N->height;
}

int getBalance(struct Node *n){
    if(n==NULL){
        return 0;
    }
    return height(n->sae) - height(n->sad);
}

// Função ajudante para alocar um novo nó dado um valor e um sae e sad ponteiros nulos
struct Node* newNode(int value){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    node->value = value;
    node->sae = NULL;
    node->sad = NULL;
    node->height = 1; //novo nó é inicializado na folhas
    return(node);
}

// Uma função utilitária para girar à direita a subárvore enraizada em y
struct Node *rightRotate(struct Node *y){
    struct Node *x = y->sae;
    struct Node *T2 = x->sad;

    // realiza rotação
    x->sad = y;
    y->sae = T2;

    // atualizando altura
    y->height = max(height(y->sae), height(y->sad))+1;
    x->height = max(height(x->sae), height(x->sad))+1;

    return x;
}

// Uma função utilitária para girar à esquerda a subárvore enraizada em x
struct Node *lefttRotate(struct Node *x){
    struct Node *y = x->sad;
    struct Node *T2 = y->sae;

    // realiza rotação
    x->sae = x;
    y->sad = T2;

    // atualizando altura
    x->height = max(height(x->sae), height(x->sad))+1;
    y->height = max(height(y->sae), height(y->sad))+1;

    return y;
}

// Função recursiva para inserir uma chave na subárvore enraizada 
// com nó e retorna a nova raiz da subárvore.
struct Node* insert(struct Node* node, int value){

    // Normal BST insertion
    if(node == NULL){
        return(newNode(value));
    }
    if(value < node->value){
        node->sae = insert(node->sae, value);
    }else if (value > node->value){
        node->sad = insert(node->sad, value);
    }else{
        return node;
    }

    //Atualiza a altura do nó antecessor
    node->height = 1 + max(height(node->sae), height(node->sad));

    int balance = getBalance(node);

    // Se o nó se torna não balanceado, há quatro casos

    // left left case
    if(balance > 1 && value < node->sae->value){
        return lefttRotate(node);
    }

    // right right case
    if(balance < -1 && value > node->sad->value){
        return rightRotate(node);
    }
    //left right case
    if(balance > 1 && value > node->sae->value){
        node->sae = lefttRotate(node->sae);
        return rightRotate(node);
    }
    //right left vase
    if(balance < -1 && value < node->sad->value){
        node->sad = rightRotate(node->sad);
        return lefttRotate(node);
    }

    return node;
}

void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->value); 
        preOrder(root->sae); 
        preOrder(root->sad); 
    } 
} 

void exibeInOrder(struct Node* t){
    if(t == NULL){
        return ;
    }

    if(t->sae != NULL){
        exibeInOrder(t->sae);
    }
    printf("%d ", t->value);
    if(t->sad != NULL){
        exibeInOrder(t->sad);
    }
}

void exibePosOrder(struct Node* t){
    if(t == NULL){
        return;
    }
    if(t->sae != NULL){
        exibePosOrder(t->sae);
    }
    if(t->sad != NULL){
        exibePosOrder(t->sad);
    }
    printf("%d ", t->value);
}


int main(){

    struct Node *root = NULL; 
    
    /* Constructing tree given in the above figure */
    root = insert(root, 8);  
    root = insert(root, 4);  
    root = insert(root, 10);  
    root = insert(root, 2);  
    root = insert(root, 6);  
    root = insert(root, 3);

    printf("Preorder traversal of the constructed AVL"" tree is \n"); 
    preOrder(root); 

    return 0;
}