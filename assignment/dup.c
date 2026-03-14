#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 200007
typedef struct node {
    long long a, lld, cnt, h;
    long long sz;
    struct node *left, *right;
} node;

long long unique_size = 0;

node pool[300005];
long long pool_idx = 0;

node* create(long long a, long long lld) {
    node* n = &pool[pool_idx++];
    n->a = a; n->lld = lld;
    n->cnt = 1; n->h = 1; n->sz = 1;
    n->left = n->right = NULL;
    return n;
}

long long scmp(long long a1,long long d1,long long a2,long long d2){
    if(a1+d1 > a2+d2) return 1;
    if(a1+d1 < a2+d2) return 2;
    if(a1 > a2) return 1;
    if(a1 < a2) return 2;
    return 0;
}

long long ht(node* n)        { return n ? n->h : 0; }
long long sz(node* n)  { return n ? n->sz : 0; }

void upd(node* n) {
    if(!n) return;
    n->h  = 1 + (ht(n->left) > ht(n->right) ? ht(n->left) : ht(n->right));
    n->sz = sz(n->left) + sz(n->right) + n->cnt;
}

long long bal(node* n) { return n ? ht(n->left) - ht(n->right) : 0; }

node* rotR(node* y) {
    node* x = y->left;
    y->left = x->right;
    x->right = y;
    upd(y); upd(x);
    return x;
}

node* rotL(node* x) {
    node* y = x->right;
    x->right = y->left;
    y->left = x;
    upd(x); upd(y);
    return y;
}

node* rebal(node* n) {
    upd(n);
    if(bal(n) > 1) {
        if(bal(n->left) < 0) n->left = rotL(n->left);  
        return rotR(n);
    }
    if(bal(n) < -1) {
        if(bal(n->right) > 0) n->right = rotR(n->right);
        return rotL(n);
    }
    return n;
}

node* insert(node* root, long long a, long long lld) {
    if(!root) {
        unique_size++;
        return create(a, lld);
    }
    long long c = scmp(root->a, root->lld, a, lld);
    if(c == 0) {
        root->cnt++;
        root->sz++;
        return root;
    }
    if(c == 1) root->left  = insert(root->left,  a, lld); 
    else       root->right = insert(root->right, a, lld); 
    return rebal(root);
}

node* minnode(node* n) {
    return n->left ? minnode(n->left) : n; 
}

node* delete(node* root, long long a, long long lld) {
    if(!root) return NULL;
    long long c = scmp(root->a, root->lld, a, lld);
    if(c == 1)      root->left  = delete(root->left,  a, lld);
    else if(c == 2) root->right = delete(root->right, a, lld);
    else {
        if(root->cnt > 1) {
            root->cnt--;
            root->sz--;
            return rebal(root);
        }
        unique_size--;
        if(!root->left)  return root->right;
        if(!root->right) return root->left;
        node* mn = minnode(root->right);
        root->a   = mn->a;
        root->lld   = mn->lld;
        root->cnt = mn->cnt;
 
        root->right = delete(root->right, mn->a, mn->lld);
        unique_size++; 
        upd(root);
        return rebal(root);
    }
    return rebal(root);
}

long long search(node* root, long long a, long long lld) {
    if(!root) return -1;
    long long c = scmp(root->a, root->lld, a, lld);
    if(c == 0) return root->cnt;
    if(c == 1) return search(root->left,  a, lld);
    return search(root->right, a, lld);
}

node* kthstr(node* root, long long k) {
    if(!root) return NULL;
    long long right_sz = sz(root->right);
    if(k <= right_sz)                    return kthstr(root->right, k);
    if(k <= right_sz + root->cnt)        return root;
    return kthstr(root->left, k - right_sz - root->cnt);
}

void printbst(node* root) {
    if(!root) return;
    printbst(root->right);
    printf("%lld %lld %lld\n", root->a, root->lld, root->cnt);
    printbst(root->left);
}

int main(){
long long n;
scanf("%lld", &n);
node* root = NULL;

for(long long i = 0; i < n; i++){
    long long a, lld;
    scanf("%lld %lld", &a, &lld);
    root = insert(root, a, lld);
}

long long q;
scanf("%lld", &q);

while(q--){
    char str[20];
    scanf("%s", str);

    if(strcmp(str,"TRADE") == 0){
        long long a1, d1, a2, d2;
        scanf("%lld %lld %lld %lld", &a1, &d1, &a2, &d2);

        if(a2 == -1 && d2 == -1){
            root = insert(root, a1, d1);
            printf("1\n");
        }
        else if(search(root, a2, d2) <= 1){
            printf("0\n");
        }
        else {
            long long have_offered = search(root, a1, d1);
            if(have_offered == -1){
                printf("1\n");
                root = delete(root, a2, d2);
                root = insert(root, a1, d1);
            }
            else {
                if(scmp(a1, d1, a2, d2) == 2){
                    printf("0\n");
                }
                else {
                    printf("1\n");
                    root = delete(root, a2, d2);
                    root = insert(root, a1, d1);
                }
            }
        }
    }
    else if(strcmp(str, "KTH_STRONGEST") == 0){
        long long k;
        scanf("%lld", &k);
        node* tmp = kthstr(root, k);
        if(!tmp) printf("-1\n");
        else     printf("%lld %lld %lld\n", tmp->a, tmp->lld, tmp->cnt);
    }
}

printf("%lld\n", unique_size);
printbst(root);
}

