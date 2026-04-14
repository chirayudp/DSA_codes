#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int dist ;
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            dist = grid[x][y] ;
            if( x == n-1 && y == n-1 )return dist;

            for (int k = 0; k < 8; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >=0 && nx <= n-1 && ny >=0 && ny <= n-1 && grid[nx][ny] == 0){
                    grid[nx][ny] = dist +1 ;
                    q.push({nx,ny});
                }
            }
            
        }
        return -1 ;
    }
};

int main(){
int n; cin >> n;

}