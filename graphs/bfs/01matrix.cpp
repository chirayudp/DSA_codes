#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1 && mat[nx][ny] == -1) {
                    mat[nx][ny] = 1 + mat[x][y];
                    q.push({nx, ny});
                }
            }
        }
        return mat;
    }
};


int main(){
int n; cin >> n;

}