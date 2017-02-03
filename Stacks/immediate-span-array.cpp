/*******************************************************************************

Immediate span array
====================

Ref - http://www.geeksforgeeks.org/stock-buy-sell/
    - Cormen 4.1

--------------------------------------------------------------------------------

Problem
=======
Maximum number of elements A[j] preceeding A[i] such that A[j] <= A[i]

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
6 1 2 3 2
1 1 2 3 1

*******************************************************************************/

#include <stdio.h>

void printArray(int a[], int n) {
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void span(int a[], int n)   {
    int span = 1;
    printf("%d ", span);
    for(int i = 1; i < n; ++i)  {
        if(a[i] < a[i - 1])
            span = 1;
        else
            span++;
        printf("%d ", span);
    }
    printf("\n");
}

int main()  {
    int a[] = {6, 1, 2, 3, 2};
    printArray(a, 5);
    span(a, 5);
    return 0;
}
