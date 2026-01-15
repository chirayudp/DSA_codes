#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge(int* arr, int l, int mid, int r){
    int left[mid-l+1],right[r-mid];
    for (int i = l; i <=mid; i++)
    {
        left[i-l]=arr[i];
    }
    for (int i = mid+1; i <= r; i++)
    {
        right[i-(mid+1)]=arr[i];
    }
    int i=0,j=0;
    for (int k = l; k <= r; k++)
    {
        if (i>=(mid-l+1))arr[k]=right[j++];
        else if (j>=(r-mid))arr[k]=left[i++];
        else if (left[i]<=right[j])arr[k]=left[i++];
        else arr[k]=right[j++];  
    }
    return ;
}

void mergesort(int* arr, int l, int r){
    if(r-l<=0)return ;
    int mid=(r-l)/2 +l;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return ;
}

int main(){
int arr[]={5,203,5 ,1,9,7,-400};
int n=sizeof(arr)/sizeof(arr[0]);
mergesort(arr,0,n-1);
for (int i = 0; i < n; i++)
{
    printf("%d ", arr[i]);
}
printf("\n");
return 0;
}

