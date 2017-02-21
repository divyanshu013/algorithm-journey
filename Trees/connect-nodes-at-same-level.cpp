/*******************************************************************************

Connect nodes at same level
===========================

Ref - http://www.geeksforgeeks.org/connect-nodes-at-same-level/

--------------------------------------------------------------------------------

Problem
=======
Connect a child node to its next sibling or the next node at same level.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Tree is:
1
2 3
4 5 6
Connected 1 to NULL
Connected 2 to 3
Connected 3 to NULL
Connected 4 to 5
Connected 5 to 6
Connected 6 to NULL

*******************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *nextSibling;
};

struct Node * getNode(int data)  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = newNode->nextSibling = NULL;

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

void connectSiblings(Node *root) {
    if(root)    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())   {
            Node *temp = q.front();
            q.pop();
            if(temp)    {
                temp->nextSibling = q.front();
                if(q.front())
                    printf("Connected %d to %d\n", temp->data, q.front()->data);
                else
                    printf("Connected %d to NULL\n", temp->data);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else    {
                if(!q.empty())
                    q.push(NULL);
            }
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
    printf("Tree is:\n");
    printTree(root);
    connectSiblings(root);
    return 0;
}
