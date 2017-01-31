/*******************************************************************************

Get minimum
=================================

Ref - http://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
    - http://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

--------------------------------------------------------------------------------

Problem
=======
A getMin() function for stack to retrieve the minimum value in stack in O(1) time.

--------------------------------------------------------------------------------

Time Complexity
===============
O(1)

--------------------------------------------------------------------------------

Output
======
Pushed 2
Pushed 6
Pushed 4
Pushed 1
Pushed 5
Pushed 1
Min: 1
Popped 1
Min: 1
Popped 5
Min: 1
Popped 1
Min: 2
Popped 4
Min: 2
Popped 6
Min: 2
Popped 2
Stack empty

*******************************************************************************/

#include <stdio.h>
#include <stack>

using namespace std;

stack<int> minStack;
stack<int> s;

void push(int data) {
    if(s.empty())   {
        s.push(data);
        minStack.push(data);
    }
    else    {
        s.push(data);
        if(data <= minStack.top())
            minStack.push(data);
    }
    printf("Pushed %d\n", data);
}

int pop()   {
    if(s.empty())   {
        printf("Stack empty\n");
        return 0;
    }
    else    {
        if(s.top() == minStack.top())
            minStack.pop();
        int data = s.top();
        s.pop();
        printf("Popped %d\n", data);
        return data;
    }
}

int getMin()    {
    return minStack.top();
}

int main()  {
    push(2);
    push(6);
    push(4);
    push(1);
    push(5);
    push(1);

    printf("Min: %d\n", getMin());
    pop();
    printf("Min: %d\n", getMin());
    pop();
    printf("Min: %d\n", getMin());
    pop();
    printf("Min: %d\n", getMin());
    pop();
    printf("Min: %d\n", getMin());
    pop();
    printf("Min: %d\n", getMin());
    pop();
    pop();
    return 0;
}
