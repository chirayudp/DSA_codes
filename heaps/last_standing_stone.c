#include<stdio.h>
#include<stdlib.h>

void heapify(int* heap, int *size, int i) {
    int lar = i;
    int l = i * 2 + 1;
    int r = 2 * i + 2;
    if (l < *size && heap[l] > heap[lar])
        lar = l;
    if (r < *size && heap[r] > heap[lar])
        lar = r;
    if (lar != i) {
        int tmp = heap[lar];
        heap[lar] = heap[i];
        heap[i] = tmp;
        heapify(heap, size, lar);
    }
}
void build(int* heap, int* n) {
    for (int i = (*n) / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}
int delete(int* heap,int *size){
    int max=heap[0];
    heap[0]=heap[(*size)-1];(*size)--;
    heapify(heap, size,0);
    return max;
}
void insert(int* heap,int* size,int val){
    int i=*size;
    heap[(*size)++]=val;
    while(i>0 && heap[(i-1)/2] < heap[i]){
        int tmp=heap[(i-1)/2];
        heap[(i-1)/2]=heap[i];
        heap[i] = tmp;
        i=(i-1)/2;
    }
}
int lastStoneWeight(int* stones, int n) {
    if (n == 1) return stones[0];
    int i=n;
    while(i>1){
        build(stones, &i);
        int x = delete(stones,&i), y = delete(stones,&i);
        if(x!=y)insert(stones,&i,x-y);
        // else insert(stones,&i,0);
    }
    return i?stones[0]:0;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    printf("%d",lastStoneWeight(arr,n));
}