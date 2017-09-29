#include <stdio.h>
#include <math.h>
#include "header.h"
#include <stdbool.h>

void merge(int*,int,int,int);
void merge_sort(int*,int,int);

int main() {
  int n = 10;
  int mod = 100;
  int *array = getRandomPositiveIntArray(n,mod);

  printf("%s\n", "Array before sorting:");
  printIntArray(array, n);

  merge_sort(array, 0, n-1);

  printf("\n\n%s\n", "Array after sorting:");
  printIntArray(array, n);
  printf("\n");
}

void merge(int *array, int p, int q, int r) {
  //printf("\n\n%s\n", "Array before merge");
  //printIntArray(array, r+1);
  int n1 = q - p + 1;
  //printf("\n\n%s%d\n", "n1=", n1);
  int n2 = r - q ;
  //printf("\n\n%s%d\n", "n2=", n2);
  int left[n1];
  int right[n2];
  for (int i = 0; i < n1; i++)
    left[i] = array[p + i];
  //printf("\n\n%s\n", "Left array:");
  //printIntArray(left, n1);
  for (int i = 0; i < n2; i++)
    right[i] = array[q + i + 1];
  //printf("\n\n%s\n", "Right array:");
  //printIntArray(right, n2);
  int i = 0;
  int j = 0;
  int k = p;
  while (i < n1 && j < n2) {
    if (left[i]<=right[j]) {
      array[k] = left[i];
      i++;
    } else {
      array[k] = right[j];
      j++;
    }
    k++;
  }
  //printf("\n\n%s\n", "Array after first while:");
  //printIntArray(array, r+1);
  while (i < n1 || j < n2) {
    if (i < n1) {
      array[k] = left[i];
      i++;
    } else {
      array[k] = right[j];
      j++;
    }
    k++;
  }
  //printf("\n\n%s\n", "Array after second while:");
  //printIntArray(array, r+1);
}

void merge_sort(int *array, int p, int r) {
  if (p < r) {
    int q = (int) floor((p+r)/2);
    merge_sort(array, p, q);
    merge_sort(array, q + 1, r);
    merge(array, p, q, r);
  }
}
