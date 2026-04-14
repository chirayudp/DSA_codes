//traversal of a scc
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5 ;
vector<int> adj[N],radj[N];
bool vis[N];
stack<int> stk;

void dfs1(int u){
    vis[u] = true;
    for (int v : adj[u])
    {
        if(!vis[v])
        dfs1(v);
    }
    stk.push(u);
    
}

void dfs2(int u,vector<int>& comp){
    vis[u]= true ;
    comp.push_back(u);
    for(int v: radj[u]){
        if(!vis[v])dfs2(v,comp);
    }
}

int main(){
int n,m; cin >> n>>m;
for (int i = 0; i < m; i++)
{
    int u,v; cin >> u >> v;
    adj[u].push_back(v);
    radj[v].push_back(u);
}
for (int i = 0; i < n; i++)
{
    if(!vis[i])
        dfs1(i);
}
//reset vis
fill(vis,vis+n+1,false);
//process scc
while (!stk.empty())
{
    int u = stk.top(); stk.pop();
    for (int v : adj[u])
    {
        if(!vis[v]){
            vector<int> comp;
            dfs2(v,comp);
            // print the scc
            for (int i :comp)
            {
                cout << i << " ";
            }
            cout << endl;
            
        }
        
    }

}

}