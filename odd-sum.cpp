#include<bits/stdc++.h>
using namespace std;
long long fact(int i){
    if(i==0)return 1;
    return i*fact(i-1);
}
long long pow(int b, int p){
    if(p == 0) return 1;
    return b* pow(b,p-1);
}

int main(){
long long i=1;
int m = 0;
int arr[100];
int f=0;
while(2147483648 > fact(i)){
    for (int j = 0; j < 100; j++)
    {
        if(fact(i) % pow(67,j) == 0){
            arr[f++] = j;
        }
    }
    
    i++;

}
for (int i = 0; i < 100; i++)
{
    int flag = 1;
    for (int j = 0; j < 100; j++)
    {
        if(arr[i] = j){
            flag=1;
            break;
        }
    }
    if(flag){
        cout << arr[i];
    }
    
}

cout << 1;
}