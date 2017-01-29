/*******************************************************************************

Linked list intersection
========================

Ref - http://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

--------------------------------------------------------------------------------

Problem
=======
Given two linked lists find the intersecting node for the two lists.

--------------------------------------------------------------------------------

Time Complexity
===============
O(m + n)

*******************************************************************************/

#include <stdio.h>

struct Node {
    int data;
    Node *next;
};

int intersection(Node *first, Node *second) {
    Node *p = first, *q = second;
    int m = 0, n = 0;
    while(p)    {
        p = p->next;
        m++;
    }
    while(q)    {
        q = q->next;
        n++;
    }

    int diff = m - n;
    if(diff > 0)    {
        while(diff != 0)    {
            first = first->next;
            diff--;
        }
    }
    else if(diff < 0)   {
        while(diff != 0)    {
            second = second->next;
            diff++;
        }
    }

    while(first != second)  {
        first = first->next;
        second = second->next;
    }

    return first->data; // or second->data
}

int main()  {
    // create two lists and call intersection()
    return 0;
}
