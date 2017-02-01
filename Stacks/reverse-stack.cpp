/*******************************************************************************

Reverse stack
=================================

Ref - http://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

--------------------------------------------------------------------------------

Problem
=======
Reverse a stack using push and pop operations

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Stack
4
3
2
1
Stack after reversal
1
2
3
4

*******************************************************************************/

#include <stdio.h>
#include <stack>

using namespace std;

void insert(stack<int> *s, int data)    {
    if((*s).empty())    {
        (*s).push(data);
        return;
    }

    else    {
        int temp = (*s).top();
        (*s).pop();
        insert(s, data);
        (*s).push(temp);
    }
}

void reverse(stack<int> *s)    {
    if((*s).empty())
        return;

    else    {
        int data = (*s).top();
        (*s).pop();
        reverse(s);
        insert(s, data);
    }
}

int main()  {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    printf("Stack\n4\n3\n2\n1\n");
    reverse(&s);

    printf("Stack after reversal\n");
    while(!s.empty())   {
        printf("%d\n", s.top());
        s.pop();
    }
    return 0;
}
