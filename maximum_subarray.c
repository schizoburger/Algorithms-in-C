#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "header.h"

typedef struct Tuple {
  int left;
  int right;
  int sum;
} Tuple;

Tuple findMaxCrossingSubarray(int*,int,int,int);
Tuple findMaximumSubarray(int*,int,int);

int main() {
  int n = 10;
  int mod = 100;
  int *array = getRandomIntArray(n,mod);
  printf("%s\n", "Array: ");
  printIntArray(array, n);
  Tuple max_tuple =findMaximumSubarray(array,0,n-1);
  printf("\n%s%d%s%d%s%d\n", "Max subarray starts at index: ", max_tuple.left, ", ends at index: ", max_tuple.right, " and its sum is: ", max_tuple.sum);
}

Tuple findMaxCrossingSubarray(int *array, int low, int mid, int high) {
  int left_sum = INT_MIN;
  int sum = 0;
  int max_left = mid;
  for (int i = mid; i >= low; i--) {
    sum = sum + array[i];
    if (sum > left_sum) {
      left_sum = sum;
      max_left = i;
    }
  }
  int right_sum = INT_MIN;
  sum = 0;
  int max_right = mid;
  for (int j = mid + 1; j <= high; j++) {
    sum = sum + array[j];
    if (sum > right_sum) {
      right_sum = sum;
      max_right = j;
    }
  }
  Tuple toReturn = {max_left, max_right, left_sum+right_sum};
  return toReturn;
}

Tuple findMaximumSubarray(int * array, int low, int high) {
  if (high==low) {
    Tuple toReturn = {low, high, array[low]};
    return toReturn;
  } else {
    int mid = (int) floor((low+high)/2);
    Tuple left_tuple = findMaximumSubarray(array, low, mid);
    Tuple right_tuple = findMaximumSubarray(array, mid + 1, high);
    Tuple cross_tuple = findMaxCrossingSubarray(array, low, mid, high);
    if (left_tuple.sum >= right_tuple.sum && left_tuple.sum >= cross_tuple.sum) {
      return left_tuple;
    } else if (right_tuple.sum >= left_tuple.sum && right_tuple.sum >= cross_tuple.sum) {
      return right_tuple;
    } else {
      return cross_tuple;
    }
  }
}
