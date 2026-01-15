#include<stdio.h>
#include<stdlib.h>

void merge(int* arr1,int*arr2, int* arr3,int l,int mid,int r){
    int* left1=malloc(sizeof(int)*(mid-l+1));
    int* left2=malloc(sizeof(int)*(mid-l+1));
    int* left3=malloc(sizeof(int)*(mid-l+1));
    for(int i=l;i<=mid;i++){
        // printf("_inl\n");
        left1[i-l] = arr1[i];
        left2[i-l] = arr2[i];
        left3[i-l] = arr3[i];
    }
    int* right1=malloc(sizeof(int)*(r-mid));
    int* right2=malloc(sizeof(int)*(r-mid));
    int* right3=malloc(sizeof(int)*(r-mid));
    for(int i=mid+1;i<=r;i++){
        // printf("_inr\n");
        right1[i-mid-1] = arr1[i];
        right2[i-mid-1] = arr2[i];
        right3[i-mid-1] = arr3[i];
    }
    int i=0,j=0;
    for(int k=l;k<=r;k++){
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
    // for(int i=0; i <= mid-l;i++)free(left1[i]);
    // free(left1);
    // for(int i=0; i <= mid-r-1;i++)free(right1[i]);
    // free(right1);
    // printf("%d*%d\n",l,r);
    return ;
}
void mergesort(int* arr1,int* arr2,int* arr3,int l,int r){
    if(r-l<=0)return;
    int mid=(r-l)/2 + l;
    mergesort(arr1,arr2,arr3,l,mid);
    mergesort(arr1,arr2,arr3,mid+1,r);
    merge(arr1,arr2,arr3,l,mid,r);
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    int arr0[t],arr1[t],arr2[t];
    for(int i=0;i<t;i++){
        int x,y;
        scanf("%d %d",&x,&y);arr0[i]=x-y;
        arr1[i]=x;arr2[i]=y;
        // printf("_in1\n");
    }
    // for(int j=0;j<(t);j++){
    //     printf("%d ",arr1[j]);
    // }
    // printf("\n");
    // for(int j=0;j<(t);j++){
    //     printf("%d ",arr2[j]);
    // }
    // printf("\n");
    // for(int j=0;j<(t);j++){
    //     printf("%d ",arr0[j]);
    // }
    // printf("\n");

    int sum = 0;
    mergesort(arr1,arr2,arr0,0,t-1);

    // for(int j=0;j<(t);j++){
    //     printf("%d ",arr1[j]);
    // }
    // printf("\n");
    // for(int j=0;j<(t);j++){
    //     printf("%d ",arr2[j]);
    // }
    // printf("\n");
    // for(int j=0;j<(t);j++){
    //     printf("%d ",arr0[j]);
    // }
    // printf("\n");


    for(int j=0;j<(t);j++){
        if(j<t/2){sum+=arr1[j];}
        else sum+=arr2[j];
    }
    
    // printf("\n");printf("|%d| ",sum);

    printf("%d\n",sum);
    // printf("\n");
}