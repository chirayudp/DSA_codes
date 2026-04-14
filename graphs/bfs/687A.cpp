#include<bits/stdc++.h>
using namespace std;

int isbip(vector<vector<int>>& adj,vector<int>&col){
    int v = adj.size();
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if(col[i] == -1){
            q.push(i);
            col[i] = 0;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto &nbr : adj[cur])
                {
                    if(col[nbr] == -1){
                        if(col[nbr] == -1){
                            col[nbr] = 1 - col[cur];
                            q.push(nbr);
                        }
                    }
                    else if(col[nbr] == col[cur])
                        return 0;
                }
                
            }
            
        }
    }
    return 1;
    
}
int main(){
int n,m; cin >> n >> m;
vector<vector<int>> adj(n);
for (int i = 0; i < m; i++)
{
    int u,v; cin >> u >> v;
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);

}
vector<int> col(n,-1);
vector<int> arr1;
vector<int> arr2;
int x = isbip(adj,col);
if(!x){
cout << -1 << endl;
return 0;
}
for (int i = 0; i < n; i++)
{
    if(col[i])
    arr2.push_back(i);
    else
    arr1.push_back(i);
}


int p = arr1.size();
int q = arr2.size();
cout << p << endl;
for (int i = 0; i < p; i++)
{
    cout << arr1[i] + 1 << " " ;
}
cout << endl << q << endl;
for (int i = 0; i < q; i++)
{
    cout << arr2[i] + 1 << " " ;
}
return 0 ;
}