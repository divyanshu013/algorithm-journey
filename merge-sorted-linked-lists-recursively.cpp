/*******************************************************************************

Merge sorted linked lists recursively
=====================================

Ref - http://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

--------------------------------------------------------------------------------

Problem
=======
Merge two sorted linked lists using recursion

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
4 -> 8 -> 10 -> 14

1 -> 7 -> 12 -> 18

1 -> 4 -> 7 -> 8 -> 10 -> 12 -> 14 -> 18 

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

Node * merge(Node *a, Node *b) {
    if(!a)
        return b;
    if(!b)
        return a;

    Node *head;
    if(a->data <= b->data)  {
        head = a;
        head->next = merge(a->next, b);
    }
    else    {
        head = b;
        head->next = merge(a, b->next);
    }

    return head;
}

int main()  {
    Node *head = getNode(14);
    push(&head, 10);
    push(&head, 8);
    push(&head, 4);
    printList(head);
    printf("\b\b\b   \n");

    Node *head2 = getNode(18);
    push(&head2, 12);
    push(&head2, 7);
    push(&head2, 1);
    printList(head2);
    printf("\b\b\b   \n"); // destructive backspace

    Node *merged = merge(head, head2);
    printList(merged);
    printf("\b\b\b   \n");
    return 0;
}
