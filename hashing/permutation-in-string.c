#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
bool checkInclusion(char* s1, char* s2) {
    int n2=strlen(s2);
    int n1=strlen(s1);
    if(n1>n2)return false;
        int hash1[26]={0};
        int hash2[26]={0};
    for (int i = 0; i < n1; i++)
    {
        hash1[s1[i]-'a']++;
        hash2[s2[i]-'a']++;
    }
   
    for (int l = 0; l <= n2-n1; l++)
    {
        int yes=1;
        for (int i = 0; i < 26; i++)
        {
            if (hash1[i]!=hash2[i])
            {
                yes=0;
                break;
            }
            
        }
        if (yes)return true;
        if (l<n2-n1)
        {
            hash2[s2[l]-'a']--;
            hash2[s2[l+n1]-'a']++;
        }
        
    }
    return false;
    
}


int main(){
char s1[100];
char s2[100];

scanf("%s %s",s1,s2);
if (checkInclusion(s1,s2))
{
    printf("yes\n");
}
else 
    printf("no\n");

}
