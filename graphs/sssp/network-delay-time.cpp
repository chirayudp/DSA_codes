#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<long long> dist(n+1,LLONG_MAX);
        vector<vector<pair<long long ,long long>>> adj(n+1);
        long long t = times.size();
        for (long long i = 0; i < t; i++)
        {
            long long u = times[i][0],v=times[i][1],d = times[i][2];
            adj[u].push_back({d,v});
        }
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while (!pq.empty())
        {
            auto [d,u] = pq.top();
            pq.pop();
            if(d  > dist[u])continue;
            for (auto [w,v] : adj[u])
            {
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w ; 
                    pq.push({dist[v],v});
                }
            }
            
        }
        long long ans = 0;
        for(int i = 1 ;i<n+1;i++){
            if(dist[i] == LLONG_MAX)return -1 ;
            ans = max(ans,dist[i]);
        }

        return ans;
    }
};

long long main(){
long long n; cin >> n;

}