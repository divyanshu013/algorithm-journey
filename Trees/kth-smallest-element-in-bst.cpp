/*******************************************************************************

Kth smallest element in BST
===========================

Ref - http://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/

--------------------------------------------------------------------------------

Problem
=======
Inorder traversal of a BST will give a sorted list which can be used to find the
kth smallest element keeping track of the count.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
3rd smallest element in BST: 3
4th smallest element in BST: 4

*******************************************************************************/

#include <stdio.h>

struct Node {
    int data;
    Node *left;
    Node *right;
};

struct Node * getNode(int data)  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct Node * kth(Node *root, int *count, int k)    {
    if(!root)
        return NULL;

    Node *left = kth(root->left, count, k);
    if(left)
        return left;
    if(++(*count) == k)
        return root;

    return kth(root->right, count, k);
}

int main()  {

    /* BST
              4
           /     \
          2       5
         /  \
        1    3           */

    Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(5);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    int count = 0;

    printf("3rd smallest element in BST: %d\n", kth(root, &count, 3)->data);
    count = 0;
    printf("4th smallest element in BST: %d\n", kth(root, &count, 4)->data);
    return 0;
}
