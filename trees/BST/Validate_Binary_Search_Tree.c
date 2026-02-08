#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
// bool isValidBST(struct TreeNode* root) {
//     if(root==NULL)return true;
//     if(root->left && root->left->val >= root->val)return false;
//     if(root->right && root->right->val <= root->val)return false;
//     bool l=isValidBST(root->left);
//     bool r=isValidBST(root->right);

//     if(r && l)return true;
//     return false;
// }
int idx;
int arr[10000] = {0};
void store(struct TreeNode* root) {
    if(root== NULL)return ;
    store(root->left);
    arr[idx++] = root->val;
    store(root->right);
}
bool isValidBST(struct TreeNode* root) {
    if (root->left == NULL && root->right == NULL)
        return true;
    idx=0;
    store(root);
    int t = 1;
    for (int i = 0; i < idx-1 ; i++) {
        if (arr[i] >= arr[i + 1]) {
            t = 0;
            break;
        }
    }
    if (t)
        return true;
    return false;
}
int main(){
long long n;
scanf("%lld",&n);

}
