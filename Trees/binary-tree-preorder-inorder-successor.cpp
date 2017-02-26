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
                
            }
        }
    }
}
