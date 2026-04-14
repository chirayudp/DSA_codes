#include<bits/stdc++.h>
using namespace std;
bool isbipartite(vector<vector<int>> &adj){
    int v = adj.size();
    vector<int> colored(v,-1);
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if(colored[i] == -1){
            colored[i] = 0;
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int nbr : adj[cur])
                {
                    if(colored[nbr] == -1){
                        colored[nbr] = 1 - colored[cur];
                        q.push(nbr);
                    }
                    else if(colored[nbr] == colored[cur]){
                        return false;
                    }
                }
                
            }
            
        }
    }
    return true;
    
}
int main(){
vector<vector<int>> adj = {{1,3},{0,2},{1,3},{0,2}};
if(isbipartite(adj)){
    printf("yes\n");
    return 0;
}
printf("no\n");
}