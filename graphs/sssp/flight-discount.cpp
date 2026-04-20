#include<bits/stdc++.h>
using namespace std;
using ll = long long;
long long dijkstra(int n , vector<vector<tuple<int,int>>> &adj){
    vector<vector<ll>> dist(n+1,vector<ll>(2,LLONG_MAX));
    dist[0][0]=0;
    priority_queue<tuple<ll,int,int> , vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>>pq;
    pq.push({0,0,0});
    while (!pq.empty())
    {
        auto [d,u,used] = pq.top();
        pq.pop();
        if(d > dist[u][used])continue;
        for (auto [v,w] : adj[u])
        {
            if(dist[u][used] + w < dist[v][used]){
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used],v,used});
            }
            if(used == 0){
                if(dist[u][0] + w/2 < dist[v][1]){
                dist[v][1] = dist[u][0] + w/2;
                pq.push({dist[v][1],v,1});
            }
            }
        }
        
    }
    return min(dist[n-1][0],dist[n-1][1]);
    
}
int main(){
int n,m; cin >> n>>m;
    vector<vector<tuple<int,int>>> adj(n);
for (int i = 0; i < m; i++)
{
    int u,v,w;
    cin >>u>>v>>w;
    u--;v--;
    adj[u].push_back({v,w});
}
long long d = dijkstra( n , adj);
cout << d;
}

