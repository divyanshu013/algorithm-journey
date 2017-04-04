/*******************************************************************************

Sum exists in two arrays
========================

--------------------------------------------------------------------------------

Problem
=======
Given two arrays A[] and B[] and a number K, check if a + b == K where a belongs
to A and b to B.

--------------------------------------------------------------------------------

Time Complexity
===============
O(nlogn)

--------------------------------------------------------------------------------

Output
======
Array A is initially: 7 3 1 9 5 5 2
Array B is initially: 9 0 2 4 4 8 3
17 sum exists
20 sum does NOT exist

*******************************************************************************/

#include <stdio.h>

void printArray(int arr[], int n) {
  for(int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
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

bool binarySearch(int A[], int l, int r, int k) {
  while (l <= r) {
    int mid = (l + r)/2;
    if (A[mid] == k) {
      return true;
    }
    else if (A[mid] < k) {
      l = mid + 1;
    }
    else  {
      r = mid - 1;
    }
  }

  return false;
}

void checkSum(int A[], int B[], int n, int k) {
  quickSort(A, 0, n - 1);
  for (int i = 0; i < n; i++) {
    int c = k - B[i];
    if (binarySearch(A, 0, n - 1, c)) {
      printf("%d sum exists\n", k);
      return;
    }
  }
  printf("%d sum does NOT exist\n", k);
}

int main()  {
  int A[] = {7, 3, 1, 9, 5, 5, 2};
  int B[] = {9, 0, 2, 4, 4, 8, 3};
  printf("Array A is initially: ");
  printArray(A, 7);
  printf("Array B is initially: ");
  printArray(B, 7);

  checkSum(A, B, 7, 17);
  checkSum(A, B, 7, 20);
  return 0;
}
