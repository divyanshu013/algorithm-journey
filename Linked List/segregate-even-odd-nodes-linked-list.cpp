/*******************************************************************************

Segregate even odd nodes linked list
====================================

Ref - http://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Modify linked list to make all even numbers appear at the beginning.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
8 -> 6 -> 4 -> 2 -> 9 -> 7 -> 5 -> 3 -> 1 

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

void segregate(Node *head)  {
    Node *evenHead = NULL, *oddHead = NULL, *evenCurrent = NULL, *oddCurrent = NULL;
    while(head != NULL) {
        if(head->data % 2 == 0) {
            if(!evenHead)   {
                evenHead = head;
                evenCurrent = evenHead;
            }
            else    {
                evenCurrent->next = head;
                evenCurrent = head;
            }
        }
        else    {
            if(!oddHead)    {
                oddHead = head;
                oddCurrent = oddHead;
            }
            else    {
                oddCurrent->next = head;
                oddCurrent = head;
            }
        }

        head = head->next;
    }

    if(evenCurrent)
        evenCurrent->next = oddHead;
    if(oddCurrent)  // for a list having no odd nodes
        oddCurrent->next = NULL;
    if(evenHead)
        printList(evenHead);
    else    // for a list having only odd nodes
        printList(oddHead);
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

    segregate(head);
}
