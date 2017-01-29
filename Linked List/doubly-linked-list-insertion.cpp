/*******************************************************************************

Doubly linked list insertion
============================

Ref - http://quiz.geeksforgeeks.org/doubly-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Insert nodes in Doubly linked list at some position.

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

struct DLLNode  {
    int data;
    DLLNode *prev;
    DLLNode *next;
};

struct DLLNode * getNode(int data)  {
    DLLNode *newNode = new DLLNode();
    newNode->data = data;
    newNode->prev = newNode->next = NULL;

    return newNode;
}

void insert(DLLNode **head, int data, int position) {
    DLLNode *newNode = getNode(data);

    if(!newNode)    {
        printf("Memory error\n");
        return;
    }

    DLLNode *p = *head, *q;

    if(position == 0)   {
        newNode->next = p;
        p->prev = newNode;
        *head = newNode;
    }

    else    {
        int i = 0;
        while(p && i < position)   {
            q = p;
            p = p->next;
            ++i;
        }

        q->next = newNode;
        newNode->next = p;
        newNode->prev = q;
    }
}

void printList(DLLNode *head)  {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\b\b\b   \n"); // destructive backspace
}

int main()  {
    DLLNode *head = getNode(1);
    insert(&head, 2, 1);
    insert(&head, 3, 0);
    insert(&head, 4, 3);
    printList(head);
    return 0;
}
