

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000007
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[max];
        scanf("%s", s);
        int k;
        scanf("%d", &k);
        int n = strlen(s);
        int stack[n];
        int top = -1;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            while (top >= 0  && k > 0 && stack[top] > d) {
                top--;
                k--;
            }
            stack[++top] = d;
        }

        while (k > 0) {
            top--;
            k--;
        }

        for (int i = 0; i <= top; i++) {
            printf("%d", stack[i]);
        }
        printf("\n");
    }

    return 0;
}
