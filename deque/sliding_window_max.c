#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* maxSlidingWindow(int* nums, int n, int k, int* returnSize) {
    int* deq = malloc(sizeof(int)*n);
    int head = 0, tail = -1, t = 0;
    int* ans = malloc(sizeof(int) * (n + 1 - k));
    for (int i = 0; i < n; i++) {
        while (head <= tail && nums[deq[tail]] <= nums[i])
            --tail;

        deq[++tail] = i;

        if (head<=tail && deq[head] <= i - k)
            head++;

        if (i >= k - 1)
            ans[t++] = nums[deq[head]];
    }
    *returnSize = n + 1 - k;
    free(deq);
    return ans;
}
int main(){
int arr[]={1,3,-1,-3,5,3,6,7};
int k;
scanf("%d",&k);
int n=sizeof(arr)/sizeof(arr[0]);
int returnSize;
int* ans = maxSlidingWindow(arr, n, k,&returnSize);
for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
}
free(ans);
}
