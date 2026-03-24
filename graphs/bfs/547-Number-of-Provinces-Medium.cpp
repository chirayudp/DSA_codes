#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void connected(vector<vector<int>>& isConnected,int s,vector<int> &vis) {
        queue<int> q;
        q.push(s);
        vis[s]=1;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < isConnected.size(); i++)
            {
                if(isConnected[cur][i] == 1 && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> vis(v);
        int cnt = 0;
        for (int i = 0; i < v; i++)
        {
            if(!vis[i]){
                cnt++;
                connected(isConnected,i,vis);
            }
        }
        return cnt;
    }
};

int main(){
int n; cin >> n;
vector<vector<int>> con(n,vector<int>(n));
for (int i = 0; i < n; i++)
{
    int m;cin >> m;
    for (int j = 0; j < m; j++)
    {
        cin >> con[i][j] ;
    }
    
}

for (int i = 0; i < n; i++)
{
    int m = con[i].size();
    for (int j = 0; j < m; j++)
    {
        cout << con[i][j] << " ";
    } 
    cout << endl;
}
Solution s;
cout << s.findCircleNum(con) << endl;

}