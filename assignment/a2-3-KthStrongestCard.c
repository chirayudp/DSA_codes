

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// ─────────────────────────────────────────────
// AVL Node
// Convention: stronger = right, weaker = left
// sz = total cards in subtree (duplicates counted)
// ─────────────────────────────────────────────
typedef struct node {
    int a, d, cnt, h;
    long long sz;
    struct node *left, *right;
} node;

int unique_size = 0;

// Pool allocator — much faster than malloc per node
node pool[300005];
int pool_idx = 0;

node* create(int a, int d) {
    node* n = &pool[pool_idx++];
    n->a = a; n->d = d;
    n->cnt = 1; n->h = 1; n->sz = 1;
    n->left = n->right = NULL;
    return n;
}

// ─────────────────────────────────────────────
// Strength comparison
// 1 = first stronger, 2 = first weaker, 0 = equal
// ─────────────────────────────────────────────
int scmp(int a1,int d1,int a2,int d2){
    if(a1+d1 > a2+d2) return 1;
    if(a1+d1 < a2+d2) return 2;
    if(a1 > a2) return 1;
    if(a1 < a2) return 2;
    return 0;
}

// ─────────────────────────────────────────────
// AVL Helpers
// ─────────────────────────────────────────────
int ht(node* n)        { return n ? n->h : 0; }
long long sz(node* n)  { return n ? n->sz : 0; }

void upd(node* n) {
    if(!n) return;
    n->h  = 1 + (ht(n->left) > ht(n->right) ? ht(n->left) : ht(n->right));
    n->sz = sz(n->left) + sz(n->right) + n->cnt;
}

int bal(node* n) { return n ? ht(n->left) - ht(n->right) : 0; }

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
        if(bal(n->left) < 0) n->left = rotL(n->left);   // LR case
        return rotR(n);
    }
    if(bal(n) < -1) {
        if(bal(n->right) > 0) n->right = rotR(n->right); // RL case
        return rotL(n);
    }
    return n;
}

// ─────────────────────────────────────────────
// Insert
// ─────────────────────────────────────────────
node* insert(node* root, int a, int d) {
    if(!root) {
        unique_size++;
        return create(a, d);
    }
    int c = scmp(root->a, root->d, a, d);
    if(c == 0) {
        root->cnt++;
        root->sz++;
        return root;
    }
    if(c == 1) root->left  = insert(root->left,  a, d); // root stronger → new is weaker → goes left
    else       root->right = insert(root->right, a, d); // root weaker  → new is stronger → goes right
    return rebal(root);
}

// ─────────────────────────────────────────────
// Delete one copy; removes node if cnt hits 0
// ─────────────────────────────────────────────
node* minnode(node* n) { return n->left ? minnode(n->left) : n; }

node* delete(node* root, int a, int d) {
    if(!root) return NULL;
    int c = scmp(root->a, root->d, a, d);
    if(c == 1)      root->left  = delete(root->left,  a, d);
    else if(c == 2) root->right = delete(root->right, a, d);
    else {
        // found the node
        if(root->cnt > 1) {
            root->cnt--;
            root->sz--;
            return rebal(root);
        }
        // cnt == 1, remove node
        unique_size--;
        if(!root->left)  return root->right;
        if(!root->right) return root->left;
        // two children: replace with inorder successor (min of right subtree)
        node* mn = minnode(root->right);
        root->a   = mn->a;
        root->d   = mn->d;
        root->cnt = mn->cnt;
        // now delete that successor (it has cnt copies, delete all at once)
        // but delete() only removes one copy at a time, so we need a full node removal
        // use a helper that removes the min node entirely
        root->right = delete(root->right, mn->a, mn->d);
        unique_size++; // delete decremented it, correct back since we already counted above
        upd(root);
        return rebal(root);
    }
    return rebal(root);
}

// ─────────────────────────────────────────────
// Search: returns cnt or -1
// ─────────────────────────────────────────────
int search(node* root, int a, int d) {
    if(!root) return -1;
    int c = scmp(root->a, root->d, a, d);
    if(c == 0) return root->cnt;
    if(c == 1) return search(root->left,  a, d);
    return         search(root->right, a, d);
}

// ─────────────────────────────────────────────
// Kth strongest (1-indexed)
// stronger=right, so we visit right subtree first
// sz counts total cards including duplicates
// ─────────────────────────────────────────────
node* kthstr(node* root, int k) {
    if(!root) return NULL;
    long long right_sz = sz(root->right);
    if(k <= right_sz)                    return kthstr(root->right, k);
    if(k <= right_sz + root->cnt)        return root;
    return kthstr(root->left, k - right_sz - root->cnt);
}

// ─────────────────────────────────────────────
// Print: stronger=right, so reverse inorder = right→root→left
// gives strongest to weakest
// ─────────────────────────────────────────────
void printbst(node* root) {
    if(!root) return;
    printbst(root->right);
    printf("%d %d %d\n", root->a, root->d, root->cnt);
    printbst(root->left);
}

int main(){
    int n;
    scanf("%d", &n);
    node* root = NULL;

    for(int i = 0; i < n; i++){
        int a, d;
        scanf("%d %d", &a, &d);
        root = insert(root, a, d);
    }

    int q;
    scanf("%d", &q);

    while(q--){
        char str[20];
        scanf("%s", str);

        if(strcmp(str, "TRADE") == 0){
            int a1, d1, a2, d2;
            scanf("%d %d %d %d", &a1, &d1, &a2, &d2);

            if(a2 == -1 && d2 == -1){
                // Rule 2: no card requested, always accept
                root = insert(root, a1, d1);
                printf("1\n");
            }
            else if(search(root, a2, d2) <= 1){
                // Rule 1: don't have or only 1 copy → decline
                printf("0\n");
            }
            else {
                // Have >= 2 copies of requested card
                int have_offered = search(root, a1, d1);
                if(have_offered == -1){
                    // Rule 3a: don't own offered card → accept
                    printf("1\n");
                    root = delete(root, a2, d2);
                    root = insert(root, a1, d1);
                }
                else {
                    // Rule 3b: already own offered card → compare strength
                    if(scmp(a1, d1, a2, d2) == 2){
                        // offered weaker than requested → decline
                        printf("0\n");
                    }
                    else {
                        // offered equal or stronger → accept
                        printf("1\n");
                        root = delete(root, a2, d2);
                        root = insert(root, a1, d1);
                    }
                }
            }
        }
        else if(strcmp(str, "KTH_STRONGEST") == 0){
            int k;
            scanf("%d", &k);
            node* tmp = kthstr(root, k);
            if(!tmp) printf("-1\n");
            else     printf("%d %d %d\n", tmp->a, tmp->d, tmp->cnt);
        }
    }

    printf("%d\n", unique_size);
    printbst(root);

    return 0;
}