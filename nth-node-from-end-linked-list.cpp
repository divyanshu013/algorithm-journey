/*******************************************************************************

N-th node from end of a linked list
===================================

Ref - http://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Find the nth node from the end of a linked list

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
4 -> 3 -> 2 -> 1
3th node from end is 3

*******************************************************************************/

#include <stdio.h>

struct Node {
    int data;
    Node *next;
};

struct Node * getNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node **head, int data)    {
    Node *newNode = getNode(data);

    if(head)   {
        newNode->next = *head;
        *head = newNode;
    }

    else    {
        *head = newNode;
    }
}

void printList(Node *head)  {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\b\b\b   \n"); // destructive backspace
}

struct Node * nthNodeFromEnd(Node *head, int n)    {
    Node *p = head, *q = head;
    for (int i = 0; i < n; i++) {
        if(p)
            p = p->next;
        else    {
            printf("Node doesn't exists\n");
            return NULL;
        }
    }
    while(p)    {
        q = q->next;
        p = p->next;
    }
    return q;
}

int main()  {
    Node *head = getNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    printList(head);

    Node *nth = nthNodeFromEnd(head, 3);
    if(nth)
        printf("%dth node from end is %d\n", 3, nth->data);
    return 0;
}
