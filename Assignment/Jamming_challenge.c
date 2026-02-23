#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    long long l,u;
    long long idx;
    struct node* next;
} node;

node* create(long long l, long long u,long long i){
    node* new= malloc(sizeof(node));
    new->l=l;new->u=u;
    new->idx=i;
    new->next=NULL;
    return new;
}

void merge(node** arr, long long l, long long mid, long long r) {
    long long n1 = mid-l+1;
    long long n2 = r-mid;

    node** left = malloc(sizeof(node*)*n1);
    for (long long i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }

    node** right = malloc(sizeof(node*)*n2);
    for (long long i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    long long i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i]->l < right[j]->l)
            arr[k++] = left[i++];
        else if (left[i]->l > right[j]->l)
            arr[k++] = right[j++];
        else {
            if (left[i]->u > right[j]->u)
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];

    free(left);
    free(right);
}

void mergesort(node** arr,long long l, long long r){
    if(r-l<=0)return ;
    long long mid=(r-l)/2 +l;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return;
}
void mergearr(long long* arr, long long l, long long mid, long long r){
    long long left[mid-l+1],right[r-mid];
    for (long long i = l; i <=mid; i++)
    {
        left[i-l]=arr[i];
    }
    for (long long i = mid+1; i <= r; i++)
    {
        right[i-(mid+1)]=arr[i];
    }
    long long i=0,j=0;
    for (long long k = l; k <= r; k++)
    {
        if (i>=(mid-l+1))arr[k]=right[j++];
        else if (j>=(r-mid))arr[k]=left[i++];
        else if (left[i]<=right[j])arr[k]=left[i++];
        else arr[k]=right[j++];  
    }
    return ;
}

void mergesortarr(long long* arr, long long l, long long r){
    if(r-l<=0)return ;
    long long mid=(r-l)/2 +l;
    mergesortarr(arr,l,mid);
    mergesortarr(arr,mid+1,r);
    mergearr(arr,l,mid,r);
    return ;
}
long long query(long long* bit, long long i) {
    long long sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & (-i);
    }
    return sum;
}

void update(long long* bit, long long n, long long i, long long val) {
    while (i<= n) {
        bit[i] += val;
        i += i & (-i);
    }
}

int main() {
    long long t;scanf("%lld",&t);
    while(t--){
        long long n;scanf("%lld",&n);
        node* head=NULL;
        node* tail = NULL;
        for(long long i=0;i<n;i++){
            long long l, u;scanf("%lld %lld",&l, &u);
            node* new = create(l,u,i);
            if (head == NULL)
            {
                head=tail=new;
            }
            else {
                tail->next=new;
                tail=tail->next;
            }
            
        }   

        node** arr = malloc(sizeof(node*)*n);
        node* tmp=head;
        long long i=0;
        while (tmp && i<n)
        {
            arr[i++]=tmp;
            tmp =tmp->next;
        }
        mergesort(arr,0,n-1);
        long long uarr[n];
        for (long long i = 0; i < n; i++)
        {
            uarr[i]=arr[i]->u;
        }
        mergesortarr(uarr, 0,n-1);
        long long m = 0;
        for (long long i = 0; i < n; i++) {
            if (i == 0 || uarr[i] != uarr[i - 1]) {
                uarr[m++] = uarr[i];
            }
        }

        //main bullshitt
        for (long long i = 0; i < n; i++) {
            long long left = 0, right = m - 1;
            long long pos = -1;

            while (left <= right) {
                long long mid = left + (right - left) / 2;

                if (uarr[mid] == arr[i]->u) {
                    pos = mid;
                    break;
                } else if (uarr[mid] < arr[i]->u) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            arr[i]->u = pos + 1;
        }
        long long bit[m + 1];
        for (long long i = 0; i < m+1; i++)
        {
            bit[i]=0;
        }
        long long score[n];
        for (long long i = 0; i < n; i++)
            score[i] = n - 1; 

        long long z=n;
        long long seen = 0;
        for (long long i = 0; i < n; i++) {
            long long u = arr[i]->u;

            long long containers = query(bit, m) - query(bit, u - 1);

            score[arr[i]->idx] -= containers;

            update(bit, m, u, 1);
        }

        for (long long i = 0; i <= m; i++) {
            bit[i] = 0;
        }
        for (long long i = n - 1; i >= 0; i--) {
            long long u = arr[i]->u;

            long long contains = query(bit, u);

            score[arr[i]->idx] += contains;

            update(bit, m, u, 1);
        }

        for (long long i = 0; i < n; i++) {
            printf("%lld ", score[i]);
        }
        printf("\n");
    }

}