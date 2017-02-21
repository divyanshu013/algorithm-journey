/*******************************************************************************

Connect tree with only leaf and internal nodes
==============================================

--------------------------------------------------------------------------------

Problem
=======
From a given preorder string construct a tree with leaf nodes as 'L' and internal nodes as
'I', with each node having only 0 or 2 child. eg- ILILL

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Tree is:
I
L I
L L

*******************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

struct Node * getNode(char data)  {
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
            printf("%c ", root->data);
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

struct Node * constructTree(const char *str, int *i)  {
    Node *newNode = getNode(str[*i]);
    if(newNode->data == 'L')
        return newNode;

    if(str[++*i] != '\0')
        newNode->left = constructTree(str, i);

    if(str[++*i] != '\0')
        newNode->right = constructTree(str, i);

    return newNode;
}

int main()  {
    int i = 0;
    const char *str = "ILILL";
    // Interesting to note
    // const char * mutable pointer to immutable string since string literal is stored in read only memory
    // http://stackoverflow.com/questions/9834067/difference-between-char-and-const-char for more details
    Node *root = constructTree(str, &i);
    printf("Tree is:\n");
    printTree(root);
    return 0;
}
