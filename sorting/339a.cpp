#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin >> s;
    int n = s.size();
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if(s[i] != '+'){
            v.push_back(s[i] - '0');
        }
    }

}