/*******************************************************************************

Tree traversal
=================================

Ref - http://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

--------------------------------------------------------------------------------

Problem
=======
Tree traversal using preorder, inorder and postorder

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

Space Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Preorder traversal:
1 2 4 5 3
Inorder traversal:
4 2 5 1 3
Postorder traversal:
4 5 2 3 1

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

void preOrder(Node *root)   {
    if(root)    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root)   {
    if(root)    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node *root)   {
    if(root)    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);

    printf("Preorder traversal:\n");
    preOrder(root);
    printf("\n");

    printf("Inorder traversal:\n");
    inOrder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postOrder(root);
    printf("\n");

    return 0;
}
