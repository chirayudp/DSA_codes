#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int diameterOfBinaryTree(struct TreeNode* root) {
    if(root==NULL)return 0;
    int l=diameterOfBinaryTree(root->left);
    int r=diameterOfBinaryTree(root->right);
    return (l>r)?l:r;
}


int main(){
long long n;
scanf("%lld",&n);

}
