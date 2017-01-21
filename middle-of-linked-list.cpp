/*******************************************************************************

Middle of linked list
=====================

Ref - http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Find middle of a linked list

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
5 -> 4 -> 3 -> 2 -> 1
Mid of linked list is 3

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

void mid(Node *head)    {
    Node *fast = head, *slow = head;
    if(head == NULL)    {
        printf("Empty list\n");
        return;
    }

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Mid of linked list is %d\n", slow->data);
}

int main()  {
    Node *head = getNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printList(head);

    mid(head);
    return 0;
}
