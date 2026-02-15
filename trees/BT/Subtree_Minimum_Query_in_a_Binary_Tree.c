#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node
{
    int value;
    struct Node *parent, *left, *right;
} TreeNode;

TreeNode *InitNode(int value)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->left = temp->right = temp->parent = NULL;
    temp->value = value;
    return temp;
}

int minm(int a, int b)
{
    return ((a < b) ? a : b);
}

int minofnode(TreeNode *root, int *arr, int *idx)
{
    if (root == NULL)
        return __INT_MAX__;
    if (root->left == NULL && root->right == NULL)
    {
        // printf("(%d) ", root->value);
        arr[root->value] = root->value;
        return root->value;
    }
    int l = minofnode(root->left, arr, idx);
    int r = minofnode(root->right, arr, idx);
    int min = root->value;
    if (l < min)
        min = l;
    if (r < min)
        min = r;
    arr[root->value] = min;
    // printf("(m%d) ", min);
    return min;
}
int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    TreeNode **tree = (TreeNode **)calloc(n, sizeof(TreeNode *));
    for (int i = 0; i < n; i++)
        tree[i] = InitNode(i);
    int root_index = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        if (array[i] == -1)
        {
            tree[i]->parent = NULL;
            root_index = i;
        }
        else
        {
            tree[i]->parent = tree[array[i]];
            if (tree[array[i]]->left != NULL)
                tree[array[i]]->right = tree[i];
            else
                tree[array[i]]->left = tree[i];
        }
        tree[i]->value = i;
    }
    TreeNode *root = tree[root_index];
    int idx = 0;
    int arr[n];
    minofnode(root, arr, &idx);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // The above code takes input of the tree and the root node can be accessed via root
    // Each node has attributes - value, left, right and parent.
}
