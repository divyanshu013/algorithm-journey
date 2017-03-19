/*******************************************************************************

Insertion sort
==============

Ref - http://quiz.geeksforgeeks.org/insertion-sort/

--------------------------------------------------------------------------------

Problem
=======
Classic old insertion sort.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n^2)

--------------------------------------------------------------------------------

Output
======
Array is initially:
64 34 25 12 22 11 90
After insertion sort, array is:
11 12 22 25 34 64 90

*******************************************************************************/

#include <stdio.h>

void printArray(int arr[], int n) {
  for(int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

void insertionSort(int arr[], int n) {
  for(int i = 1; i < n; ++i)  {
    int temp = arr[i];
    int j = i;
    while(j > 0 && arr[j - 1] > temp) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = temp;
  }
}

int main()  {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  printf("Array is initially:\n");
  printArray(arr, 7);
  printf("After insertion sort, array is:\n");
  insertionSort(arr, 7);
  printArray(arr, 7);
  return 0;
}
