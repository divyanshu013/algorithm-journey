/*******************************************************************************

Ancestors of a node
=================================

Problem
=======
Finding all the ancestors of a node in a binary tree.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Ancestors of 6 are:
3 1 
Ancestors of 5 are:
2 1 

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

int ancestors(Node *root, Node *node)   {
    if(root)    {
        if(root->left == node || root->right == node || ancestors(root->left, node) || ancestors(root->right, node))    {
            printf("%d ", root->data);
            return 1;
        }
    }

    return 0;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    Node *node5 = root->left->right = getNode(5);
    Node *node6 = root->right->right = getNode(6);
    printf("Ancestors of 6 are:\n");
    ancestors(root, node6);
    printf("\n");
    printf("Ancestors of 5 are:\n");
    ancestors(root, node5);
    printf("\n");
    return 0;
}
