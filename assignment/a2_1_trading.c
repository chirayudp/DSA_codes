#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100007
typedef struct node
{
    int a,d;
    int cnt;
    struct node* next;
}node;
typedef struct hashmap
{
    node* arr[max];
    int size;
}hashmap;

node* create(int a, int d){
    node* new = malloc(sizeof(node));
    new->a=a;
    new->d=d;
    new->cnt=1;
    new->next=NULL;
    return new;
}
unsigned int hash(int a ,int d){
    return (unsigned int)(a*17 + d)%max;
}
void insert(hashmap *map,int a ,int d){
    unsigned int h=hash(a,d);
    node* cur=map->arr[h];
    while (cur)
    {
        if (cur->a==a && cur->d==d)
        {
            cur->cnt++;
            return ;
        }
        
        cur=cur->next;
    }

    node* new =create(a,d);
    new->next=map->arr[h];
    map->arr[h] = new;
    map->size++;
}
void delete(hashmap * map,int a,int d){
    unsigned int h=hash(a,d);
    node* cur=map->arr[h];
    node* prev=NULL;
    while (cur)
    {
        if (cur->a==a && cur->d==d)
        {
            if(cur->cnt==1){
                if (prev==NULL)
                {
                    map->arr[h]=cur->next;
                }
                else prev->next=cur->next;
                free(cur);
                map->size--;
            }
            else cur->cnt--;
            return ;
        }
        prev=cur;
        cur=cur->next;
    }

}
int search(hashmap* map,int a,int d){
    unsigned int h=hash(a,d);
    node* cur=map->arr[h];
    while (cur!=NULL)
    {
        if (cur->a==a && cur->d==d)
        {
            return cur->cnt;
        }
        cur=cur->next;
    }
    return -1;
}
void inithash(hashmap* map){
    for (int i = 0; i < max; i++)
    {
        map->arr[i]=NULL;
    }
}
int strengthcmp(int a1,int d1,int a2,int d2){
    if(a1+d1 > a2+d2)return 1 ;
    if(a1+d1 < a2+d2)return 2;
    if(a1>a2)return 1;
    return 2;
}


void merge(node** arr, int l, int mid, int r){
    node* left[mid-l+1];
    node* right[r-mid];

    for(int i=l;i<=mid;i++)
        left[i-l]=arr[i];
    for(int i=mid+1;i<=r;i++)
        right[i-(mid+1)]=arr[i];

    int i=0,j=0;
    for(int k=l;k<=r;k++)
    {
        if(i >= (mid-l+1)) arr[k]=right[j++];
        else if(j >= (r-mid)) arr[k]=left[i++];
        else
        {
            int s1 = left[i]->a + left[i]->d;
            int s2 = right[j]->a + right[j]->d;

            if(s1 > s2 || (s1==s2 && left[i]->a > right[j]->a))
                arr[k]=left[i++]; 
            else
                arr[k]=right[j++];
        }
    }
}
void mergesort(node** arr, int l, int r){
    if(r-l <= 0) return;
    int mid = (r-l)/2 + l;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}


int main(){
int n;
scanf("%d",&n);
hashmap* map = malloc(sizeof(hashmap));
inithash(map);
map->size=0;

for (int i = 0; i < n; i++)
{
    int a,d;scanf("%d %d",&a,&d);
    insert(map,a,d);
}
// for (int i = 0; i < max; i++)
// {
//     node* cur=map->arr[i];
//     while (cur!=NULL)
//     {
//         printf("%d %d %d\n",cur->a,cur->d,cur->cnt);
//         cur=cur->next;
//     }
// }

int q;
scanf("%d",&q);
for (int i = 0; i < q; i++)
{
    int a1,d1,a2,d2;
    char str[10];
    scanf("%s %d %d %d %d",str,&a1,&d1,&a2,&d2);
    // printf("ip %d %d\n",a1,d1);
    if (a2==-1 && d2==-1)
    {
        insert(map,a1,d1);
        printf("1\n");
    }
    else if(search(map,a2,d2)<=1){
        printf("0\n");
    }
    else{
        int x = search(map,a1,d1);
        if(x == -1){
            printf("1\n");
            delete(map,a2,d2);
            insert(map,a1,d1);
        }
        else{
            if(strengthcmp(a1,d1,a2,d2)==2){
                printf("0\n");
            }
            else{
                printf("1\n");
                delete(map,a2,d2);
                insert(map,a1,d1);
            }
        }
    }
    // printf("{%d}>%d\n",i,map->size);
    // for (int i = 0; i < max; i++)
    // { 
    //     node* cur=map->arr[i];
    //     while (cur!=NULL)
    //     {
    //         printf("%d %d %d\n",cur->a,cur->d,cur->cnt);
    //         cur=cur->next;
    //     }
        
    // }

}
int s=map->size;
node* brr[s];
int j=0;
printf("%d\n",s);
for (int i = 0; i < max; i++)
{ 
    node* cur=map->arr[i];
    while (cur!=NULL)
    {
        brr[j++] =cur;
        cur=cur->next;
    }
    
}
mergesort(brr,0,s-1);
for (int i = 0; i < s; i++)
{ 
    printf("%d %d %d\n",brr[i]->a,brr[i]->d,brr[i]->cnt);
}
for(int i=0;i<max;i++){
    node* cur = map->arr[i];
    while(cur){
        node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
free(map);
}
