#include<bits/stdc++.h>
using namespace std;

int main(){
int t; cin >> t;
while (t--)
{
    int n,m; cin >> n >> m;
    vector<int> freq(26,0);
    for (int i = 0; i < n; i++)
    {
        string s ;cin >> s;
        freq[tolower(s[0])-'a'] = 1;
    }
    int h = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >>str;
        int k = 0;
        for (int j = 0; j < (int)str.size(); j++)
        {
            if(freq[tolower(str[j])-'a'] == 0){
                k = 1;
            }
        }
        if(k){
            h = 1;
        }
    }
    if(h){
        cout << "NO\n"; 
    }
    else cout << "YES\n";

}


}