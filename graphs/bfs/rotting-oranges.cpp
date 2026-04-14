#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int time=0;
        int rotten = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2){
                    rotten++;
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                    fresh++;
            }
            
        }
        if(fresh == 0)return 0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty() && fresh>0){
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(0 <= nx && nx < n && 0 <= ny && ny < m  && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
            time++; 
        }
        if(fresh == 0)return time;
        return -1;
    }
};

