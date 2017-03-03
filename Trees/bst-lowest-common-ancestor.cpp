/*******************************************************************************

BST lowest common ancestor
==========================

Ref - http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
LCA of 8 and 22 is 20
LCA of 10 and 22 is 20
LCA of 8 and 14 is 8

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

void swap(int *a, int *b)   {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct Node * getLCA(Node *root, int a, int b)  {
    if(!root)
        return NULL;    // LCA doesn't exist

    if(a > b)   // make a less than b
        swap(&a, &b);

    if(root->data >= a && root->data <= b)  // adding equals comparisson if one of the node itself is the LCA
        return root;

    if(root->data > b)
        return getLCA(root->left, a, b);

    else if(root->data > a)
        return getLCA(root->right, a, b);

    return root;
}

int main()
{
    /* BST
             20
           /    \
          8      22
         /  \
        4   12
            / \
           10  14         */

   Node *root = getNode(20);
   root->left = getNode(8);
   root->right = getNode(22);
   root->left->left = getNode(4);
   root->left->right = getNode(12);
   root->left->right->left = getNode(10);
   root->left->right->right = getNode(14);

    printf("LCA of 8 and 22 is %d\n", getLCA(root, 22, 8)->data);
    printf("LCA of 10 and 22 is %d\n", getLCA(root, 10, 22)->data);
    printf("LCA of 8 and 14 is %d\n", getLCA(root, 8, 14)->data);

    return 0;
}
