/*******************************************************************************

BST Find in range
=================

--------------------------------------------------------------------------------

Problem
=======
Find all the nodes of a BST in the range k1 and k2.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Nodes in range 8 to 20: 8 10 12 14 20
Nodes in range 14 to 22: 14 20 22 

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

void range(Node *root, int k1, int k2)  {
    if(root)    {
        if(root->data >= k1)
            range(root->left, k1, k2);  // more nodes will be towards left of root
        if(root->data >= k1 && root->data <= k2)
            printf("%d ", root->data);
        if(root->data <= k2)
            range(root->right, k1, k2); // more nodes will be towards right of root
    }
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

   printf("Nodes in range 8 to 20: ");
   range(root, 8, 20);

   printf("\nNodes in range 14 to 22: ");
   range(root, 14, 22);
   printf("\n");

   return 0;
}
