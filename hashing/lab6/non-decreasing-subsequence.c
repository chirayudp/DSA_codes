#include <stdio.h>
#include <stdlib.h>

long long countSubseq(long long arr[], long long n) {
    long long dp[n];
    long long total = 0;

    for(long long i = 0; i < n; i++) {
        dp[i] = 1;

        for(long long j = 0; j < i; j++) {
            if(arr[j] <= arr[i]) {
                dp[i] += dp[j];
            }
        }

        total += dp[i];
    }

    return total;
}

void readArray(long long arr[], long long n) {
    for(long long i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
}

int main() {
    long long t;
    scanf("%lld", &t);

    while(t--) {
        long long n;
        scanf("%lld", &n);

        long long arr[n];
        readArray(arr, n);

        long long ans = countSubseq(arr, n);

        printf("%lld\n", ans);
    }

    return 0;
}