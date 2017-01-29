/*******************************************************************************

Circular linked list insertion
==============================

Ref - http://quiz.geeksforgeeks.org/circular-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Insert a node in a Circular linked list at some position

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
3 -> 1 -> 2 -> 4

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
    insert(&head, 2, 1);
    insert(&head, 3, 0);
    insert(&head, 4, 3);
    printList(head);
    return 0;
}
