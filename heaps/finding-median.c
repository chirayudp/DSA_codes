#define max 50001

typedef struct {
    int *minheap;
    int *maxheap;
    int minsize;
    int maxsize;
} MedianFinder;
void swap(int* a,int* b){
    int tmp =  *a;
    *a = *b;
    *b = tmp;
}
void insertmin(MedianFinder* obj,int num){
    int i=obj->minsize++;
    obj->minheap[i]=num;
    while (i>0 && obj->minheap[(i-1)/2] > obj->minheap[i])
    {
        swap(&obj->minheap[(i-1)/2] ,&obj->minheap[i]);
        i = (i-1)/2;
    }
    
}
void insertmax(MedianFinder* obj,int num){
    int i=obj->maxsize++;
    obj->maxheap[i]=num;
    while (i>0 && obj->maxheap[(i-1)/2] < obj->maxheap[i])
    {
        swap(&obj->maxheap[(i-1)/2] ,&obj->maxheap[i]);
        i = (i-1)/2;
    }
}
void heapifymax(MedianFinder* obj,int i){
    int lar = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < obj->maxsize && obj->maxheap[lar]<obj->maxheap[left])lar = left;
    if(right < obj->maxsize && obj->maxheap[lar]<obj->maxheap[right])lar = right;
    if (lar!=i)
    {
        swap(&obj->maxheap[lar],&obj->maxheap[i]);
        heapifymax(obj,lar);
    }
}
void heapifymin(MedianFinder* obj,int i){
    int sml = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < obj->minsize && obj->minheap[sml]>obj->minheap[left])sml = left;
    if(right < obj->minsize && obj->minheap[sml]>obj->minheap[right])sml = right;
    if (sml!=i)
    {
        swap(&obj->minheap[sml],&obj->minheap[i]);
        heapifymin(obj,sml);
    }
}
int delete(MedianFinder* obj,int i){
    if (i)
    {
        int lar = obj->maxheap[0];
        obj->maxheap[0] = obj->maxheap[obj->maxsize-1];
        obj->maxsize--;
        heapifymax(obj,0);
        return lar;
    }
    else{
        int sml = obj->minheap[0];
        obj->minheap[0] = obj->minheap[obj->minsize-1];
        obj->minsize--;
        heapifymin(obj,0);
        return sml;
    }
    
}
MedianFinder* medianFinderCreate() {
    MedianFinder* new = malloc(sizeof(MedianFinder));
    new->minheap = malloc(sizeof(int)* max);
    new->maxheap = malloc(sizeof(int)* max);
    new->minsize= new->maxsize = 0;
    return new;
}
void balance(MedianFinder* obj){
    if(obj->maxsize > obj->minsize + 1){
        int l = delete(obj,1);
        insertmin(obj,l);
    }
    else if(obj->minsize > obj->maxsize + 1){
        int s = delete(obj,0);
        insertmax(obj,s);
    }
}
void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxsize == 0 || num<=obj->maxheap[0])
    {
        insertmax(obj,num);
    }
    else insertmin(obj,num);
    balance(obj);
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxsize == obj->minsize)
    {
        return (obj->maxheap[0]+obj->minheap[0])/2.0;
    }
    else if (obj->maxsize > obj->minsize)
    {
        return (obj->maxheap[0])/1.0;
    }
    return (obj->minheap[0])/1.0;
    
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->minheap);
    free(obj->maxheap);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/