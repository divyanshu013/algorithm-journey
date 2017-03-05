/*******************************************************************************

Check if BST
============

Ref - http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Tree is NOT BST


*******************************************************************************/

#include <stdio.h>
#include <limits.h>

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

bool isBST(Node *root, int min, int max)  {
    if(!root)
        return true;
    else
        return root->data > min && root->data < max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
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

    // swap children to check
    root->left->right = getNode(1);
    root->left->left = getNode(3);
    // root->left->left = getNode(1);
    // root->left->right = getNode(3);

    if(isBST(root, INT_MIN, INT_MAX))
        printf("Tree is BST\n");
    else
        printf("Tree is NOT BST\n");


}
