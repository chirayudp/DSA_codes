
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root){
        if(!root)return ;
        vector<vector<int>> arr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> lev;
            for (int i = 0; i < s; i++)
            {
                TreeNode* cur = q.front(); q.pop();
                lev.push_back(cur->val);

                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            arr.push_back(lev);
        }
        return arr;
    }
        
};