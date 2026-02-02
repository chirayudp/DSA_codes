#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count=0;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int maxDepth(struct TreeNode* root) {
    if (root == NULL){
        printf("%d",count);
        return 0;
    }
     
    if (root->left == NULL && root->right == NULL)
        return 1;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    if (r>l){
        printf("%d",count);
        return count+=r;
    }
    printf("%d",count);
    return count+=l;
}
int main(){
long long n;
scanf("%lld",&n);

}
