/*******************************************************************************

Sum of tree
===========

--------------------------------------------------------------------------------

Problem
=======
Sum of all nodes of a tree.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Sum of tree: 21

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

int sum(Node *root) {
    if(root)
        return sum(root->left) + sum(root->right) + root->data;
    else
        return 0;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    printf("Sum of tree: %d\n", sum(root));
    return 0;
}
