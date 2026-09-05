#include<bits/stdc++.h>
using namespace std;

int main(){
int t; cin >> t;
while (t--)
{
    int n,k;
    cin >> n >> k;
    string s;cin >> s;
    int count =0;
    int j = n/k;
    for (int i = 0; i < j; i++)
    {
        int flag = 0;
        for (int p = 0; p < k ; p++)
        {
            if (s[(i*k)+p] == '0')
            {
                flag = 1;
                break;
            }
            
        }
        if (!flag)
        {
            count++ ;
        }
        
        
    }
    cout<< count << endl;

}

}