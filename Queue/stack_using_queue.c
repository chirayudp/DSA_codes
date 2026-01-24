#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int q[100];
    int f;
    int b;
} MyStack;


MyStack* myStackCreate() {
    MyStack* new = malloc(sizeof(MyStack));
    new->f = new->b = -1;
    return new;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->b == -1)
    {
        obj->q[++obj->f]=x;
        return ;
    }
    
    
}

int myStackPop(MyStack* obj) {
}

int myStackTop(MyStack* obj) {
    
}

bool myStackEmpty(MyStack* obj) {
    
}

void myStackFree(MyStack* obj) {
    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

int main(){
long long n;
scanf("%lld",&n);

}
