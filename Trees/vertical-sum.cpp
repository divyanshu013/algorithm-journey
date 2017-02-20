/*******************************************************************************

Vertical sum in tree
====================

Ref - http://www.geeksforgeeks.org/vertical-sum-in-a-given-binary-tree/

--------------------------------------------------------------------------------

Problem
=======
Finding the vertical sums in a tree, for left child column-- and for right child
collumn++

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Vertical sum for all columns are:
6 4 2 6 3

*******************************************************************************/

#include <stdio.h>
#include <unordered_map>    // c++11
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

void getVerticalSum(Node *root, unordered_map<int, int> *umap, int column)  {
    if(root)    {
        getVerticalSum(root->left, umap, column - 1);
        (*umap)[column] += root->data;
        getVerticalSum(root->right, umap, column + 1);
    }
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    printf("Vertical sum for all columns are:\n");
    unordered_map<int, int> umap;
    getVerticalSum(root, &umap, 0);
    unordered_map<int, int>::iterator itr;
    for(itr = umap.begin(); itr != umap.end(); itr++)
        printf("%d ", itr->second);
    printf("\n");
    return 0;
}
