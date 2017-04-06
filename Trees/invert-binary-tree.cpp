/*******************************************************************************

Invert binary tree
==================

Ref - http://qa.geeksforgeeks.org/3965/invert-the-binary-tree-and-return-it

--------------------------------------------------------------------------------

Problem
=======
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7

invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Tree before inversion:
1 (2, 3)
2 (4, 5) 3 (6, 7)
4 (NULL, NULL) 5 (NULL, NULL) 6 (NULL, NULL) 7 (NULL, NULL)

Tree after inversion
1 (3, 2)
3 (7, 6) 2 (5, 4)
7 (NULL, NULL) 6 (NULL, NULL) 5 (NULL, NULL) 4 (NULL, NULL)

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
    newNode->right = newNode->left = NULL;

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

Node * invert(Node *root) {
  if (root) {
    root->left = invert(root->left);
    root->right = invert(root->right);

    swap(root->left, root->right);
  }

  return root;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    printf("Tree before inversion:\n");
    printTree(root);
    printf("\n");
    root = invert(root);
    printf("Tree after inversion\n");
    printTree(root);
    printf("\n");
    return 0;
}
