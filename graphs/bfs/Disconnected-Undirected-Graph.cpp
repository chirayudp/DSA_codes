#include<bits/stdc++.h>
using namespace std;

void connected(vector<vector<int>>&adj,int src,vector<int> &vis,vector<int> &res){
    int v= adj.size();

    queue<int> q;
    q.push(src);
    vis[src]=1;
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
}

vector<int> bfs(vector<vector<int>>&adj){
    int v= adj.size();
    vector<int> vis(v);
    vector<int> res;
    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){ 
            connected(adj,i,vis,res);
        }
    }
    return res;
}

