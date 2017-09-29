#include <stdio.h>
#include "header.h"

void insertion_sort(int*,int);
void recursive_insertion_sort(int*,int);
void merge(int*,int);

int main() {
  int n = 10;
  int mod = 100;
  int *array = getRandomPositiveIntArray(n,mod);
  printf("%s\n", "Array before sorting:");
  printIntArray(array, n);
  recursive_insertion_sort(array, n);
  printf("\n\n%s\n", "Array after sorting:");
  printIntArray(array, n);
  binary_search(array,0,n-1, 999);
  printf("\n");
}

void insertion_sort(int * array,int n) {
  for (int i = 1; i < n; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j+1] = array[j];
      j = j - 1;
    }
    array[j+1] = key;
  }
}
void recursive_insertion_sort(int * array, int n) {
  if (n > 0) {
    recursive_insertion_sort(array, n - 1);
    merge(array, n - 1);
  }
}

void merge(int * array, int n) {
  int key = array[n];
  int i = 0;
  //printf("\n%s\n", "Array before while:");
  //printIntArray(array, n+1);
  while (i < n) {
    if (key < array[i]) {
      int current = array[i];
      array[i] = key;
      key = current;
    }
    i++;
  }
  array[n]=key;
  //printf("\n%s\n", "Array after while:");
  //printIntArray(array, n+1);
}
