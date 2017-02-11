/*******************************************************************************

Path sum exists
===============

Ref - http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/

--------------------------------------------------------------------------------

Problem
=======
Check if a path sum exists in a tree or not.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Path sum of 7 exists
Path sum of 8 exists
Path sum of 15 does NOT exist

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

bool isPathSum(Node *root, int sum) {
    if(root)    {
        sum -= root->data;

        bool result = isPathSum(root->left, sum);
        result = result || isPathSum(root->right, sum);
        return result;
    }
    else
        return sum == 0;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    if(isPathSum(root, 7))
        printf("Path sum of 7 exists\n");
    else
        printf("Path sum of 7 does NOT exist\n");
    if(isPathSum(root, 8))
        printf("Path sum of 8 exists\n");
    else
        printf("Path sum of 8 does NOT exist\n");
    if(isPathSum(root, 15))
        printf("Path sum of 15 exists\n");
    else
        printf("Path sum of 15 does NOT exist\n");
    return 0;
}
