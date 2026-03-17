/**
* Note: The returned array must be malloced, assume caller calls free().
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char key[11];
    int cnt;
    struct node* next;
} node;
typedef struct {
    int size;
    node* arr[500];
} hashmap;

node* create(char* key) {
    node* new = malloc(sizeof(node));
    strcpy(new->key, key);
    new->next = NULL;
    new->cnt = 1;
    return new;
}
void init(hashmap* map) {
    for (int i = 0; i < 500; i++) {
        map->arr[i] = NULL;
    }
}
unsigned int hash(char* key) {
    unsigned int h = 0;
    while (*key) {
        h = h * 17 + *key;
        key++;
    }
    return h % 500;
}
void insert(hashmap* map, char* key) {
    unsigned int h = hash(key);
    node* cur = map->arr[h];
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            cur->cnt++;
            return;
        }
        cur = cur->next;
    }
    node* new = create(key);
    new->next = map->arr[h];
    map->arr[h] = new;
    map->size++;
}
int cmp(const void *a,const void* b){//
    node* x = *(node**)a;
    node* y = *(node**)b;
    if (x->cnt != y->cnt)
    {
        return x->cnt > y->cnt;
    }
    return strcmp(x->key,y->key);
}
char** topKFrequent(char** words, int w, int k, int* r) {
    hashmap* map = malloc(sizeof(hashmap));
    init(map);
    map->size = 0;
    for (int i = 0; i < w; i++) {
        insert(map, words[i]);
    }
    node** a = malloc(sizeof(node*) * map->size);
    *r = map->size;
    int t = 0;
    for (int i = 0; i < 500; i++) {
        node* cur = map->arr[i];
        while (cur) {
            a[t] = malloc(sizeof(node));
            a[t++] = cur;
            cur = cur->next;
        }
    }
    qsort(a,map->size,sizeof(node),cmp);
    char** arr = malloc(sizeof(char*) * map->size);
    t=0;
    for (int i = 0; i < k; i++)
    {
        arr[t] = malloc(strlen(a[i]->key) + 1);
        strcpy(arr[t++],a[i]->key);
    }
    
    return arr;
}