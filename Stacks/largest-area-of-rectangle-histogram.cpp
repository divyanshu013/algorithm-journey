/*******************************************************************************

Largest area rectangle histogram
================================

Ref - http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
    - http://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/

--------------------------------------------------------------------------------

Problem
=======
Given a histogram find the area of the largest rectangle formed by it.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n) - Each bar pushed to stack only once

--------------------------------------------------------------------------------

Output
======
Max area: 12

*******************************************************************************/

#include <stdio.h>
#include <stack>

using namespace std;

int maxArea(int hist[], int n)  {
    stack<int> s;   // holds indexes of bars in increasing order of heights

    int max = 0, i = 0;

    while(i < n)    {

        // pushing current bar to stack if it exceeds stack top
        if(s.empty() || hist[i] >= hist[s.top()])
            s.push(i++);

        // finding area since current bar is less than the stack top
        // area of rectangle with stack top as the smallest height
        // right index -> i
        // left index -> element before s.top()
        else    {
            int top = s.top();
            s.pop();

            // if stack is empty then this is smallest member and left index is 0
            int area = hist[top] * (s.empty() ? i : i - s.top() - 1);

            if(area > max)
                max = area;
        }
    }

    // finding area for remaining smaller bars
    while(!s.empty())   {
        int top = s.top();
        s.pop();
        int area = hist[top] * (s.empty() ? i : i - s.top() - 1);

        if(area > max)
            max = area;
    }

    return max;
}

int main()  {
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    printf("Max area: %d\n", maxArea(hist, 7));
    return 0;
}
