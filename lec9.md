# Lecture 9

## Implementation of Binary Trees

```c
typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

node* root;
root = create(x);

create (x) {

  node* new;
  new->data = x;
  if (left subtree exists) {
    take value y for left node from user.
    new -> left = create(y);
    else new->left = null;
  }

  if (right subtree exists) {
    take value z for right node from user.
    new -> right = create(z);
    else new->right = null;
  }
}
```

## How can we store a general tree (T) as a binary tree (B)?

The left-child right-sibling binary tree.

- Root of B is Root of T
- B's left child is T's first child, and B's right child represents T's next sibling.

## Puzzle

p = number of null pointers

p = i₁ + 2l = i₁ + 2l = n+1

> [!IMPORTANT]
> l = i₂ + i₁
