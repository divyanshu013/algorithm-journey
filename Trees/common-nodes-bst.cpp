/*******************************************************************************

Common nodes in BST
===================

Ref - http://www.geeksforgeeks.org/print-common-nodes-in-two-binary-search-trees/

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Common nodes are:
1 3 4 5

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

void printCommon(Node *root1, Node *root2)  {
  stack<Node *> s1, s2;

  while(true) {
    if(root1) {
      s1.push(root1);
      root1 = root1->left;
    }

    else if(root2)  {
      s2.push(root2);
      root2 = root2->left;
    }

    // for !root1 and !root2
    else if(!s1.empty() && !s2.empty()) {
      root1 = s1.top();
      root2 = s2.top();
      if(root1->data == root2->data) {
        printf("%d ", root1->data);
        s1.pop();
        s2.pop();

        root1 = root1->right;
        root2 = root2->right;
      }

      else if(root1->data < root2->data)  {
        s1.pop();
        root1 = root1->right;
        root2 = NULL; // no need to push root2 again
      }

      else  {
        s2.pop();
        root2 = root2->right;
        root1 = NULL;
      }
    }

    else
      break;  // both roots and stacks empty
  }
}

int main()  {

    /* BST
              4
           /     \
          2       5
         /  \
        1    3           */

    Node *root1 = getNode(4);
    root1->left = getNode(2);
    root1->right = getNode(5);
    root1->left->left = getNode(1);
    root1->left->right = getNode(3);

    /* BST
              5
           /     \
          3       8
         /  \
        1    4           */

    Node *root2 = getNode(5);
    root2->left = getNode(3);
    root2->right = getNode(8);
    root2->left->left = getNode(1);
    root2->left->right = getNode(4);

    printf("Common nodes are:\n");
    printCommon(root1, root2);
    printf("\n");
    return 0;
}
