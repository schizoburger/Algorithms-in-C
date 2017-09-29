#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int * getRandomPositiveIntArray(int,int);
int * getRandomIntArray(int,int);
void printIntArray(int*,int);

int * getRandomPositiveIntArray(int length, int mod) {
  srand(time(NULL));
  int *array = malloc(length);
  if (!array)
    return NULL;
  for(int i = 0; i < length; i++)
    array[i] = rand() % mod;

  return array;
}

int * getRandomIntArray(int length, int mod) {
  srand(time(NULL));
  int *array = malloc(length);
  if (!array)
    return NULL;
  for(int i = 0; i < length; i++)
    array[i] = rand() % mod - (int) floor(mod/2);

  return array;
}

void printIntArray(int *array, int length) {
  for(int i = 0; i < length; i++) {
    if (i < length - 1) {
      printf("%d, ", array[i]);
    } else {
      printf("%d", array[i]);
    }
  }
}
