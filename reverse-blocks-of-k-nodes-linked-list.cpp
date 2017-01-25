/*******************************************************************************

Reverse blocks of k nodes
=========================

Ref - http://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

--------------------------------------------------------------------------------

Problem
=======
Reverse blocks of k nodes in linked list.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
7 -> 8 -> 9 -> 4 -> 5 -> 6 -> 1 -> 2 -> 3

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

struct Node * reverse(Node *head, int k)   {
    if(k < 2)
        return head;    // no reverse required
    else    {
        Node *current = head;
        Node *prev = NULL;
        Node *nextNode = NULL;
        int i = 0;

        while(current != NULL && i < k) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            ++i;
        }

        if(nextNode != NULL)
            head->next = reverse(nextNode, k);  // call for next block recursively

        return prev;    // new head
    }
}

int main()  {
    Node *head = getNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    printList(head);

    Node *reversed = reverse(head, 3);
    printList(reversed);
}
