#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void merge(int* arr , int l, int mid, int r){
    if(l>=r)return ;
    int ls=mid-l+1;
    int rs=r-mid;
    int left[ls];
    int right[rs];
    for (int i = l; i <=mid; i++)
    {
        left[i-l]=arr[i];
    }
    for (int i = mid+1; i <=r; i++)
    {
        right[i-1-mid] = arr[i];
    }
    int n=0 ,m=0;
    for (int i = l; i <= r; i++)
    {
        if( n>=ls)arr[i]=right[m++];
        else if(m>=rs)arr[i]=left[n++];
        else if(left[n]<right[m])arr[i]=left[n++];
        else arr[i]=right[m++];
    }
}

void mergesort(int* arr,int l, int r){
    if (l>=r)return ;
    int mid = l + ((r-l)>>1);
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return;
}

int missingminsum(int* nums, int s)  {
    mergesort(nums,0,s-1);
    if (nums[0]!=1)return 1;
    int sum=1;
    for (int i = 0; i < s; i++)
    {
        if(nums[i]>sum)return sum;
        sum+=nums[i];
    }
    return sum;
}

int main(){
long long n;
scanf("%lld",&n);
int arr[n];
for (int i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);
}
int m = missingminsum(arr,n);
printf("%d",m);
printf("\n");
}
