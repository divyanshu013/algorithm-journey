/*******************************************************************************

Quick sort
==============

Ref - http://quiz.geeksforgeeks.org/quick-sort/

--------------------------------------------------------------------------------

Problem
=======
Classic old quick sort.

--------------------------------------------------------------------------------

Time Complexity
===============
O(nlogn)

--------------------------------------------------------------------------------

Output
======
Array is initially:
64 34 25 12 22 11 90
After quick sort, array is:
11 12 22 25 34 64 90

*******************************************************************************/

#include <stdio.h>

void printArray(int arr[], int n) {
  for(int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = arr[m + i + 1];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i++];
    }
    else  {
      arr[k] = R[j++];
    }
    k++;
  }

  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void swap(int *p, int *q) {
  int temp = *p;
  *p = *q;
  *q = temp;
}

int partition(int arr[], int l, int r)  {
  int pivot = arr[r];
  int i = l;
  for (int j = l; j < r; j++) {
    if (arr[j] <= pivot) {
      swap(&arr[i++], &arr[j]);
    }
  }
  swap(&arr[i], &arr[r]);
  return i;
}

void quickSort(int arr[], int l, int r) {
  if (l < r) {
    int p = partition(arr, l, r);

    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
  }
}

int main()  {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  printf("Array is initially:\n");
  printArray(arr, 7);
  printf("After quick sort, array is:\n");
  quickSort(arr, 0, 6);
  printArray(arr, 7);
  return 0;
}
