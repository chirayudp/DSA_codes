#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000000 
int top=-1;
int stk[max];

void push(int item){
    
        stk[++(top)]=item;
}
void pop(){
    if (top >= 0)
    {
        int item = stk[top];
        top--;
    }
}
void ptop(){
    if(top==-1){
        printf("Empty!\n");
        return;
    }
    printf("%d\n", stk[top]);
}
int main(){
    
int t;
scanf("%d",&t);
for (int i = 0; i < t; i++)
{
    int q;
    scanf("%d",&q);
    switch (q)
    {
    case 1:{
        int a;
        scanf("%d",&a);
        push(a);
        
        
        break;}
    
    case 3:{
        ptop();
        
        break;
    }
    case 2:{
        
        pop();
        
        break;
    }
    default:
        break;
    }
}

}
