/*******************************************************************************

Tree traversal stack
====================

Ref - http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
    - http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
    - http://www.geeksforgeeks.org/iterative-postorder-traversal/

--------------------------------------------------------------------------------

Problem
=======
Tree traversal using a stack explicitly (no recursion)

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

Space Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Preorder traversal:
1 2 4 5 3
Inorder traversal:
4 2 5 1 3
Postorder traversal:
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

void preOrder(Node *root)   {
    stack<Node *> s;
    while(true) {
        while(root) {
            printf("%d ", root->data);
            s.push(root);
            root = root->left;
        }

        if(s.empty())
            break;

        root = s.top();
        s.pop();
        root = root->right;
    }
}

void inOrder(Node *root)   {
    stack <Node *> s;
    while(true) {
        while(root) {
            s.push(root);
            root = root->left;
        }

        if(s.empty())
            break;

        root = s.top();
        s.pop();
        printf("%d ", root->data);

        root = root->right;
    }
}

void postOrder(Node *root)   {
    // non-tail recursion
    stack <Node *> s1, s2;
    if(root)    {
        s1.push(root);
        while(!s1.empty())  {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if(root->left)
                s1.push(root->left);
            if(root->right)
                s1.push(root->right);
        }

        while(!s2.empty())  {
            root = s2.top();
            s2.pop();
            printf("%d ", root->data);
        }
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);

    printf("Preorder traversal:\n");
    preOrder(root);
    printf("\n");

    printf("Inorder traversal:\n");
    inOrder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postOrder(root);
    printf("\n");

    return 0;
}
