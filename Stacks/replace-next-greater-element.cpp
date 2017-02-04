/*******************************************************************************

Replace next greater element
============================

Ref - http://www.geeksforgeeks.org/next-greater-element/

--------------------------------------------------------------------------------

Problem
=======
In an array replace each element by the next greater element nearest to it on the
right.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n) - each element pushed to stack once

--------------------------------------------------------------------------------

Output
======
3 2 4 1 9 7
4 4 4 9 9 7

*******************************************************************************/

#include <stdio.h>
#include <stack>
using namespace std;

void printArray(int a[], int n) {
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void replaceGreater(int a[], int n) {
    stack<int> s;
    for(int i = 0; i < n; ++i)  {
        if(s.empty() || a[s.top()] > a[i])
            s.push(i);

        else    {
            while(!s.empty() && a[i] > a[s.top()])  {
                a[s.top()] = a[i];
                s.pop();
            }
        }
    }

    printArray(a, 6);
}

int main()  {
    int a[] = {3, 2, 4, 1, 9, 7};
    printArray(a, 6);

    replaceGreater(a, 6);
    return 0;
}
