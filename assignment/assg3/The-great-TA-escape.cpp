#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;

int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};


int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin >> t;
while(t--){
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dist(n, vector<ll>(m, inf));

    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> pq;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || j == m - 1){
                dist[i][j] = a[i][j];
                pq.push({dist[i][j], i, j});
            }
        }
    }

    while(!pq.empty()){
        auto [d, r, c] = pq.top();
        pq.pop();

        if(d > dist[r][c]) continue;

        if(r == n -1 || c == 0){
            cout << d << "\n";
            break;
        }

        for(int k = 0; k < 8; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                if(dist[r][c] + a[nr][nc] < dist[nr][nc]){
                    dist[nr][nc] = dist[r][c] + a[nr][nc];
                    pq.push({dist[nr][nc], nr, nc});
                }
            }
        }
    }
}
}