

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000007
int main() {
    long long t;
    scanf("%lld", &t);
    for (long long i = 0; i < t; i++){
        char s[max];
        scanf("%s", s);
        long long k;
        scanf("%lld", &k);
        long long n = strlen(s);
        long long stack[n];
        long long top = -1;

        for (long long j = 0; j < n; j++) {
            long long lld = s[i] - '0';
            while (top >= 0  && k > 0 && stack[top] > lld) {
                top--;
                k--;
            }
            stack[++top] = lld;
        }
        while (k > 0) {
            top--;
            k--;
        }

        long long l=0;
        while (stack[l]==0)l++;
        
        
        for (long long i = l; i <= top; i++) {
            printf("%lld", stack[i]);
        }
        printf("\n");
    }

    return 0;
}
