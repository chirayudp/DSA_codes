#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long arr[n];
    for (long long i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    long long r = n ,l=0;

    while (r > 0) {

        while (arr[l] == 0) {
            l = (l + 1) % n;
        }
        l = (l + 1) % n;
        while (arr[l] == 0 ) {
            l = (l + 1) % n;
        }

        printf("%lld ", arr[l]);
        arr[l] = 0;
        r--;

        l = (l + 1) % n;
    }

    return 0;
}

