/*******************************************************************************

Isomorphic trees
================

Ref - http://www.geeksforgeeks.org/tree-isomorphism-problem/

--------------------------------------------------------------------------------

Problem
=======
Check if two trees are Isomorphic to each other (can be obtained by swapping nodes,
left and right child).

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
First tree:
1
2 3
4 5 6
7 8
Second tree:
1
3 2
6 4 5
8 7
Trees are Isomorphic

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

bool isIsomorphic(Node *root1, Node *root2) {
    if(root1 && root2)  {
        if(root1->data != root2->data)
            return false;

        return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
            (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
    }
    else if(!root1 && !root2)
        return true;
    else
        return false;   // only one node is NULL
}

int main()  {
    Node *n1 = getNode(1);
    n1->left        = getNode(2);
    n1->right       = getNode(3);
    n1->left->left  = getNode(4);
    n1->left->right = getNode(5);
    n1->right->left  = getNode(6);
    n1->left->right->left = getNode(7);
    n1->left->right->right = getNode(8);
    printf("First tree:\n");
    printTree(n1);

    Node *n2 = getNode(1);
    n2->left         = getNode(3);
    n2->right        = getNode(2);
    n2->right->left   = getNode(4);
    n2->right->right   = getNode(5);
    n2->left->right   = getNode(6);
    n2->right->right->left = getNode(8);
    n2->right->right->right = getNode(7);
    printf("Second tree:\n");
    printTree(n2);

    if(isIsomorphic(n1, n2))
        printf("Trees are Isomorphic\n");
    else
        printf("Trees are NOT Isomorphic\n");
    return 0;
}
