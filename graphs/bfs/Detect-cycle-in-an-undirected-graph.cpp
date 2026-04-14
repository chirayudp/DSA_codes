#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>&adj,int src,vector<int>&vis){
    queue<pair<int,int>> q;
    vis[src] = 1;
    q.push({src,-1});

    while (!q.empty())
    {
        int cur = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto i : adj[cur])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push({i,cur});
            }
            else if(i != par)
                return true;
        }
        
    }
    
}
bool iscycle(vector<vector<int>>&adj){
    int v = adj.size();
    vector<int> vis(v);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if(bfs(adj,i,vis))
                return true;
        }
        
    }
    return false;
}

int main(){
int n; cin >> n;

}