/*******************************************************************************

Construct k-ary tree from array
===============================

--------------------------------------------------------------------------------

Problem
=======
From a given array of preorder traversal of a full k-ary tree, construct the tree.

Algorithm
=========
The children for a k-ary tree of ith node will be from k*i + 1 to k*i + k.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

*******************************************************************************/

#include <stdio.h>
#include <vector>
using namespace std;

struct Node {
    char data;
    vector<Node *> child;  // vector of child pointers
};

struct Node * getNode(char data)  {
    Node *newNode = new Node();
    newNode->data = data;

    return newNode;
}

void printTreePreorder(Node *root, int k)  {
    if(root)    {
        printf("%c", root->data);
        for(int i = 0; i < k; ++i)  {
            printTreePreorder(root->child[i], k);
        }
    }
}

struct Node * getTree(const char str[], int *i, int n, int k) {

    Node *newNode = getNode(str[*i]);
    for(int j = 0; j < k; ++j)  {
        printf("For %d\n", *i);
        if(k * (*i) + j < n)   {
            (*i)++;
            newNode->child.push_back(getTree(str, i, n, k));
        }
        else
            newNode->child.push_back(NULL);
    }

    return newNode;
}

int main()  {
    const char *str = "ABEFGCIJKD";
    int i = 0;  // index for preorder
    Node *root = getTree(str, &i, 10, 3);   // a 3-ary tree
    printTreePreorder(root, 3);
    return 0;
}
