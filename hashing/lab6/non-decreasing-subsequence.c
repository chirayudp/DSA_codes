#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        int stk[n+1];
        int top=0;
        int lmin[n];
        for(int i=0; i<n ;i++){
            // printf("%d %d ",i,top);
            while(top>0 && arr[stk[top]]>=arr[i]){
                top--;
            }
            int prev=(top>0)?stk[top]:-1;
            lmin[i]=i-prev;
            stk[++top]=i;
            // printf("%d %d %d\n",prev,lmin[i],top);
        }
        int count=0;
        for(int i=0;i<n;i++){
            count+=((lmin[i]+1)*lmin[i]/2);
        }
        printf("%d\n",count);
    }
}