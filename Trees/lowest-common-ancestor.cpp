/*******************************************************************************

Lowest common ancestor
======================

Ref - http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

--------------------------------------------------------------------------------

Problem
=======
Lowest/least common ancestor is the shared ancestor of two nodes farthest from
the root.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
LCA of 4 and 5: 2
LCA of 5 and 6: 1
LCA of 4 and 6: 1

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

struct Node * getLCA(Node *root, Node *a, Node *b)    {
    if(root)    {
        if(root == a || root == b)
            return root;    // the node itself is the LCA
        Node *left = getLCA(root->left, a, b);
        Node *right = getLCA(root->right, a, b);

        if(left && right)
            return root;    // the node is the LCA for left and right

        else
            return left ? left : right; // if left child was one of a or b it would not be NULL and similarily for right
    }
    else
        return NULL;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    Node *node4 = root->left->left = getNode(4);
    Node *node5 = root->left->right = getNode(5);
    Node *node6 = root->right->right = getNode(6);

    printf("LCA of 4 and 5: %d\n", getLCA(root, node4, node5)->data);
    printf("LCA of 5 and 6: %d\n", getLCA(root, node5, node6)->data);
    printf("LCA of 4 and 6: %d\n", getLCA(root, node4, node6)->data);
    return 0;
}
