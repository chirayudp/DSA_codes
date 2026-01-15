#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct guards{
    int lvl;
    int exp;
}guards;

void merge(guards** arr, int l,int mid,int r){
    guards** left = malloc(sizeof(guards*)*(mid-l+1));
    for (int i = l; i <=mid; i++){
        left[i-l]=malloc(sizeof(guards));
        left[i-l]->lvl=arr[i]->lvl;
        left[i-l]->exp=arr[i]->exp;
    }
    guards** right= malloc(sizeof(guards*)*(r-mid));
    for (int i = mid+1; i <=r; i++){
        right[i-(mid+1)]=malloc(sizeof(guards));
        right[i-(mid+1)]->lvl=arr[i]->lvl;
        right[i-(mid+1)]->exp=arr[i]->exp;
    }
    int t=0,m=0;
    for (int i = l; i <=r; i++)
    {
        if (t>=(mid-l+1)){
            arr[i]->lvl=right[m]->lvl;
            arr[i]->exp=right[m++]->exp;
        }
        else if(m>=(r-mid)){
            arr[i]->lvl=left[t]->lvl;
            arr[i]->exp=left[t++]->exp;
        }
        else if((left[t]->lvl) <= (right[m]->lvl)){
            arr[i]->lvl=left[t]->lvl;
            arr[i]->exp=left[t++]->exp;
        }
        else {
            arr[i]->lvl=right[m]->lvl;
            arr[i]->exp=right[m++]->exp;
        }
    }
    
    for (int i = 0; i <=mid-l; i++)free(left[i]);
    for (int i = 0; i <=r-mid-1; i++)free(right[i]);
    free(left);free(right);
    return;
}
void mergesort(guards** arr,int l, int r){
    if(r-l<=0)return ;
    int mid=(r-l)/2 +l;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return;
}
int main(){
int t;
scanf("%d",&t);
for (int i = 0; i < t; i++)
{
    int s,n;
    scanf("%d %d",&s,&n);
    guards** arr = malloc(sizeof(guards*)*(n));
    for (int j = 0; j < n; j++)
    {
        int x,y; scanf("%d %d",&x,&y);
        arr[j]= malloc(sizeof(guards));
        arr[j]->lvl=x;
        arr[j]->exp=y;
    }
    mergesort(arr,0,n-1);
    int h=0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j]->lvl >= s){
            h=1;
            break;
        }
        else s+=arr[j]->exp;
    }
    if(h)printf("NO\n");
    else printf("YES\n");

    for (int i = 0; i < n; i++)free(arr[i]);
    free(arr);
}

}
