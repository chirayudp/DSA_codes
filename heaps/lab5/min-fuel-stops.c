#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    long long d;
    long long f;
}node;

int cmp(const void* a, const void* b){
    node* x = *(node**)a;
    node* y = *(node**)b;
    if (x->d < y->d) return -1;
    if (x->d > y->d) return 1;
    return 0;
}
void heapify(long long* arr, long long* size,long long i){
    // for(long long i=0; i<*size;i++){
    //     printf("(%lld) ",arr[i]);
    // }
    // printf("bhe\n");
    long long lar = i;
    long long l= 2*i +1;
    long long r = 2*i +2;
    if(l<*size && arr[l]>arr[lar])lar = l;
    if(r<*size && arr[r]>arr[lar])lar = r;
    if(lar != i){
        long long tmp = arr[i];
        arr[i]= arr[lar];
        arr[lar]=tmp;
        heapify(arr,size,lar);
    }
    // for(long long i=0; i<*size;i++){
    //     printf("(%lld) ",arr[i]);
    // }
    // printf("ahe\n");
}
void push(long long* heap,long long* s,long long val){
    long long i=*s;
    heap[(*s)++]=val;
    while (i>0 && heap[(i-1)/2] < heap[i] )
    {
        long long tmp = heap[(i-1)/2];
        heap[(i-1)/2] = heap[i];
        heap[i] = tmp;
        i=(i-1)/2;
    }
    
}
long long pop(long long* heap,long long* s){
    if (*s==0)return 0;
    long long max=heap[0];
    heap[0]=heap[--(*s)];
    heapify(heap,s,0);
    return max;
}

int main(){
    long long t;
    scanf("%lld",&t);
    
    for(long long i=0; i<t;i++){
        long long n,l,p;scanf("%lld %lld %lld",&n,&l,&p);
        node* arr[n+1];
        for(long long j=0; j<n;j++){
            arr[j] = malloc(sizeof(node));
            scanf("%lld %lld",&arr[j]->d,&arr[j]->f);
        }

        arr[n] = malloc(sizeof(node));
        arr[n]->d = l;
        arr[n]->f = 0;
        n++;
        qsort(arr, n, sizeof(node*), cmp);
        long long heap[n] ;
        long long size=0;
        for (long long j = 0; j < n; j++)heap[j]=0;
        
        long long fuel = p;
        long long prev = 0;
        long long stops = 0;
        int u=0;
        for (long long j = 0; j < n; j++){
            long long dist = arr[j]->d - prev;

            while (fuel < dist){
                if (size == 0){
                    printf("-1\n");
                    u=1;
                    break;
                }
                fuel += pop(heap,&size);
                stops++;
            }
            if(u)break;
            fuel -= dist;
            push(heap,&size,arr[j]->f);
            prev = arr[j]->d;

        }
        if(u)continue;
        printf("%lld\n",stops);      
        for (int j = 0; j < n; j++)
        {
            free(arr[j]);
        }
         
    }
}