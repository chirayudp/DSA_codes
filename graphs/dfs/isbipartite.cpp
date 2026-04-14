#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int color,int idx,vector<int> &colored){
        colored[idx] == color;
        for (int nbr : graph[idx])
        {
            if(colored[nbr] == -1){
                if(!dfs(graph,1 - color,nbr,colored))
                    return false;

            }
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>colored(v,-1);
        for (int i = 0; i < v; i++)
        {
            if(colored[i] == -1){
                if(!dfs(graph,0,i,colored))
                    return false;

            }
        }
        return true;
    }
};
int main(){
int n; cin >> n;

}