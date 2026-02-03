#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void sumleaf(struct TreeNode* root, int* s){
    if(root==NULL)return ;
    if(root->left==NULL &&  root->right==NULL){
        printf("%d ",*s);
        *s+=root->val;}
    sumleaf(root->left,s);
    if(root->right && root->right->left && root->right->right){
        sumleaf(root->right,s);
    }
    return;

}
int sumOfLeftLeaves(struct TreeNode* root) {
    if(root == NULL)return 0;
    if(root->left == NULL)return 0;
    int sum=0;
    sumleaf(root, &sum);
    return sum;
}

int main(){
long long n;
scanf("%lld",&n);

}