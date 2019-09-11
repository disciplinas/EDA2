#include<stdio.h>
#include<stdlib.h>

struct Qnode {
    int key;
    struct Qnode* next;
};

struct queue{
    struct Qnode *front, *rear;
};

struct Qnode* newNode(int k){
    struct Qnode* temp = (struct Qnode*) malloc(sizeof(struct Qnode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct queue* createQueue(){
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct queue* q, int k){
    struct Qnode* temp = newNode(k);

    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

struct Qnode* deQueue(struct queue* q){
    if(q->front == NULL){
        return NULL;
    }

    struct Qnode* temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }
    return temp;
}

int main(){

    struct queue* q = createQueue();

    enQueue(q, 10); 
    enQueue(q, 20); 
    deQueue(q); 
    deQueue(q); 
    enQueue(q, 30); 
    //deQueue(q);
    enQueue(q, 40); 
    enQueue(q, 50);

    struct Qnode* n = deQueue(q);

    if (n != NULL){ 
        printf("Dequeued item is %d", n->key);
    }
    return 0;
}