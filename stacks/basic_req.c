#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ismty(int top){
    if(top == -1) return 1;
    return 0;
}

isfull(int top,int max){
    if(top == max-1)return 1;
    return 0;
}
void push(int* stack,int top,int max,int item){
    if(top == max-1){
        printf("Stack Overflow");
        return ;
    }
    else {
        top++;
        stack[top]=item;
    }
}
int pop(int* stack,int top){
    if (top == -1)
    {
        printf("Empty");
        return 0;
    }
    else{
        int item = stack[top];
        top--;
        return item;
    }
    
}
int main(){
long long n;
scanf("%lld",&n);

}
