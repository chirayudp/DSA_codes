#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};
// this might look like copy pasted from a llm but no!! i did it by myself 😁
struct Node* connect(struct Node* root) {
    if (!root)
        return NULL;
    if (root->left && root->right)
        root->left->next = root->right;
    if (root->next && root->right)
        root->right->next = root->next->left;
    connect(root->right);
    connect(root->left);
    return root;
}

int main(){
long long n;
scanf("%lld",&n);

}
