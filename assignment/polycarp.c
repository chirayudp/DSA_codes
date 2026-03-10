#include <stdio.h>
#define max 200005

long long stk[max];
long long size;
long long seg[4*max];

long long fmax(long long a, long long b) {
    return a > b ? a : b;
}

void build(int node, int l, int r, long long arr[]) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*node, l, mid, arr);
    build(2*node+1, mid+1, r, arr);
    seg[node] = fmax(seg[2*node], seg[2*node+1]);
}

long long query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return fmax(
        query(2*node, l, mid, ql, qr),
        query(2*node+1, mid+1, r, ql, qr)
    );
}

int main() {
    long long t;scanf("%lld",&t);
    while(t--){
        long long n;scanf("%lld",&n);
        long long arr[n];
        long long left[n];
        long long right[n];
        for(long long i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }   
        build(1, 0, n-1, arr);
        // for(long long i=0;i<n;i++){
        //     printf("%lld ",arr[i]);
        // }
        // printf("\n");
        size=0;
        for(long long i=0;i<n;i++){
            while (size>0 && arr[stk[size-1]] < arr[i])
            {
                size--;
            }
            if (size==0)left[i]=-1;
            else left[i]=stk[size-1];
            stk[size++]=i;
        }
        size=0;
        for(long long i=n-1;i>=0;i--){
            while (size>0 && arr[stk[size-1]] < arr[i])
            {
                size--;
            }
            if (size==0)right[i]=n;
            else right[i]=stk[size-1];
            stk[size++]=i;
        }
        long long res = 0;
        size = 0;

        for (long long i = 0; i <= n; i++) {
            long long cur = (i == n ? (long long)1e18 : arr[i]);

            while (size > 0 && arr[stk[size - 1]] < cur) {
                long long k = stk[--size];
                long long lf ;
                if (size==0)lf =-1;
                else lf = (stk[size - 1]);
                long long rf = i;

                if (lf + 1 >= k || k + 1 >= rf)
                    continue;

                long long lmax = query(1, 0, n-1, lf+1, k-1);
                long long rmax = query(1, 0, n-1, k+1, rf-1);

                long long score = arr[k] * (lmax + rmax);
                if (score > res) res = score;
            }
            stk[size++] = i;//if (i < n) stk[size++] = i;
        }


        printf("%lld\n", res);
    }
} 