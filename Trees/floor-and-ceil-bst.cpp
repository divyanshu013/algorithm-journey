/*******************************************************************************

Floor and Ceil BST
==================

Ref - http://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/

--------------------------------------------------------------------------------

Problem
=======
Ceil Value Node: Node with smallest data larger than or equal to key value.
Floor Value Node: Node with largest data smaller than or equal to key value.

--------------------------------------------------------------------------------

Time Complexity
===============
O(logn)

--------------------------------------------------------------------------------

Output
======
Floor 30 and Ceil 30 for 30
Floor 40 and Ceil 50 for 45

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

void getFloorCeil(Node *root, int key, int *floor, int *ceil)   {
    if(root)    {
        if(root->data == key)
            *floor = *ceil = key;
        else if(root->data < key)   {
            *floor = root->data;
            getFloorCeil(root->right, key, floor, ceil);
        }
        else    {
            *ceil = root->data;
            getFloorCeil(root->left, key, floor, ceil);
        }
    }
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
    int floor, ceil;
    floor = ceil = -1;

    getFloorCeil(root, 30, &floor, &ceil);
    printf("Floor %d and Ceil %d for 30\n", floor, ceil);

    floor = ceil = -1;
    getFloorCeil(root, 45, &floor, &ceil);
    printf("Floor %d and Ceil %d for 45\n", floor, ceil);
    return 0;
}
