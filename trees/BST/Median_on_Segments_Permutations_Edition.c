#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
long long n,m;
scanf("%lld %lld" ,&n,&m);
long long arr[n];
long long t=-1;
for (long long i = 0; i < n; i++)
{
   scanf("%lld",&arr[i]);
   if(arr[i]==m)t=i;
}
if(t==-1){
    printf("0\n");
    return 0 ;
}

long long count=0;
long long l=t-1,r=t;
long long bal=0;
long long freq[2*n+1];
for (long long i = 0; i <=2*n; i++)
{
    freq[i]=0;
}

freq[bal+n]=1;
while (l>=0)
{
    if (arr[l]>m)
    {
        bal+=1;
    }
    else bal-=1;
    freq[bal+n]++;
    l--;
}
bal=0;
while (r<=n-1)
{
    if (arr[r]>m)bal+=1;
   
    else if(arr[r]<m)bal-=1;
    r++;
    count+=freq[-bal+n];
    count+=freq[1-bal+n];
}

printf("%lld\n",count);
}
