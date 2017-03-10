/*******************************************************************************

Unique BST for 1...n values
===========================

--------------------------------------------------------------------------------

Problem
=======
For key values 1...n find number of structurally different unique BSTs possible.
Need to consider each value to be the root.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n^2)

--------------------------------------------------------------------------------

Output
======
For n = 5, possible BSTs are: 42

*******************************************************************************/

#include <stdio.h>

int count(int n)    {
    if(n <= 1)
        return 1;
    else    {
        int sum = 0;
        for(int root = 1; root <= n; ++root)    {
            int left = count(root - 1);
            int right = count(n - root);
            sum += left * right;    // possible sub-trees with current root
        }
        return sum;
    }
}

int main()  {
    printf("For n = 5, possible BSTs are: %d\n", count(5));
    return 0;
}
