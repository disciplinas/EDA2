#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct qnode{
    char key[26];
    struct qnode* next;
};

struct queue {
    struct qnode *first, *last;
};

struct qnode* newNode(char *k){
    struct qnode* temp = (struct qnode*)malloc(sizeof(struct qnode));
    strcpy(temp->key, k);
    //temp->key = k;
    temp->next = NULL;
    return temp;
};

struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->first = q->last = NULL;
    return q;
}

void enqueue(struct queue* q, char *k){
    struct qnode* temp = newNode(k);

    if(q->last == NULL){
        q->first = q->last = temp;
        return;
    }

    q->last->next = temp;
    q->last = temp;
}

struct qnode* dequeue(struct queue* q){
    if(q->first == NULL){
        return NULL;
    }

    struct qnode* temp = q->first;
    q->first = q->first->next;

    if(q->first == NULL){
        q->last == NULL;
    }

    return temp;

}





int main(){
    struct queue* q = createQueue();
    enqueue(q, "Brasilia");

    struct qnode* n = dequeue(q);
    printf("%s", n->key);

    return 0;
}

char last_letter(struct qnode* n){
    int len = strlen(n->key);
    const char *last_one = &n->key[len-1];

    return *last_one;
}