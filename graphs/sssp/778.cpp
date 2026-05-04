#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long ;
    const long long inf = 1e18;
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<ll>> dist(n,vector<ll>(m,inf));
        priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>>pq;
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0],0,0});// starting from 0,0 grid ;
        while (!pq.empty())
        {
            auto [t,r,c] = pq.top();
            pq.pop();
            if(t > dist[r][c])continue;
            for (auto [dr,dc] : dir )
            {
                cout << dr << " " << dc << endl;
                int nr = r + dr;
                int nc = c + dc ;
                if(nr >= 0 && nr<n && nc>=0 && nc < m){
                    int rt = max(t,(ll)grid[nr][nc]); // required time is the max of current time and the time required to reach grid height at (nr,nc);
                    if(dist[nr][nc] > rt){
                        dist[nr][nc] = rt;
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        
        return dist[n-1][m-1];
    }
};

int main(){
int n; cin >> n;

}