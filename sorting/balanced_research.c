#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void merge(int* arr1,int l,int mid,int r){
    int* left1=malloc(sizeof(int)*(mid-l+1));
    for(int i=l;i<=mid;i++){
        // printf("_inl\n");
        left1[i-l] = arr1[i];
        
    }
    int* right1=malloc(sizeof(int)*(r-mid));
    
    for(int i=mid+1;i<=r;i++){
        // printf("_inr\n");
        right1[i-mid-1] = arr1[i];
        
    }
    int i=0,j=0;
    for(int k=l;k<=r;k++){
        if(i>=(mid-l+1)){
            arr1[k] = right1[j] ;
            
            j++;
        }
        else if(j>=(r-mid)){
            arr1[k] = left1[i] ;
            i++;
        }
        // didnt account for ==
        else if(left1[i]<=right1[j]){
            arr1[k] = left1[i] ;
            i++;
        }
        else{
            arr1[k] = right1[j] ;
            j++;
        }
    }
    free(left1);
    free(right1);
    return ;
}
void mergesort(int* arr1,int l,int r){
    if(r-l<=0)return;
    int mid=(r-l)/2 + l;
    mergesort(arr1,l,mid);
    mergesort(arr1,mid+1,r);
    merge(arr1,l,mid,r);
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&nums[i]);
    }
    mergesort(nums,0,n-1);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",nums[i]);
    // }
    int m=nums[1]-nums[0];
    for (int i = 2; i < n; i++)
    {
        if(m>nums[i]-nums[i-1])m=nums[1+i]-nums[i];
    }
    printf("%d",m);
}