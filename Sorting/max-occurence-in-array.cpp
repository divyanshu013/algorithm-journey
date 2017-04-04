/*******************************************************************************

Max occurence in array
======================

--------------------------------------------------------------------------------

Problem
=======
Find the number which occurs maximum times in an array. Using sorting, it takes
O(nlogn) time and using hashing it takes O(n) time.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
Array is initially:
64 11 25 12 12 11 12
Number occuring maximum times is 12

*******************************************************************************/

#include <stdio.h>
#include <unordered_map>
using namespace std;

void printArray(int arr[], int n) {
  for(int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int getMax(int arr[], int n)  {
  unordered_map<int, int> u;
  for (int i = 0; i < n; i++) {
    u[arr[i]]++;  // values are initialized from 0
  }
  unordered_map<int, int> :: iterator itr;
  itr = u.begin();
  int max = itr->first;
  int count = itr->second;
  itr++;
  for (; itr != u.end(); itr++) {
    if (itr->second > count) {
      max = itr->first;
      count = itr->second;
    }
  }
  return max;
}

int main()  {
  int arr[] = {64, 11, 25, 12, 12, 11, 12};
  printf("Array is initially:\n");
  printArray(arr, 7);
  printf("Number occuring maximum times is %d\n", getMax(arr, 7));
  return 0;
}
