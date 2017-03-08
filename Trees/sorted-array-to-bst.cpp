/*******************************************************************************

Sorted array to BST
===================

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
3
1 4
2 5

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
            printf("%d ", root->data);
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        else    {
            printf("\n");
            if(!q.empty())
                q.push(NULL);
        }
    }
}

struct Node * toBST(int a[], int left, int right)   {
    if(left > right)
        return NULL;
    Node *newNode;
    if(left == right)
        newNode = getNode(a[left]);
    else    {
        int mid = (left + right)/2;
        newNode = getNode(a[mid]);
        newNode->left = toBST(a, left, mid - 1);
        newNode->right = toBST(a, mid + 1, right);
    }

    return newNode;
}

int main()  {
    int a[] = {1, 2, 3, 4, 5};
    Node *root = toBST(a, 0, 4);
    printTree(root);
    return 0;
}
