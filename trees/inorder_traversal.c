#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode* root, int* arr, int* idx) {
    if (root == NULL)
        return ;
    inorder(root->left, arr, idx);
    arr[*idx] = root->val;
    (*idx)++;
    inorder(root->right, arr, idx);
    
}

int* inorderTraversal(struct TreeNode* root, int* r) {
    int* arr = malloc(sizeof(int) * 100);
    int idx =0;
    inorder(root, arr, &idx);
    *r = idx;
    return arr;
}

int main(){
long long n;
scanf("%lld",&n);

}
