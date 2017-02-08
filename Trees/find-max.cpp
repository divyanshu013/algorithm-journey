/*******************************************************************************

Find max in tree
================

Ref - http://quiz.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/

--------------------------------------------------------------------------------

Problem
=======
Find maximum element in a tree.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Maximum element in tree: 5

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

int getMax(Node *root)  {
    if(root)    {
        int data = root->data;
        int left = getMax(root->left);
        int right = getMax(root->right);
        int max;

        if(left > right)
            max = left;
        else
            max = right;

        if(data > max)
            max = data;

        return max;
    }
    else    {
        return -1; // some sentinel value
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);

    printf("Maximum element in tree: %d\n", getMax(root));
    return 0;
}
