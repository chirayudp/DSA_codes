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

int checksum(node* root,long long key,long long sum){
    if(root == NULL)return 0;
    long long s=sum+root->val;
    // printf("vp%lld sum%lld",root->val,s);
    if(s == key){
        if(root->left == NULL && root->right == NULL){
            // printf("ep\n");
            return 1;
        }
        // return 0;
    }
    int r=checksum(root->right,key,s);
    int l=checksum(root->left,key,s); 
    if(r || l)return 1;
    return 0;
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
        node* root = build(arr,n);
        
        int s=checksum(root,k,0);
        printf("%d\n",s);
        free(root);
    }

}
