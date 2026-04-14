// cycles always have atleast one dependency so they are not processed
#include<bits/stdc++.h>
using namespace std;

vector<int> kahnstopo(int n,vector<vector<int>>&adj){
    vector<int> indeg(n+1,0);
    // fill no.of dependencies
    for (int i = 0; i < n; i++)
    {
        for(int v : adj[i]){
            indeg[v]++;
        }
    }
    // enque all sources
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(indeg[i] == 0)q.push(i);
    }
    // bfs lesgoo
    vector<int> topo;
    while (!q.empty())
    {
        int u = q.front();q.pop();
        topo.push_back(u);
        for(int v : adj[u]){
            indeg[v]--; // remove dependencies
            if(!indeg[v])q.push(v);
        }
    }
    return topo;
    
}
int main(){
int n,m; cin >> n>>m;
vector<vector<int>> adj(n);
for (int i = 0; i < m; i++)
{
    int u,v; cin >> u >> v;
    u--;v--;
    adj[u].push_back(v);
}
vector<int> res = kahnstopo(n,adj);
if(res.size() != n){
    cout<< "cycle exists!\n";
    return 0;   
}
for (int i : res)
{
    cout << i+1 << " ";
}
cout << endl;
}