/*******************************************************************************

Stock Buy Sell to Maximize Profit
=================================

Ref - http://quiz.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

--------------------------------------------------------------------------------

Problem
=======
Finding elements in BSTs.

--------------------------------------------------------------------------------

Time Complexity
===============
O(logn)

except for skew trees O(n)

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

*******************************************************************************/

#include <stdio.h>

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

int main()
{
    /* BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    

    return 0;
}
