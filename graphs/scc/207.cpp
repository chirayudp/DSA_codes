#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isdag(vector<vector<int>> &adj){
        int v = adj.size();
        vector<int> indg(v+1,0);
        for (int i = 0; i < v; i++)
        {
            for(int j : adj[i]){
                indg[j]++;
            }
        }
        int count = 0;
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if(indg[i] == 0)q.push(i);
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            count++;
            for(int v : adj[u]){
                indg[v]--;
                if(indg[v] == 0){
                    q.push(v);
                }
            }
        }
        if(count == v)return true;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int v = prerequisites.size();
        vector<vector<int>> adj(n)  ;
        for (int i = 0; i < v; i++)        
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return isdag(adj);
        
    }
};


int main(){
int n; cin >> n;

}
