#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
long long n;
scanf("%lld",&n);
long long arr[n];
for (long long i = 0; i < n; i++)
{
    scanf("%lld",&arr[i]);
}
long long lmin[n];
long long rmin[n];

long long lmax[n];
long long rmax[n];

long long stk[n];
stk[0]=0;
long long top=0;
long long prev=0;
long long next=0;
long long maxcont[n];
for (long long i = 0; i < n; i++)
{
    while (top>0 && arr[stk[top]]<=arr[i])
    {
        top--;
    }
    if(top)
        prev=stk[top];
    else prev = -1;
    lmax[i]=i-prev;
    stk[++top]=i;
}
top=0;
for (long long i = n-1; i >=0; i--)
{
    while (top>0 && arr[stk[top]]<arr[i])
    {
        top--;
    }
    next=top?stk[top]:n;
    rmax[i]=next-i;
    stk[++top]=i;
}
for (long long i = 0; i < n; i++)
{
    maxcont[i]=lmax[i]*rmax[i];
}
top=0;
prev=0;
next=0;
for (long long i = 0; i < n; i++)
{
    while (top>0 && arr[stk[top]]>=arr[i])
    {
        top--;
    }
    if(top)
        prev=stk[top];
    else prev = -1;
    lmin[i]=i-prev;
    stk[++top]=i;
}
top=0;
for (long long i = n-1; i >=0; i--)
{
    while (top>0 && arr[stk[top]]>arr[i])
    {
        top--;
    }
    next=top?stk[top]:n;
    rmin[i]=next-i;
    stk[++top]=i;
}
long long mincont[n];
for (long long i = 0; i < n; i++)
{
    mincont[i]=(lmin[i]*rmin[i]);
}
long long imb=0;
for (long long i = 0; i < n; i++)
{
    imb+= arr[i]*(maxcont[i] - mincont[i]);
}

printf("%lld\n",imb);
}

// long long stk[n];stk[0]=0;
// long long l=0;long long r=0;
// long long size=0;
// long long imb=0;
// while (l<n)
// {
//     if (r>=n)
//     {
//         l++;
//         r=l;
//         size=0;
//     }
//     if (r==l)
//     {
//         stk[0]=arr[l];
//         r++;
//         size++;
//     }
//     else {
//         if (size==1)
//         {
//             stk[size++]=arr[r++];
//             if(stk[0]>stk[1]){
//                 long long tmp=stk[0];
//                 stk[0]=stk[1];
//                 stk[1]=tmp;
//             }
//             imb+=stk[1]-stk[0];
//             // printf("%lld ",imb);
//         }
//         else if(size>1){
//             if(stk[0]>stk[1]){
//                 long long tmp=stk[0];
//                 stk[0]=stk[1];
//                 stk[1]=tmp;
//             }
//             if(arr[r]>stk[1])stk[1]=arr[r];
//             else if(arr[r]<stk[0])stk[0]=arr[r];
//             imb+=stk[1]-stk[0];
//             // printf("%lld ",imb);
//             r++;size++;
//         }
//     }
// }