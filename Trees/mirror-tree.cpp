/*******************************************************************************

Mirror a tree
=============

Ref - http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

--------------------------------------------------------------------------------

Problem
=======
Mirror a binary tree. Left child and right child are interchanged for all nodes.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Actual Tree:
1
2 3
4 5 6
Mirrored Tree:
1
3 2
6 5 4 

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

void mirror(Node *root) {
    if(root)    {
        mirror(root->left);
        mirror(root->right);

        // swap the pointers while popping the recursive stacks
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    else
        return;
}

void printTree(Node *root) {
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(root)    {
            printf("%d ", root->data);
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        else    {
            printf("\n");
            if(!q.empty())
                q.push(NULL);
        }
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    printf("Actual Tree:\n");
    printTree(root);
    mirror(root);
    printf("Mirrored Tree:\n");
    printTree(root);
    return 0;
}
