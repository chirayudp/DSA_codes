#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100007
typedef struct node {
    int val;
    int count;
    struct node* next;
} node;

typedef struct hashmap {
    node* arr[max];
    int size;
} hashmap;

int hash(int k) { 
    return ((k * 17)%max + max) % max; 
}

void insert(hashmap* map, int val) {
    unsigned int h = hash(val);
    node* cur = map->arr[h];

    while (cur) {
        if (cur->val == val) {
            cur->count++;
            return;
        }

        cur = cur->next;
    }
    node* new = malloc(sizeof(node));
    new->count = 1;
    new->val = val;
    new->next = map->arr[h];
    map->arr[h] = new;
}
int search(hashmap* map, int val) {
    unsigned int h = hash(val);
    node* cur = map->arr[h];

    while (cur) {
        if (cur->val == val) {
            return cur->count;
        }

        cur = cur->next;
    }
    return -1;
}
void initmap(hashmap* map) {
    for (int i = 0; i < max; i++) {
        map->arr[i] = NULL;
    }
}
int subarraySum(int* nums, int n, int k) {

    hashmap* map = malloc(sizeof(hashmap));
    map->size = 0;
    initmap(map);
    insert(map, 0);
    int cnt = 0;
    int prefix = 0;

    for (int i = 0; i < n; i++) {
        prefix += nums[i];
        int s = search(map, prefix - k);
        if (s != -1)
            cnt += s;
        insert(map, prefix);
    }
    return cnt;
}
int main(){
int n,t;
scanf("%d %d",&n,&t);
int arr[n];
for (int i = 0; i < n; i++){
    scanf("%d",&arr[i]);
}

printf("%d\n",subarraySum(arr,n,t));
}
