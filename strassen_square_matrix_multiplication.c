#include <stdio.h>
#include <stdlib.h>

void printSquareMatrix(int**,int);
int **initSquareMatrix(int);
int **getEyeMatrix(int);
void free_matrix(int**,int);
void square_matrix_multiply_recursive(int**,int**,int,int,int,int,int);
int **sumSquareMatrices(int**,int**,int,int,int,int,int);
int **subtractSquareMatrices(int**,int**,int,int,int,int,int);

int main() {
  int n = 4;
  int **matrixA = getEyeMatrix(n);
  int **matrixB = getEyeMatrix(n);
  printSquareMatrix(matrixA,n);
  square_matrix_multiply_recursive(matrixA,matrixB,0,0,0,0,n);
  free_matrix(matrixA, n);
  free_matrix(matrixB, n);
}

void square_matrix_multiply_recursive(int **matrixA, int **matrixB, int rA, int cA, int rB, int cB, int n) {
  int **matrixC = initSquareMatrix(n);
  if (n==1) {
    matrixC[0][0] = matrixA[0][0]*matrixB[0][0];
  } else {
    int length = n/2;
  }
}

int **sumSquareMatrices(int **matrixA, int **matrixB, int rA, int cA, int rB, int cB, int n) {
  int **matrixC = initSquareMatrix(n);
  // Local variables for columns
  int cAl = cA;
  int cBl = cB;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrixC[i][j] = matrixA[rA][cAl] + matrixB[rB][cBl];
      // Increment columns
      cAl++;
      cBl++;
    }
    // Set the local variables for columns to original values
    // since we are moving to the next row
    cAl = cA;
    cBl = cB;

    // Increment rows
    rA++;
    rB++;
  }
  return matrixC;
}

int **subtractSquareMatrices(int **matrixA, int **matrixB, int rA, int cA, int rB, int cB, int n) {
  int **matrixC = initSquareMatrix(n);
  // Local variables for columns
  int cAl = cA;
  int cBl = cB;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrixC[i][j] = matrixA[rA][cAl] - matrixB[rB][cBl];
      // Increment columns
      cAl++;
      cBl++;
    }
    // Set the local variables for columns to original values
    // since we are moving to the next row
    cAl = cA;
    cBl = cB;

    // Increment rows
    rA++;
    rB++;
  }
  return matrixC;
}

void printSquareMatrix(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    printf("\n");
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
  }
  printf("\n");
}

int **getEyeMatrix(int n) {
  int **matrix = initSquareMatrix(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i==j) {
        matrix[i][j]=1;
      } else {
        matrix[i][j]=0;
      }
    }
  }
  return matrix;
}

int **initSquareMatrix(int n) {
  // allocate n rows, each row is a pointer to int
  int **matrix = (int **) malloc(n*sizeof(int*));

  // for each row allocate n ints
  for (int row = 0; row < n; row++) {
    matrix[row] = (int *) malloc(n * sizeof(int));
  }
  return matrix;
}

void free_matrix(int **matrix, int n) {
  // first free each row
  for (int row = 0; row < n; row++) {
    free(matrix[row]);
  }

  // free the memory of the pointers to the rows
  free(matrix);
}
