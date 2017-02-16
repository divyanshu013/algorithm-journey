/*******************************************************************************

Construct tree preorder inorder
===============================

Ref - http://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

--------------------------------------------------------------------------------

Problem
=======
Given preorder and inorder traversal, construct a tree.

Algorithm
=========
1. From an element in preorder, increment the preorder index in recursive call.
2. Get new node with the data.
3. Find the index in inorder of the element
4. Build tree with the elements before this as left subtree and after as right subtree.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n^2) for left skewed tree.

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

*******************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

struct Node * getNode(char data)  {
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
            printf("%c ", root->data);
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

int search(char in[], int start, int end, char value)   {
    for(int i = start; i <= end; ++i)   {
        if(in[i] == value)
            return i;
    }

    return -1;
}

struct Node * buildTree(char in[], char pre[], int inStart, int inEnd)  {
    static int preIndex = 0;    // for all recursive calls, no need to pass

    if(inStart > inEnd)
        return NULL;

    // Picking current node from preorder
    Node *temp = getNode(pre[preIndex++]);

    // for leaf node
    if(inStart == inEnd)
        return temp;

    // finding index of this node in inorder
    int inIndex = search(in, inStart, inEnd, temp->data);

    temp->left = buildTree(in, pre, inStart, inIndex - 1);
    temp->right = buildTree(in, pre, inIndex + 1, inEnd);

    return temp;
}

int main()  {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    Node *root = buildTree(in, pre, 0, 5);
    printTree(root);
    return 0;
}
