#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorder(struct TreeNode* root, int* idx, int* arr) {
    if (root == NULL)
        return;
    arr[(*idx)++] = root->val;
    preorder(root->left, idx, arr);
    preorder(root->right, idx, arr);
        return;
}
int* preorderTraversal(struct TreeNode* root, int* r) {
    int* arr = malloc(sizeof(int) * 100);
    int idx = 0;
    preorder(root, &idx, arr);
    *r = idx;
    return arr;
}

int main(){
long long n;
scanf("%lld",&n);

}