/*******************************************************************************

Iterative post order traversal
==============================

--------------------------------------------------------------------------------

Problem
=======
Iterative post order traversal (no recursion)

Algorithm
=========
1. Each node is visited twice (non tail recursion implementation)
2. Use a previous pointer to keep track of last traversed node
3. Previous node can be used to determing the direction of traversal of the tree

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Post order traversal:
4 5 2 3 1

*******************************************************************************/

#include <stdio.h>
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

void postOrder(Node *root) {
    stack<Node *> s;
    Node *prev = NULL;
    do {
        while(root) {
            s.push(root);
            root = root->left;
        }

        while(!root && !s.empty())  {
            root = s.top();

            if(root->right == NULL || prev == root->right)  {
                // traversing up from right
                printf("%d ", root->data);
                prev = root;
                s.pop();
                root = NULL;
            }
            else    {
                // traversing up from left
                root = root->right;
            }
        }
    } while(!s.empty());
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);

    printf("Post order traversal:\n");
    postOrder(root);
    printf("\n");
    return 0;
}
