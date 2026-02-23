#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void heapify(int* heap,int* s,int i){
    // for (int i = 0; i < *s; i++)
    // {
    //     printf("bh%d ",heap[i]);
    // }
    // printf("\n");
    int lar=i;
    int l=2*i+1;
    int r=2*i + 2;
    if(l<*s && heap[lar] < heap[l])lar=l;
    if(r<*s && heap[lar] < heap[r])lar=r;
    if (lar!=i)
    {
        int tmp = heap[lar];
        heap[lar] = heap[i];
        heap[i] = tmp;
        heapify(heap,s,lar);
    }
    // for (int i = 0; i < *s; i++)
    // {
    //     printf("ah%d ",heap[i]);
    // }
    // printf("\n");
}
void push(int* heap,int* s,int val){
    int i=*s;
    heap[(*s)++]=val;
    while (i>0 && heap[(i-1)/2] < heap[i] )
    {
        int tmp = heap[(i-1)/2];
        heap[(i-1)/2] = heap[i];
        heap[i] = tmp;
        i=(i-1)/2;
    }
    
}
void pop(int* heap,int* s){
    if (*s==0)
    {
        printf("-1\n");
        return;
    }
    heap[0]=heap[--(*s)];
    heapify(heap,s,0);
}
void peek(int* heap,int* s){
    if ((*s)==0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n" ,heap[0]);
    
}
int main(){
long long t;
scanf("%lld",&t);
int size;
int heap[t+1];
while (t--)
{
    int n;scanf("%d",&n);
    if (n==1)
    {
        int x;scanf("%d",&x);
        push(heap,&size,x);
    }
    else if (n==2)
    {
        pop(heap,&size);
    }
    else if (n==3)
    {
        peek(heap,&size);
    }
    
}

}
