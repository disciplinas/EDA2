#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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
    struct queue* q2 = createQueue();
    char *input;
    int i = 1;
    char last[26];
    input = (char*)malloc(sizeof(char) * 26);
    while(fgets(input, sizeof(input), stdin) != NULL){
        //printf("%s", input);
        enqueue(q, input);
    }

    struct qnode* n = dequeue(q);
    struct qnode* n2;
    //printf("%s\n", n->key);
    int len = strlen(n->key);
    char last_one = n->key[len-2];
    enqueue(q2, n->key);
    last[0] = last_one;
    //printf("last: %c\n", last[0]);
    for(n = dequeue(q); n; n = n->next){
        len = strlen(n->key);
        char last_one_ = n->key[len-2];
        last[i] = last_one_;
        if(tolower(last[i-1]) == tolower(last[i])){
            enqueue(q->last, n->key);
        }else{
            enqueue(q2, n->key);
        }
    }

    for(n = dequeue(q); n; n=n->next){
        enqueue(q2, n->key);
    }

    if(tolower('A') == 'a'){
        printf("Claro que e pow\n");
    }

    for(n2 = dequeue(q2); n2; n2 = n2->next){
        printf("%s", n2->key);
    }

    return 0;
}

char last_letter(struct qnode* n){
    int len = strlen(n->key);
    const char *last_one = &n->key[len-1];

    return *last_one;
}