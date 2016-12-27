/*******************************************************************************

Generate all strings of n bits
==============================

Ref - ADS 2.12

--------------------------------------------------------------------------------

Problem
=======
Generate all strings of n bits. Assume A[0...n-1] is an array of size n.

--------------------------------------------------------------------------------

Algorithm
=========
1) Every bit can take two values, 0s and 1s.
2) Start from end of string and set current bit as 0 and 1.
3) Call recursively.

--------------------------------------------------------------------------------

Time Complexity
===============
O(2^n)

--------------------------------------------------------------------------------

Output
======
000
100
010
110
001
101
011
111

*******************************************************************************/

#include <stdio.h>

char A[3];

void genString(int n) {
    if (n == 0) {
        printf("%s\n", A);
    }
    else    {
        A[n - 1] = '0';
        genString(n - 1);
        A[n - 1] = '1';
        genString(n - 1);
    }
}

int main()  {
    genString(3);
    return 0;
}
