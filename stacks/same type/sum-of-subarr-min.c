//sum-of-subarr-min
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int sumSubarrayMins(int* arr, int n) {
    int l[n];l[0]=0;
    int r[n];
    int stk[n];
    int top=0;
    for (int i = 0; i < n; i++){
        while (top>0 && arr[stk[top]] > arr[i])
        {
            top--;
        }
        int premin = (top)?stk[top]:-1;
        l[i]=i-premin;// here it included itself also so in right it shouldnt include itself;
        stk[++top]=i;
    }
    top=0;
    for (int i = n-1; i >=0; i--)
    {
        while (top>0 && arr[stk[top]] > arr[i])
        {
            top--;
        }
        int postmin = (top)?stk[top]:n;
        r[i]=postmin-i;
        stk[++top]=i;       
    }
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=(arr[i]*l[i]*r[i]);
    }
    return sum;
}

int main(){
int n;
scanf("%d",&n);
int arr[n];
for (int i = 0; i < n; i++){
  scanf("%d",&arr[i]);
}
  int x = sumSubarrayMins(arr,n);
  printf("%d/n",x);

}
