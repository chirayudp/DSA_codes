#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isValid(char* s) {
    char c= s[0];
    if (c==')' || c== '}'|| c==']' )return false;

    int n = strlen(s);
    // curvy = 1;sq = 2;flower = 3;
    int stk[n];
    
    int top=-1;
    int x=1;
    for (int i = 0; i < n; i++)
    {
        c=s[i];
        if (top==-1 && ( c== ')') )return false;
        else if (c=='(' )stk[++top]=1;
        else if (c ==')' && stk[top]== 1){
            top--;
        }
            
    }
    if (top>=0)return false;
    return true;

}

int main(){
char n[100];
scanf("%s",n);
if(isValid(n))printf("valid\n");
else printf("invalid\n");
}