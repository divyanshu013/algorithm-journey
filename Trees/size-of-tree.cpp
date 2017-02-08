/*******************************************************************************

Size of tree
============

Ref - http://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/

--------------------------------------------------------------------------------

Problem
=======
Finding the size of a binary tree.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

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

int getSize(Node *root) {
    if(root)    {
        return getSize(root->left) + getSize(root->right) + 1;
    }
    else
        return 0;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);

    printf("Size of the tree: %d\n", getSize(root));
    return 0;
}
