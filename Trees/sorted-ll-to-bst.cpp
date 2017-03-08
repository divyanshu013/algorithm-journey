/*******************************************************************************

Sorted LL to BST
================

Ref - http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

--------------------------------------------------------------------------------

Problem
=======
The idea is to insert nodes in BST in the same order as the appear in Linked List,
so that the tree can be constructed in O(n) time complexity.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
3 (2, 5)
2 (1, NULL) 5 (4, NULL)
1 (NULL, NULL) 4 (NULL, NULL)

*******************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

struct LNode    {
    int data;
    LNode *next;
};

struct TNode {
    int data;
    TNode *left;
    TNode *right;
};

struct LNode * getLNode(int data)   {
    LNode *newNode = new LNode();
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct TNode * getTNode(int data)  {
    TNode *newNode = new TNode();
    newNode->data = data;
    newNode->right = newNode->left = NULL;

    return newNode;
}

void printTree(TNode *root) {
    queue<TNode *> q;
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

struct TNode * toBST(LNode **head, int n)   {
    if(n < 1)
        return NULL;

    TNode *left = toBST(head, n/2);

    TNode *root = getTNode((*head)->data);
    root->left = left;

    *head = (*head)->next;

    root->right = toBST(head, n - n/2 - 1);

    return root;
}

int main()  {
    LNode *head = getLNode(1);
    head->next = getLNode(2);
    head->next->next = getLNode(3);
    head->next->next->next = getLNode(4);
    head->next->next->next->next = getLNode(5);

    TNode *root = toBST(&head, 5);
    printTree(root);
    return 0;
}
