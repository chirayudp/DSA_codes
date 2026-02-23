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
    TreeNode* p = NULL;
    TreeNode* z = root;
    while (z && z->val != key) {
        p = z;
        if (key < z->val)
            z = z->left;
        else if (key > z->val)
            z = z->right;
    }
    if (!z) {
        return root;
    }
    if (z->left == NULL)
        shift(&root, p, z, z->right);
    else if (z->right == NULL)
        shift(&root, p, z, z->left);
    else {
        TreeNode* pr = NULL;
        TreeNode* m = z->right;
        while (m->left) {
            pr = m;
            m = m->left;
        }
        if (pr) {
            shift(&root, pr, m, m->right);
            m->right = z->right;
        }
        shift(&root, p, z, m);
        m->left = z->left;
    }
    return root;
}

int main(){
long long n;
scanf("%lld",&n);

}
