#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
    int top;
    int que[100];
    int arr[100];
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* qu = malloc(sizeof(MyQueue));
    qu->top=-1;
    return qu;
}

void myQueuePush(MyQueue* obj, int x) {

    if(obj->top==-1) {
        obj->que[++(obj->top)]=x;
        return ;
    }
    int i=0,t=obj->top;
    while(t>=0){
        obj->arr[i++]=obj->que[t--];
    }
    obj->arr[i++]=x;   
    int k=i-1;

    for (int j = 0; j < i; j++)
    {
        obj->que[j] = obj->arr[k--];
    }
    obj->top++;
}

int myQueuePop(MyQueue* obj) {
    return obj->que[obj->top--];
}

int myQueuePeek(MyQueue* obj) {
    return obj->que[obj->top];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

int main(){
long long n;
scanf("%lld",&n);

}
