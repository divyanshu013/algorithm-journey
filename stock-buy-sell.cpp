/*******************************************************************************

Stock Buy Sell to Maximize Profit
=================================

Ref - http://www.geeksforgeeks.org/stock-buy-sell/
    - Cormen 4.1

--------------------------------------------------------------------------------

Problem
=======
The cost of a stock on each day is given in an array, find the max profit that you
can make by buying and selling in those days. For example, if the given array is
{100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0,
selling on day 3. Again buy on day 4 and sell on day 6. If the given array of prices
is sorted in decreasing order, then profit cannot be earned at all.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Buy on day : 0   Sell on day: 3
Buy on day : 4   Sell on day: 6

*******************************************************************************/
#include <stdio.h>

struct Stock    {
    int buy, sell, profit;
};

void stockAnalysis (int price[], int n) {
    if (n == 1) {
        return;
    }

    int count = 0; // solution pairs

    Stock stock[n/2 + 1]; // maximum possible pairs

    int i = 0;
    while (i < n - 1) {

        // finding local minima
        while ((i < n - 1) && (price[i + 1] <= price[i])) {
            i++;
        }

        if (i == n - 1) {
            break;
        }

        // store index of minima
        stock[count].buy = i++;

        //finding local maxima
        while ((i < n) && (price[i] >= price[i - 1])) { // also comparing with local minima
            i++;
        }

        // store index of maxima
        stock[count].sell = i - 1; // stock was at maxima on previous day
        stock[count].profit = price[stock[count].sell] - price[stock[count].buy];

        count++;
    }

    if (count == 0) {
        printf("Do not buy stocks\n");
    }

    else    {
        for (int i = 0; i < count; i++)
            printf("Buy on %d and sell on %d for profit of %d\n", stock[i].buy, stock[i].sell, stock[i].profit);
    }

    return;
}

int main() {
    // int price[] = {100, 180, 260, 310, 40, 535, 695}; // original case

    // int price[] = {100, 200, 300, 400};
    // int price[] = {400, 300, 200, 100};
    int price[] = {100, 130, 115, 140, 110, 130, 50, 105, 100};
    int n = sizeof(price)/sizeof(price[0]);
    stockAnalysis(price, n);
    return 0;
}
