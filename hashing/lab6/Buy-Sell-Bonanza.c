
#include <stdio.h>
#include <stdlib.h>
#define max 50003
typedef struct node {
    long long key,val;
    struct node *next;
} node;
typedef struct hashmap{
    node* arr[max];
    long long size;
}hashmap;
unsigned long long hash(long long key){
    return (unsigned long long)((key*17)%max+ max)%max;
}
node* create(long long key,long long val){
    node* new = malloc(sizeof(node));
    new->val = val;
    new->key= key;
    new->next=NULL;
    return new;
}
void insert(hashmap* map,long long key,long long val){
    unsigned long long h=hash(key);
    node* new = create(key,val);
    new->next = map->arr[h];
    map->arr[h] = new;
}

long long search(hashmap* map,long long key){
    unsigned long long h=hash(key);
    node* cur = map->arr[h];
    while(cur){
        if(cur->key == key){
            return cur->val;
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
        long long n;
        scanf("%lld", &n);
        long long arr[n];
        for(long long i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        long long m=0;
        for(long long i=0;i<max;i++){
            map->arr[i]=NULL;
        }
        long long prefix[n+1];
        prefix[0]=0;
        prefix[1]=arr[0];
        for(long long i=2;i<=n;i++){
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        for(long long r=0;r<n+1;r++){
            long long s=search(map,prefix[r]);
            if(s!=-1){
                if(r-s>m)m=r-s;
                continue;
            }
            insert(map,prefix[r],r);
        }
        printf("%lld\n",m);
    }
    for(long long i=0;i<max;i++){
        free(map->arr[i]);
    }
}