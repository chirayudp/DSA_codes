#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct heap {
    int size;
    int cap;
    struct ListNode** data;
} heap;

void heapify(struct ListNode** arr, int* size, int i) {
    int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < *size && arr[l]->val < arr[min]->val)
        min = l;
    if (r < *size && arr[r]->val < arr[min]->val)
        min = r;
    if (min != i) {
        struct ListNode* tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
        heapify(arr, size, min);
    }
}
void build(struct ListNode** arr, int* size) {
    for (int i = *size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}
void push(struct ListNode** head, int* size,struct ListNode* obj) {
    int i=*size;
    head[(*size)++]=obj;
    while (i>0 && head[(i-1)/2]->val > head[i]->val)
    {
        struct ListNode* tmp = head[(i-1)/2];
        head[(i-1)/2] = head[i];
        head[i] = tmp;
        
        i = (i-1)/2;
    }
    
}
struct ListNode* pop(struct ListNode** heap, int* size) {
    struct ListNode* res = heap[0];
    (*size)--;
    heap[0] = heap[*size];
    heapify(heap, size, 0);
    return res;
}
struct ListNode* mergeKLists(struct ListNode** lists, int s) {
    heap* arr = malloc(sizeof(heap));
    arr->size = 0;
    arr->cap = s;
    arr->data = malloc(sizeof(struct ListNode*) * s);

    for (int i = 0; i < s; i++) {
        if (lists[i]) {
            arr->data[ arr->size++] = lists[i];
        }
    }
    build(arr->data, &arr->size);
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* tail = head;

    while (arr->size > 0) {
        struct ListNode* node = pop(arr->data, &arr->size);
        tail->next = node;
        if(node->next)push(arr->data, &arr->size,node->next);
        tail = node;
    }
    return head->next;

}