#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    long long val;
    struct node* left;
    struct node* right;
}node ;
node* create(long long num){
    node* new = malloc(sizeof(node));
    new->val = num;
    new->left = NULL;
    new->right = NULL;
    return new;
}
long long idx;
node* insert(node* root, long long value) {
    if (root == NULL)
        return create(value);

    if (value < root->val)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}
 
node* build(long long* arr, long long n) {
    node* root = NULL;
    for (long long i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}


long long depth(node* root,long long key){
    if(root == NULL)return 0;
    // printf("%lld\n",root->val);

    if(key==root->val){
        // printf("e1\n");
        return 0;
    }
    else if(key < root->val){
        long long l=depth(root->left,key);
        // printf("l%lld\n",l+1);
        return 1+l; 
    }
    long long r=depth(root->right,key);
    // printf("r%lld\n",r+1);
    return 1+r; 
}
int main(){
    long long t;
    scanf("%lld",&t);

    for(long long i=0;i<t;i++){
        long long n,k;
        scanf("%lld %lld",&n,&k);
        long long arr[n];
        for(long long j=0;j<n;j++)
            scanf("%lld",&arr[j]);
        idx=1;
        node* root = build(arr,n);
        long long lld = depth(root,k);
        printf("%lld\n",lld);
        free(root);
    }

}