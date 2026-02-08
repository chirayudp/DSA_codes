#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root) {
    if(root == NULL)return 0;
    int sum = 0;
    if(root->left && root ->left->right == NULL && root->left->left==NULL)sum+=root->val;
    sum += sumleaf(root->left);    
    sum+= sumleaf(root->right);

    return sum;
}

int main(){
long long n;
scanf("%lld",&n);

}