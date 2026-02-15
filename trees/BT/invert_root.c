#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return root;
    if (root->left == NULL && root->right == NULL)
        return root;

    struct TreeNode* l = invertTree(root->left);
    struct TreeNode* r = invertTree(root->right);
    root->left=r;
    root->right=l;

    return root;
}


int main(){
long long n;
scanf("%lld",&n);

}