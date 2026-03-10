#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100007
int isanagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return 0;
    int hashs[max];
    for(int i=0;i<max;i++){hashs[i]=0;}
    while(*s!='\0'){
        hashs[*s]++;
        hashs[*t]--;
        t++;
        s++;
    }

    for(int i=0;i<max;i++){
        if(hashs[i]!=0)return 0;
    }
    return 1;
}
int main(){
char s[max],t[max];
scanf("%s %s",s,t);
if (isanagram(s,t))
{
    printf("yes\n");
}
else printf("no\n");
}
