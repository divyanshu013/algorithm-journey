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
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

*******************************************************************************/

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

    
}
