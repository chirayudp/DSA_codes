#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode* create(int key) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* par = NULL;
    struct TreeNode* cur = root;

    while (cur) {
        par = cur;
        if (val < cur->val)
            cur = cur->left;
        else
            cur = cur->right;
    }

    struct TreeNode* n = create(val);
    if (par == NULL) return n;
    if (val < par->val)
        par->left = n;
    else
        par->right = n;
    return root;
}
