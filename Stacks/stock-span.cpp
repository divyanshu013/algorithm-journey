/*******************************************************************************

Stock span
=================================

Ref - http://www.geeksforgeeks.org/the-stock-span-problem/

--------------------------------------------------------------------------------

Problem
=======
The span of stock's price on day i is the maximum number of consecutive days just
before the given day for which the price is less than or equal to current day's.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n) - stack

--------------------------------------------------------------------------------

Output
======
10 4 5 90 120 80
1 1 2 4 5 1

*******************************************************************************/

#include <stdio.h>
#include <stack>

using namespace std;

void printArray(int a[], int n) {
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void span(int a[], int span[], int n)  {
    stack<int> s;
    s.push(0);
    span[0] = 1; // first element span is always 1

    for(int i = 1; i < n; ++i)  {
        // pop till stack top is less than or equal to current
        while(!s.empty() && a[s.top()] <= a[i])
            s.pop();

        // for empty stack stock is larger than all other previous values
        // else it is larger than elements after stack top
        span[i] = s.empty() ? (i + 1) : (i - s.top());

        // pushing current value to stack
        s.push(i);
    }

    printArray(span, 6);
}

int main()  {
    int a[] = {10, 4, 5, 90, 120, 80};
    printArray(a, 6);
    int sp[6];
    span(a, sp, 6);

    return 0;
}
