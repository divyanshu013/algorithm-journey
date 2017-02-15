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
Trees are mirrors

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

bool isMirror(Node *root1, Node *root2)   {
    if(root1 && root2)  {
        if(root1->data == root2->data)
            return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
        else
            return false;
    }
    else if(!root1 && !root2)   // both NULL
        return true;
    else
        return false;
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

    // recreating the tree before mirrored
    Node *root2 = getNode(1);
    root2->left = getNode(2);
    root2->right = getNode(3);
    root2->left->left = getNode(4);
    root2->left->right = getNode(5);
    root2->right->right = getNode(6);
    if(isMirror(root, root2))
        printf("Trees are mirrors\n");
    else
        printf("Trees are NOT mirrors\n");
    return 0;
}
