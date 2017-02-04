/*******************************************************************************

Queue linked list
=================

Ref - http://quiz.geeksforgeeks.org/queue-set-2-linked-list-implementation/

--------------------------------------------------------------------------------

Problem
=======
A queue implementation using linked list

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

struct Node {
    int data;
    Node *next;
};

struct Queue    {
    Node *front, *rear;
};

void printList(Queue *queue)  {
    Node *current = queue->front;
    while(current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\b\b\b   \n");
}

Queue * getQueueNode()   {
    Queue *newNode = new Queue();
    newNode->front = newNode->rear = NULL;
    return newNode;
}

Node * getNode(int data)    {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enQueue(Queue *q, int data)    {
    Node *newNode = getNode(data);

    if(q->rear) {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    else    {
        q->front = q->rear = newNode;
    }
}

void deQueue(Queue *q)  {
    if(q->front)    {
        printf("Dequeued %d\n", q->front->data);
        Node *temp = q->front;
        q->front = q->front->next;
        delete(temp);
    }

    else    {
        printf("Queue empty\n");
        return;
    }

    if(!q->front)
        q->rear = NULL;
}

int main()  {
    Queue *queue = getQueueNode();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    printList(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    printList(queue);

    return 0;
}
