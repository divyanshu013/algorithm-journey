/*******************************************************************************

Find length of connected cells of 1s in a matrix of 0s
======================================================
                -- or --

Find the number of islands (using DFS)
======================================

Ref - https://en.wikipedia.org/wiki/Connected_component_%28graph_theory%29
    - http://www.geeksforgeeks.org/find-number-of-islands/

--------------------------------------------------------------------------------

Problem
=======
In a 2-D matrix of 0s and 1s find the largest region connected by 1s only. The
region can be connected horizontally, vertically or diagonally.

--------------------------------------------------------------------------------

Algorithm
=========
1) Apply DFS on each component.
2) In each component call DFS on the next unvisited component.
3) Number of calls to DFS gives the number of connected components.
4) Solve recursively.

Time Complexity
===============
O(row * column) or O(n^2)

--------------------------------------------------------------------------------

Output
======
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 0 1

Number of islands: 5
Maximum number of connected cells: 4

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int max = 0; // max size of connected cells
int size = 0;

bool isValid(int A[][5], int row, int col, bool visited[][5])    {
    if(row >= 0 && row < 5 && col >= 0 && col < 5 && A[row][col] && !visited[row][col])
        return true;
    else
        return false;
}

void DFS(int A[][5], int row, int col, bool visited[][5])   {

    // possible coordinates for 8 directions
    static int x[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int y[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    visited[row][col] = true;
    ++size;

    // marking all connected cells as visited
    for(int i = 0; i < 8; ++i)  {
        if(isValid(A, row + x[i], col + y[i], visited))
            DFS(A, row + x[i], col + y[i], visited);
    }
}

int countIslands(int A[][5])  {
    bool visited[5][5];
    memset(visited, 0, sizeof(visited)); // sets memory blocks as 0s

    int count = 0;
    for(int i = 0; i < 5; ++i)  {
        for(int j = 0; j < 5; ++j)  {
            if(A[i][j] && !visited[i][j])   {
                // if cell is 1 and not yet visited
                DFS(A, i, j, visited);
                if(size > max)
                    max = size;
                size = 0;
                ++count;
            }
        }
    }

    return count;
}

int main()  {
    int A[][5] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    printf("Number of islands: %d\n", countIslands(A));
    printf("Maximum number of connected cells: %d\n", max);
    return 0;
}
