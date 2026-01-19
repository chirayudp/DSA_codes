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
        if (top==-1 && (c=='}' || c== ')'|| c==']') )return false;
        else if (c=='(' )stk[++top]=1;
        else if (c== '{')stk[++top]=2;
        else if (c=='[' )stk[++top]=3;
        else if (c ==')' && stk[top]== 1){
            top--;
        }
        else if (c =='}' && stk[top]== 2){
            top--;
        }
        else if (c ==']' && stk[top]== 3){
            top--;
        }
    }
    if (top>=0)return false;
    return true;

}

int main(){
long long n;
scanf("%lld",&n);

}