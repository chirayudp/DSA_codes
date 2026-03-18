#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        long long K;
        scanf("%d %lld", &n, &K);

        long long a[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        int pref[n + 1];
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i - 1];
        }
        int dq[n + 1];
        int head = 0, tail = -1;

        int ans = INT_MAX;

        for (int j = 0; j <= n; j++) {
            while (head <= tail) {
                int i = dq[head];
                if (pref[i] <= pref[j] - K) {
                    int len = j - i;
                    if (len < ans) ans = len;
                    head++;
                } else {
                    break;
                }
            }
            while (head <= tail) {
                if (pref[j] < pref[dq[tail]]) {
                    tail--;
                } else {
                    break;
                }
            }
            dq[++tail] = j;
        }

        if (ans != INT_MAX){
           printf("%d\n",ans);
           continue;
        }
        printf("-1\n");
    }
}
