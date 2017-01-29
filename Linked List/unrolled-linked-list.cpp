/*******************************************************************************

Unrolled linked lists
=====================

Ref - http://www.geeksforgeeks.org/unrolled-linked-list-set-1-introduction/

--------------------------------------------------------------------------------

Problem
=======
Operations on an Unrolled linked list.

--------------------------------------------------------------------------------

Algorithm
=========

1. Shift extra node in a block to the next block when inserting
2. Create new block if the last block exceeds blockSize

--------------------------------------------------------------------------------

Time Complexity
===============
O(n ^ 1/2)

*******************************************************************************/

#include <stdio.h>
#include <math.h>

struct Node {
    int data;
    Node *next;
};

struct Block    {
    Block *next;
    Node *head;
    int count;
};

struct Node * getNode(int data)  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Block * getBlock() {
    Block *newBlock = new Block();
    newBlock->count = 0;
    newBlock->next = NULL;
    newBlock->head = NULL;

    return newBlock;
}

void search(Block **head, Node **node, int blockSize, int k)    {
    Block *p = *head;
    for(int i = 0; i < k/blockSize; ++i)
        p = p->next;

    Node *q = p->head;
    k %= blockSize;
    for(int i = 0; i < k; ++i)
        q = q->next;

    *node = q;
    return;
}

void shift(Block *p, int blockSize)   { // Starts shifting from this block
    Block *q;
    Node *temp;
    while(p->count > blockSize) {
        if(p->next == NULL) { // last block
            q = getBlock();
            p->next = q;
            temp = p->head->next; // node to be shifted
            p->head->next = p->head->next->next; // node before the one to be shifted (circular)
            q->head = temp;
            temp->next = temp;
            p->count--;
            q->count++;
        }
        else    {
            q = p->next;
            temp = p->head->next;
            p->head->next = p->head->next->next;
            temp->next = q->head->next;
            q->head->next = temp;
            q->head = temp; // completing circular list
            p->count--;
            q->count++;
        }

        p = q;
    }
}

void insert(Block **block, int data, int k)    {
    Block *blockHead = *block, *r;
    Node *p, *q;
    if(!blockHead)  { // first block or node
        blockHead = getBlock();
        blockHead->head = getNode(data);
        blockHead->head->next = blockHead->head;
        blockHead->count++;
    }
    else    {
        if(k == 0)  {
            p = blockHead->head;
            q = p->next;
            p->next = getNode(data);
            p->next->next = q;
            blockHead->head = p->next;
            blockHead->count++;
            shift(blockHead, 3);
        }
        else    {
            search(&r, &p, 3, k);
            q = p;
            while(q->next != p)
                q = q->next;
            q->next = getNode(data);
            q->next->next = p;
            r->count++;
            shift(r, 3);
        }
    }
}
