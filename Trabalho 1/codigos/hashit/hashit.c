#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct {
    char* key;
    char* value;
}ht_item;

typedef struct {
    int size;
    int count;
    ht_item** items;
}ht_hash_table;

static ht_item* ht_new_item(const char* k, const char* v);
ht_hash_table* ht_new();
static void ht_del_item(ht_item* i);
void ht_del_hash_table(ht_hash_table* ht);
static int ht_hash(const char* s, const int a, const int m);
void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* h, const char* key);
static int ht_get_hash(
    const char* s, const int num_buckets, const int attempt
);
int hashCode(const char* s);
char* ht_search_key(ht_hash_table* ht, const char* key);


int main(){

    ht_hash_table* ht = ht_new();
    int cases=0, op = 0;
    char oper[3];
    char string[18];
    char str[15];
    int key;
    scanf("%d", &cases);
    scanf("%d", &op);
    int keyss = 0;
    while(cases != 0){
        while(op != 0){
            scanf("%s", &string);
            for(int i = 0; i < 3; i++){
                oper[i] = string[i];
            }
            //printf("oper: %s\n", oper);
            int k = 0;
            for(int j = 4; j < 18; j++){
                str[k] = string[j];
                k++;
            }
            //printf("strng: %s\n", str);
            if(strcmp(oper, "ADD")){
                ht_insert(ht, string[keyss], string);
                keyss++;
            }else{
                ht_delete(ht, )
            }
            op--;
        }
        cases--;
    }


    return 0;
}

// Novo elemento
static ht_item* ht_new_item(const char* k, const char* v){
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

// Quantidade de elementos que pode ser armazenado
ht_hash_table* ht_new(){
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));

    ht->size = 101;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;

}

static void ht_del_item(ht_item* i){
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table* ht){
    for(int i = 0; i < ht->size; i++){
        ht_item* item = ht->items[i];
        if(item != NULL){
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}
//hashing
static int ht_hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}
void ht_insert(ht_hash_table* ht, const char* key, const char* value) {
    ht_item* item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item != NULL) {
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    } 
    ht->items[index] = item;
    ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    } 
    return NULL;
}

static ht_item HT_DELETED_ITEM = {NULL, NULL};

void ht_delete(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (item != &HT_DELETED_ITEM) {
            if (strcmp(item->key, key) == 0) {
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    } 
    ht->count--;
}

static int ht_get_hash(
    const char* s, const int num_buckets, const int attempt
) {
    int HT_PRIME_1 = 53,HT_PRIME_2=57;
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

int hashCode(const char* s) {
    int h = 0;
    while (*s) {
        h = 31*h + (*s++);
    }
    return h;
}