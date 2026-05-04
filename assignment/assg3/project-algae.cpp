#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull base = 1315423911;

int getid(vector<string> &dict, string &s){
    for(int i = 0; i < dict.size(); i++){
        if(dict[i] == s) return i + 1;
    }
    dict.push_back(s);
    return dict.size();
}

int findpos(vector<string> &dict, string &s){
    int l = 0, r = dict.size()- 1;

    while(l <= r){
        int mid = (r-l) / 2 + l;
        if(dict[mid] == s) return mid;
        else if(dict[mid] < s) l = mid + 1;
        else r = mid - 1;
    }
    return -1; 
}
void compress(vector<string> &a, vector<string> &b,vector<int> &aa, vector<int> &bb){

    vector<string> dict = a;
    dict.insert(dict.end(), b.begin(), b.end());
    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(), dict.end()), dict.end());

    for(int i = 0; i < b.size(); i++){
        bb[i] = findpos(dict, b[i]) + 1;
    }
    for(int i = 0; i < a.size(); i++){
        aa[i] = findpos(dict, a[i]) + 1;
    }

}

void build(vector<int>&a, vector<ull>&h, vector<ull>& p){
    int n = a.size();
    h.resize(n+1);h[0] = 0;
    p.resize(n+1);p[0] = 1;

    for(int i = 1; i <n+1; i++){
        h[i] = h[i-1]*base + a[i-1];
        p[i] = p[i-1]*base;
    }
}

ull gethash(vector<ull> &h, vector<ull> &p, int l, int r){
    return (ull)(h[r] - h[l]*p[r-l]);
}
int bs(vector<unsigned long long> &a, unsigned long long x){
    int l = 0, r = a.size() - 1;

    while(l <= r){
        int mid = (r-l)/ 2 + l;
        if(a[mid] == x) return 1;
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }

    return 0;
}
int findlen(int len, vector<int>&a, vector<int> &b,vector<ull>&ha, vector<ull> &hb, vector<ull> &p){
    int bl = b.size();
    int al = a.size();
    vector<ull> temp;

    for(int i = 0; i + len <= a.size(); i++){
        temp.push_back(gethash(ha, p, i, i+len));
    }

    sort(temp.begin(), temp.end());

    for(int j = 0; j + len <= bl; j++){
        ull x = gethash(hb, p, j, j+ len);
        if(bs(temp,x)){
            return 1;
        }
    }

    return 0;
}

int solve(vector<string> &a, vector<string> &b){

    vector<int> aa(a.size()), bb(b.size());
    vector<ull> ha, hb, p;
    vector<string> dict;

    compress(a, b,aa,bb);
    build(aa, ha, p);
    build(bb, hb, p);

    int low = 0;
    int high = min(a.size(), b.size());
    int ans = 0;

    while(low <= high){
        int mid = (low + high)/2;

        if(findlen(mid, aa, bb, ha, hb, p)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
int n, m;cin >> n >> m;

vector<string> a(n);
vector<string> b(m);

for(int i = 0; i < n; i++) cin >> a[i];
for(int i = 0; i < m; i++) cin >> b[i];

cout << solve(a, b) ;

}