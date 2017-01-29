/*******************************************************************************

Sum of two linked lists
=======================

Ref - http://www.geeksforgeeks.org/sum-of-two-linked-lists/
    - http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/

--------------------------------------------------------------------------------

Problem
=======
Given two linked lists with the MSD at the head. Compute the sum to a third linked
list.

--------------------------------------------------------------------------------

Time Complexity
===============
O(m + n)

--------------------------------------------------------------------------------

Output
======
5 -> 4 -> 3 -> 2 -> 1
     8 -> 7 -> 6 -> 9
6 -> 3 -> 0 -> 9 -> 0

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

int size(Node *head)    {
    int n = 0;
    while(head) {
        head = head->next;
        n++;
    }
    return n;
}

void swapPointer(Node **a, Node **b)    {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

struct Node * addLists(Node *head, Node *head2, int *carry) {
    if(!head)
        return NULL;

    Node *result = getNode(0);
    int sum;
    result->next = addLists(head->next, head2->next, carry);
    sum = head->data + head2->data + *carry;
    *carry = sum / 10;
    sum %= 10;

    result->data = sum;
    return result;
}

void addSubList(Node *head, Node *current, int *carry, Node **result) {
    int sum;

    if(head != current) {
        addSubList(head->next, current, carry, result);
        sum = head->data + *carry;
        *carry = sum / 10;
        sum %= 10;

        push(result, sum);
    }
}

void sum(Node *head, Node *head2)  {
    int size1, size2;
    if(head)
        size1 = size(head);
    else
        return;
    if(head2)
        size2 = size(head2);
    else
        return;

    Node *result;
    int carry = 0;
    if(size1 == size2)  {
        result = addLists(head, head2, &carry);
    }
    else    {
        if(size2 >size1)
            swapPointer(&head, &head2);

        // head is the larger list
        int diff = size1 - size2;
        Node *current = head;
        for(int i = 0; i < diff; ++i)
            current = current->next;

        result = addLists(current, head2, &carry);

        addSubList(head, current, &carry, &result); // need to push nodes
    }

    if(carry)   {
        push(&result, carry);
    }
    printList(result);
}

int main()  {
    Node *head = getNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printList(head);

    Node *head2 = getNode(9);
    push(&head2, 6);
    push(&head2, 7);
    push(&head2, 8);
    printList(head2);
    sum(head, head2);
}
