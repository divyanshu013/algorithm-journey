/*******************************************************************************

Reverse level order traversal
=============================

Ref - http://www.geeksforgeeks.org/reverse-level-order-traversal/

--------------------------------------------------------------------------------

Problem
=======
Level order traversal in reverse order of levels

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

*******************************************************************************/

#include <stdio.h>
#include <queue>
#include <stack>
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

void reverseLevel(Node *root)   {
    if(root)    {
        queue<Node *> q;
        stack<Node *> s;
        q.push(root);
        while(!q.empty())   {
            root = q.front();
            q.pop();
            s.push(root);
            if(root->right)
                q.push(root->right);
            if(root->left)
                q.push(root->left);
        }

        while(!s.empty())   {
            root = s.top();
            printf("%d ", root->data);
            s.pop();
        }
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);

    printf("Reverse level order traversal:\n");
    reverseLevel(root);
    printf("\n");
    return 0;
}
