#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 200007
typedef struct node {
    long long cnt;
    long long key;
    struct node *next;
} node;
typedef struct hashmap{
    node* arr[max];
    long long size;
}hashmap;
node* create(long long key){
    node* new = malloc(sizeof(node));
    new->cnt = 1;
    new->key=key;
    new->next=NULL;
    return new;
}
unsigned long long hash(long long key){
    return (unsigned long long)((key*17)%max + max)%max;
}
void insert(hashmap* map,long long key){
    unsigned long long h=hash(key);
    node* cur=map->arr[h];
    while(cur){
        if(cur->key == key){
            cur->cnt++;
            return ;
        }
        cur = cur -> next;
    }
    node* new = create(key);
    new->next = map->arr[h];
    map->arr[h] = new;
}
long long search(hashmap* map,long long key){
    unsigned long long h=hash(key);
    node* cur = map->arr[h];
    while(cur){
        if(cur->key==key){
            return cur->cnt;
        }
        cur = cur -> next;
    }
    return -1;
}
int main() {
    long long t;
    scanf("%lld", &t);
    hashmap* map = malloc(sizeof(hashmap));
    map->size=0;

    while(t--){
        for(long long i=0;i<max;i++){
            map->arr[i]=NULL;
        }
        long long n,k;
        scanf("%lld %lld", &n,&k);
        long long arr[n];
        for(long long i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        for(long long i=0;i<=n-k;i++){
            long long s=0;
            for(long long j=0; j<k;j++){
                s=s*10 + arr[i+j];
            }
            insert(map,s);
        }
        for(long long i=0; i<max;i++){
            node* cur = map->arr[i];
            while(cur!=NULL){
                if(cur->cnt >1){
                    printf("%lld\n",cur->key);
                }
                cur = cur -> next;
            }
        }
    }
    for(long long i=0;i<max;i++){
        free(map->arr[i]);
    }
}