#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 10007

typedef struct node{
    struct node* next;
    int key;
    int idx;
}node;

node* htable[size];

int hash(int key){
    if (key<0)
    {
        key = -key;
    }
    return key % size;
}
 
void insert(int key , int index){ // insert at head if a-> b-> c then insert(x) makes x-> a-> b-> c
    int h = hash(key);
    node* new =  malloc(sizeof(node));
    new->key=key;
    new->idx=index;
    new->next=htable[h];
    htable[h]=new;
}

node* search(int key){
    int h = hash(key);
    node* cur = htable[h];
    while (cur)
    {
        if(cur->key == key)return cur;
        cur = cur->next;
    }
    return NULL;
}
int* twoSum(int* nums, int n, int target, int* r) {
    int* list = malloc(sizeof(int)*2);
    for (int i = 0; i < size; i++)
    {
        htable[i]=NULL;
    }
    
    for (int i = 0; i < n; i++)
    {
        int val = target - nums[i];
        node* cur = search(val);
        if (cur)
        {
            list[0]=cur->idx;
            list[1]=i;
            return list;
        }
        insert(nums[i],i);
    }
    *r = 2;
    return NULL;
}


int main(){

    int nums[] = {2,7,11,15};
    int target = 9;
    int n = 4;
    int returnSize;

    int* ans = twoSum(nums,n,target,&returnSize);

    if(ans){
        printf("%d %d\n", ans[0], ans[1]);
    }

    return 0;
}

