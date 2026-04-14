#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> str(n);
        for(int i = 0; i < n; i++) cin >> str[i];

        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        set<pair<int,int>> edges; 
        bool impossible = false;

        for(int i = 0; i < n-1 && !impossible; i++){
            int x = str[i].size(), y = str[i+1].size();
            bool found = false;
            for(int j = 0; j < min(x, y); j++){
                int s1 = str[i][j] - 'a';
                int s2 = str[i+1][j] - 'a';
                if(s1 != s2){
                    if(!edges.count({s1, s2})){ 
                        adj[s1].push_back(s2);
                        indeg[s2]++;
                        edges.insert({s1, s2});
                    }
                    found = true;
                    break;
                }
            }
            if(!found && x > y) impossible = true;
        }

        if(impossible){
            cout << "Impossible\n";
            continue;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < 26; i++)
            if(indeg[i] == 0) pq.push(i);

        vector<int> res;
        while(!pq.empty()){
            int u = pq.top(); pq.pop();
            res.push_back(u);
            for(int v : adj[u]){
                if(--indeg[v] == 0) pq.push(v);
            }
        }

        if(res.size() != 26)
            cout << "Impossible\n";
        else{
            for(int c : res) cout << char('a' + c);
            cout << "\n";
        }
    }
}