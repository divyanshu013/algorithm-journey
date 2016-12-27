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
O(k^n)

--------------------------------------------------------------------------------

Output
======
Binary strings:
000
100
010
110
001
101
011
111

K-ary strings:
000
100
200
010
110
210
020
120
220
001
101
201
011
111
211
021
121
221
002
102
202
012
112
212
022
122
222

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

void genKString(int n, int k)   {
    if (n == 0) {
        printf("%s\n", A);
    }
    else    {
        for (int j = 0; j < k; j++) {
            A[n - 1] = '0' + j;
            genKString(n - 1, k);
        }
    }
}

int main()  {
    printf("Binary strings:\n");
    genString(3);
    printf("\nK-ary strings:\n");
    genKString(3, 3);
    return 0;
}
