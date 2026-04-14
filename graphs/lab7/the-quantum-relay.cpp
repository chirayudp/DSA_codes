#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> bset;
void dfs(vector<vector<int>>&adj,vector<int>& vis,int u ,int par,int t,vector<int>&ti ,vector<int>&low){
    vis[u] = 1;
    ti[u] = low [u] = t++;
    for (auto &v : adj[u])
    {
        if(!vis[v]){
            if( par == v) continue;
            low[v] = min(low[u],low[v]);
            dfs(adj,vis,v,u,t,ti,low);
            if(low[v]>ti[v]){
                return ;
            }
        }
        else if( v!= par){
            low[v] = min(low[u],ti[u]);   
        }
        else{
            bset.insert({u,v});
            bset.insert({v,u});
        }
    }
    return ;
}
void isgate(vector<vector<int>>&adj){
    int v = adj.size();
    vector<int> vis(v,0);
    vector<int> ti(v,0),low(v,0);
    for (int i = 0; i < v; i++)
    {
        dfs(adj,vis,i,-1,0,ti,low);
    }
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u,v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    isgate(adj);
    for (int i = 0; i < q; i++)
    {
        int u,v; cin >> u >> v;
        u--;v--;
        int x = bset.count({u,v});
        if(x)cout << "YES\n";
        else cout << "NO\n";
        
    }

}