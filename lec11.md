# Lecture 11

## Binary Search Trees

Binary Trees such that all elements are unique and all to the left are lesser
and all to the right are greater than the current element.

## Finding min and max in a BST

For min keep going left until you reach null pointer, that element is min.
This is because all elements to the left are less than the element.

For max, keep going to the right.

## Full Node

A node with exactly 2 children.

## Non-full Node

A node with 0 or 1 children.

> [!IMPORTANT]
> Min and Max are always Non-full nodes.
> This is because if they are full, they have a lesser and greater element,
> and thus are not the min or max.

## In-order output

All left elements are printed, then node, then right.
-> elements are printed in ascending order

> [!IMPORTANT]
> If y is the successor of x then x is the predecessor of y. The pair (x,y)
> is called a (predecessor, successor) pair.

![BST](BST.png)
> [!IMPORTANT]
> Both Nodes of a (predecessor, successor) pair can never be full nodes.

PROOF:

(i, j) -> (predecessor, successor)

1. If j comes before i, i will be in the left subtree of j.
2. If i comes before j, j will be in the right subtree of i
3. For every (pred, succ) pair, either pred is ancestor of succ
or succ is ancestor of pred.

For 1:
Since i is the max value < j it means that i is the max in the left subtree of j.
Thus, i is NOT a full node, as at every subtree BST properties apply.

For 2:
Since j is the min value > i it means that j is min in the right subtree of i.
Thus, j is NOT a full node.

```c
BST_SUCCESSOR(node) {
  if (node->right != NUL)
    return BST_MIN (node->right);
  // Keeps going until the subtree is left of parent
  p = node->parent;
  while (p != NULL and node == p->right) {
    node = p; p = node->parent;
    return p;
  }
}
```

```c
BST_PREDECESSOR(node) {
  if (node->left != NUL)
    return BST_MAX (node->left);
  // Keeps going until the subtree is right of parent
  p = node->parent;
  while (p != NULL and node == p->left)
    node = p; p = node->parent;
  return p;
}
```

```c
// Inserts at leaf
BST_INSERT(root, item) {
  y = NULL, x = root;
  while (x != NULL) {
    y = x;
    if (item < x->data)
      x = x->left;
    else
      x = x->right;
  }
  node z;
  z->parent = y;
  z->data = item;
  z->left = NULL;
  z->right = NULL;

  if (root == NULL) return z;
  if (item < y-> data)
    y->left = z;
  else
    y->right = z;
  return root;
}
```

## Delete

Cases:

  1. (trivial) 0 children
  2. (easy) 1 child
  3. (tricky) 2 children

```c
BST_DELETE(root, item) {
  while (root -> data != item && root != NULL){
    if (root->data < item)
      root = root->right;
    else if (root->data > item)
      root = root->left;
  }
  if (root->data == item) {
    if (root->left!=NULL && root->right!=NULL){

    }
    else if (root->left!=NULL && root->right!=NULL) {

    }
    else {
      node p = root->parent;
      if (p->right == root)
        p->right == NULL;
      else
        p->left == NULL;
    }
  }
}
```

```c
BST_DELETE(root, node) {
  if (node->left == NULL)
    SHIFT_UP(root, node, node->right);
  else if (node->right == NULL)
    SHIFT_UP(root, node, node->right);
  else {
    y = BST_SUCCESSOR(node);
    swap(y->data, node->data);
    delete y;
  }

}

// Only valid for Non-full nodes
SHIFT_UP(root, node, child) {
  if (node->parent == NULL)
    root = child;
  else if (node = node->parent->left)
      node->parent->left = child;
  else if (node = node->parent->right)
      node->parent->right = child;
}
```
