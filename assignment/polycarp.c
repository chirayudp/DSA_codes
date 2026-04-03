#include <stdio.h>

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
        // for(long long i=0;i<n;i++){
        //     printf("%lld ",arr[i]);
        // }--
        // printf("\n");
        long long stk[n];
        long long size=0;
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
        long long lmax[n];lmax[0]=arr[0];
        long long rmax[n];rmax[n-1]=arr[n-1];
        for (long long i = 0; i < n; i++) {
            if (i - 1 <= left[i])
                lmax[i] = 0;
            else
            {
                if (i == 0) lmax[i] = 0;   
                else {
                    if (lmax[i - 1] > arr[i - 1])
                        lmax[i] = lmax[i - 1];
                    else
                        lmax[i] = arr[i - 1];
                }
            }
        }
        for (long long i = n - 1; i >= 0; i--) {
            if (i + 1 >= right[i]) {
                rmax[i] = 0;
            } else {
                if (i == n - 1) {
                    rmax[i] = 0;
                } else {
                    if (rmax[i + 1] > arr[i + 1])
                        rmax[i] = rmax[i + 1];
                    else
                        rmax[i] = arr[i + 1];
                }
            }
        }

        long long res=0;
        for (long long i = 0; i < n; i++)
        {
            long long li = (left[i] +1);
            long long lf = i-1;
            long long rf = right[i] -1;
            long long ri = i+1;
            if (li > lf || rf < ri)continue;
            long long score = arr[i] * (lmax[i] + rmax[i]);
            if(score > res)res = score;
            // printf("(%lld) ",score);
            // else{res+=score; printf("{%lld} ",res);}
        }
        printf("%lld\n",res);
    }
} 


