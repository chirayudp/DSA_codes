#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
}node ;
node* create(int n){
    node* new = malloc(sizeof(node));
    new->val = n;
    new->left = new->right = NULL;
    return new;
}

node* insert(node*root , int n){
    if (root == NULL)return create(n);

    if (n>root->val)
    {
        root->right = insert(root->right,n);
    }
    else root->left = insert(root->left,n);
    return root;
    
}
node* build(int* arr,int n){
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root,arr[i]);
    }
    return root;
}
int rangeSumBST(node* root, int low, int high) {
    if(root == NULL)return 0;
    if(root->val >high)return rangeSumBST(root->left, low, high );
    if(root->val <low)return rangeSumBST(root->right, low , high);
    return root->val + rangeSumBST(root->left, low , high) + rangeSumBST(root->right, low, high );  
}   

void freebt(node* root){
    if(root == NULL)return ;
    freebt(root->right);
    freebt(root->left);
    free(root);
    return ;
}
int main(){
int n;
scanf("%d",&n);
int low, high;
scanf("%d %d",&low ,&high);
int arr[n];
for (int i = 0; i < n; i++)
{
   scanf("%d",&arr[i]);
}
node* root = build(arr, n);
int sum = rangeSumBST(root , low , high);
printf("%d\n",sum);
freebt(root);
}
