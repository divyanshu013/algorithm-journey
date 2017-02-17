/*******************************************************************************

Construct tree inorder postorder
================================

Ref - http://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

--------------------------------------------------------------------------------

Problem
=======
Construct a binary tree for given inorder and postorder.

Algorithm
=========
1. Find last node from post[]. (root)
2. Search in inorder to find left and right subtrees.
3. Recursively create tree.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n^2)

--------------------------------------------------------------------------------

Output
======
1
2 3
4 5 6 7
8 

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

int search(int in[], int start, int end, int value)   {
    for(int i = start; i <= end; ++i)   {
        if(in[i] == value)
            return i;
    }

    return -1;
}

struct Node * buildTree(int in[], int post[], int inStart, int inEnd)  {
    static int postIndex = inEnd;    // for all recursive calls, no need to pass

    if(inStart > inEnd)
        return NULL;

    // Picking current node from postorder
    Node *temp = getNode(post[postIndex--]);

    // for leaf node
    if(inStart == inEnd)
        return temp;

    // finding index of this node in inorder
    int inIndex = search(in, inStart, inEnd, temp->data);

    // need to build right subtree first in postorder
    temp->right = buildTree(in, post, inIndex + 1, inEnd);
    temp->left = buildTree(in, post, inStart, inIndex - 1);

    return temp;
}

int main()  {
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    Node *root = buildTree(in, post, 0, 7);
    printTree(root);
    return 0;
}
