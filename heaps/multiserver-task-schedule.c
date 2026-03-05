#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void heapify(long long* heap,long long* s,long long i){
    // for (long long i = 0; i < *s; i++)
    // {
    //     printf("bh%lld ",heap[i]);
    // }
    // printf("\n");
    long long lar=i;
    long long l=2*i+1;
    long long r=2*i + 2;
    if(l<*s && heap[lar] > heap[l])lar=l;
    if(r<*s && heap[lar] > heap[r])lar=r;
    if (lar!=i)
    {
        long long tmp = heap[lar];
        heap[lar] = heap[i];
        heap[i] = tmp;
        heapify(heap,s,lar);
    }
    // for (long long i = 0; i < *s; i++)
    // {
    //     printf("ah%lld ",heap[i]);
    // }
    // printf("\n");
}
void push(long long* heap,long long* s,long long val){
    long long i=*s;
    heap[(*s)++]=val;
    while (i>0 && heap[(i-1)/2] > heap[i] )
    {
        long long tmp = heap[(i-1)/2];
        heap[(i-1)/2] = heap[i];
        heap[i] = tmp;
        i=(i-1)/2;
    }
    
}
long long pop(long long* heap,long long* s){
    if (*s==0)return 0;
    long long min=heap[0];
    heap[0]=heap[--(*s)];
    heapify(heap,s,0);
    return min;
}
int main(){
long long t;
scanf("%lld",&t);

while (t--){
  long long n, k;
  scanf("%lld %lld",&n,&k);

    long long arr[n], proc[n];
    for (long long i = 0; i < n; i++){
        scanf("%lld %lld",&arr[i],&proc[i]);
    }
    
    long long heap[n];
    long long size=k;

    for (long long i = 0; i < k; i++)heap[i]=0;

    long long ans[n];

    for (long long i = 0; i < n; i++){
    
        long long a = pop(heap,&size);
        long long start =(a <= arr[i])?arr[i]:a;
        ans[i] = start;

        long long finish = start + proc[i];

        push(heap,&size,finish);

    }
    for (long long i = 0; i < n; i++){
        printf("%lld ",ans[i]);
    }
    printf("\n");
}
}