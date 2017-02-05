/*******************************************************************************

Successive pairs stack
======================

--------------------------------------------------------------------------------

Problem
=======
In a stack, check for if all numbers are successive pairs. For odd size, skip the
top.

--------------------------------------------------------------------------------

Algorithm
=========
Pop all elements from the stack into another stack and check.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

Space Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Pairs exists

*******************************************************************************/

#include <stdio.h>
#include <stack>
#include <stdlib.h>

using namespace std;

bool checkPairs(stack<int> s)   {
    stack<int> temp;
    while(!s.empty())   {
        temp.push(s.top());
        s.pop();
    }

    while(!temp.empty())    {
        int a = temp.top();
        temp.pop();
        if(temp.empty())
            return true;
        else    {
            int b = temp.top();
            temp.pop();
            if(abs(a - b) != 1)
                return false;
        }
    }

    return true;
}

int main()  {
    stack<int> s;
    s.push(4);
    s.push(5);
    s.push(-2);
    s.push(-3);
    s.push(11);
    s.push(10);
    s.push(5);
    s.push(6);
    s.push(20);
    if(checkPairs(s))
        printf("Pairs exists\n");
    else
        printf("Pairs do NOT exist\n");

    return 0;
}
