
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int ls,rs,cap;
    int *left ;
    int *right;
} MedianFinder;


MedianFinder* medianFinderCreate() {
    MedianFinder* new = malloc(sizeof(MedianFinder));
    new->ls = new->rs = 0;
    new->cap=10005;
    new->left = malloc(sizeof(int)*10005);
    new->right = malloc(sizeof(int)*10005);
    return new;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->ls<obj->rs)
    {
        obj->left[(obj->ls)++] = num;
    }
    else obj->right[(obj->ls)++] = num;
}

double medianFinderFindMedian(MedianFinder* obj) {
    
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

int main(){
long long n;
scanf("%lld",&n);
MedianFinder* obj = medianFinderCreate();
medianFinderAddNum(obj, n);
medianFinderFree(obj);
}
