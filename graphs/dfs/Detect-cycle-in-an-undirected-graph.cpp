#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>&adj,int cur,int par,vector<int>&vis){
    //visit the current vertex
    vis[cur]=1;
    for (auto i : adj[cur])
    {
        if(!vis[i]){
            if(dfs(adj,i,cur,vis))
                return true;
        }
        else if(i != par)
            return true;
    }
    return false ;
}

bool iscycle(vector<vector<int>>&adj){
    int v = adj.size();
    vector<int> vis(v);
    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){
            if(dfs(adj,i,-1,vis))
                return true;
        }
    }
    return false;
}

int main(){
int n; cin >> n;

}