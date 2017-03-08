/*******************************************************************************

Sorted DLL to BST
=================

--------------------------------------------------------------------------------

Time Complexity
===============
O(nlogn) - n/2 calls in each level and logn levels in all

--------------------------------------------------------------------------------

Output
======
3
2 5
1 4

*******************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct Node * getNode(int data)  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

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
            if(root->prev)
                q.push(root->prev);
            if(root->next)
                q.push(root->next);
        }
        else    {
            printf("\n");
            if(!q.empty())
                q.push(NULL);
        }
    }
}

struct Node * mid(Node *head)   {
    Node *fast, *slow;
    fast = slow = head;

    if(!head)
        return NULL;

    while(fast && fast->next)   {   // need the second middle node for even list
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

struct Node * toBST(Node *head) {
    if(!head || !head->next)
        return head;
    else    {
        Node *temp = mid(head);
        if(temp->prev)
            temp->prev->next = NULL;
        if(temp->next)
            temp->next->prev = NULL;

        temp->prev = toBST(head);
        temp->next = toBST(temp->next);

        return temp;
    }
}

int main()  {
    Node *head = getNode(1);
    Node *n2 = head->next = getNode(2);
    n2->prev = head;
    Node *n3 = n2->next = getNode(3);
    n3->prev = n2;
    Node *n4 = n3->next = getNode(4);
    n4->prev = n3;
    Node *n5 = n4->next = getNode(5);
    n5->prev = n4;

    head = toBST(head);
    printTree(head);
}
