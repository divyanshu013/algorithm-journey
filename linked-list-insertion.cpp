/*******************************************************************************

Linked list insertion
=====================

Ref - https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list

--------------------------------------------------------------------------------

Problem
=======
Insert a node into linked list at some position

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
3 -> 1 -> 2 -> 4

*******************************************************************************/

#include <stdio.h>

struct Node {
    int data;
    Node *next;
};

struct Node * getNode(int data)    {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert(Node **head, int data, int position)    {
    Node *newNode = getNode(data);

    if(!newNode)    {
        printf("Memory error\n");
        return;
    }

    Node *p = *head, *q;

    if(position == 0)   {
        newNode->next = p;
        *head = newNode;
    }

    else    {
        int i = 0;
        while (p && i < position)   {
            i++;
            q = p;
            p = p->next;
        }

        q->next = newNode;
        newNode->next = p;
    }
}

void printList(Node *head)  {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\b\b\b   \n"); // destructive backspace
}

int main()  {
    Node *head = getNode(1);
    insert(&head, 2, 1);
    insert(&head, 3, 0);
    insert(&head, 4, 3);
    printList(head);
    return 0;
}
