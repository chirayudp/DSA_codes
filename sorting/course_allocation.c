#include<stdio.h>
#include<stdlib.h>

void merge(long long* arr1,long long*arr2, long long* arr3,long long l,long long mid,long long r){
    long long* left1=malloc(sizeof(long long)*(mid-l+1));
    long long* left2=malloc(sizeof(long long)*(mid-l+1));
    long long* left3=malloc(sizeof(long long)*(mid-l+1));
    for(long long i=l;i<=mid;i++){
        // printf("_inl\n");
        left1[i-l] = arr1[i];
        left2[i-l] = arr2[i];
        left3[i-l] = arr3[i];
    }
    long long* right1=malloc(sizeof(long long)*(r-mid));
    long long* right2=malloc(sizeof(long long)*(r-mid));
    long long* right3=malloc(sizeof(long long)*(r-mid));
    for(long long i=mid+1;i<=r;i++){
        // printf("_inr\n");
        right1[i-mid-1] = arr1[i];
        right2[i-mid-1] = arr2[i];
        right3[i-mid-1] = arr3[i];
    }
    long long i=0,j=0;
    for(long long k=l;k<=r;k++){
        if(i>=(mid-l+1)){
            arr1[k] = right1[j] ;
            arr2[k] = right2[j] ;
            arr3[k] = right3[j] ;
            j++;
        }
        else if(j>=(r-mid)){
            arr1[k] = left1[i] ;
            arr2[k] = left2[i] ;
            arr3[k] = left3[i] ;i++;
        }
        // didnt account for ==
        else if(left3[i]<=right3[j]){
            arr1[k] = left1[i] ;
            arr2[k] = left2[i] ;
            arr3[k] = left3[i] ;i++;
        }
        else{
            arr1[k] = right1[j] ;
            arr2[k] = right2[j] ;
            arr3[k] = right3[j] ;j++;
        }
    }
    return ;
}
void mergesort(long long* arr1,long long* arr2,long long* arr3,long long l,long long r){
    if(r-l<=0)return;
    long long mid=(r-l)/2 + l;
    mergesort(arr1,arr2,arr3,l,mid);
    mergesort(arr1,arr2,arr3,mid+1,r);
    merge(arr1,arr2,arr3,l,mid,r);
    return;
}
int main()
{
    long long t;
    scanf("%lld",&t);
    long long arr0[t],arr1[t],arr2[t];
    for(long long i=0;i<t;i++){
        long long x,y;
        scanf("%lld %lld",&x,&y);arr0[i]=x-y;
        arr1[i]=x;arr2[i]=y;
    }
    long long sum = 0;
    mergesort(arr1,arr2,arr0,0,t-1);
    for(long long j=0;j<(t);j++){
        if(j<t/2){sum+=arr1[j];}
        else sum+=arr2[j];
    }
    printf("%lld\n",sum);
}