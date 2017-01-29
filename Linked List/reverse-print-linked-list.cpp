/*******************************************************************************

Reverse print linked list
=========================

Ref - http://www.geeksforgeeks.org/write-a-recursive-function-to-print-reverse-of-a-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Print a linked list in reverse recursively

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

Space Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

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

void reversePrint(Node *head)   {
    if(head == NULL)
        return;

    reversePrint(head->next);
    printf("%d -> ", head->data);
}

int main()  {
    Node *head = getNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    printList(head);

    reversePrint(head);
    printf("\b\b\b   \n"); // destructive backspace
    return 0;
}
