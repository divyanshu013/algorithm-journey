/*******************************************************************************

Reverse k elements queue
========================

--------------------------------------------------------------------------------

Problem
=======
Reverse first k elements of a queue.

--------------------------------------------------------------------------------

Algorithm
=========
1. Push first k elements into a stack.
2. Pop all elements and enqueue.
3. Dequeue (size - k) times and enqueue.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

Space Complexity
===============
O(k)

--------------------------------------------------------------------------------

Output
======
10 20 30 40 50 60 70 80 90 100
40 30 20 10 50 60 70 80 90 100

*******************************************************************************/

#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

void printQueue(queue<int> q)   {
    while(!q.empty())   {
        printf("%d ", q.front());
        q.pop();
    }
    printf("\n");
}

void reverseK(queue<int> *q, int k)    {
    stack<int> s;
    if(k > (*q).size()) {
        printf("Queue length insufficient\n");
        return;
    }

    for(int i = 0; i < k; ++i)  {
        s.push((*q).front());
        (*q).pop();
    }

    for(int i = 0; i < k; ++i)  {
        (*q).push(s.top());
        s.pop();
    }

    for(int i = 0; i < (*q).size() - k; ++i)    {
        (*q).push((*q).front());
        (*q).pop();
    }
}

int main()  {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    printQueue(q);

    reverseK(&q, 4); // reverse first 4 elements
    printQueue(q);

    return 0;
}
