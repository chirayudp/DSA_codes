#include<bits/stdc++.h>
using namespace std;

void dfsrecursion(vector<vector<int>>&adj , vector<int>&vis , int s,vector<int>& res){
    vis[s]=1;
    res.push_back(s);
    for (auto i : adj[s])
    {
        if(!vis[i]) dfsrecursion(adj,vis,i,res);
    }
}

vector<int> dfs(vector<vector<int>>&adj){
    vector<int> vis(adj.size());
    vector<int> res;
    for (int i = 0; i < adj.size(); i++)
    {
        if(!vis[i])
            dfsrecursion(adj,vis,i,res);
    }
        
    return res;
}

