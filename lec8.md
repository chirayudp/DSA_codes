# Lecture 8

<!-- toc -->

- [Doubly Ended Queues (Dequeues)](#doubly-ended-queues-dequeues)
- [Trees](#trees)
  * [Binary Tree](#binary-tree)
  * [Full Binary Tree](#full-binary-tree)
  * [Complete Binary Tree](#complete-binary-tree)
  * [Perfect Binary Tree](#perfect-binary-tree)
  * [Balanced Binary Tree](#balanced-binary-tree)
  * [Degenerate / Pathological Binary Tree](#degenerate--pathological-binary-tree)

<!-- tocstop -->

## Doubly Ended Queues (Dequeues)

Insertion and deletion can happen at both ends.

Example : Hospital waiting list. In case of emergency
removal is from rear instead of front.

| - | 6 | 12 | - |
| --------------- | --------------- | --------------- | --------------- |
| - | 6 | 12 | 5 |
| - | - | 12 | 5 |
| - | - | 12 | - |
| - | 7 | 12 | - |
| - | 7 | 12 | 9 |

1. Add 5 to rear
2. Remove from front
3. Remove from rear
4. Add 7 to front
5. Add 9 to rear

```cpp
insert_front(q[], front, rear, max, item) {
  if (front == rear + 1 || front == 0 && rear == max -1) {
    printf("Queue Full"\n);
  } else {
    if (front == -1) {
      front = 0; rear = 0;
    } else if (front == 0) {
      front = max-1;
    } else {
      front = front -1;
    }
    q[front] = item;
  }
}

delete_rear(q[], front, rear, max) {
  if (front == -1) {
    printf("Queue empty");
  } else {
    item = q[rear];
    if (front == rear) {
      front = rear = -1;
    } else if (rear == 0){
      rear = max - 1;
    } else {
      rear = rear - 1;
    }
    return item;
  }
}
```

## Trees

Non linear data structure

![Tree](tree_0.webp)

8 Family Members

1-8 are nodes.

- 1 is the parent of nodes 2 and 3 and they are its children.

- 2 and 3 are siblings as they have the same parent.

- Root node is the only node without parents, in this case 1.

- Leaf nodes are the nodes without children.

- A node is an ancestor of another node
if it lies on the path from it to the root node

- Node X is a descendant of node Y if Y is an ancestor of X.

- Depth: Distance from root node
- Height: Maximum depth amongst all nodes

### Binary Tree

A tree in which each node has at most 2 children

### Full Binary Tree

A tree in which each node has 0 or 2 children

### Complete Binary Tree

All levels are filled in from top to bottom and left to right.

> [!IMPORTANT]
> It is not necessary for a complete binary tree to be full.
> e.g 1 - (2 - (4) 3) is not a full binary tree but it is a complete binary tree

### Perfect Binary Tree

A full binary tree in which all leaves have the same depth.

> This means that it is also a complete binary tree

### Balanced Binary Tree

Height of left and right subtrees of every node differ by at most 1.

In a complete binary tree the depths of all leaf nodes differ by at most 1.

However, Balanced Binary Trees are not necessarily Complete.

### Degenerate / Pathological Binary Tree

Each node has at most one child

- Edge: Connection between two nodes. Number of edges = Number of nodes - 1

- For a full binary tree, ```2h+1 <= n <= 2 ^ (h+1) - 1```

- Number of leaf nodes in a perfect binary tree is (n+1/2)

- Number of leaf nodes = i₂ + 1, i₂ = internal nodes of degree 2
