#include<bits/stdc++.h>
using namespace std;
void disp(vector<int> &v){
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl ;
}
int main(){
    int t ;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n ;
        vector<int> v;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int x; 
            cin >> x ;
            v.push_back(x);
        }
        // sort(v.begin(),v.end());
        for (int i=0;i<v.size();i++)
        {
            int s=0,g=0;
            for(int j = i+1; j<=v.size()-1;j++){
                if(v[j] < v[i])s++;
                else if(v[j] > v[i])g++;
            }

            ans.push_back(max(s, g));
        }
        disp(ans);
    }
        
    
}

