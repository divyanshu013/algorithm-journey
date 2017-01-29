/*******************************************************************************

Linked list deletion
====================

Ref - http://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/

--------------------------------------------------------------------------------

Problem
=======
Delete a node in a linked list at some position.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
4 -> 3 -> 2 -> 1
3 -> 2

*******************************************************************************/

#include <stdio.h>

struct Node {
    int data;
    Node *next;
};

struct Node * getNode(int data)    {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert(Node **head, int data, int position)    {
    Node *newNode = getNode(data);

    if(!newNode)    {
        printf("Memory error\n");
        return;
    }

    Node *p = *head, *q;

    if(position == 0)   {
        newNode->next = p;
        *head = newNode;
    }

    else    {
        int i = 0;
        while (p && i < position)   {
            i++;
            q = p;
            p = p->next;
        }

        q->next = newNode;
        newNode->next = p;
    }
}

void del(Node **head, int position)  {
    if(*head == NULL)   {
        printf("List empty\n");
        return;
    }

    Node *p = *head, *q;
    if(position == 0)   {
        *head = (*head)->next;
        delete(p);
    }

    else    {
        int i = 0;
        while(p && i < position)    {
            i++;
            q = p;
            p = p->next;
        }

        if(!p)  {
            printf("Position doesn't exists\n");
            return;
        }

        q->next = p->next;
        delete(p);
    }
}

void printList(Node *head)  {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\b\b\b   \n"); // destructive backspace
}

int main()  {
    Node *head = getNode(1);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 4, 0);
    printList(head);

    del(&head, 0);
    del(&head, 2);
    printList(head);
    return 0;
}
