#include <stdio.h>
#include <math.h>
#include "header.h"

void binary_search(int*,int,int,int);

void binary_search(int * array, int p, int r, int v) {
  if (p==r) {
    printf("\n\n%d%s%s%s\n", v ," is ", array[p]==v ? "" : "not ","in array.");
  } else {
    int q = (int) floor((p+r)/2);
    if (array[q]==v) {
      printf("\n\n%d%s\n", v, "is in array.");

    } else if (v < array[q]) {
      binary_search(array, p, q - 1, v);
    } else {
      binary_search(array, q + 1, r, v);
    }
  }
}
