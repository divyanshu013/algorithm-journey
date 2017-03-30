/*******************************************************************************

Radix sort
==========

Ref - http://www.geeksforgeeks.org/radix-sort/

--------------------------------------------------------------------------------

Problem
=======
Classic old radix sort.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Array is initially:
64 34 25 12 22 11 90
After radix sort, array is:
11 12 22 25 34 64 90

*******************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

void printArray(int arr[], int n) {
  for(int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int getMax(int arr[], int n)  {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void countingSort(int arr[], int n, int exp)  {
  // queue array also acts as a count array
  queue<int> q[10];

  for (int i = 0; i < n; i++) {
    q[(arr[i]/exp) % 10].push(arr[i]);
  }

  int k = 0;
  for (int i = 0; i < 10; i++) {
    while (!q[i].empty()) {
      arr[k++] = q[i].front();
      q[i].pop();
    }
  }
}
void radixSort(int arr[], int n) {

  // get the maximum number to find number of digits
  int max = getMax(arr, n);

  // counting sort for each digit
  for (int i = 1; max/i > 0; i *= 10) {
    countingSort(arr, n, i);
  }
}

int main()  {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  printf("Array is initially:\n");
  printArray(arr, 7);
  printf("After radix sort, array is:\n");
  radixSort(arr, 7);
  printArray(arr, 7);
  return 0;
}
