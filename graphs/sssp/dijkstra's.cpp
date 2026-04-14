    #include<bits/stdc++.h>
    using namespace std;
    vector<long long> dijkstra(long long n, vector<vector<pair<long long,long long>>>&adj,long long src){
        vector<long long > dist(n,LLONG_MAX);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0,src});
        dist[src] = 0;
        while (!pq.empty())
        {
            auto [d,u] = pq.top();
            pq.pop();
            if(d> dist[u])continue;
            for (auto [v,w] : adj[u])
            {
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
            
        }
        return dist ;
        
    }
  int main(){
    long long n; cin >> n;

    }