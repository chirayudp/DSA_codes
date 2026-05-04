    #include<bits/stdc++.h>

    using namespace std;
    using ll = long long ;
    const ll inf = 1e18;

    vector<pair<ll,ll>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    ll dijkstra(vector<vector<pair<ll,ll>>>& adj,ll src,ll dst){
        ll n = adj.size();
        vector<ll> dist(n,-1);

        dist[src] = inf;
        priority_queue<pair<ll,ll>>pq;
        pq.push({dist[src],src});// starting from 0,0 grid ;
        while (!pq.empty())
        {
            auto [d,u] = pq.top();
            pq.pop();
            if(d < dist[u]) continue;
            if(u == dst) return d;
            for (auto [v,w] : adj[u] )
            {
                ll nd = min(w,d);
                if(nd > dist[v]){
                    
                        dist[v] = nd;
                        pq.push({nd,v});
                    }
                }
            }
            
            // for (ll j = 0; j < n; j++)
            // {
            //     cout << dist[j]<< " ";
            // }
        return -1;
    }

    int main(){
        ll n,m; cin >> n >> m ;
        vector<vector<pair<ll,ll>>> adj(n);
        for (ll i = 0; i < m; i++)
        {
            ll u,v,w; cin >> u >> v >> w;
            u--;v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        ll q; cin >> q;
        for (ll i = 0; i < q; i++)
        {
            ll u,v; cin >> u >> v ;
            u--;v--; 
            if(u == v){
                cout << 0 << endl;
                continue;
            }
            cout << dijkstra(adj,u,v) << endl;
        }
            
    }
