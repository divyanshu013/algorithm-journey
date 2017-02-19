/*******************************************************************************

Zig zag (Spiral) tree traversal
======================

Ref - http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

--------------------------------------------------------------------------------

Problem
=======
Traverse the tree in spiral (zig zag) level order.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Zig-zag traversal is:
1 3 2 4 5 6

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

void myswap(stack<Node *> *a, stack<Node *> *b) {
    stack<Node *> temp = *a;
    *a = *b;
    *b = temp;
}

void zigzag(Node *root) {
    if(root)    {
        stack<Node *> current, store;
        current.push(root);
        bool leftToRight = true;

        while(!current.empty()) {
            Node *temp = current.top();
            printf("%d ", temp->data);
            current.pop();
            if(leftToRight) {
                if(temp->left)
                    store.push(temp->left);
                if(temp->right)
                    store.push(temp->right);
            }
            else    {
                if(temp->right)
                    store.push(temp->right);
                if(temp->left)
                    store.push(temp->left);
            }

            if(current.empty()) {
                leftToRight = !leftToRight;
                myswap(&current, &store);   // or std::swap(current, store)
            }
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
    printf("Zig-zag traversal is:\n");
    zigzag(root);
    printf("\n");
    return 0;
}
