#include <stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void) {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        long long num = x - 2LL * y;  // = 3*(b + 2c)
        if (num < 0 || num % 3 != 0) {
            printf("NO\n");
            continue;
        }

        long long s = num / 3;         // s = b + 2c
        long long low = (-y > 0) ? -y : 0; // c >= max(0, -y)
        long long high = s / 2;        // c <= s/2

        if (low <= high) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
