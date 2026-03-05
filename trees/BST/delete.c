#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// without parent;
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* min(TreeNode* root) {
    if (root == NULL)
        return NULL;
    if (root->left == NULL)
        return root;
    return min(root->left);
}
void shift(TreeNode** root, TreeNode* par, TreeNode* c,TreeNode* gc) {
    if (par == NULL) {
        *root = gc;
        return;
    }
    if (c == par->left)
        par->left = gc;
    else
        par->right = gc;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* par = NULL;
    TreeNode* cur = root;
    while (cur && cur->val != key) {
        par = cur;
        if (key < cur->val)
            cur = cur->left;
        else if (key > cur->val)
            cur = cur->right;
    }
    if (!cur) {
        return root;
    }
    if (cur->left == NULL)
        shift(&root, par, cur, cur->right);
    else if (cur->right == NULL)
        shift(&root, par, cur, cur->left);
    else {
        TreeNode* par_min = NULL;
        TreeNode* m = cur->right;
        while (m->left) {
            par_min = m;
            m = m->left;
        }
        if (par_min) {
            shift(&root, par_min, m, m->right);
            m->right = cur->right;
        }
        shift(&root, par, cur, m);
        m->left = cur->left;
    }
    return root;
}

int main(){
long long n;
scanf("%lld",&n);

}
