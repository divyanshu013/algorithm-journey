/*******************************************************************************

Binary tree preorder inorder successor
======================================

--------------------------------------------------------------------------------

Problem
=======
Finding the preoder and inorder successor in a binary stack requires a static
stack to remember the already traversed nodes in between calls.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

*******************************************************************************/

#include <stdio.h>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

struct Node * preoderSuccessor(Node *p)  {
    static stack<Node *> s;
    if(p)    {
        if(p->left) {
            s.push(p);
            p = p->left;
        }
        else    {
            while(!p->right)    {
                p = s.top();
                s.pop();
            }
            p = p->right;
        }
    }

    return p;
}

struct Node * inorderSuccessor(Node *p) {
    static stack<Node *> s;
    if(p)   {
        if(p->right)    {
            s.push(p);
            p = p->right;
            while(p->left)  {
                s.push(p);
                p = p->left;
            }
        }
        else    {
            p = s.top();
            s.pop();
        }
    }

    return p;
}
