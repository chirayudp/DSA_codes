#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int k;
    int size;
    int* arr;
} KthLargest;

void heapify(int* heap, int* size, int i) {
    int sml = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < *size && heap[l] < heap[sml])
        sml = l;
    if (r < *size && heap[r] < heap[sml])
        sml = r;
    if (sml != i) {
        int tmp = heap[sml];
        heap[sml] = heap[i];
        heap[i] = tmp;
        heapify(heap, size, sml);
    }
}
void build(int* heap, int* size) {
    for (int i = (*size / 2 - 1); i >= 0; i--) {
        heapify(heap, size, i);
    }
}

void insert(int* heap, int* size, int val) {
    int i = *size;
    heap[(*size)++] = val;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int tmp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = tmp;
        i = (i - 1) / 2;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* new = malloc(sizeof(KthLargest));
    int max = k;
    new->arr = malloc(sizeof(int) * k);
    new->k = k;
    new->size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (new->size < k) {
            new->arr[new->size++] = nums[i];
            if (k == new->size)
                build(new->arr, &new->size);
        } else if (nums[i] > new->arr[0]) {
            new->arr[0] = nums[i];
            heapify(new->arr, &(new->size), 0);
        }
    }
    if (new->size < k)
        build(new->arr, &new->size);
    return new;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->k > obj->size) {
        insert(obj->arr, &obj->size, val);
    } else if (val > obj->arr[0]) {
        obj->arr[0] = val;
        heapify(obj->arr, &(obj->size), 0);
    }
    return obj->arr[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    KthLargest* obj = kthLargestCreate(k, arr, n);
    int q;
    scanf("%d",&q);
    while(q--){
        int val;
        scanf("%d",&val);
        printf("%d\n",kthLargestAdd(obj,val));
    }
    kthLargestFree(obj);
}
