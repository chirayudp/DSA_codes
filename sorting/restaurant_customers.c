#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct custime{
    int time;
    int val;
}custime;

void merge(custime** arr, int l,int mid,int r){
    custime** left = malloc(sizeof(custime*)*(mid-l+1));
    for (int i = l; i <=mid; i++){
        left[i-l]=malloc(sizeof(custime));
        left[i-l]->time=arr[i]->time;
        left[i-l]->val=arr[i]->val;
    }
    custime** right= malloc(sizeof(custime*)*(r-mid));
    for (int i = mid+1; i <=r; i++){
        right[i-(mid+1)]=malloc(sizeof(custime));
        right[i-(mid+1)]->time=arr[i]->time;
        right[i-(mid+1)]->val=arr[i]->val;
    }
    int n=0,m=0;
    for (int i = l; i <=r; i++)
    {
        if (n>=(mid-l+1)){
            arr[i]->time=right[m]->time;
            arr[i]->val=right[m++]->val;
        }
        else if(m>=(r-mid)){
            arr[i]->time=left[n]->time;
            arr[i]->val=left[n++]->val;
        }
        else if((left[n]->time) <= (right[m]->time)){
            arr[i]->time=left[n]->time;
            arr[i]->val=left[n++]->val;
        }
        else {
            arr[i]->time=right[m]->time;
            arr[i]->val=right[m++]->val;
        }
    }
    
    for (int i = 0; i <=mid-l; i++)free(left[i]);
    for (int i = 0; i <=r-mid-1; i++)free(right[i]);
    free(left);free(right);
    return;
}
void mergesort(custime** arr,int l, int r){
    if(r-l<=0)return ;
    int mid=(r-l)/2 +l;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return;
}
int main(){
int n;
scanf("%d",&n);
custime** arr = malloc(sizeof(custime*)*(n<<1));

int o=0;
for (int i = 0; i < n; i++)
{
    int a,b;
    scanf("%d %d",&a,&b);
    arr[o]=malloc(sizeof(custime));
    arr[o]->time=a;arr[o++]->val=1;
    arr[o]=malloc(sizeof(custime));
    arr[o]->time=b;arr[o++]->val=-1;
}
int c=0,max=0;
mergesort(arr,0,2*n-1);
for (int i = 0; i < 2*n; i++)
{
    if (arr[i]->val==1)c++;
    if (c>max)max=c;
    if(arr[i]->val == -1) c--;     
}
printf("%d",max);

for (int i = 0; i < (n<<1); i++)
{
    free(arr[i]);
}
free(arr);
}
