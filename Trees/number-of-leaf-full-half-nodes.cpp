/*******************************************************************************

Number of full half and leaf nodes
==================================

--------------------------------------------------------------------------------

Problem
=======
Number of leaf, full and half nodes in a tree.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Leaf Nodes: 3
Half Nodes: 1
Full Nodes: 2

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

void printNodes(Node *root) {
    if(root)    {
        queue<Node *> q;
        q.push(root);
        int leaf = 0, full = 0, half = 0;
        while(!q.empty())   {
            root = q.front();
            q.pop();
            if(root->left && root->right)
                full++;
            else if(root->left || root->right)
                half++;
            else
                leaf++;

            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }

        printf("Leaf Nodes: %d\nHalf Nodes: %d\nFull Nodes: %d\n", leaf, half, full);
    }
    else    {
        printf("Root is NULL\n");
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);

    printNodes(root);
    return 0;
}
