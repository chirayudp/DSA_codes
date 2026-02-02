#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p,struct TreeNode* q) {
    if(root ==NULL ||root ==p ||root ==q)return root;

    struct TreeNode* r= lowestCommonAncestor(root->right,p,q);
    struct TreeNode* l= lowestCommonAncestor(root->left,p,q);

    if(r && l)return root;
    if(r)return r;
    return l;
}

int main(){
long long n;
scanf("%lld",&n);

}
