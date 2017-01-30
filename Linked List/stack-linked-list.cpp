/*******************************************************************************

Stack linked list
=================

Ref - http://quiz.geeksforgeeks.org/stack-set-1/

--------------------------------------------------------------------------------

Problem
=======
Implement a stack using linked list

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Push 2
Push 3
Push 4
Push 5
Pop 5
Pop 4
Pop 3
Pop 2
Stack empty
Stack empty

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

void push(Node **top, int data) {
    Node *temp = getNode(data);
    temp->next = *top;
    *top = temp;
    printf("Push %d\n", data);
}

bool isEmpty(Node *top) {
    if(!top)
        return true;
    else
        return false;
}

int pop(Node **top) {
    if(isEmpty(*top))  {
        printf("Stack empty\n");
        return 0;
    }
    else    {
        Node *temp = *top;
        int data = temp->data;
        delete(temp);
        *top = (*top)->next;
        printf("Pop %d\n", data);
        return data;
    }
}

int main()  {
    Node *head = NULL;
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
}
