#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int f;
    int b ;
    int q[3000];
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* new = malloc(sizeof(RecentCounter));
    new->f= new->b=-1;
    return new;
}

int recentCounterPing(RecentCounter* obj, int t) {
    if (obj->f==-1)
    {
        obj->q[++obj->f]=t;
        obj->b++;
        return 1;
    }
    obj->q[++obj->b]=t;
    while (obj->f <= obj->b)
    {
        if (obj->q[obj->f]>= t-3000){printf("%d ",obj->q[obj->b]); return obj->b-(obj->f)+1;}
        obj->f++;
    }
    return 0;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}


/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/

int main(){
long long n;
scanf("%lld",&n);

}


