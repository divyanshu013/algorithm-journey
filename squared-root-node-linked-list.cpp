/*******************************************************************************

Square root node linked list
============================

Ref - http://technerds.in/2016/12/15/finding-square-root-nth-node/

--------------------------------------------------------------------------------

Problem
=======
For any linked list find the square root node. For a linked list of size n, the
root node is sqrt(n)th node from the head.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
Square root node is 7

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

void sqrtNode(Node *head)  {
    if(head)    {
        Node *root = head;
        int n = 1, count = 1;
        while(head) {
            if(n > count * count)  {
                root = root->next;
                count++;
            }
            head = head->next;
            n++;
        }
        printf("Square root node is %d\n", root->data);
    }
    else
        return;
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

    sqrtNode(head);
}
