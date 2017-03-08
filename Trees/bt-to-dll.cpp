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

Alternatively,
1) Fix Left Pointers: In this step, we change left pointers to point to previous
    nodes in DLL. The idea is simple, we do inorder traversal of tree. In inorder
    traversal, we keep track of previous visited node and change left pointer to
    the previous node.

2) Fix Right Pointers: The above is intuitive and simple. How to change right
    pointers to point to next node in DLL? The idea is to use left pointers fixed
    in step 1. We start from the rightmost node in Binary Tree (BT). The rightmost
    node is the last node in DLL. Since left pointers are changed to point to
    previous node in DLL, we can linearly traverse the complete DLL using these
    pointers. The traversal would be from last to first node. While traversing
    the DLL, we keep track of the previously visited node and change the right
    pointer to the previous node.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
10 -> 20 -> 30 -> 40 -> 50
1 -> 2 -> 3 -> 4 -> 5 

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

void fixPrev(Node *root)    {
    static Node *pre = NULL;
    if(root)    {
        fixPrev(root->left);
        root->left = pre;
        pre = root;
        fixPrev(root->right);
    }
}

struct Node * fixNext(Node *root)   {
    Node *pre = NULL;
    while(root->left)   {
        root->right = pre;
        pre = root;
        root = root->left;
    }
    root->right = pre;  // for head node

    return root;
}

struct Node *toDLLAlt(Node *root)   {
    fixPrev(root);

    while(root->right)
        root = root->right;
    return fixNext(root);
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

    /* BST
             4
           /    \
          2      5
         /  \
        1   3           */

    Node *root2 = getNode(4);
    root2->left = getNode(2);
    root2->right = getNode(5);
    root2->left->left = getNode(1);
    root2->left->right = getNode(3);

    root2 = toDLLAlt(root2);
    printList(root2);
    return 0;
}
