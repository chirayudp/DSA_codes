#include<bits/stdc++.h>
using namespace std;

// void dfs(vector<vector<int>>&adj,int s,vector<int>& vis,vector<long long>& cnt){
//     vis[s] = 1;
//     for(int i : adj[s]){
//         if(!vis[i]){
//             cnt[i] = cnt[s] + 1;
//             dfs(adj,i,vis,cnt);
//         }
//     }
//     return ;
// }
int bfs(vector<vector<int>>&adj,int s, vector<long long>& cnt){
    int n = adj.size();
    vector<int> vis(n,0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur])
        {
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
                cnt[i] = cnt[cur] + 1;

            }

        }
    }
    return 0;
}
// void dfs(vector<vector<int>>&adj,int s,vector<int>& vis,vector<int>& cnt){
//     int v = adj.size();
//     for (int i = 0; i < v; i++)
//     {
//         if(!vis[i]){
//             dfs(adj,i,vis,cnt);
//             if()
//         }
//     }
//     return ;
// }
int main(){

    int n, m;
    cin >> n >> m ;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u,v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    
    int s;
    cin >> s ;
    s--;
    // vector<int> vis(n,0);
    vector<long long> cnt(n, -1);
    cnt[s] = 0;
    bfs(adj,s,cnt);
    for (int i = 0; i < n; i++)
    {
        cout << cnt[i] << " ";
    }
    
}