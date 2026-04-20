#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v;
    long long w;
};
vector<long long> bellmanford(int n , vector<edge>&edges , int src){
    vector<long long >dist(n,LLONG_MAX);
    dist[src] = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (auto &e : edges)
        {
            if(dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w ;
            }
        }
        
    }
    for (auto &e : edges)
        {
            if(dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]){
                cout << "Alert!! Negetive cycle detected.";
                return {};
            }
        }
    return dist;
}
int main(){
int n; cin >> n;

}