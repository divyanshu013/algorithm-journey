/*******************************************************************************

AVL Trees Insertion and Deletion
================================

Ref - http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
    - http://www.geeksforgeeks.org/avl-tree-set-2-deletion/

--------------------------------------------------------------------------------

Problem
=======

Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take
O(h) time where h is the height of the BST. The cost of these operations may
become O(n) for a skewed Binary tree. If we make sure that height of the tree
remains O(Logn) after every insertion and deletion, then we can guarantee an
upper bound of O(Logn) for all these operations. The height of an AVL tree is
always O(Logn) where n is the number of nodes in the tree.

--------------------------------------------------------------------------------

Time Complexity
===============
O(logn)

--------------------------------------------------------------------------------

Output
======
AVL Tree is:
30 (20, 40)
20 (10, 25) 40 (NULL, 50)
10 (NULL, NULL) 25 (NULL, NULL) 50 (NULL, NULL)

*******************************************************************************/

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data, height;
    Node *left;
    Node *right;
};

struct Node * getNode(int data)  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;

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
            printf("%d (", root->data);
            if(root->left)  {
                printf("%d, ", root->left->data);
                q.push(root->left);
            }
            else
                printf("NULL, ");
            if(root->right) {
                printf("%d) ", root->right->data);
                q.push(root->right);
            }
            else
                printf("NULL) ");
        }
        else    {
            printf("\n");
            if(!q.empty())
                q.push(NULL);
        }
    }
}

int height(Node *root)  {
    if(root)
        return root->height;
    else
        return 0;
}

void setHeight(Node *root)   {
    if(root)
        root->height = max(height(root->left), height(root->right)) + 1;
}

int getBalance(Node *root)  {
    if(root)
        return height(root->left) - height(root->right);
    else
        return 0;
}

// right rotation
struct Node * LLSingle(Node *x) {
    Node *w = x->left;
    x->left = w->right;
    w->right = x;
    setHeight(x);
    setHeight(w);
    return w;
}

// left rotation
struct Node * RRSingle(Node *x) {
    Node *w = x->right;
    x->right = w->left;
    w->left = x;
    setHeight(x);
    setHeight(w);
    return w;
}

struct Node * insert(Node *root, int data)  {
    if(!root)
        return getNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);

    else if(data > root->data)
        root->right = insert(root->right, data);

    else    // equal nodes (not possible in BST)
        return root;

    // update new height of the tree
    setHeight(root);

    // checking for balance factor
    int balance = getBalance(root);

    // Left case
    if(balance > 1) {
        if(data < root->left->data) {
            // LL (needs right rotation)
            return LLSingle(root);
        }
        else    {
            // LR (needs left and right rotation)
            root->left = RRSingle(root->left);
            return LLSingle(root);
        }
    }

    // Right case
    else if(balance < -1)   {
        if(data > root->right->data)    {
            // RR (needs left rotation)
            return RRSingle(root);
        }
        else    {
            // RL (needs right and left rotation)
            root->right = LLSingle(root->right);
            return RRSingle(root);
        }
    }

    else
        return root;    // unchanged
}

int main()  {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50 */

    printf("AVL Tree is:\n");
    printTree(root);

    return 0;
}
