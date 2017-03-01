/*******************************************************************************

Stock Buy Sell to Maximize Profit
=================================

Ref - http://quiz.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
    - http://quiz.geeksforgeeks.org/binary-search-tree-set-2-delete/

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

Tree after deleting 60:
50
30 70
20 40 80

Tree after deleting 30:
50
20 70
40 80

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

struct Node * maxChild(Node *root)  {
    if(root->right)
        return maxChild(root->right);

    return root;
}

struct Node * del(Node *root, int data) {
    if(!root)
        return NULL;

    if(data == root->data)  {
        // only one child
        if(!root->left) {
            Node *temp = root->right;
            delete(root);
            return temp;
        }
        else if(!root->right)   {
            Node *temp = root->left;
            delete(root);
            return temp;
        }

        // both children
        else    {
            Node *temp = maxChild(root->left);
            root->data = temp->data;
            root->left = del(root->left, temp->data);
        }
    }

    else if(data < root->data)
        root->left = del(root->left, data);

    else
        root->right = del(root->right, data);

    return root;
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

    printf("\nTree after deleting 60:\n");
    del(root, 60);
    printTree(root);
    printf("\n");

    printf("Tree after deleting 30:\n");
    del(root, 30);
    printTree(root);
    printf("\n");

    return 0;
}
