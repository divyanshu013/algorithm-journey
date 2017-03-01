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
Tree is:
50
30 70
20 40 60 80

Lowest element in tree: 20
Highest element in tree: 80

Data 60 exists in tree
Data 75 does NOT exist in tree

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

struct Node * insert(Node *root, int data)  {
    if(root)    {
        if(data < root->data)
            root->left = insert(root->left, data);
        else if(data > root->data)
            root->right = insert(root->right, data);
    }
    else
        root = getNode(data);

    return root;
}

struct Node * lowest(Node *root)    {
    if(root->left)
        return lowest(root->left);

    return root;
}

struct Node * highest(Node *root)    {
    if(root->right)
        return highest(root->right);

    return root;
}

struct Node * find(Node *root, int data)    {
    if(root)    {
        if(root->data == data)
            return root;
        else if(data < root->data)
            return find(root->left, data);
        else
            return find(root->right, data);
    }

    return NULL;
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

    printf("Tree is:\n");
    printTree(root);
    printf("\n");
    printf("Lowest element in tree: %d\n", lowest(root)->data);
    printf("Highest element in tree: %d\n", highest(root)->data);
    printf("\n");

    if(find(root, 60))
        printf("Data 60 exists in tree\n");
    else
        printf("Data 60 does NOT exist in tree\n");

    if(find(root, 75))
        printf("Data 75 exists in tree\n");
    else
        printf("Data 75 does NOT exist in tree\n");

    return 0;
}
