#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>&adj){
    int v= adj.size();
    vector<int> vis(v);
    vector<int> res;

    queue<int> q;
    q.push(0);
    vis[0]=1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (auto i : adj[cur])
        {
            if(!vis[i]){ 
                vis[i] = 1;
                q.push(i);
            }
        }
        
    }
    return res;
}

