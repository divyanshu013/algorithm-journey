/*******************************************************************************

Clone linked list random
=================================

Ref - http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
    - http://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/

--------------------------------------------------------------------------------

Problem
=======
Clone a linked list having a *next and *rand which points to some random node.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
(1, 3) -> (2, 1) -> (3, 4) -> (4, 2)
(1, 3) -> (2, 1) -> (3, 4) -> (4, 2)

*******************************************************************************/

#include <stdio.h>

struct Node {
    int data;
    Node *next;
    Node *rand;
};

struct Node * getNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->rand = NULL;
    return newNode;
}

void printList(Node *head)  {
    Node *current = head;
    while(current) {
        printf("(%d, %d) -> ", current->data, current->rand->data);
        current = current->next;
    }
    printf("\b\b\b   \n"); // destructive backspace
}

void clone(Node *head)  {
    Node *current = head;
    while(current) {
        Node *temp = getNode(current->data);
        temp->next = current->rand;
        current->rand = temp;
        current = current->next;
    }

    current = head;
    while(current)  {
        Node *temp = current->rand;
        temp->rand = temp->next->rand;
        current = current->next;
    }

    current = head;
    Node *newHead = current->rand;
    while(current)  {
        Node *temp = current->rand;
        current->rand = temp->next;
        if(current->next)
            temp->next = current->next->rand;
        else
            temp->next = NULL;
        current = current->next;
    }

    printList(newHead);
}

int main()  {
    Node *node1 = getNode(1);
    Node *node2 = getNode(2);
    Node *node3 = getNode(3);
    Node *node4 = getNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    node1->rand = node3;
    node2->rand = node1;
    node3->rand = node4;
    node4->rand = node2;

    printList(node1);
    clone(node1);
    return 0;
}
