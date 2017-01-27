/*******************************************************************************

Josephus circle linked list
===========================

Ref - http://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/

--------------------------------------------------------------------------------

Problem
=======
Determine the last node remaining in a cicular linked list representing a
Josephus Circle problem.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n^2)

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

*******************************************************************************/

/*******************************************************************************

Reverse blocks of k nodes
=========================

Ref - http://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
    - http://www.sanfoundry.com/c-program-solve-josephus-problem-using-linked-list/

--------------------------------------------------------------------------------

Problem
=======
Reverse blocks of k nodes in linked list.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
Killing 3
Killing 5
Killing 6
Killing 4
Killing 1
Killing 7
Killing 2
Killing 9
Last remaining node is 8

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
    Node *current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while(current != head);
    printf("\b\b\b   \n"); // destructive backspace
}

void josephus(Node *head, int m)   {
    Node *current = head;
    while(current->next != current)   {
        Node *temp = current;
        for(int i = 0; i < m - 1; ++i)  {
            temp = current;
            current = current->next;
        }
        // current needs to be deleted
        temp->next = current->next;
        printf("Killing %d\n", current->data);
        delete(current);
        current = temp->next;
    }

    printf("Last remaining node is %d\n", current->data);
}

int main()  {
    Node *head = getNode(1);
    Node *end = head;
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    end->next = head;
    printList(head);

    josephus(head, 7);  // eliminate every 7th person around the circle
}
