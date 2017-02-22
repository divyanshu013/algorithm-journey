/*******************************************************************************

Sum of generic tree
===================

--------------------------------------------------------------------------------

Problem
=======
In a generic tree (with any number of children per node) find the sum of all nodes.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Sum of the generic tree is: 21

*******************************************************************************/

#include <stdio.h>

struct Node {
    int data;
    Node *firstChild;
    Node *nextSibling;
};

struct Node * getNode(int data)  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->firstChild = newNode->nextSibling = NULL;

    return newNode;
}

int getSum(Node *root)  {
    if(root)
        return root->data + getSum(root->firstChild) + getSum(root->nextSibling);
}

int main()  {
    Node *root = getNode(1);
    Node *root2 = root->firstChild = getNode(2);
    Node *root3 = root2->nextSibling = getNode(3);
    root3->nextSibling = getNode(4);
    Node *root5 = root3->firstChild = getNode(5);
    root5->nextSibling = getNode(6);
    printf("Sum of the generic tree is: %d\n", getSum(root));
    return 0;
}
