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
void leia_string(char *s);

int main(){
    struct queue* q = createQueue();
    struct queue* q2 = createQueue();
    char *input;
    char *aux;
    int i = 1;
    char last_l[26];
    char first_f[26];
    input = (char*)malloc(sizeof(char) * 26);
    aux = malloc(sizeof(char) * 26);
    while(fgets(aux, sizeof(aux), stdin) != NULL){
        leia_string(input);
        enqueue(q, input);
    }

    struct qnode* n = dequeue(q);
    struct qnode* n2;

    int len = strlen(n->key);

    char first_one = n->key[0];
    char last_one = n->key[len];

    //printf("F: %c\n", first_one);
    printf("L: %c\n",  last_one);

    enqueue(q2, n->key);
    last_l[0] = last_one;
    first_f[1] = n->key[len-len];

    /*for(n = dequeue(q); n; n = n->next){
        len = strlen(n->key);
        char last_one_ = n->key[len-1];
        last[i] = last_one_;
        if(tolower(last[i]) == tolower(last[i-1])){
            enqueue(q->last, n->key);
            printf("È igual: %s\n", n->key);
        }else{
            enqueue(q2, n->key);
        }
        i++;
    }*/

    /*for(n = dequeue(q); n; n = n->next){
        printf("%s", n->key);
    }*/

    return 0;
}

char last_letter(struct qnode* n){
    int len = strlen(n->key);
    const char *last_one = &n->key[len-1];

    return *last_one;
}

void leia_string(char *s) {
  int c, i;
  char *p;
  c = getchar();
  if (c =='\n') {
    c =getchar();
  } /* fim-if */
  i = 0;
  p=s;
  while (c!='\n') {
    (*s) = c;
    c = getchar();
    i++;
    s=p+i;
  } /* fim-while */
  (*s) = '\0';
} /* fim-leia_string */
