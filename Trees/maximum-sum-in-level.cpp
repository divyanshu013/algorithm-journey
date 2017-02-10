/*******************************************************************************

Maximum sum in level
====================

Ref - http://www.geeksforgeeks.org/find-level-maximum-sum-binary-tree/

--------------------------------------------------------------------------------

Problem
=======
Maximum sum in levels.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Maximum sum in levels: 15

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

int maxSum(Node *root)  {
    if(root)    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);   // sentinel value to determine change in levels
        int max = 0, sum = 0;
        while(!q.empty())   {
            root = q.front();
            q.pop();
            if(root)    {
                sum += root->data;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            else    {
                if(sum > max)
                    max = sum;
                sum = 0;
                if(!q.empty())  // check for leaf nodes
                    q.push(NULL);
            }
        }

        return max;
    }
    else
        return 0;
}

int main()  {
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    printf("Maximum sum in levels: %d\n", maxSum(root));
    return 0;
}
