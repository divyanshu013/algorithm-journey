/*******************************************************************************

Identical Trees
===============

Ref - http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/

--------------------------------------------------------------------------------

Problem
=======
Identical trees have the same stucture and data.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Actual Tree:
1
2 3
4 5 6
Second Tree:
1
2 3
4 5 6
Trees are identical

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

bool isIdentical(Node *root1, Node *root2)   {
    if(root1 && root2)  {
        if(root1->data == root2->data)
            return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
        else
            return false;
    }
    else if(!root1 && !root2)   // both NULL
        return true;
    else
        return false;
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

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    printf("Actual Tree:\n");
    printTree(root);

    // recreating the tree before mirrored
    Node *root2 = getNode(1);
    root2->left = getNode(2);
    root2->right = getNode(3);
    root2->left->left = getNode(4);
    root2->left->right = getNode(5);
    root2->right->right = getNode(6);
    printf("Second Tree:\n");
    printTree(root2);
    if(isIdentical(root, root2))
        printf("Trees are identical\n");
    else
        printf("Trees are NOT identical\n");
    return 0;
}
