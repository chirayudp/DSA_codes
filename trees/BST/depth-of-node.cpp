#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* right;
    node* left;
    int val;

    node(int key){
        val = key;
        left = nullptr;
        right = nullptr;
    }
};
int depth(node* root,int k){
    if(!root)return -1;
    queue<pair<node*,int>> q;
    q.push({root,0});
    while (!q.empty())
    {
        auto [n,d] = q.front(); q.pop();

        if(k == n->val)return d;
        if(k< n->val)q.push({n->left,d+1});
        else q.push({n->right,d+1});    
    }
    return -1;
}
int main(){
int n; cin >> n;

}