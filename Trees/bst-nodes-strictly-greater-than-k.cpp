/*******************************************************************************

BSTs Nodes strictly greater than k
==================================

--------------------------------------------------------------------------------

Problem
=======
For a BST of size 'n', each node has an additional field root->size storing the
number of keys in the sub-tree rooted at root (including itself). Find the total
number of nodes in the tree strictly greater than some value 'k'.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n) - Skew
O(logn) - Avg

--------------------------------------------------------------------------------

Output
======
20 (8, 22)
8 (4, 12) 22 (NULL, NULL)
4 (NULL, NULL) 12 (10, 14)
10 (NULL, NULL) 14 (NULL, NULL)

Nodes strictly greater than k = 11 are: 4

*******************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

struct Node {
    int data, size;
    Node *left;
    Node *right;
};

struct Node * getNode(int data, int size)  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->size = size;

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

int greaterKeys(Node *root, int k)  {
    int count = 0;
    while(root) {
        if(k < root->data)  {
            count += (root->right) ? root->right->size + 1 : 1;
            root = root->left;
        }

        else if(k > root->data) {
            root = root->right;
        }

        else    {
            count += (root->right) ? root->right->size : 0;
            break;
        }
    }

    return count;
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

   Node *root = getNode(20, 7);
   root->left = getNode(8, 5);
   root->right = getNode(22, 1);
   root->left->left = getNode(4, 1);
   root->left->right = getNode(12, 3);
   root->left->right->left = getNode(10, 1);
   root->left->right->right = getNode(14, 1);

   printTree(root);
   printf("\nNodes strictly greater than k = 11 are: %d\n", greaterKeys(root, 11));

   return 0;
}
