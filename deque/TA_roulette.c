#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
int n;
scanf("%d",&n);
int deq[n];
int head=0,tail=n;
for (int i = 0; i < n; i++) deq[i]=i+1;
while(tail>0){
    tail--;
    while(deq[head] == 0){
        head=(head+1)%n;    
    }
    
    head = (head+1) % n;
    while(deq[head] == 0){
        head = (head + 1)%n;
    }
    if (deq[head]!=0) printf("%d ",deq[head]);
    deq[head]=0;
}
}
