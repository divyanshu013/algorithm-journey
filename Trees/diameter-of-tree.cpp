/*******************************************************************************

Diameter of tree
================

Ref - http://www.geeksforgeeks.org/diameter-of-a-binary-tree/

--------------------------------------------------------------------------------

Problem
=======
Diameter of a tree is the number of nodes on the longest path between two leaves
in the tree (not necessarily through root)

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Diameter: 5

*******************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;

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

int diameter(Node *root, int *height)   {
    if(root)    {
        int lh = 0, rh = 0, ld = 0, rd = 0;

        ld = diameter(root->left, &lh);
        rd = diameter(root->right, &rh);

        *height = max(lh, rh) + 1;
        return max(lh + rh + 1, max(ld, rd));
    }
    else    {
        *height = 0;
        return 0;
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    int height = 0;
    printf("Diameter: %d\n", diameter(root, &height));
    return 0;
}
