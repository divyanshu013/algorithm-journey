/*******************************************************************************

BT to DLL
=========

Ref - http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/

--------------------------------------------------------------------------------

Problem
=======
1. If left subtree exists, process the left subtree
    a) Recursively convert the left subtree to DLL.
    b) Then find inorder predecessor of root in left subtree (inorder predecessor is rightmost node in left subtree).
    c) Make inorder predecessor as previous of root and root as next of inorder predecessor.
2. If right subtree exists, process the right subtree (Below 3 steps are similar to left subtree).
    a) Recursively convert the right subtree to DLL.
    b) Then find inorder successor of root in right subtree (inorder successor is leftmost node in right subtree).
    c) Make inorder successor as next of root and root as previous of inorder successor.
3. Find the leftmost node and return it (the leftmost node is always head of converted DLL).

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
10 -> 20 -> 30 -> 40 -> 50

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

void printList(Node *head)  {
    while(head) {
        printf("%d -> ", head->data);
        head = head->right;
    }
    printf("\b\b\b   \n");
}

struct Node * toDLL(Node *root) {
    if(root)    {
        if(root->left)  {
            Node *left = toDLL(root->left);

            // find inorder predecessor of root
            while(left->right)
                left = left->right;

            left->right = root;
            root->left = left;
        }

        if(root->right) {
            Node *right = toDLL(root->right);

            // find inorder successor of root
            while(right->left)
                right = right->left;

            root->right = right;
            right->left = root;
        }
    }

    return root;
}

int main()  {

    /* BST
             40
           /    \
          20      50
         /  \
        10   30           */

    Node *root = getNode(40);
    root->left = getNode(20);
    root->right = getNode(50);
    root->left->left = getNode(10);
    root->left->right = getNode(30);

    root = toDLL(root);
    while(root->left)
        root = root->left;

    // taking list to the head
    printList(root);
    return 0;
}
