/*******************************************************************************

Level order traversal
=====================

Ref - http://www.geeksforgeeks.org/level-order-tree-traversal/

--------------------------------------------------------------------------------

Problem
=======
Level order traversal of a binary tree

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Level order traversal:
1 2 3 4 5

*******************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

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

void levelOrder(Node *root) {
    queue<Node *> q;
    if(root)
        q.push(root);
    else
        return;

    while(!q.empty())   {
        root = q.front();
        q.pop();
        printf("%d ", root->data);
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);

    printf("Level order traversal:\n");
    levelOrder(root);
    printf("\n");
    return 0;
}
