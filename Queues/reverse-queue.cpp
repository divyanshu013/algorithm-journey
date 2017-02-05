/*******************************************************************************

Reverse queue
=============

Ref - http://stackoverflow.com/questions/818443/a-way-to-reverse-queue-using-only-two-temporary-queues-and-nothing-more

--------------------------------------------------------------------------------

Problem
=======
Reverse a queue using queue operations only.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

Space Complexity
===============
O(n) - for stack

--------------------------------------------------------------------------------

Output
======
4 3 2 1

*******************************************************************************/

#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> *q)    {
    stack<int> s;
    while(!(*q).empty())   {
        s.push((*q).front());
        (*q).pop();
    }

    while(!s.empty())   {
        (*q).push(s.top());
        s.pop();
    }
}

void printQueue(queue<int> q)   {
    while(!q.empty())   {
        printf("%d ", q.front());
        q.pop();
    }
    printf("\n");
}

int main()  {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    reverseQueue(&q);
    printQueue(q);
    return 0;
}
