/*******************************************************************************

Prune BST
=========

Ref - http://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/

--------------------------------------------------------------------------------

Problem
=======
Remove the nodes lying outside the given range. Use postorder traversal to delete
the root at last (after deleting left and right if needed).

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
20 (8, NULL)
8 (NULL, 12)
12 (10, 14)
10 (NULL, NULL) 14 (NULL, NULL) 

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
    newNode->left = newNode->right = NULL;

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

struct Node * prune(Node *root, int k1, int k2)  {
    if(root)    {
        // postorder to work on children first
        root->left = prune(root->left, k1, k2);
        root->right = prune(root->right, k1, k2);

        if(root->data < k1) {
            Node *temp = root->right;
            delete(root);
            return temp;
        }

        else if(root->data > k2)    {
            Node *temp = root->left;
            delete(root);
            return temp;
        }
    }

    return root;
}

int main()
{
    /* BST
             20
           /    \
          8      22
         /  \
        4   12
            / \
           10  14         */

   Node *root = getNode(20);
   root->left = getNode(8);
   root->right = getNode(22);
   root->left->left = getNode(4);
   root->left->right = getNode(12);
   root->left->right->left = getNode(10);
   root->left->right->right = getNode(14);

   printf("Nodes in range 8 to 20:\n");
   prune(root, 8, 20);
   printTree(root);

   return 0;
}
