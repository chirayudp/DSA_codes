#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000000007
long long top=-1;
void push(long long* stk ,long long n,long long item){
    if(top+1 == n){
        printf("-1\n");
        return;
    }
    stk[++top]=item;
}
void pop(){
    if (top == -1){
        printf("-1\n");
        return;
    }
    top--;
}
void size(){
    printf("%lld\n",top+1);
}
void getsum(long long *arr){
    long long sum=0;
    for (long long i = 0; i < top+1; i++)
    {
        sum+=((arr[i] % max + max )% max);
    }
    printf("%lld\n",( sum % max + max ) % max);
}
void isfull(long long* arr,long long n){
    if (top+1 == n)
    {
        printf("YES\n");
        return ;
    }
    printf("NO\n");
}

int main(){  
long long k,n;
scanf("%lld %lld",&k,&n);
long long stk[n];
for (long long i = 0; i < k; i++)
{
    long long q;
    scanf("%lld",&q);
    if (q==1)
    {
        long long x;
        scanf("%lld",&x);
        push(stk,n,x);
    }
    else if (q==2)
    {
        pop();
    }
    else if (q==3)
    {
       getsum(stk);
    }
    else if (q==4)
    {
        isfull(stk,n);
    }
    
    else if (q==5)
    {
        size();
    }
    
}

}
