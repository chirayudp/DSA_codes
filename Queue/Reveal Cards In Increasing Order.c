/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

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
    for(int i=0; i <= mid-l;i++)free(left1[i]);
    free(left1);
    for(int i=0; i <= mid-r-1;i++)free(right1[i]);
    free(right1);
    printf("%d*%d\n",l,r);
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
int* deckRevealedIncreasing(int* deck, int d, int* returnSize) {
    mergesort(deck,0,d);
    int l=0,r=0;
    int n=d-1;
    int* arr = malloc(sizeof(int)*d);
    while(r!=d-1){
        arr[r++]=deck[n--];
        int tmp=arr[0];
        for (int i = 1; i < r; i++)
        {
            arr[i-1]=arr[i];
        }
        arr[r]=tmp;
    }    
    return arr ;
}