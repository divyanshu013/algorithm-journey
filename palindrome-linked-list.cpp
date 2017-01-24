/*******************************************************************************

Palindrome linked list
======================

Ref - http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

--------------------------------------------------------------------------------

Problem
=======
Check if a linked list is Palindrome.

Algorithm
=========
Traverse till the middle element and reverse the rest of the list.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
1 -> 2 -> 3 -> 2 -> 1
Palindrome

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

void palindrome(Node *head)    {
    Node *fast = head, *slow = head;
    if(head == NULL)    {
        printf("Empty list\n");
        return;
    }

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reversing second half
    Node *temp = slow;
    slow = slow->next;
    while(slow) {
        Node *nextNode = slow->next;
        slow->next = temp;
        temp = slow;
        slow = nextNode;
    }

    Node *temp2 = head;
    while(temp != temp2)    {
        if(temp->data != temp2->data)   {
            printf("Not palindrome\n");
            return;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }

    printf("Palindrome\n");
}

int main()  {
    Node *head = getNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);

    palindrome(head);
    return 0;
}
