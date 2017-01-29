/*******************************************************************************

Doubly linked list deletion
===========================

Ref - http://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Delete a node from doubly linked list at some position

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

struct DLLNode  {
    int data;
    DLLNode *next;
    DLLNode *prev;
};

struct DLLNode * getNode(int data)  {
    DLLNode *newNode = new DLLNode();
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

void insert(DLLNode **head, int data, int position) {
    DLLNode *newNode = getNode(data);

    if(!newNode)    {
        printf("Memory error\n");
        return;
    }

    DLLNode *p = *head, *q;

    if(position == 0)   {
        newNode->next = p;
        p->prev = newNode;
        *head = newNode;
    }

    else    {
        int i = 0;
        while(p && i < position)   {
            q = p;
            p = p->next;
            ++i;
        }

        q->next = newNode;
        newNode->next = p;
        newNode->prev = q;
    }
}

void del(DLLNode **head, int position)  {
    if(*head == NULL)   {
        printf("List empty\n");
        return;
    }

    DLLNode *p = *head, *q;

    if(position == 0)   {
        *head = (*head)->next;
        delete(p);
    }
    else    {
        int i = 0;
        while(p && i < position)    {
            q = p;
            p = p->next;
            i++;
        }

        if(!p)  {
            printf("Position doesn't exists\n");
            return;
        }
        else    {
            q->next = p->next;
            delete(p);
        }
    }
}

void printList(DLLNode *head)  {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\b\b\b   \n"); // destructive backspace
}

int main()  {
    DLLNode *head = getNode(1);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 4, 0);
    printList(head);

    del(&head, 0);
    del(&head, 2);
    printList(head);
    return 0;
}
