/*******************************************************************************

Counting sort
==============

Ref - http://www.geeksforgeeks.org/counting-sort/

--------------------------------------------------------------------------------

Problem
=======
Classic old counting sort.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Array is initially:
64 34 25 12 22 11 90
After counting sort, array is:
11 12 22 25 34 64 90

*******************************************************************************/

#include <stdio.h>
#define RANGE 100

void printArray(int arr[], int n) {
  for(int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

void countingSort(int arr[], int n) {

  // count array to store count of individual characters
  int count[RANGE + 1];
  for (int i = 0; i < RANGE + 1; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    ++count[arr[i]];
  }

  // build the sorted array
  int k = 0;
  for (int i = 0; i <= RANGE; i++) {
    for (int j = 0; j < count[i]; j++) {
      arr[k++] = i;
    }
  }
}

int main()  {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  printf("Array is initially:\n");
  printArray(arr, 7);
  printf("After counting sort, array is:\n");
  countingSort(arr, 7);
  printArray(arr, 7);
  return 0;
}
