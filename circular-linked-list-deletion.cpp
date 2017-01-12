/*******************************************************************************

Circular linked list deletion
=================================

Ref - http://quiz.geeksforgeeks.org/circular-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Delete a node in a Circular linked list at some position.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

*******************************************************************************/

#include <stdio.h>

struct CLLNode  {
    int data;
    CLLNode *next;
};

struct CLLNode * getNode(int data)  {
    CLLNode *newNode = new CLLNode();
    newNode->data = data;
    newNode->next = newNode;

    return newNode;
}

void insert(CLLNode **head, int data, int position) {
    CLLNode *newNode = getNode(data);
    if(!newNode)    {
        printf("Memory error\n");
        return;
    }

    if(*head == NULL)
        *head = newNode;

    else    {
        CLLNode *current = *head, *q;
        if(position == 0)   {
            newNode->next = current;
            while(current->next != *head)   {
                current = current->next;
            }
            current->next = newNode;
            *head = newNode;
        }

        else    {
            int i = 0;
            while(current && i < position)    {
                q = current;
                i++;
                current = current->next;
            }

            newNode->next = current;
            q->next = newNode;
        }
    }
}

void del(CLLNode **head, int position)  {
    CLLNode *current = *head, *q;
    if (!current) {
        printf("List is empty\n");
        return;
    }

    if(position == 0)   {

        current = current->next;
        while(current != *head)   {
            q = current;
            current = current->next;
        }
    }

    for (int i = 0; i < position; ++i)  {
        q = current;
        current = current->next;
    }

    if(current == *head)  {
        *head = (*head)->next;
    }
    q->next = current->next;
    delete(current);
}

void printList(CLLNode *head)  {
    CLLNode *current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while(current != head);
    printf("\b\b\b   \n"); // destructive backspace
}

int main()  {
    CLLNode *head = getNode(1);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 4, 0);
    printList(head);

    del(&head, 0);
    del(&head, 2);
    printList(head);
    return 0;
}
