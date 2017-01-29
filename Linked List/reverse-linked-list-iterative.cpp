/*******************************************************************************

Iterative reverse linked list
=============================

Ref - http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Reverse a linked list iteratively

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
4 -> 3 -> 2 -> 1
1 -> 2 -> 3 -> 4

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

void reverse(Node **head)   {
    Node *pre = NULL;
    if(*head == NULL)   {
        printf("Empty list\n");
        return;
    }

    Node *current = *head;
    while(current != NULL)  {
        Node *next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }

    *head = pre;
}

int main()  {
    Node *head = getNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    printList(head);

    reverse(&head);
    printList(head);
    return 0;
}
