/*******************************************************************************

Root to leaf paths
==================

Ref - http://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/

--------------------------------------------------------------------------------

Problem
=======
In a binary tree print all root to leaf paths.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Paths in the tree:
1 -> 2 -> 4
1 -> 2 -> 5
1 -> 3 -> 6

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

void printList(int path[], int length)  {
    for(int i = 0; i < length; ++i)
        printf("%d -> ", path[i]);
    printf("\b\b\b   \n");
}

void paths(Node *root, int path[], int length)  {
    if(root)    {
        path[length++] = root->data;
        if(!root->left && !root->right) // leaf Node
            printList(path, length);
        else    {
            paths(root->left, path, length);
            paths(root->right, path, length);
        }
    }
    else
        return;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    int path[100], length = 0;
    printf("Paths in the tree:\n");
    paths(root, path, length);
    return 0;
}
