#include<bits/stdc++.h>
using namespace std;
vector<int> topo(int n , vector<vector<int>>& adj,vector<int>&indeg){
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indeg[i] == 0){
            // cout << i << endl;
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty()){
        int u = q.front();
        // cout << u << endl;
        q.pop();
        res.push_back(u);
        for(int v : adj[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                // cout <<"v" << v << endl;
                q.push(v);}
        }
    }
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m ;
        cin >> n >> m ;
        vector<vector<int>> adj(n);
        vector<int> indeg(n+1,0);
        for(int i = 0 ;i<m;i++){
            int u,v;
            cin >> u >> v;
            u--;v--;
            adj[u].push_back(v);
            indeg[v]++;
        }
        vector<int> res = topo(n,adj,indeg);

        if(res.size() != n){
            cout << "NO\n";
        }
        else
        cout << "YES\n";

    }
}
