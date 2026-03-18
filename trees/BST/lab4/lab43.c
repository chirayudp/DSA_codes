#include <stdio.h>
#include <stdlib.h>

void merge(long long* arr, long long l, long long mid, long long r){
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

void mergesort(long long* arr, long long l, long long r){
    if(r-l<=0)return ;
    long long mid=(r-l)/2 +l;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return ;
}

int main() {
    long long t;
    scanf("%lld", &t);
    for (long long e = 0; e < t; e++)
    {
        long long n, q;
        scanf("%lld %lld", &n, &q);

        long long value[n+ 1];
        int alive[n+1];

        for (long long i = 1; i <= n; i++) {
            scanf("%lld",&value[i]);
            alive[i] = 1;
        }
        long long tmp[n];
         while (q--) {
            long long x;
            scanf("%lld", &x);

            if (alive[x])
                alive[x] = 0;

            long long k = 0;
            for (long long i = 1; i <= n; i++) {
                if (alive[i])
                    tmp[k++] = value[i];
            }
            if (k == 0) {
                printf("-1\n");
                continue;
            }
            mergesort(tmp, 0, k - 1);
            long long midx;

            if (k %2 == 0) midx = (k / 2) - 1;
            else midx = k / 2;
            printf("%lld\n", tmp[midx]);
        }
    
    }
}
