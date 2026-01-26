#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000003
int main(){
long long t;
scanf("%lld",&t);
for (long long i = 0; i < t; i++)
{
    char* s = malloc(sizeof(char)*(max));
    scanf("%s",s);
    long long k;scanf("%lld",&k);
    long long n = strlen(s);
    long long stk[n];
    long long top=-1;
    for (long long j = 0; j < n; j++)
    {
        long long d = s[j]-'0';
        while (top>=0 && k>0 && stk[top]>d)
        {
            // printf("%lld ",top);
            top--;
            k--;
        }
        stk[++top]=d;
        // printf("\n");
    }
    
    while (k > 0 && top>=0) {
            top--;
            k--;
        }

    long long l=0;
    while (l<=top && stk[l]==0)l++;
    if (l>top)printf("0\n");
    else{
        for (long long p = l; p < top+1; p++)
        {
            printf("%lld",stk[p]);
        }printf("\n");
    }
        
    
    
    free(s);
}
}
