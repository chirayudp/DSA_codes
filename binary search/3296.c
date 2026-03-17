#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int okay(int* workerTimes, int w, int mountainHeight, long long t) {
    long long totalheight = 0;
    for (int i = 0; i < w; i++) {
        double a = ((double)t / (double)workerTimes[i]);
        long long x = (sqrt(1 + 8 * a) - 1) / 2;
        // printf("(%d,%lld) ",i,x);
        totalheight += x;
        if (totalheight >= mountainHeight)
            return 1;
    }
    if (totalheight >= mountainHeight)
        return 1;
    return 0;
}
long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int w) {
    long long l = 0;
    long long r = 1e18;

    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (okay(workerTimes, w, mountainHeight, mid)) {
            r = mid;
        } else
            l = mid + 1;
    }
    return r;
}
int main(){
int n,h;
scanf("%d %d",&n,&h);
int arr[n];
for (int i = 0; i < n; i++){
  scanf("%d",&arr[i]);
}
printf("%lld\n",minNumberOfSeconds(h,arr,n));

}
