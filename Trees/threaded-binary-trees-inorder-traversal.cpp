/*******************************************************************************

Threaded binary trees inorder traversal
=======================================

Ref - http://quiz.geeksforgeeks.org/threaded-binary-tree/

--------------------------------------------------------------------------------

Problem
=======
The idea of threaded binary trees is to make inorder traversal faster and do it
without stack and without recursion. A binary tree is made threaded by making all
right child pointers that would normally be NULL point to the inorder successor
of the node (if it exists).

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

Space Complexity
===============
O(1) unlike normal binary trees

--------------------------------------------------------------------------------

Output
======
2 5 1 16 11 31
After insertion of the node:
2 5 1 16 11 13 31

*******************************************************************************/

#include <stdio.h>

struct Node {
    int data;
    int lTag;
    int rTag;
    Node *left, *right;
};

struct Node * getNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->lTag = newNode->rTag = 0;
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct Node * successor(Node *p)    {
    Node *pos = p->right;
    if(p->rTag) {
        while(pos->lTag)
            pos = pos->left;
    }
    return pos;
}

void inorder(Node *root)    {
    Node *p = successor(root);
    while(p != root)    {
        printf("%d ", p->data);
        p = successor(p);
    }
}

void insert(Node *p, int data)  {
    Node *q = getNode(data);
    q->right = p->right;
    q->rTag = p->rTag;
    q->left = p;
    q->lTag = 0;
    p->right = q;
    p->rTag = 1;

    if(q->rTag) {
        Node *temp = q->right;
        while(temp->lTag)
            temp = temp->left;
        temp->left = q;
    }
}

int main()  {
    Node *root = getNode(-1);   // dummy node
    root->lTag = root->rTag = 1;
    root->right = root;

    Node *n1 = root->left = getNode(1);
    n1->lTag = n1->rTag = 1;
    Node *n2 = n1->left = getNode(5);
    n2->lTag = 1;
    n2->rTag = 0;
    n2->right = n1;
    Node *n3 = n2->left = getNode(2);
    n3->lTag = n3->rTag = 0;
    n3->left = root;
    n3->right = n2;
    Node *n4 = n1->right = getNode(11);
    n4->lTag = n4->rTag = 1;
    Node *n5 = n4->left = getNode(16);
    n5->lTag = n5->rTag = 0;
    n5->left = n1;
    n5->right = n4;
    Node *n6 = n4->right = getNode(31);
    n6->lTag = n6->rTag = 0;
    n6->left = n4;
    n6->right = root;

    inorder(root);  // inorder traversal using inorder successor
    printf("\n");
    insert(n4, 13); // inserts a node with data 13 after node n4
    printf("After insertion of the node:\n");
    inorder(root);
    printf("\n");
    return 0;
}
