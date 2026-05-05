#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* right;
    node* left;
    int val;

    node(int key){
        val = key;
        left = nullptr;
        right = nullptr;
    }
};

node* insertbst(node* root , int k){
    node* cur = root , *par = NULL;
    while (cur)
    {
        par = cur;
        if(k < cur->val)cur = cur->left;
        else cur = cur -> right;
    }
    node* x = new node(k);
    if(par == NULL)return x;
    if(x->val > par->val) par->right = x;
    else par->left = x;
    return root;
}
void transplant(node** root,node* par,node* n1,node* n2){
    if(!par){
        *root = n2;
        return;
    }
    if(n1 == par->left) par ->left = n2;
    else par->right = n2;
    return ;
}

node* deletebst(node* root, int k){
    node* cur = root , *par = NULL;
    while (cur && cur ->val != k)
    {
        par = cur;
        if(k < cur->val)cur = cur->left;
        else cur = cur -> right;
    }
    if(cur == NULL) return root;
    if(cur->left == NULL)transplant(&root,par,cur , cur->right);
    else if(cur->right == NULL)transplant(&root,par,cur , cur->left);
    else {
        node* p = NULL;
        node* m = cur->right;
        while (m->left)
        {
            p = m;
            m = m->left;
        }
        if(p){
            transplant(&root,p,m , m->right);
            m->right = cur->right;
        }
        transplant(&root,par,cur,m);
        m->left= cur->left;
    }
    delete cur;    
    return root;
}
int main(){
int n; cin >> n;

}