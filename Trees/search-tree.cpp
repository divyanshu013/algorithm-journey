/*******************************************************************************

Search tree
===========

--------------------------------------------------------------------------------

Problem
=======
Find if an element is present in a tree

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
5 is present in tree
7 is NOT present in tree

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

bool isPresent(Node *root, int data)    {
    if(root)    {
        if(root->data == data)
            return true;
        else if(isPresent(root->left, data))
            return true;
        else
            return isPresent(root->right, data);
    }
    else
        return false;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);

    if(isPresent(root, 5))
        printf("%d is present in tree\n", 5);
    else
        printf("%d is NOT present in tree\n", 5);

    if(isPresent(root, 7))
        printf("%d is present in tree\n", 7);
    else
        printf("%d is NOT present in tree\n", 7);

    return 0;
}
