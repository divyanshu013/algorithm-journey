/*******************************************************************************

BST Find path between two nodes
===============================

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Path from 4 to 22 is:
4 8 20 22
Path from 14 to 4 is:
4 8 12 14
Path from 20 to 4 is:
4 8 20

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

void swap(int *a, int *b)   {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct Node * getLCA(Node *root, int a, int b)  {
    if(!root)
        return NULL;    // LCA doesn't exist

    if(root->data >= a && root->data <= b)  // adding equals comparisson if one of the node itself is the LCA
        return root;

    if(root->data > b)
        return getLCA(root->left, a, b);

    else if(root->data > a)
        return getLCA(root->right, a, b);

    return root;
}

void printPath(Node *root, int a, int b)    {
    if(a > b)   // make a less than b
        swap(&a, &b);

    Node *lca = getLCA(root, a, b);
    if(!lca)    {
        printf("Invalid nodes\n");
        return;
    }

    stack<int> s;
    Node *temp = lca;
    while(temp->data != a)    {
        s.push(temp->data);
        if(a < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    s.push(temp->data); // a

    while(!s.empty())   {
        printf("%d ", s.top());
        s.pop();
    }

    temp = lca->right; // root already added to path
    if(!temp || lca->data == b)
        return; // LCA is the node itself

    while(temp->data != b)  {
        printf("%d ", temp->data);
        if(b > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    printf("%d ", temp->data);  // add b itself
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

   printf("Path from 4 to 22 is:\n");
   printPath(root, 4, 22);
   printf("\n");
   printf("Path from 14 to 4 is:\n");
   printPath(root, 14, 4);
   printf("\n");
   printf("Path from 20 to 4 is:\n");
   printPath(root, 20, 4);
   printf("\n");

   return 0;
}
