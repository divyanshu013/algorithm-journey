/*******************************************************************************

Reverse linked list in pairs
============================

Ref - http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Reverse the elements of a linked lists in pairs.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
6 -> 5 -> 4 -> 3 -> 2 -> 1
5 -> 6 -> 3 -> 4 -> 1 -> 2 

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

struct Node * reverse(Node *head)   {
    if(head == NULL || head->next == NULL)
        return head;    // works if odd number of nodes in the list
    else    {
        Node *temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp;
        head->next->next = reverse(head->next->next);

        return head;
    }
}

int main()  {
    Node *head = getNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    printList(head);

    Node *reversed = reverse(head);
    printList(reversed);
}
